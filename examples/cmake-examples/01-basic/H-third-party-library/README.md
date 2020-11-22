


## Concepts
---
### Finding a Package
---
As mentioned above the `find_package()` function will search for CMake modules in the formant "FindXXX.cmake" from the list of folders in `CMAKE_MODULE_PATH`, The exact format of the arguments to `find_package` will depend on the module you are looking for. This is typically documented at the top of the `FindXXX.cmake` file.

*Some Exmaples*

1. **Boost**
> find_package(Boost REQUIRED COMPONETS filesystem system)

The arguments are:
- `Boost` : Name of the Library. This is part of used to find the module file `FindBoost.cmake`
- `#{version}`: the minimum version of boost to find
- `REQUIRED`: Tells the module that this is required and to fail it it cannot be found
- `COMPONENTS`: The list of libraries to find

2. **OpenCV**
> find_package(OpenCV 3 REQUIRED)



### Checking if the package is found
Most included packages will set a variable `XXX_FOUND`,which can be used to chech if the package is available on the system .

1. **Boost**
```php
if(Boost_FOUND)
    message("boost found!")
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Cannot find boost")
endif()
```
- `Boost_INCLUDE_DIRS` The path to the boost header files

2. **OpenCV**

```php
if(OpenCV_FOUND)
    message("opencv found!")
    include_directories(${OpenCV_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Cannot find opencv")
endif()
```

### Alias/Imported targets
Most modern CMake libraries export ALIAS targets in their module files. The benefit of imported targets are that they can also populate include directories and linked libraries.

> target_link_libraries(third_party_include PRIVATE Boost::filesystem)

### Non-alias targets
While most modern libraries use imported targets, not all modules have been updated. In the case where a library hasn`t been updated you will often find the following variables abailable:
- `xxx_INCLUDE_DIRS` A variable pointing to the include directory for the library
- `xxx_LIBRARY`: A variable pointing to the library path.

```php
# Include the boost headers
target_include_directories( third_party_include
    PRIVATE ${Boost_INCLUDE_DIRS}
)

# link against the boost libraries
target_link_libraries( third_party_include
    PRIVATE
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
)
```
