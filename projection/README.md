# BVH Ray Tracer (Triangle Mesh Rendering)

This module implements a CPU-based ray tracer for triangle meshes and accelerates ray–geometry intersection using a **Bounding Volume Hierarchy (BVH)** built from **Axis-Aligned Bounding Boxes (AABBs)**.

It is part of the **Computer Graphics Rendering Framework**, focused on fast spatial queries and realistic image synthesis for complex 3D models.

---

## Key Features

- Ray–Triangle intersection (barycentric / Möller–Trumbore style)
- Triangle mesh ray tracing (OBJ-based scenes)
- AABB computation for primitives and BVH nodes
- Top-down BVH construction (binary tree)
- Fast BVH traversal for nearest-hit intersection
- Designed for large meshes (e.g., Bunny, Dragon)
- Eigen-based vector and matrix math

---

## How It Works

### 1) Ray–Triangle Intersection
Each ray is tested against triangles using barycentric coordinates to compute hit distance, intersection point, and surface normal.

### 2) BVH Construction
A binary BVH is built in a top-down manner:

1. Compute triangle centroids  
2. Choose the longest axis of the current bounds  
3. Sort primitives along that axis  
4. Split into two subsets  
5. Recursively build child nodes and store merged AABBs  

This reduces intersection time from **O(N)** per ray to roughly **O(log N)** on average.

### 3) BVH Traversal
During rendering, rays traverse the BVH:
- If the ray misses a node’s AABB, that subtree is skipped  
- If it hits, traversal continues until leaf triangles are tested  

---

## Build & Run

### Requirements
- C++17 compatible compiler  
- CMake 3.10+  
- Eigen (included in the repository)

### Compile

From the `projection` directory:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Run

```bash
./bvh_raytracer
```

The application will:
- Load a triangle mesh scene (from `data/`)  
- Build a BVH acceleration structure  
- Render the scene using ray tracing  
- Save the output image to the module’s output folder (commonly `img/` or the build directory)

> Tip: Use **Release** mode for best performance—BVH speedups are most noticeable on large meshes.

---

## Project Structure

- `src/` – Ray tracing, BVH build/traversal, intersection routines  
- `data/` – Input meshes / scenes  
- `img/` – Rendered output images  
- `build/` – Build artifacts  

---

## Applications

- Offline rendering engines  
- BVH/spatial data structure benchmarking  
- Collision detection and visibility queries  
- Graphics research and prototyping  

---

## Author

Developed as part of the modular **Comp
