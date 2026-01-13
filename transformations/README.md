# Ray Tracing & Shading Module

This module implements a CPU-based ray tracing pipeline for basic geometric primitives and physically-inspired shading. It supports both orthographic and perspective cameras and produces rendered images using a Phong lighting model.

It is part of the **Computer Graphics Rendering Framework**, focusing on ray generation, intersection testing, and shading in 3D scenes.

---

## Features

- Ray–Sphere intersection
- Ray–Parallelogram intersection
- Orthographic and Perspective camera models
- Primary ray generation
- Surface normal computation
- Phong illumination model:
  - Ambient
  - Diffuse
  - Specular
- Eigen-based vector and matrix math

---

## How It Works

1. **Ray Generation**  
   Rays are generated per pixel from either an orthographic or perspective camera.

2. **Intersection Testing**  
   Rays are tested against analytic primitives (spheres and parallelograms). The closest hit is selected.

3. **Shading**  
   Surface color is computed using the Phong lighting model with ambient, diffuse, and specular terms.

4. **Image Output**  
   The final RGB result is written as an output image for inspection and comparison.

---

## Build & Run

### Requirements
- C++17 compatible compiler (GCC / Clang / MSVC)
- CMake 3.10+
- Eigen (included in the repository)

### Compile

From the `transformations` directory:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Run

```bash
./ray_tracer
```

The application will:
- Render a simple scene using ray casting
- Apply Phong lighting for shading
- Save the output image to the project’s output folder (commonly `img/`)

---

## Project Structure

- `src/` – Ray generation, intersections, shading, math utilities  
- `img/` – Rendered output images  
- `data/` – Scene parameters / inputs (if used)  
- `build/` – Build artifacts  

---

## Applications

- Ray tracing fundamentals and research  
- Lighting model validation  
- Camera model testing  
- Foundations for advanced rendering systems  

---

## Author

Developed as part of a modular **Computer Graphics Rendering Framework** implementing core ray tracing and shading algorithms.
