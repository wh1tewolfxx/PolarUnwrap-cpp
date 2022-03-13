#include "PolarUnwrap.h"


std::pair< nc::NdArray< int >, nc::NdArray< int > > PolarUnwrap::convert(nc::NdArray< double >& radius, nc::NdArray< double >& theta, Annulus& annulus) {
    
    nc::NdArray< double > x = radius * nc::cos(theta) + annulus.center.x;
    
    nc::NdArray< double > y = radius * nc::sin(theta) + annulus.center.y;
    
    return std::make_pair(x.astype<int>(), y.astype<int>());
}


std::pair< nc::NdArray< int >, nc::NdArray< int > > PolarUnwrap::Unwrap(Annulus& annulus) {
    
    std::pair< nc::NdArray< double >, nc::NdArray< double > > m;
    
    switch (annulus.flipDirection)
    {
    case Annulus::Flip::NONE:
        m = nc::meshgrid(linspace(annulus.start_angle, annulus.end_angle, annulus.getArcLength()), arange(annulus.inner_radius, annulus.outer_radius, 1.0));
        break;

    case Annulus::Flip::HORIZ_AXIS:
        m = meshgrid(linspace(annulus.start_angle, annulus.end_angle, annulus.getArcLength()), arange(annulus.outer_radius, annulus.inner_radius, -1.0));
        break;

    case Annulus::Flip::VERT_AXIS:
        m = meshgrid(linspace(annulus.end_angle, annulus.start_angle, annulus.getArcLength()), arange(annulus.inner_radius, annulus.outer_radius, 1.0));
        break;

    case Annulus::Flip::HORIZ_VERT_AXIS:
        m = meshgrid(linspace(annulus.end_angle, annulus.start_angle, annulus.getArcLength()), arange(annulus.outer_radius, annulus.inner_radius, -1.0));
        break;
    }
      
    auto converted = convert(m.second, m.first, annulus);

    return converted;
}