# Advanced Ray Tracing & Viewing Pipeline

This module implements advanced ray tracing effects and camera models, including shadows, reflections, refractions, depth of field, and procedural textures. It extends the basic ray tracer with physically inspired light transport and viewing effects.

It is part of the **Computer Graphics Rendering Framework**, focusing on the viewing pipeline and secondary ray generation for realistic image synthesis.

---

## Features

- Perspective and orthographic cameras
- Field-of-view and focal length control
- Shadow ray casting
- Phong illumination model (ambient, diffuse, specular)
- Recursive reflection rays
- Refraction using Snell’s Law
- Depth of Field (aperture sampling)
- Procedural textures using Perlin Noise
- Ray–Sphere and Ray–Plane intersection
- Eigen-based linear algebra

---

## Rendering Pipeline

1. **Primary Ray Generation**  
   Rays are generated from the camera based on projection and field-of-view.

2. **Visibility & Shadows**  
   Shadow rays determine light occlusion.

3. **Lighting & Shading**  
   Phong lighting with diffuse and specular components.

4. **Recursive Effects**  
   - Reflection rays  
   - Refraction rays  
   - Limited bounce depth for performance  

5. **Camera Effects**  
   - Perspective projection  
   - Depth of field via aperture sampling  

6. **Procedural Texturing**  
   - Perlin noise with linear and cubic interpolation  

---

## Build & Run

### Requirements
- C++17 compatible compiler  
- CMake 3.10+  
- Eigen (included in the repository)

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
./assignment3
```

The program will:
- Cast primary and secondary rays  
- Compute shadows, reflections, and refractions  
- Apply depth of field and procedural textures  
- Output the rendered image to the current directory  

---

## Example Outputs

The engine can generate:

- Shadowed scenes with Phong lighting  
- Reflective and refractive objects  
- Depth of field blur  
- Procedural Perlin noise textures  

Sample results are available in the `img/` folder.

---

## Applications

- Physically based rendering research  
- Ray tracing engine development  
- Camera model simulation  
- Optical effects experimentation  
- Foundations for global illumination systems  

---

## Project Structure

- `src/` – Ray generation, shading, recursion, camera models  
- `img/` – Rendered outputs  
- `build/` – CMake build artifacts  
- `data/` – Scene configuration  

---

## Author

Developed as part of a modular **Computer Graphics Rendering System** implementing advanced viewing and light transport effects.# Advanced Ray Tracing & Viewing Pipeline

This module implements advanced ray tracing effects and camera models, including shadows, reflections, refractions, depth of field, and procedural textures. It extends the basic ray tracer with physically inspired light transport and viewing effects.

It is part of the **Computer Graphics Rendering Framework**, focusing on the viewing pipeline and secondary ray generation for realistic image synthesis.

---

## Features

- Perspective and orthographic cameras
- Field-of-view and focal length control
- Shadow ray casting
- Phong illumination model (ambient, diffuse, specular)
- Recursive reflection rays
- Refraction using Snell’s Law
- Depth of Field (aperture sampling)
- Procedural textures using Perlin Noise
- Ray–Sphere and Ray–Plane intersection
- Eigen-based linear algebra

---

## Rendering Pipeline

1. **Primary Ray Generation**  
   Rays are generated from the camera based on projection and field-of-view.

2. **Visibility & Shadows**  
   Shadow rays determine light occlusion.

3. **Lighting & Shading**  
   Phong lighting with diffuse and specular components.

4. **Recursive Effects**  
   - Reflection rays  
   - Refraction rays  
   - Limited bounce depth for performance  

5. **Camera Effects**  
   - Perspective projection  
   - Depth of field via aperture sampling  

6. **Procedural Texturing**  
   - Perlin noise with linear and cubic interpolation  

---

## Build & Run

### Requirements
- C++17 compatible compiler  
- CMake 3.10+  
- Eigen (included in the repository)

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
./assignment3
```

The program will:
- Cast primary and secondary rays  
- Compute shadows, reflections, and refractions  
- Apply depth of field and procedural textures  
- Output the rendered image to the current directory  

---

## Example Outputs

The engine can generate:

- Shadowed scenes with Phong lighting  
- Reflective and refractive objects  
- Depth of field blur  
- Procedural Perlin noise textures  

Sample results are available in the `img/` folder.

---

## Applications

- Physically based rendering research  
- Ray tracing engine development  
- Camera model simulation  
- Optical effects experimentation  
- Foundations for global illumination systems  

---

## Project Structure

- `src/` – Ray generation, shading, recursion, camera models  
- `img/` – Rendered outputs  
- `build/` – CMake build artifacts  
- `data/` – Scene configuration  

---

## Author

Developed as part of a modular **Computer Graphics Rendering System** implementing advanced viewing and light transport effects.# Advanced Ray Tracing & Viewing Pipeline

This module implements advanced ray tracing effects and camera models, including shadows, reflections, refractions, depth of field, and procedural textures. It extends the basic ray tracer with physically inspired light transport and viewing effects.

It is part of the **Computer Graphics Rendering Framework**, focusing on the viewing pipeline and secondary ray generation for realistic image synthesis.

---

## Features

- Perspective and orthographic cameras
- Field-of-view and focal length control
- Shadow ray casting
- Phong illumination model (ambient, diffuse, specular)
- Recursive reflection rays
- Refraction using Snell’s Law
- Depth of Field (aperture sampling)
- Procedural textures using Perlin Noise
- Ray–Sphere and Ray–Plane intersection
- Eigen-based linear algebra

---

## Rendering Pipeline

1. **Primary Ray Generation**  
   Rays are generated from the camera based on projection and field-of-view.

2. **Visibility & Shadows**  
   Shadow rays determine light occlusion.

3. **Lighting & Shading**  
   Phong lighting with diffuse and specular components.

4. **Recursive Effects**  
   - Reflection rays  
   - Refraction rays  
   - Limited bounce depth for performance  

5. **Camera Effects**  
   - Perspective projection  
   - Depth of field via aperture sampling  

6. **Procedural Texturing**  
   - Perlin noise with linear and cubic interpolation  

---

## Build & Run

### Requirements
- C++17 compatible compiler  
- CMake 3.10+  
- Eigen (included in the repository)

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
./assignment3
```

The program will:
- Cast primary and secondary rays  
- Compute shadows, reflections, and refractions  
- Apply depth of field and procedural textures  
- Output the rendered image to the current directory  

---

## Example Outputs

The engine can generate:

- Shadowed scenes with Phong lighting  
- Reflective and refractive objects  
- Depth of field blur  
- Procedural Perlin noise textures  

Sample results are available in the `img/` folder.

---

## Applications

- Physically based rendering research  
- Ray tracing engine development  
- Camera model simulation  
- Optical effects experimentation  
- Foundations for global illumination systems  

---

## Project Structure

- `src/` – Ray generation, shading, recursion, camera models  
- `img/` – Rendered outputs  
- `build/` – CMake build artifacts  
- `data/` – Scene configuration  

---

## Author

Developed as part of a modular **Computer Graphics Rendering System** implementing advanced viewing and light transport effects.
