#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

/*
int main() 
{
	cv::VideoCapture MyVideo(0);//������� ������� ������� ������ ��� �������� �����, �������� - ����� ���������� ��� ������, 0 - ��� ��������� ������, ����� ������ �������� ����� ����� �� ����� ������� ��� ��� ��������� 

		if (!MyVideo.isOpened()) return -1;// ������� ��� ������ �����

		cv::Mat frame1; // ������� ��� �������� ���� 

		double frameWidth = MyVideo.get(cv::CAP_PROP_FRAME_WIDTH); //���������� = ������� ��� ������ ������ � ������ �����
		double frameHeight = MyVideo.get(cv::CAP_PROP_FRAME_HEIGHT);

		cv::VideoWriter output("VideoSave.avi", cv::VideoWriter::fourcc('M','J','P','G'), 30, cv::Size(frameWidth, frameHeight)); // ���������� ����� (�������� �����, �����, 30 - ���, �������)

		while (MyVideo.read(frame1)) //�������: ���� ���� ������ ����� 
		{
			cv::imshow("������ ������ (1)", frame1); //���������� "�������� ����� � ����", ����

			output.write(frame1);

			if (cv::waitKey(40) >= 0) //������� ��� ��������� ����� �� �������
			{
				break;
			}
		}
		
		

		output.release();
		MyVideo.release();
		cv::destroyAllWindows();

		return 0;
}*/