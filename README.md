## Face-detection-in-PYNQ
This project is aim to face detection and Sobel processing image then display it. The main procedures are as follows. Firstly,we will use ZYNQ 7020 to build the PYNQ framework, and then  a face detection algorithm will be built and with the help of  USB camera to detect face. In addition, we will apply Vivado HLS to build Sobel algorithm, and put AXI streams data flow interface into package so as to generate image convolution IP kernel, then turn to DMA module to generate IP read memory, completing convolution operation (Sobel) by hardware, and finally  we can make the processed picture.  

PS：Face detection algorithm are wrriten by Python call OpenCV library construction.Sobel algorithm are built by HLS.

该项目以实现人脸识别与图像处理（Sobel)为目标。首先使用ZYNQ 7020板卡搭建PYNQ框架，使用ARM核调用USB摄像头实现人脸检测功能，与此同时，我们还将使用Vivado HLS构建Sobel算法，并使用AXI-streams生成相应的图像卷积IP，后采用DMA模块生成IP，以实现对图片数据访问，将摄像头所捕获的图像送入Sobel模块进行快速处理，后显示出来。

PS：人脸检测算法使用OpenCV构建，ARM部分程序代码使用Python编写，PL部分使用HLS编写。

bd图如下图1所示
![bd img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/bd.png?raw=true)

## Hardware
-	ZYNQ 7020 or PYNQ Z2 
-	TF Card 8G C10  
-	USB Camera  
-	Network cable  
-	Power Supply  

## Soft
Vivado HLS 2018.3  
Vivado 2018.3    
Jupyter Notebook

## Instructions
1.Make TF Card Image boot card. [References](https://blog.csdn.net/quhai1340/article/details/102799896)  
2.Set the FPGA to TF card to boot.  
3.Use serial port to connect FPGA.  
4.Set FPGA network to auto start.  
5.Configure FPGA IP address and test network.  
6.Use the 'lsusb' command to view the camera.  
7.Run jupyter notebook.    
8.Upload "Face detection project.ipynb(2)"、"xml file"、"HLS Sobel bit" and compile it.

## Procedure flow  
Using camera to detect face in real time. The program will automatically record the current image when a face is detected. After adjusting the resolution and color channel, the original image will be saved locally. The image with face annotation will be displayed in notebook.Then code load Sobel bit file process the original image and display the processed image.  

ARM核将实时分析摄像头所拍摄的图像，当拍摄的图像出现人脸并被成功识别后，程序将对人脸进行标注显示（下图1），并将未带标注框的原始图像（下图2）进行颜色与尺寸调整后保存到本地。然后调用HLS_Sobel模块对图像进行卷积处理并保存（下图3）。

![Tag img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Tag%20img.png?raw=true)
![Original img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Original%20img.jpg?raw=true)
![Sobel img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Sobel%20img.png?raw=true)
