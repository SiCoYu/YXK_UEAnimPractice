# YXK_UEAnimPractice
## Features
* Generic vertex arrays for arbitrary data in the vertex processing stage.
* Internal vertex cache for better vertex processing.
* Affine and perspective correct per vertex parameter interpolation.
* Vertex and pixel shaders written in C++ using some C++ template magic.

## Resources
* [Triangle Rasterization](http://www.cs.unc.edu/~blloyd/comp770/Lecture08.pdf)
* [Accelerated Half-Space Triangle Rasterization](https://www.researchgate.net/publication/286441992_Accelerated_Half-Space_Triangle_Rasterization)
* [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
* [SDL2](http://libsdl.org/)
## License

This code is licensed under the MIT License (see [LICENSE](LICENSE)).

## CMake-GUI
if you want to generate VS solution on windows, please as follow.
* Open CMake-GUI
* Select Source Code. e.g:D:/SoftwareRenderer
* Select Build Directory. e.g:D:/SoftwareRenderer/build. It's only need to new a directory under Project.
* Configure. if error, Please Config the library and include path.
e.g
D:/SoftwareRenderer/SDL2/lib/x86/SDL2main.lib
D:/SoftwareRenderer/SDL2/lib/x86/SDL2.lib
D:/SoftwareRenderer/SDL2/lib/x86
D:/SoftwareRenderer/SDL2/include
* Reperate step 4. Configure Done.
* Generate. Generate Done.
* Open .sln, In build/xxx.sln
* Default Start Project is BUILD_ALL, then Build the solution.
* Set Start Project. e.g:RasterizerTest
* Build, Run/Debug. Success!!!
if load image or object failed, please modify the path first.