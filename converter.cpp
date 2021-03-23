
// Author : Ahmet Yusuf Birinci

/*

    This example program shows how to convert video to frames.
    You should give a path and also should give a frame skip variable to reduce frame count if you want.
    Its default set to 1.
*/
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream> 
#include <experimental/filesystem>


using namespace std;
namespace fs = experimental::filesystem;

int main(int argc, char** argv)
{
    try
    {
        if (argc != 3) {
            cout << "Give the path to a folder that containing vid.mp4 file!" << endl;
            cout << "You should give a number to set frame skip interval!";
            return 0;
        
        }
        int counter = 0; // Thats our counter for filenames and stop controller
        string path = "";
        const string data_directory = argv[1];

        const int setSens = stoi(argv[2]); // converting our variable from str to int
        cout << "frame skip interval set to: " << setSens << endl;

        cv::VideoCapture cap(data_directory + "/vid.mp4"); // 0 for webcam. "Wherewer:/your/video/file/" for video(vid.mp4)
        int actualFrameCount = cap.get(cv::CAP_PROP_FRAME_COUNT); // getting total frame count.

        cout << "Total frame count =  " << actualFrameCount << endl;
        
        if (!cap.isOpened())
        {
            cerr << "Unable to connect to camera or open the video file" << endl;
            return 1;
        }
        

        if (!fs::is_directory("frames") || !fs::exists("frames")) { // Check if folder exists
            fs::create_directory("frames"); // create folder
        }

        string s = "";

        while(counter < actualFrameCount)
        {
            counter += 1;

            // Grab a frame
            cv::Mat temp;
            if (!cap.read(temp))
            {
                break;
            }

            // reduce the number of frames if desired 
            if (counter % setSens != 0) {
                continue;
            }
            // converting frame count to string for filename
            s = to_string(counter / setSens);
            path = "frames/frame-" + s + ".jpg";
            //writing img to file.
            cv::imwrite(path, temp);
            
            }
        cout << "created " << s << " number of files." << endl << "done!";
        }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }
    
}


