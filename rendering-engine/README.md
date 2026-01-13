# Software Rasterization & Rendering Engine

This module implements a complete CPU-based rasterization pipeline for rendering triangulated 3D models. It supports camera transformations, orthographic and perspective projection, shading models, depth testing, and real-time visualization of mesh geometry.

It is part of the **Computer Graphics Rendering Framework**, focusing on the core stages of the graphics pipeline: transformation, projection, rasterization, and shading.

---

## Features

* Triangle rasterization
* Orthographic and Perspective cameras
* Wireframe and solid rendering
* Flat shading and per-vertex (Gouraud) shading
* Depth buffering (Z-buffer)
* Per-face and per-vertex normal computation
* Real-time object rotation and animation
* Eigen-based linear algebra
* CPU-based shader simulation

---

## Rendering Pipeline

1. **Model Transformation**
   Object-space to world-space using rotation and translation matrices.

2. **Camera Transformation**
   World-space to view-space using a camera transformation matrix.

3. **Projection**

   * Orthographic projection
   * Perspective projection

4. **Rasterization**

   * Triangle scan conversion
   * Depth testing
   * Attribute interpolation

5. **Shading**

   * Flat shading (per-face normals)
   * Per-vertex shading (interpolated lighting)
   * Diffuse and specular lighting models

---

## Build & Run

### Requirements

* C++17 compatible compiler
* CMake (3.10+)
* Eigen (already included in the project)

### Compile

From the `rendering-engine` directory:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Run

```bash
./rendering_engine
```

The program will:

* Load 3D mesh models from the `data/` folder
* Render them using the software rasterizer
* Display shaded results and save output images to the `img/` directory

---

## Example Outputs

The engine can render:

* Solid orthographic projection
* Wireframe visualization
* Flat shaded surfaces
* Smooth per-vertex shaded surfaces
* Animated rotating models
* Perspective camera views

Example models include the Stanford Bunny and other triangulated meshes.

---

## Applications

* Learning and research in computer graphics
* Software rasterizer development
* Shading and lighting model testing
* Camera and projection system validation
* Graphics pipeline prototyping

---

## Project Structure

* `src/` – Rasterizer, camera, shaders, and math utilities
* `data/` – Input mesh models
* `img/` – Rendered output images and animations
* `examples/` – Sample rendering configurations

---

## Author

Developed as part of a modular **Computer Graphics Rendering System** implementing a full software-based graphics pipeline for educational and research purposes.
