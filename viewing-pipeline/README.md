# Advanced Viewing & Ray Tracing Pipeline

This module implements advanced camera models and light transport effects for a CPU-based ray tracing system. It extends the basic renderer with physically inspired viewing effects such as shadows, reflections, refractions, depth of field, and procedural textures.

It is part of the **Computer Graphics Rendering Framework**, focusing on secondary ray generation and realistic image synthesis.

---

## Features

* Perspective and Orthographic camera models
* Field-of-View and focal length control
* Shadow ray casting
* Phong illumination model (ambient, diffuse, specular)
* Recursive reflections
* Refraction using Snell’s Law
* Depth of Field (aperture sampling)
* Procedural textures using Perlin Noise
* Ray–Sphere and Ray–Plane intersections
* Eigen-based linear algebra

---

## Rendering Pipeline

1. **Primary Ray Generation**
   Rays are generated from the camera using perspective or orthographic projection.

2. **Visibility & Shadows**
   Shadow rays are cast toward light sources to determine occlusion.

3. **Shading & Lighting**
   Phong lighting is computed using surface normals and light direction.

4. **Recursive Effects**

   * Reflection rays
   * Refraction rays
   * Controlled recursion depth for performance

5. **Camera Effects**

   * Perspective projection
   * Depth of Field via aperture sampling

6. **Procedural Texturing**

   * Perlin noise with linear and cubic interpolation

---

## Build & Run

### Requirements

* C++17 compatible compiler
* CMake 3.10+
* Eigen (included in the repository)

### Compile

From the `viewing-pipeline` directory:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Run

```bash
./viewing_pipeline
```

The application will:

* Generate primary and secondary rays
* Compute shadows, reflections, and refractions
* Apply depth of field and procedural textures
* Save the rendered image to the `img/` directory

---

## Example Outputs

The engine can render:

* Shadowed scenes with Phong shading
* Reflective and refractive surfaces
* Depth of field blur
* Procedural Perlin noise textures

Sample images are available in the `img/` folder.

---

## Project Structure

* `src/` – Ray generation, shading, recursion, camera models
* `img/` – Rendered output images
* `data/` – Scene configuration files
* `build/` – CMake build artifacts

---

## Applications

* Physically-based rendering research
* Ray tracing engine development
* Camera and optical simulation
* Graphics pipeline prototyping
* Foundations for global illumination systems

---

## Author

Developed as part of a modular **Computer Graphics Rendering Framework** implementing advanced viewing and light-transport algorithms.
