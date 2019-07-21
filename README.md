# CMakeLists skeleton

### Directory tree:

```
.
├── benchmarks
│   └── squareRoot.bench.cpp
├── build
├── CMakeLists.txt
├── src
│   └── squareRoot.hpp
├── tests
│   └── squareRoot.t.cpp
├── .gitmodules
└── vendor
```

### Build

```
cd build;
cmake ../ -DWITH_GTEST=ON ;
make -j8;
make test
```