# Core Geometry Engine – Point-in-Polygon & Spatial Processing

This module is part of the **Computer Graphics Rendering System** and focuses on fundamental 2D geometric operations used in rendering pipelines, spatial analysis, and visualization systems.

The project implements a complete workflow for reading geometric data, processing polygon boundaries, and performing efficient point-in-polygon queries using computational geometry techniques.

---

## Project Overview

This component provides:

* Loading and saving 2D point clouds from `.xyz` files
* Parsing polygon geometry from Wavefront `.obj` format
* Bounding box computation for spatial acceleration
* Robust segment–segment intersection testing
* Point-in-Polygon classification using the Even–Odd Rule
* Visualization-ready outputs for validation and analysis

These algorithms are commonly used in:

* Computer graphics pipelines
* GIS and spatial analytics
* Collision detection
* Mesh processing
* Rendering and visibility testing

---

## Input Formats

### Point Cloud (.xyz)

```
N
x y z
x y z
...
```

Only the x and y coordinates are used for 2D computation.

### Polygon (.obj)

```
v x y z
v x y z
...

l i j
l j k
...
```

Vertices define polygon points, and line segments define polygon edges.

---

## Build & Run

```bash
mkdir build
cd build
cmake ..
make
./assignment1
```

---

## Core Algorithms

### 1. Bounding Box Generation

Computes a tight axis-aligned bounding box to identify an external reference point.

### 2. Segment Intersection

Detects intersections between query rays and polygon edges with numerical stability.

### 3. Point-In-Polygon Test

Implements the Even–Odd Rule by casting a ray from the query point and counting edge intersections.

---

## Visualization

The system highlights:

* Input point cloud (green)
* Polygon boundary (red)
* Points inside polygon (yellow)

This enables fast verification of spatial classification accuracy.

---

## Applications

* Rendering pipelines
* Hit-testing in 2D engines
* Geospatial containment queries
* Simulation boundary checks
* Computational geometry research

---

## Author

Developed as part of a larger **Computer Graphics Rendering Framework** focusing on geometric foundations for real-time and offline visualization systems.

