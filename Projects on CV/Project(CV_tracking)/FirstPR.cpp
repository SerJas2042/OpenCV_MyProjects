#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv; //включение библиотеки CV чтобы пропустить длинную запись, пример: cv::VideoCapture camera() >> VideoCapture camera()
using namespace std;

////////// Открытие пнг, и его увеличение ///////////
/*int main()
{
	string MediaFolder = "C:/Users/serzh/source/repos/Project(CV_tracking)/media/1.png";
	Mat img = imread(MediaFolder);
	Mat img1 = img;
	cv::resize(img, img1, Size(1920, 1080));
	imshow("Фигуры", img2);

	waitKey(0);

	return(0);
}*/

/////////////////захват камеры с эффектом контуров/////////////////////

int main()
{
	VideoCapture camera(0); //захват вэб камеры
	Mat  frame3, frame1, frame2; //3 заготовки окон

	int h = (frame1, cv::CAP_PROP_FRAME_HEIGHT); //получение данных о высоте 
	int w = (frame1, cv::CAP_PROP_FRAME_WIDTH); // получение данных о ширине

	camera.read(frame1); // получить один кадр из окна 1, чтобы потом увеличить его 

	cv::VideoWriter output("C:/Users/serzh/source/repos/Project(CV_tracking)/media/VideoSave.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(w, h)); //создание записи видео с помощью видеокодера


	while (true) //цикл для прогрузки кадров
	{
		resize(frame1, frame2, Size(h/3, w/3)); //увеличение окна номер 1 и перенос с сохранением параметров в окно 2
		camera.read(frame2); // читать кадры из окна 2

		Canny(frame2, frame3, 30, 30, 3); //функция для нахождения контуров - искать в окне 2 и передавать в окно 3
		imshow("Camera",frame3); // показать кадры из окна 3 

		output.write(frame3); // записывать кадры окна 3 
		if (waitKey(25) >= 0) break; // если - нажатие клавиши, остановить цикл
	}

	output.release(); //завершить процесс записи
	camera.release(); //завершить процесс видеозахвата
	destroyAllWindows; //закрыть все окна

}
