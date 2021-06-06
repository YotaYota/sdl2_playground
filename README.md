## Build

```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

`build/compile_commands.json` for _ccls_ is created by CMake.

## TODO
- implement RenderComponent
- Game is just a placeholder for Window and Renderer -> use EntityManager in
main loop instead

