#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <math.h>
#include <chrono>
#include <NumCpp.hpp>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>




#include "Region.h"
#include "PolarUnwrap.h"


using namespace std;
using namespace cv;
using namespace nc;




int main()
{
    //Init PolarUnwrap object
    PolarUnwrap polarUnwrap;


    //Create annulus region [Donut]
    Annulus annulus =
    {

        120,    //inner radius
        225,    //outer radius
        Annulus::Center(658,531),    //Center
        0,      //start angle
        2 * M_PI,  //end angle
        Annulus::Flip::HORIZ_AXIS
    };

    //Load bearing.bmp using opencv.
	std::string image_path = samples::findFile("bearing.bmp");
	Mat img = imread(image_path, 0);
	if (img.empty())
	{
		std::cout << "Could not read the image: " << image_path << std::endl;
		return 1;
	}

    //Start Timer.
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    //Call PolarUnwrap function which performs geometric transformation and returns a pair x,y ndarrays.
	std::pair< nc::NdArray< int >, nc::NdArray< int > > p = polarUnwrap.Unwrap(annulus);

    //End Timer.
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //Display Timer.
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    //Define opencv mat object.
    Mat polar(p.first.shape().rows, p.first.shape().cols, CV_8U);

    //Iterate over each pixel and assign the pixel calculated from unwrap to the polar image.
    if (img.type() == CV_8U) {

        for (int row = 0; row < p.first.shape().rows; ++row)
        {
            for (int col = 0; col < p.first.shape().cols; ++col)
            {
                polar.at<uchar>(row, col) = img.at<uchar>(p.second(row, col), p.first(row, col));
            }
        }
       
    }

	cv::imshow("Display window", polar);

	waitKey(0);
}
