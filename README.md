# Bit-map-Fortuna
This is a library to load a 16 bit bitmap image onto the "La Fortuna" AT90USB1286 microcontroller supplied by the University Of Southampton

It also has functionallity to load onto other types of microcontorller by overriding the output function.

## Usage

To use this libary, simply create a new Bitmap object and it will automatically call the output function to display it on the screen.

```C++
bitFortuna::Bitmap example("[filename].BMP");
```

You can also view a debug menu that displays data about the image that you have loaded.

```C++
example.display_debug();
```

The data it shows is:
-Width
-Height
-Planes
-Bits Per Pixel:
    1 = monochrome palette. NumColors = 1             (NOT SUPPORTED)
    4 = 4bit palletized. NumColors = 16               (NOT SUPPORTED) 
    8 = 8bit palletized. NumColors = 256              (NOT SUPPORTED)
    16 = 16bit RGB. NumColors = 65536                 (SUPPORTED)
    24 = 24bit RGB. NumColors = 16M                   (HALF SUPPORTED)
-Compression:
    0 = BI_RGB   no compression  
    1 = BI_RLE8 8bit RLE encoding  
    2 = BI_RLE4 4bit RLE encoding
-XpixelsPerM
-YpixelsPerM
-Colors Used
-Important Colors
