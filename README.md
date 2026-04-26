# CxImage

CxImage is a C++ class that can load, save, display, and transform images in a very simple and fast way. It supports a wide range of image formats and provides numerous image processing features.

Originally developed by Davide Pizzolato, CxImage has been a staple for C++ graphics programming for many years. This repository includes the core library and its bundled dependencies, along with fixes for modern compilers and cross-platform compatibility.

## Features

- **Wide Format Support**: Load and save BMP, GIF, JPG, PNG, MNG, TIFF, ICO, TGA, PCX, WBMP, WMF, J2K, JPC, PGX, PNM, RAS, RAW, and PSD.
- **Image Processing**: Geometric transformations (rotate, resize, mirror), digital signal processing (filters, histograms, color balance), and interpolation.
- **Advanced Capabilities**: Alpha channel support, selections, and multi-layer images.
- **Cross-Platform**: Traditional Windows support along with CMake-based build support for Linux and other platforms.

## Project Structure

- `CxImage/`: Core library source code and headers.
- `zlib/`, `png/`, `jpeg/`, `tiff/`, `jasper/`, `jbig/`, `mng/`, `raw/`, `libpsd/`: Bundled third-party libraries.
- `doc/`: Documentation, history, and logo.
- `demo/`, `demo2/`, etc.: Demo applications showing how to use the library.

## Getting Started

### Building with CMake (Cross-Platform)

CxImage uses CMake for a unified build process across different platforms.

1. **Create a build directory**:
   ```bash
   mkdir build
   cd build
   ```

2. **Configure the project**:
   ```bash
   cmake ..
   ```

3. **Build the library**:
   ```bash
   # On Linux/macOS
   make

   # Or using CMake's build command
   cmake --build .
   ```

### Building on Windows (Visual Studio)

In addition to CMake, you can use the provided solution files:

- Open `CxImageFull.sln` (for older VS) or `CxImageFull_vc10.sln` in Visual Studio.
- Select your desired configuration (e.g., Release) and build the solution.

## Licensing

CxImage is provided under a custom license that is similar to the zlib license, allowing for free use in both commercial and non-commercial applications. See `CxImage/license.txt` for the full legal text.

Third-party libraries included in this repository are subject to their own respective licenses (e.g., libpng license, libjpeg license, etc.).

## More Information

For detailed documentation, refer to the HTML files in the `doc/` directory or visit the [CxImage home page](http://www.xdp.it).
