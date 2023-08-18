# sceneView

Simple application for viewing 3d meshes lit with the phong shading model(https://en.wikipedia.org/wiki/Phong_shading).

Uses my custom math library: gMath(https://github.com/eqdiag/gMath).

All dependencies are self-contained in this project using git's submodule system.

## Installation


```
git clone https://github.com/eqdiag/sceneView
mkdir -p out/build
cd out/build
cmake ../..
make
```

## Keyboard Controls

  * `1` Load "assets/models/cube.obj" mesh
  * `2` Load "assets/models/teapot.obj" mesh
  * `3` Load "assets/models/bunny.obj" mesh
  * `4` Load "assets/models/suzanne.obj" mesh
  * `4` Load "assets/models/suzanne.obj" mesh
  * `m` Toggle between shading based on mesh normals OR phong shading model
  * `ESC` Exit program


## Mouse Controls
  * `mouseScroll` Controls camera zoom
  * `mouseMove` Controls camera rotation around mesh


                       
## Copyright and Attribution
Copyright (c) 2023 eqdiag. Released under the [MIT License](https://github.com/eqdiag/sceneView/blob/main/LICENSE).
