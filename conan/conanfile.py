from conans import ConanFile, CMake

class TestProject(ConanFile):
    name = "Test"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake", "cmake_find_package"

    def requirements(self):
        self.requires("catch2/3.3.2")

    def build(self):
        cmake = CMake(self)
        cmake.build()