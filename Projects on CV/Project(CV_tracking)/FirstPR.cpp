#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv; //��������� ���������� CV ����� ���������� ������� ������, ������: cv::VideoCapture camera() >> VideoCapture camera()
using namespace std;

////////// �������� ���, � ��� ���������� ///////////
/*int main()
{
	string MediaFolder = "C:/Users/serzh/source/repos/Project(CV_tracking)/media/test.png";
	Mat img = imread(MediaFolder);
	Mat img2 = img;
	cv::resize(img, img2, Size(img2.cols * 2, img2.rows * 2), 0, 0, INTER_NEAREST);
	imshow("������", img2);

	waitKey(0);

	return(0);
}*/

/////////////////������ ������ � �������� ��������/////////////////////

int main()
{
	VideoCapture camera(0); //������ ��� ������
	Mat  frame3, frame1, frame2; //3 ��������� ����

	int h = (frame1, cv::CAP_PROP_FRAME_HEIGHT); //��������� ������ � ������ 
	int w = (frame1, cv::CAP_PROP_FRAME_WIDTH); // ��������� ������ � ������

	camera.read(frame1); // �������� ���� ���� �� ���� 1, ����� ����� ��������� ��� 

	cv::VideoWriter output("C:/Users/serzh/source/repos/Project(CV_tracking)/media/VideoSave.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(w, h)); //�������� ������ ����� � ������� �����������


	while (true) //���� ��� ��������� ������
	{
		resize(frame1, frame2, Size(h/3, w/3)); //���������� ���� ����� 1 � ������� � ����������� ���������� � ���� 2
		camera.read(frame2); // ������ ����� �� ���� 2

		Canny(frame2, frame3, 30, 30, 3); //������� ��� ���������� �������� - ������ � ���� 2 � ���������� � ���� 3
		imshow("Camera",frame3); // �������� ����� �� ���� 3 

		output.write(frame3); // ���������� ����� ���� 3 
		if (waitKey(25) >= 0) break; // ���� - ������� �������, ���������� ����
	}

	output.release(); //��������� ������� ������
	camera.release(); //��������� ������� ������������
	destroyAllWindows; //������� ��� ����

}