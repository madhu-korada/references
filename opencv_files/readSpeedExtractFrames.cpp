/*
 * Compile: 
 g++ -std=c++11 readSpeedExtractFrames.cpp `pkg-config --libs opencv` 
 */

#include "opencv2/opencv.hpp"
#include <iostream>

#include <fstream>
#include <string>

using namespace std;
using namespace cv;
 
int main()
{
	string   speed_str;
	ifstream speedFile( "speed.csv" );

	double speed_dbl;
	
	if( speedFile.is_open() )
	{
		// Create a VideoCapture object and open the input file
		// If the input is the web camera, pass 0 instead of the video file name
		VideoCapture objVideoCapture( "drop.avi" ); 
		
		// Check if camera opened successfully
		if( !objVideoCapture.isOpened() )
		{
			cout << "Error opening video stream or file" << endl;
			return -1;
		}
		
		int i =0;
		//int cvFrame_count = 0;
		while(1)
		{
			Mat cvFrame;
			// Capture cvFrame-by-cvFrame
			objVideoCapture >> cvFrame;
			
			// If the cvFrame is empty, break immediately
			if( cvFrame.empty() )
			{
				cout << "\nEnd of video!\n";
				break;
			}
						
			getline( speedFile, speed_str );
			if( speed_str != "" )
			{
				speed_dbl = stod( speed_str );
				cout << speed_dbl << '\n'; // Convert string to double: stod
			}
			else
				cout << "\nEnd of speed reading!";		


			// ------------------Just for imshow-------------------------start
			// Display the resulting cvFrame
			imshow( "Frame", cvFrame );
			// Press  ESC on keyboard to exit
			char c = (char)waitKey(25);
			if( c == 27)
				break;
			
			// Just for imshow------------------------end
		}
			
		// When everything done, release the video capture object
		objVideoCapture.release();
		speedFile.close();
	}
	else
		return -1;
	
	return 0;
}

