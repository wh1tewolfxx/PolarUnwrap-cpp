#pragma once

#ifndef REGION_H
#define REGION_H

#include<math.h>

struct Annulus {
    /// <summary>
    /// Center point of Annulus
    /// </summary>
    struct Center {
        double x, y;
        Center() : x(0), y(0) {};
        Center(double x, double y) {
            this->x = x;
            this->y = y;
        }
    };

    /// <summary>
    /// Enumeration defines the flip direction of the image.
    /// </summary>
    enum Flip { 

        /// <summary>
        /// No Flip.
        /// </summary>
        NONE,

        /// <summary>
        /// Flip over the horizontal axis.
        /// </summary>
        HORIZ_AXIS,

        /// <summary>
        /// Flip across the vertical axis.
        /// </summary>
        VERT_AXIS, 

        /// <summary>
        /// Flip over both horizontal and vertical axis.
        /// </summary>
        HORIZ_VERT_AXIS 
    };

private:
    const int calculateArcLength() {
        return round(outer_radius * fabs(end_angle - start_angle));
    }
public:

    /// <summary>
    /// The calculated arc length of the supplied annulus. Formula: outer_radius * (end_angle - start_angle)
    /// </summary>
    /// <returns>Returns calculated Arc Length as an integer.</returns>
    const int getArcLength() {
        return calculateArcLength();
    }
public:



    const double inner_radius, outer_radius;
    const Center center;
    const double start_angle, end_angle;
    const Flip flipDirection;

};

#endif