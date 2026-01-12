#pragma once

#include <Eigen/Core>

class VertexAttributes
{
public:
    VertexAttributes(double x = 0, double y = 0, double z = 0, double w = 1)
    {
        position << x, y, z, w;
    }

    // Interpolates the vertex attributes
    static VertexAttributes interpolate(
        const VertexAttributes &a,
        const VertexAttributes &b,
        const VertexAttributes &c,
        const double alpha,
        const double beta,
        const double gamma)
    {
        VertexAttributes r;
        r.position = alpha * a.position + beta * b.position + gamma * c.position;
        r.color = alpha * a.color + beta * b.color + gamma * c.color;
        return r;
    }

    Eigen::Vector4d position;
     Eigen::Vector3d normal;
    Eigen::Vector4d color;
};

class FragmentAttributes
{
public:
    FragmentAttributes(double r = 0, double g = 0, double b = 0, double a = 1)
    {
        color << r, g, b, a;
    }

    Eigen::Vector4d color;
    Eigen::Vector4d position;
};


class FrameBufferAttributes
{
public:
    FrameBufferAttributes(double r = 0, double  g = 0, double  b = 0, double  a = 1)
    {
        color << r, g, b, a;
        depth = 2;
    }

    Eigen::Matrix<uint8_t, 4, 1> color;
    double depth;
};

class UniformAttributes
{
public:
    Eigen::Matrix4d view;
    Eigen::Vector4d color;
};

