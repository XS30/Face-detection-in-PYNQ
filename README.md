## Face-detection-in-PYNQ
This project will use ZYNQ 7020 to build the PYNQ framework, and build face detection algorithm, and finally use USB camera to detect face.In addition,Use Vivado HLS to build Sobel algorithm, then call AXI streams data flow interface to package and generate image convolution IP kernel, then use DMA module to generate IP read memory, complete convolution operation (Sobel) by hardware, and then display the processed picture.  

PS：Face detection algorithm using Python call OpenCV library construction.

![bd img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/bd.png?raw=true)

## Hardware
-	ZYNQ 7020 or PYNQ Z2 
-	TF Card 8G C10  
-	USB Camera  
-	Network cable  
-	Power Supply  

## Soft
Vivado HLS 2018.3
Jupyter Notebook

## Instructions
1.Make TF Card Image boot card. [References](https://blog.csdn.net/quhai1340/article/details/102799896)  
2.Set the FPGA to TF card to boot.  
3.Use serial port to connect FPGA.  
4.Set FPGA network to auto start.  
5.Configure FPGA IP address and test network.  
6.Use the 'lsusb' command to view the camera.  
7.Run jupyter notebook.    
8.Upload "Face detection project.ipynb" "Xml data" and compile it.

## Procedure flow  
Using camera to detect face in real time. The program will automatically record the current image when a face is detected. After adjusting the resolution and color channel, the original image will be saved locally. The image with face annotation will be displayed in notebook.Then code load Sobel bit file process the original image and display the processed image.  

![Tag img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Tag%20img.png?raw=true)
![Original img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Original%20img.jpg?raw=true)
![Sobel img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Sobel%20img.png?raw=true)
