#pragma once

#include "Blob.h"
#include "use_opencv.h"
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"

const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);
const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);

CvCapture* capture;
VideoCapture capVideo;
IplImage* frame;
Mat imgFrame1;
Mat imgFrame2;
Mat imgFrame1Copy;
Mat imgFrame2Copy;
vector<Blob> blobs;
Point crossingLine[2];
Point crossingLineLeft[2];
bool blnFirstFrame = true;
int frameCount = 2;
int peopleCountLeft, intHorizontalLinePosition, peopleCountRight = 0;

void matchCurrentFrameBlobsToExistingBlobs(std::vector<Blob> &existingBlobs, std::vector<Blob> &currentFrameBlobs);
void addBlobToExistingBlobs(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs, int &intIndex);
void addNewBlob(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs);
double distanceBetweenPoints(cv::Point point1, cv::Point point2);
bool checkIfBlobsCrossedTheLineRight(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &peopleCountRight);
bool checkIfBlobsCrossedTheLineLeft(std::vector<Blob> &blobs, int &intHorizontalLinePositionLeft, int &peopleCountLeft);
void drawBlobInfoOnImage(std::vector<Blob> &blobs, cv::Mat &imgFrame2Copy);

namespace BP_PeopleCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Window_control
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  labelFrameRate;

	private: System::Windows::Forms::Label^  labelPeopleUp;
	private: System::Windows::Forms::Label^  labelTime;




	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  labelFrameNo;

	private: System::Windows::Forms::Label^  labelPeopleDown;

	private: System::ComponentModel::IContainer^  components;
#pragma endregion

	protected:

	private:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->labelFrameRate = (gcnew System::Windows::Forms::Label());
			this->labelPeopleUp = (gcnew System::Windows::Forms::Label());
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelFrameNo = (gcnew System::Windows::Forms::Label());
			this->labelPeopleDown = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->groupBox4);
			this->panel1->Controls->Add(this->groupBox3);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(353, 506);
			this->panel1->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->labelFrameNo);
			this->groupBox4->Controls->Add(this->labelPeopleDown);
			this->groupBox4->Controls->Add(this->labelFrameRate);
			this->groupBox4->Controls->Add(this->labelPeopleUp);
			this->groupBox4->Controls->Add(this->labelTime);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(3, 368);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(345, 133);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Video Properties:";
			// 
			// labelFrameRate
			// 
			this->labelFrameRate->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelFrameRate->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFrameRate->Location = System::Drawing::Point(8, 97);
			this->labelFrameRate->Name = L"labelFrameRate";
			this->labelFrameRate->Size = System::Drawing::Size(333, 25);
			this->labelFrameRate->TabIndex = 6;
			this->labelFrameRate->Text = L"Video Frame Rate:";
			this->labelFrameRate->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelPeopleUp
			// 
			this->labelPeopleUp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelPeopleUp->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPeopleUp->Location = System::Drawing::Point(8, 28);
			this->labelPeopleUp->Name = L"labelPeopleUp";
			this->labelPeopleUp->Size = System::Drawing::Size(165, 25);
			this->labelPeopleUp->TabIndex = 4;
			this->labelPeopleUp->Text = L"People up:";
			this->labelPeopleUp->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelTime
			// 
			this->labelTime->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelTime->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTime->Location = System::Drawing::Point(176, 62);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(165, 25);
			this->labelTime->TabIndex = 3;
			this->labelTime->Text = L"Time:";
			this->labelTime->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Controls->Add(this->comboBox1);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(3, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(344, 62);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Source";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(249, 22);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(79, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Capture From Camera", L"Capture From File" });
			this->comboBox1->Location = System::Drawing::Point(8, 23);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(235, 27);
			this->comboBox1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(3, 65);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(345, 303);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Original Video:";
			// 
			// trackBar1
			// 
			this->trackBar1->AutoSize = false;
			this->trackBar1->Location = System::Drawing::Point(8, 270);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(322, 26);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(10, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(320, 240);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// labelFrameNo
			// 
			this->labelFrameNo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelFrameNo->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFrameNo->Location = System::Drawing::Point(8, 62);
			this->labelFrameNo->Name = L"labelFrameNo";
			this->labelFrameNo->Size = System::Drawing::Size(165, 25);
			this->labelFrameNo->TabIndex = 8;
			this->labelFrameNo->Text = L"Frame:";
			this->labelFrameNo->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelPeopleDown
			// 
			this->labelPeopleDown->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelPeopleDown->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPeopleDown->Location = System::Drawing::Point(176, 28);
			this->labelPeopleDown->Name = L"labelPeopleDown";
			this->labelPeopleDown->Size = System::Drawing::Size(165, 25);
			this->labelPeopleDown->TabIndex = 7;
			this->labelPeopleDown->Text = L"People down:";
			this->labelPeopleDown->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(359, 512);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(3);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BP People Counter";
			this->panel1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text == "")
		{
			MessageBox::Show(this, "Select Capture Method", "Error!!!");
		}
		if (button2->Text == "Start")
		{
			peopleCountLeft = 0;
			peopleCountRight = 0;

			if (comboBox1->Text == "Capture From Camera")
			{
				capture = cvCaptureFromCAM(0);
				trackBar1->Minimum = 0;
				trackBar1->Maximum = 0;
				button2->Text = "Stop";

				frame = cvQueryFrame(capture);
				imgFrame1 = cvarrToMat(frame);
				imgFrame2 = cvarrToMat(frame);

				char chCheckForEscKey = 0;
				bool blnFirstFrame = true;
				int frameCount = 2;

				timer1->Start();
			}
			else if (comboBox1->Text == "Capture From File")
			{
				openFileDialog1->Filter = "AVI files (*.avi)|*.txt|All files (*.*)|*.*";
				openFileDialog1->FilterIndex = 2;
				openFileDialog1->RestoreDirectory = true;
				openFileDialog1->FileName = "";
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					char *fileName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
					capture = cvCaptureFromFile(fileName);
					capVideo.open(fileName);
					trackBar1->Minimum = 0;
					trackBar1->Maximum = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
					button2->Text = "Stop";

					frame = cvQueryFrame(capture);
					imgFrame1 = cvarrToMat(frame);
					imgFrame2 = cvarrToMat(frame);

					char chCheckForEscKey = 0;
					bool blnFirstFrame = true;
					int frameCount = 2;

					timer1->Start();
				}
			}
		}
		else if (button2->Text == "Stop")
		{
			cvReleaseCapture(&capture);
			button2->Text = "Start";
			timer1->Stop();
		}
	}

	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
			frame = cvQueryFrame(capture);

			if (frame != NULL)
			{
				imgFrame2 = cvarrToMat(frame);
				vector<Blob> currentFrameBlobs;
				Mat imgFrame1Copy = imgFrame1.clone();
				Mat imgFrame2Copy = imgFrame2.clone();
				Mat imgDifference;
				Mat imgThresh;

				int intHorizontalLinePosition = imgFrame2.rows * 0.5;

				crossingLine[0].x = 0;
				crossingLine[0].y = intHorizontalLinePosition;

				crossingLine[1].x = imgFrame1.cols - 1;
				crossingLine[1].y = intHorizontalLinePosition;

				crossingLineLeft[0].x = 0;
				crossingLineLeft[0].y = intHorizontalLinePosition;

				crossingLineLeft[1].x = imgFrame1.cols - 1;
				crossingLineLeft[1].y = intHorizontalLinePosition;

				cvtColor(imgFrame1Copy, imgFrame1Copy, CV_BGR2GRAY);
				cvtColor(imgFrame2Copy, imgFrame2Copy, CV_BGR2GRAY);
				GaussianBlur(imgFrame1Copy, imgFrame1Copy, cv::Size(5, 5), 0);
				GaussianBlur(imgFrame2Copy, imgFrame2Copy, cv::Size(5, 5), 0);
				absdiff(imgFrame1Copy, imgFrame2Copy, imgDifference);
				threshold(imgDifference, imgThresh, 30, 255.0, CV_THRESH_BINARY);

				Mat structuringElement5x5 = getStructuringElement(MORPH_RECT, cv::Size(5, 5));

				for (int i = 0; i < 2; i++) {
					dilate(imgThresh, imgThresh, structuringElement5x5);
					dilate(imgThresh, imgThresh, structuringElement5x5);
					erode(imgThresh, imgThresh, structuringElement5x5);
				}

				Mat imgThreshCopy = imgThresh.clone();
				vector<vector<cv::Point>> contours;
				findContours(imgThreshCopy, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

				vector<vector<cv::Point>> convexHulls(contours.size());

				for (unsigned int i = 0; i < contours.size(); i++) {
					convexHull(contours[i], convexHulls[i]);
				}

				for (auto &convexHull : convexHulls) {
					Blob possibleBlob(convexHull);

					//cechy ksztaltu, ktory bedzie interpretowany jako czlowiek (mozna to dac do edycji w forms, zeby moc kalibrowac dla roznych filmow)
					if (possibleBlob.currentBoundingRect.area() >(imgFrame2Copy.cols * imgFrame2Copy.rows) / 100 &&
						possibleBlob.dblCurrentAspectRatio > 0.2 &&
						possibleBlob.dblCurrentAspectRatio < 4.0 &&
						possibleBlob.currentBoundingRect.width > imgFrame2Copy.cols / 10 &&
						possibleBlob.currentBoundingRect.height > imgFrame2Copy.rows / 4 &&
						possibleBlob.currentBoundingRect.width < imgFrame2Copy.cols / 2 &&
						possibleBlob.dblCurrentDiagonalSize > 60.0 &&
						(contourArea(possibleBlob.currentContour) / (double)possibleBlob.currentBoundingRect.area()) > 0.50) {
						currentFrameBlobs.push_back(possibleBlob);
					}
				}

				if (blnFirstFrame == true) {
					for (auto &currentFrameBlob : currentFrameBlobs) {
						blobs.push_back(currentFrameBlob);
					}
				}
				else {
					matchCurrentFrameBlobsToExistingBlobs(blobs, currentFrameBlobs);
				}

				imgFrame2Copy = imgFrame2.clone();
				drawBlobInfoOnImage(blobs, imgFrame2Copy);

				// sprawdŸ ludzi id¹cych z góry
				bool blnAtLeastOneBlobCrossedTheLine = checkIfBlobsCrossedTheLineRight(blobs, intHorizontalLinePosition, peopleCountRight);
				// sprawdŸ ludzi id¹cych z do³u
				bool blnAtLeastOneBlobCrossedTheLineLeft = checkIfBlobsCrossedTheLineLeft(blobs, intHorizontalLinePosition, peopleCountLeft);

				// bia³a linia jeœli wykryto kontakt, ¿ó³ta jeœli nie wykryto kontaktu
				if (blnAtLeastOneBlobCrossedTheLine || blnAtLeastOneBlobCrossedTheLineLeft) {
					line(imgFrame2Copy, crossingLineLeft[0], crossingLineLeft[1], SCALAR_WHITE, 2);
				}
				else line(imgFrame2Copy, crossingLineLeft[0], crossingLineLeft[1], SCALAR_YELLOW, 2);

				//drawPeopleCountOnImage(peopleCountRight, imgFrame2Copy);


				// przygotowanie do kolejnej iteracji
				currentFrameBlobs.clear();
				imgFrame1 = imgFrame2.clone();

				blnFirstFrame = false;
				frameCount++;

				frame = new IplImage(imgFrame2Copy);

				pictureBox1->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
				pictureBox1->Refresh();

				trackBar1->Value = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES);
				labelTime->Text = "Time: " + (TimeSpan::FromMilliseconds(cvGetCaptureProperty(capture, CV_CAP_PROP_POS_MSEC)).ToString())->Substring(0, 8);
				labelFrameNo->Text = "Frame: " + cvGetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES).ToString();
				labelFrameRate->Text = "Video Frame Rate: " + cvGetCaptureProperty(capture, CV_CAP_PROP_FPS).ToString();
				labelPeopleUp->Text = "People up: " + peopleCountRight.ToString();
				labelPeopleDown->Text = "People down: " + peopleCountLeft.ToString();

			}
	}

	void matchCurrentFrameBlobsToExistingBlobs(vector<Blob> &existingBlobs, vector<Blob> &currentFrameBlobs) {
		for (auto &existingBlob : existingBlobs) {
			existingBlob.blnCurrentMatchFoundOrNewBlob = false;
			existingBlob.predictNextPosition();
		}

		for (auto &currentFrameBlob : currentFrameBlobs) {
			int intIndexOfLeastDistance = 0;
			double dblLeastDistance = 10000.0;

			for (unsigned int i = 0; i < existingBlobs.size(); i++) {

				if (existingBlobs[i].blnStillBeingTracked == true) {
					double dblDistance = distanceBetweenPoints(currentFrameBlob.centerPositions.back(), existingBlobs[i].predictedNextPosition);

					if (dblDistance < dblLeastDistance) {
						dblLeastDistance = dblDistance;
						intIndexOfLeastDistance = i;
					}
				}
			}

			if (dblLeastDistance < currentFrameBlob.dblCurrentDiagonalSize * 0.5) {
				addBlobToExistingBlobs(currentFrameBlob, existingBlobs, intIndexOfLeastDistance);
			}
			else {
				addNewBlob(currentFrameBlob, existingBlobs);
			}

		}

		for (auto &existingBlob : existingBlobs) {
			if (existingBlob.blnCurrentMatchFoundOrNewBlob == false) {
				existingBlob.intNumOfConsecutiveFramesWithoutAMatch++;
			}
			if (existingBlob.intNumOfConsecutiveFramesWithoutAMatch >= 5) {
				existingBlob.blnStillBeingTracked = false;
			}
		}
	}


	void addBlobToExistingBlobs(Blob &currentFrameBlob, vector<Blob> &existingBlobs, int &intIndex) {
		existingBlobs[intIndex].currentContour = currentFrameBlob.currentContour;
		existingBlobs[intIndex].currentBoundingRect = currentFrameBlob.currentBoundingRect;
		existingBlobs[intIndex].centerPositions.push_back(currentFrameBlob.centerPositions.back());
		existingBlobs[intIndex].dblCurrentDiagonalSize = currentFrameBlob.dblCurrentDiagonalSize;
		existingBlobs[intIndex].dblCurrentAspectRatio = currentFrameBlob.dblCurrentAspectRatio;
		existingBlobs[intIndex].blnStillBeingTracked = true;
		existingBlobs[intIndex].blnCurrentMatchFoundOrNewBlob = true;
	}


	void addNewBlob(Blob &currentFrameBlob, vector<Blob> &existingBlobs) {
		currentFrameBlob.blnCurrentMatchFoundOrNewBlob = true;
		existingBlobs.push_back(currentFrameBlob);
	}


	double distanceBetweenPoints(cv::Point point1, cv::Point point2) {
		int intX = abs(point1.x - point2.x);
		int intY = abs(point1.y - point2.y);

		return(sqrt(pow(intX, 2) + pow(intY, 2)));
	}


	void drawAndShowContours(cv::Size imageSize, vector<vector<cv::Point>> contours, string strImageName) {
		Mat image(imageSize, CV_8UC3, SCALAR_BLACK);
		drawContours(image, contours, -1, SCALAR_WHITE, -1);
		imshow(strImageName, image);
	}


	void drawAndShowContours(cv::Size imageSize, vector<Blob> blobs, string strImageName) {
		Mat image(imageSize, CV_8UC3, SCALAR_BLACK);
		vector<vector<cv::Point>> contours;

		for (auto &blob : blobs) {
			if (blob.blnStillBeingTracked == true) {
				contours.push_back(blob.currentContour);
			}
		}

		drawContours(image, contours, -1, SCALAR_WHITE, -1);
		imshow(strImageName, image);
	}


	bool checkIfBlobsCrossedTheLineRight(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &peopleCountRight) {
		bool blnAtLeastOneBlobCrossedTheLine = false;

		for (auto blob : blobs) {
			if (blob.blnStillBeingTracked == true && blob.centerPositions.size() >= 2) {
				int prevFrameIndex = (int)blob.centerPositions.size() - 2;
				int currFrameIndex = (int)blob.centerPositions.size() - 1;

				// Left way
				if (blob.centerPositions[prevFrameIndex].y > intHorizontalLinePosition && blob.centerPositions[currFrameIndex].y <= intHorizontalLinePosition) {
					peopleCountRight++;
					blnAtLeastOneBlobCrossedTheLine = true;
				}
			}
		}

		return blnAtLeastOneBlobCrossedTheLine;
	}


	bool checkIfBlobsCrossedTheLineLeft(vector<Blob> &blobs, int &intHorizontalLinePosition, int &peopleCountLeft) {
		bool blnAtLeastOneBlobCrossedTheLineLeft = false;

		for (auto blob : blobs) {
			if (blob.blnStillBeingTracked == true && blob.centerPositions.size() >= 2) {
				int prevFrameIndex = (int)blob.centerPositions.size() - 2;
				int currFrameIndex = (int)blob.centerPositions.size() - 1;

				// Left way
				if (blob.centerPositions[prevFrameIndex].y <= intHorizontalLinePosition && blob.centerPositions[currFrameIndex].y > intHorizontalLinePosition && blob.centerPositions[currFrameIndex].x > 0) {
					peopleCountLeft++;
					blnAtLeastOneBlobCrossedTheLineLeft = true;
				}
			}
		}

		return blnAtLeastOneBlobCrossedTheLineLeft;
	}


	void drawBlobInfoOnImage(vector<Blob> &blobs, Mat &imgFrame2Copy) {
		for (unsigned int i = 0; i < blobs.size(); i++) {
			if (blobs[i].blnStillBeingTracked == true) {
				rectangle(imgFrame2Copy, blobs[i].currentBoundingRect, SCALAR_RED, 2);
			}
		}
	}

	void drawPeopleCountOnImage(int &peopleCountRight, Mat &imgFrame2Copy) {
		double dblFontScale = (imgFrame2Copy.rows * imgFrame2Copy.cols) / 300000.0;
		int intFontThickness = (int)round(dblFontScale * 1.5);

		// Up (at the right side of mat)
		cv::Size textSize = getTextSize(to_string(peopleCountRight), 1, dblFontScale, intFontThickness, 0);
		putText(imgFrame2Copy, "Up people count:" + to_string(peopleCountRight), cv::Point(imgFrame2Copy.cols - imgFrame2Copy.cols / 3, 24), 1, dblFontScale, SCALAR_RED, intFontThickness);

		// Down (at the left side of mat)
		cv::Size textSize1 = getTextSize(to_string(peopleCountLeft), 1, dblFontScale, intFontThickness, 0);
		putText(imgFrame2Copy, "Down people count:" + to_string(peopleCountLeft), cv::Point(10, 24), 1, dblFontScale, SCALAR_YELLOW, intFontThickness);
	}

	};
}
