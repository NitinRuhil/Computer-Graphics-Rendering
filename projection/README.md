# Ray Tracing & BVH Acceleration Module

This module implements a physically-based ray tracing pipeline for triangle meshes, including a high-performance acceleration structure based on Axis-Aligned Bounding Box (AABB) Trees (Bounding Volume Hierarchies).

It is part of the **Computer Graphics Rendering Framework**, focusing on realistic image synthesis, spatial data structures, and efficient ray–geometry intersection.

---

## Features

* Ray–Triangle intersection (Möller–Trumbore algorithm)
* Triangle mesh ray tracing
* Axis-Aligned Bounding Box (AABB) computation
* Top-Down BVH (Bounding Volume Hierarchy) construction
* Fast ray traversal using hierarchical spatial partitioning
* Support for large 3D meshes (Bunny, Dragon, etc.)
* Eigen-based vector and matrix math

---

## Architecture

### Ray–Triangle Intersection

Each ray is tested against mesh triangles using barycentric coordinates to compute hit distance, surface normal, and visibility.

### Bounding Volume Hierarchy (BVH)

A binary AABB Tree is built using a top-down strategy:

1. Compute triangle centroids
2. Find the longest axis of the bounding box
3. Sort primitives along this axis
4. Recursively split into two balanced subsets
5. Store merged bounding boxes in internal nodes

This reduces intersection complexity from **O(N)** to approximately **O(log N)** per ray.

---

## Build & Run

### Requirements

* C++17
* CMake
* Eigen (included in the project)

### Compile

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Run

```bash
./assignment4
```

The program will render the scene and generate an output image in the build directory.

Release mode is strongly recommended, as BVH acceleration provides speedups of 200× or more compared to brute-force ray tracing.

---

## Rendering Output

Example scenes included:

* Stanford Bunny
* Stanford Dragon

BVH acceleration allows complex models to be rendered efficiently with correct shading and visibility.

---

## Applications

* Offline rendering engines
* Real-time ray tracing research
* Collision detection
* Visibility and occlusion queries
* Simulation and physics engines
* Spatial data structure benchmarking

---

## Author

Developed as part of a modular **Computer Graphics Rendering System** focusing on geometric computation, acceleration structures, and physically-based rendering.
