#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\tracking.hpp"

int main()
{
	cv::VideoCapture MyVideo(0);
	if (!MyVideo.isOpened()) return -1;

	cv::Mat frame1; 

	double frameWidth = MyVideo.get(cv::CAP_PROP_FRAME_WIDTH); 
	double frameHeight = MyVideo.get(cv::CAP_PROP_FRAME_HEIGHT);

	cv::VideoWriter output("VideoSave.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeight)); 

	cv::Ptr<cv::Tracker> tracker = cv::TrackerKCF::create();
	MyVideo.read(frame1);
	cv::Rect2d trackingBox = cv::selectROI(frame1, false);
	tracker->init(frame1, trackingBox);

	while (MyVideo.read(frame1)) 
	{
		cv::imshow("Захват камеры (1)", frame1); 

		output.write(frame1);

		if (cv::waitKey(40) >= 0)
		{

			break;
		}
	}



	output.release();
	MyVideo.release();
	cv::destroyAllWindows();

	return 0;
}