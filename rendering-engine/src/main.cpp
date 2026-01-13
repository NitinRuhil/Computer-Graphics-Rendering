// C++ include
#include <iostream>
#include <string>
#include <vector>

// Utilities for the Assignment
#include "raster.h"

#include <gif.h>
#include <fstream>

#include <Eigen/Geometry>
// Image writing library
#define STB_IMAGE_WRITE_IMPLEMENTATION // Do not include this line twice in your project!
#include "stb_image_write.h"

using namespace std;
using namespace Eigen;

//Image height
const int H = 480;

//Camera settings
const double near_plane = 1.5;       //AKA focal length
const double far_plane = near_plane * 100;
const double field_of_view = 0.7854; //45 degrees
const double aspect_ratio = 1.5;
const bool is_perspective = false;
const Vector3d camera_position(0, 0, 3);
const Vector3d camera_gaze(0, 0, -1);
const Vector3d camera_top(0, 1, 0);

//Object
const std::string data_dir = DATA_DIR;
const std::string mesh_filename(data_dir + "bunny.off");
MatrixXd vertices; // n x 3 matrix (n points)
MatrixXi facets;   // m x 3 matrix (m triangles)

//Material for the object
const Vector3d obj_diffuse_color(0.5, 0.5, 0.5);
const Vector3d obj_specular_color(0.2, 0.2, 0.2);
const double obj_specular_exponent = 256.0;

//Lights
std::vector<Vector3d> light_positions;
std::vector<Vector3d> light_colors;
//Ambient light
const Vector3d ambient_light(0.3, 0.3, 0.3);

//Fills the different arrays
void setup_scene()
{
    //Loads file
    std::ifstream in(mesh_filename);
    if (!in.good())
    {
        std::cerr << "Invalid file " << mesh_filename << std::endl;
        exit(1);
    }
    std::string token;
    in >> token;
    int nv, nf, ne;
    in >> nv >> nf >> ne;
    vertices.resize(nv, 3);
    facets.resize(nf, 3);
    for (int i = 0; i < nv; ++i)
    {
        in >> vertices(i, 0) >> vertices(i, 1) >> vertices(i, 2);
    }
    for (int i = 0; i < nf; ++i)
    {
        int s;
        in >> s >> facets(i, 0) >> facets(i, 1) >> facets(i, 2);
        assert(s == 3);
    }

    //Lights
    light_positions.emplace_back(8, 8, 0);
    light_colors.emplace_back(16, 16, 16);

    light_positions.emplace_back(6, -8, 0);
    light_colors.emplace_back(16, 16, 16);

    light_positions.emplace_back(4, 8, 0);
    light_colors.emplace_back(16, 16, 16);

    light_positions.emplace_back(2, -8, 0);
    light_colors.emplace_back(16, 16, 16);

    light_positions.emplace_back(0, 8, 0);
    light_colors.emplace_back(16, 16, 16);

    light_positions.emplace_back(-2, -8, 0);
    light_colors.emplace_back(16, 16, 16);

    light_positions.emplace_back(-4, 8, 0);
    light_colors.emplace_back(16, 16, 16);
}

void build_uniform(UniformAttributes &uniform)
{
    //TODO: setup camera, compute w, u, v
    Vector3d w = - camera_gaze / camera_gaze.norm();
    Vector3d u = camera_top.cross(w) / (camera_top.cross(w)).norm();
    Vector3d v = w.cross(u);
    
    //TODO: compute the camera transformation

    Matrix4d camera_transformation;

    camera_transformation << Vector4d(u[0], u[1], u[2], 0),
                 Vector4d(v[0], v[1], v[2], 0),
                 Vector4d(w[0], w[1], w[2], 0),
                 Vector4d(camera_position(0), camera_position(1), camera_position(2), 1);
    camera_transformation = camera_transformation.inverse().eval();

    //TODO: setup projection matrix

    double t = tan(field_of_view / 2.0) * near_plane;
    double r = t * aspect_ratio;
    double l = -r;
    double b = -t;
    double n = -near_plane;
    double f = -far_plane;

    Matrix4d P;
    P << Vector4d(2/(r-l), 0, 0, -(r+l)/(r-l)),
                Vector4d(0, 2/(t-b), 0, -(t+b)/(t-b)),
                Vector4d(0, 0, 2/(n-f), -(n+f)/(n-f)),
                Vector4d(0, 0, 0, 1);
    P.transposeInPlace();

    if (is_perspective)
    {
        //TODO setup prespective camera
        Matrix4d pers_cam;
        pers_cam << Vector4d(n, 0, 0, 0),
                        Vector4d(0, n, 0, 0),
                        Vector4d(0, 0, n+f, -f*n),
                        Vector4d(0, 0, 1, 0);
        pers_cam.transposeInPlace();
        uniform.view =  P * pers_cam * camera_transformation;
    }
    else
    {
        uniform.view = P * camera_transformation;
    }
}

void simple_render(Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic> &frameBuffer)
{
    UniformAttributes uniform;
    build_uniform(uniform);
    Program program;

    program.VertexShader = [](const VertexAttributes &va, const UniformAttributes &uniform) {
        //TODO: fill the shader
        VertexAttributes outer_va;
        outer_va.position = uniform.view * va.position;
        return outer_va;
    };

    program.FragmentShader = [](const VertexAttributes &va, const UniformAttributes &uniform) {
        //TODO: fill the shader
        return FragmentAttributes(1, 0, 0);
    };

    program.BlendingShader = [](const FragmentAttributes &fa, const FrameBufferAttributes &previous) {
        //TODO: fill the shader
        return FrameBufferAttributes(fa.color[0], fa.color[1], fa.color[2], fa.color[3]);
    };

    std::vector<VertexAttributes> vertex_attributes;
    //TODO: build the vertex attributes from vertices and facets
    int facets_total  = facets.rows();
    for (int i = 0; i < facets_total ; i++)
    {
        Vector3i vect = facets.row(i);
        for (int j = 0; j < 3; j++)
        {
            // Vector3d vertex = vertices.row(r(j));
            VertexAttributes va(vertices(vect(j), 0), vertices(vect(j), 1), vertices(vect(j), 2));

            vertex_attributes.push_back(va);
        }
    }

    rasterize_triangles(program, uniform, vertex_attributes, frameBuffer);
}

Matrix4d compute_rotation(const double alpha)
{
    //TODO: Compute the rotation matrix of angle alpha on the y axis around the object barycenter
    Matrix4d res;
    res << Vector4d(cos(alpha), 0, -sin(alpha), 0),
           Vector4d(0, 1, 0, 0),
           Vector4d(sin(alpha), 0, cos(alpha), 0),
           Vector4d(0, 0, 0, 1);

    return res;
}

void wireframe_render(const double alpha, Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic> &frameBuffer)
{
    UniformAttributes uniform;
    build_uniform(uniform);
    Program program;

    Matrix4d trafo = compute_rotation(alpha);
    uniform.view *= trafo;
    //uniform.transform = trafo;

    program.VertexShader = [](const VertexAttributes &va, const UniformAttributes &uniform) {
        //TODO: fill the shader
        VertexAttributes outer_va;
        outer_va.position = uniform.view * va.position;
        return outer_va;
    };

    program.FragmentShader = [](const VertexAttributes &va, const UniformAttributes &ujniform) {
        //TODO: fill the shader
        return FragmentAttributes(1, 0, 0);
    };

    program.BlendingShader = [](const FragmentAttributes &fa, const FrameBufferAttributes &previous) {
        //TODO: fill the shader
        return FrameBufferAttributes(fa.color[0] , fa.color[1] , fa.color[2] , fa.color[3] );
    };

    std::vector<VertexAttributes> vertex_attributes;

    //TODO: generate the vertex attributes for the edges and rasterize the lines
    //TODO: use the transformation matrix
    int facets_total  = facets.rows();
    for (int i = 0; i < facets_total; ++i)
    {
        Vector3i vect = facets.row(i);
        for (int j = 0; j < 3; ++j)
        {
            VertexAttributes va(vertices(vect(j), 0), vertices(vect(j), 1), vertices(vect(j), 2));
            vertex_attributes.push_back(va);
            VertexAttributes va2(vertices(vect((j + 1) % 3), 0), vertices(vect((j + 1) % 3), 1), vertices(vect((j + 1) % 3), 2));
            vertex_attributes.push_back(va2);
        }
    }
    rasterize_lines(program, uniform, vertex_attributes, 0.5, frameBuffer);
}

void get_shading_program(Program &program)
{
    program.VertexShader = [](const VertexAttributes &va, const UniformAttributes &uniform) {
        VertexAttributes outer_va;
        outer_va.position = uniform.view * va.position;
        outer_va.normal = va.normal;

        Vector3d transform_normal = va.normal;

        Vector3d lights_color(0,0,0);
        int position_s = light_positions.size();
        int i = 0;
        while(i< position_s){
            const Vector3d &light_position = light_positions[i];
            const Vector3d &light_color = light_colors[i];

            Vector3d position (outer_va.position(0), outer_va.position(1), outer_va.position(2));
            Vector3d normal (transform_normal(0), transform_normal(1), transform_normal(2));

            const Vector3d L_normal = (light_position - position).normalized();

            const Vector3d diffuse = obj_diffuse_color * std::max(L_normal.dot(normal), 0.0);

            Vector3d v = (camera_position - position).normalized();
            const Vector3d h = (((camera_position - position).normalized())+L_normal)/(((camera_position - position).normalized())+L_normal).norm();

            const Vector3d specular = obj_specular_color * std::pow(std::max(normal.dot(h), 0.0), obj_specular_exponent);

            const Vector3d direction = light_position - position;
            lights_color += (diffuse + specular).cwiseProduct(light_color) / direction.squaredNorm();
            i++;
        }
 	lights_color += ambient_light;
        Vector4d c = Vector4d(lights_color(0), lights_color(1), lights_color(2), 1);
        outer_va.color = c; 
        return outer_va;
};


    program.FragmentShader = [](const VertexAttributes &va, const UniformAttributes &uniform) {
        //TODO: create the correct fragment
        FragmentAttributes outer_fa = FragmentAttributes(va.color(0), va.color(1), va.color(2), uniform.color(3));
        if (!is_perspective) {
            outer_fa.position = va.position.cwiseProduct(Vector4d(1,1,-1,1));
        } else {
            outer_fa.position = va.position;
        }
        return outer_fa;
    };

    program.BlendingShader = [](const FragmentAttributes &fa, const FrameBufferAttributes &previous) {
        //TODO: implement the depth check
        enum DepthComparison { LESS_THAN, GREATER_EQUAL };

        DepthComparison comparison = (fa.position[2] < previous.depth) ? LESS_THAN : GREATER_EQUAL;

        switch (comparison) {
            case LESS_THAN: {
                FrameBufferAttributes outer_fb(fa.color[0], fa.color[1], fa.color[2], fa.color[3]);
                outer_fb.depth = fa.position[2];
                return outer_fb;
            }
            case GREATER_EQUAL: {
                return previous;
            }
        }
        
    };
}

void flat_shading(const double alpha, Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic> &frameBuffer)
{
    UniformAttributes uniform;
    build_uniform(uniform);
    Program program;
    get_shading_program(program);
    Eigen::Matrix4d trafo = compute_rotation(alpha);
    uniform.view *= trafo;

    std::vector<VertexAttributes> vertex_attributes;
    //TODO: compute the normals
    //TODO: set material colors
     int facets_total  = facets.rows();
     int i = 0;
     while(i<facets_total){
        Vector3i r = facets.row(i);
        Vector3d a = vertices.row(r(0));
        Vector3d b = vertices.row(r(1));
        Vector3d c = vertices.row(r(2));
        Vector3d norm = (b - a).cross(c - a).normalized();
        Vector3d norm_4 = Vector3d(norm(0), norm(1), norm(2));

        for (int j = 0; j <= 2; j++) {
            VertexAttributes va(vertices(r(j), 0), vertices(r(j), 1), vertices(r(j), 2));
            norm_4 = va.normal;
            vertex_attributes.push_back(va);
        }
        i++;
    }
    rasterize_triangles(program, uniform, vertex_attributes, frameBuffer);

}

void pv_shading(const double alpha, Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic> &frameBuffer)
{
    UniformAttributes uniform;
    build_uniform(uniform);
    Program program;
    get_shading_program(program);

    Eigen::Matrix4d trafo = compute_rotation(alpha);
    uniform.view *= trafo;

    //TODO: compute the vertex normals as vertex normal average

    std::vector<VertexAttributes> vertex_attributes;
    //TODO: create vertex attributes
    //TODO: set material colors
    Eigen::MatrixXd normal_vertex = Eigen::MatrixXd::Zero(vertices.rows(), 3);
    normal_vertex.setZero();
    int facets_total  = facets.rows();
    for(int i = 0; i < facets_total; i++) {
        Vector3i r = facets.row(i);
        Vector3d a = vertices.row(r(0));
        Vector3d b = vertices.row(r(1));
        Vector3d c = vertices.row(r(2));
        Vector3d norm = (b - a).cross(c - a).normalized();


        normal_vertex.row(r(0)) += norm;
        normal_vertex.row(r(1)) += norm;
        normal_vertex.row(r(1)) += norm;
    }
    int i = 0;
    while(i<facets_total){
        Vector3i r = facets.row(i);
        for (int j = 0; j < 3; j++) {
            VertexAttributes v(vertices(r(j), 0), vertices(r(j), 1), vertices(r(j), 2));
            Vector3d n = normal_vertex.row(r(j)).normalized();
            vertex_attributes.push_back(v);
        }
        i++;
    }
    rasterize_triangles(program, uniform, vertex_attributes, frameBuffer);
}

int main(int argc, char *argv[])
{
    setup_scene();

    int W = H * aspect_ratio;
    Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic> frameBuffer(W, H);
    vector<uint8_t> image;

    simple_render(frameBuffer);
    framebuffer_to_uint8(frameBuffer, image);
    stbi_write_png("simple.png", frameBuffer.rows(), frameBuffer.cols(), 4, image.data(), frameBuffer.rows() * 4);
    frameBuffer = Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic>(W, H);

    wireframe_render(0, frameBuffer);
    framebuffer_to_uint8(frameBuffer, image);
    stbi_write_png("wireframe.png", frameBuffer.rows(), frameBuffer.cols(), 4, image.data(), frameBuffer.rows() * 4);
    frameBuffer = Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic>(W, H);

    flat_shading(0, frameBuffer);
    framebuffer_to_uint8(frameBuffer, image);
    stbi_write_png("flat_shading.png", frameBuffer.rows(), frameBuffer.cols(), 4, image.data(), frameBuffer.rows() * 4);
    frameBuffer = Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic>(W, H);

    pv_shading(0, frameBuffer);
    framebuffer_to_uint8(frameBuffer, image);
    stbi_write_png("pv_shading.png", frameBuffer.rows(), frameBuffer.cols(), 4, image.data(), frameBuffer.rows() * 4);
    frameBuffer = Eigen::Matrix<FrameBufferAttributes, Eigen::Dynamic, Eigen::Dynamic>(W, H);

    //TODO: add the animation
    GifWriter gif;

    int delay = 25;
    GifWriter g;
    GifBegin(&g, "wireframe_render.gif", frameBuffer.rows(), frameBuffer.cols(), delay);
    for (float i = 0; i < 1; i += 0.05)
    {
        frameBuffer.setConstant(FrameBufferAttributes());
        wireframe_render(EIGEN_PI * i * 2, frameBuffer);
        framebuffer_to_uint8(frameBuffer, image);
        GifWriteFrame(&g, image.data(), frameBuffer.rows(), frameBuffer.cols(), delay);
    }
    GifEnd(&g);

    GifBegin(&g, "flat_shading.gif", frameBuffer.rows(), frameBuffer.cols(), delay);
    for (float i = 0; i < 1; i += 0.05)
    {
        frameBuffer.setConstant(FrameBufferAttributes());
        flat_shading(EIGEN_PI * i * 2, frameBuffer);
        framebuffer_to_uint8(frameBuffer, image);
        GifWriteFrame(&g, image.data(), frameBuffer.rows(), frameBuffer.cols(), delay);
    }
    GifEnd(&g);

    GifBegin(&g, "pv_shading.gif", frameBuffer.rows(), frameBuffer.cols(), delay);
    for (float i = 0; i < 1; i += 0.05)
    {
        frameBuffer.setConstant(FrameBufferAttributes());
        pv_shading(i * EIGEN_PI * 2.0, frameBuffer);
        framebuffer_to_uint8(frameBuffer, image);
        GifWriteFrame(&g, image.data(), frameBuffer.rows(), frameBuffer.cols(), delay);
    }
    GifEnd(&g);

    return 0;
}

