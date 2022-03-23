#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

/*
int main() 
{
	cv::VideoCapture MyVideo(0);//функция которая создает обьект для завхвата видео, параметр - выбор устройства для записи, 0 - все возможные камеры, можно ввести название видео файла из папки проекта для его просмотра 

		if (!MyVideo.isOpened()) return -1;// условие для работы видео

		cv::Mat frame1; // функция для создания окна 

		double frameWidth = MyVideo.get(cv::CAP_PROP_FRAME_WIDTH); //переменная = функция для чтения ширины и высоты видео
		double frameHeight = MyVideo.get(cv::CAP_PROP_FRAME_HEIGHT);

		cv::VideoWriter output("VideoSave.avi", cv::VideoWriter::fourcc('M','J','P','G'), 30, cv::Size(frameWidth, frameHeight)); // сохранение видео (название файла, плеер, 30 - фпс, размеры)

		while (MyVideo.read(frame1)) //условие: пока идет захват видео 
		{
			cv::imshow("Захват камеры (1)", frame1); //показывать "введеный текст в окне", окно

			output.write(frame1);

			if (cv::waitKey(40) >= 0) //функция для остановки видео по клавише
			{
				break;
			}
		}
		
		

		output.release();
		MyVideo.release();
		cv::destroyAllWindows();

		return 0;
}*/