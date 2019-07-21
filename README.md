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

#### Install libraries

```
git submodule init
git submodule update
```

#### Build project

```
cd build;
cmake ../ -DWITH_GTEST=ON ;
make -j8;
make test
```
