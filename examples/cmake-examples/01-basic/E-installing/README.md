
## Concepts
---
### Installing
---
CMake offers the ability to add a `make install` target to allow a user to
install binaries, libraries and other files. The base install location is controlled
by the variable +CMAKE_INSTALL_PREFIX+ which can be set using ccmake or by calling
cmake with `cmake .. -DCMAKE_INSTALL_PREFIX=/install/location` 

The files that are installed are controlled by the [install()](https://cmake.org/cmake/help/v3.0/command/install.html) function.

```php
install (TARGETS cmake_examples_inst_bin 
          DESTINATION bin)
```
Install the binary generated from the target cmake_examples_inst_bin target to
the destination `${CMAKE_INSTALL_PREFIX}/bin`
```php
install (TARGETS cmake_examples_inst
    LIBRARY DESTINATION lib)
```

Install the shared library generated from the target cmake_examples_inst target to
the destination `${CMAKE_INSTALL_PREFIX}/lib`

**Note**  
```php
This may not work on windows. On platforms that have DLL targets you may  need to add the following
         ```
install (TARGETS cmake_examples_inst
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)
```

Install the header files for developing against the +cmake_examples_inst+ library
into the `${CMAKE_INSTALL_PREFIX}/include+ directory`.

```php
install (FILES cmake-examples.conf
    DESTINATION etc)
```
Install a configuration file to the destination `${CMAKE_INSTALL_PREFIX}/etc`

After `make install` has been run, CMake generates an install_manifest.txt file
which includes details on all installed files.

**NOTE**
If you run the `make install` command as root, the install_manifest.txt file will
be owned by root.
