# Ray Tracing & Shading Module

This module implements a foundational CPU-based ray tracing system with support for geometric primitives, perspective and orthographic projections, and physically-inspired shading models.

It is part of the **Computer Graphics Rendering Framework**, focusing on ray generation, intersection testing, and lighting computation in 3D scenes.

---

## Features

* Ray–Sphere and Ray–Parallelogram intersection
* Orthographic and Perspective camera models
* Primary ray generation
* Surface normal computation
* Phong illumination model:

  * Ambient lighting
  * Diffuse reflection
  * Specular highlights
* RGB color shading
* Eigen-based vector and matrix math

---

## Rendering Pipeline

1. **Ray Generation**
   Rays are generated from the camera using either orthographic or perspective projection.

2. **Intersection Testing**
   Rays are tested against analytic geometry (spheres and planes/parallelograms).

3. **Surface Shading**
   Lighting is computed using ambient, diffuse, and specular components.

4. **Image Formation**
   The closest intersection determines the final pixel color in the rendered image.

---

## Build & Run

### Requirements

* C++17 compatible compiler
* CMake (3.10+)
* Eigen (included in the project)

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
./assignment2
```

The program will:

* Cast rays into the scene
* Intersect them with spheres and planes
* Apply lighting and shading
* Output rendered images to the project directory

---

## Example Outputs

* Orthographic projection of a plane
* Perspective projection of a plane
* Shaded sphere with full Phong lighting

Example images can be found in the `img/` folder.

---

## Applications

* Ray tracing research and education
* Lighting model validation
* Camera and projection system testing
* Foundations for global illumination engines
* Graphics pipeline prototyping

---

## Project Structure

* `src/` – Ray generation, intersection, shading, math
* `data/` – Scene parameters
* `img/` – Rendered output images
* `build/` – CMake build artifacts

---

## Author

Developed as part of a modular **Computer Graphics Rendering System** implementing core ray tracing and shading algorithms.
