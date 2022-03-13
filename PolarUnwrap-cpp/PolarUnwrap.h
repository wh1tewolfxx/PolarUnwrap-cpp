#pragma once

#ifndef POLARUNWRAP_H
#define POLARUNWRAP_H

#include "Region.h"
#include <NumCpp.hpp>

using namespace nc;
using namespace std;

struct PolarUnwrap {

private:

	std::pair< nc::NdArray< int >, nc::NdArray< int > > convert(nc::NdArray< double >& radius, nc::NdArray< double >& theta, Annulus& annulus);
public:
	std::pair< nc::NdArray< int >, nc::NdArray< int > > Unwrap(Annulus& annulus);

};

#endif // POLARUNWRAP_H

