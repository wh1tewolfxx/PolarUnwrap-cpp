# PolarUnwrap-cpp

Linear polar unwrap implemented with **NumCPP** for Machine/Computer vision. A linear polar unwrap is a 2D geometric transformation that remaps an image from polar coordinate space to cartesian space. 

OpenCV Reference: [warpPolar()](https://docs.opencv.org/3.4/da/d54/group__imgproc__transform.html#ga49481ab24fdaa0ffa4d3e63d14c0d5e4)

This implementation of the polar unwrap use annulus region (Ring/Donut shape region). 

* Center of annulus region - x,y coordinate
* inner_radius - The distance in pixels from the center to the inner part of the annulus.
* outer_radius - The distance in pixels from the center to the outer part of the annulus.
* start_angle - The starting angle of the unwrap defined in radians.
* end_angle - The ending angle of the unrap defined in radians.



In this way, the transformation only selects the necessary pixel region (an annulus vs a circle) for the function, allowing for faster execution.

# Example Image Transformation

Here is an example input image of a 806-2RS ball bearing. 

![Input Image](bearing.bmp)

The example output image of the unwrapped 806-2RS ball bearing.

![Output Image](unwrap.png)

# Performance
* Tested on Intel Core i7-9750H 2.6GHz - 16GB
![Performance](Algorithm%20Chrono%20Measurement%20-%20Intel%20Core%20i7-9750H%202.6GHz%20-%2016GB.png)