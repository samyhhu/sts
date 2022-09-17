from conan import ConanFile


class Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualRunEnv"

    def layout(self):
        self.folders.generators = "conan"

    def requirements(self):
        self.requires("fmt/8.1.1")
        self.requires("simdjson/2.2.2")

        # Testing only dependencies below
        self.requires("gtest/1.12.1")
