## Face-detection-in-PYNQ
This project will use ZYNQ 7020 to build the PYNQ framework, and build face detection algorithm, and finally use USB camera to detect face.In addition,Using Vivado to generate GPIO bit file.Turn on LED when the face is detected.

PS：Face detection algorithm using Python call OpenCV library construction.

## Hardware
-	ZYNQ 7020 or PYNQ Z2 
-	TF Card 8G C10  
-	USB Camera  
-	Network cable  
-	Power Supply  
-	LED（3.3v）


## Instructions
1.Make TF Card Image boot card. [References](https://blog.csdn.net/quhai1340/article/details/102799896)  
2.Set the FPGA to TF card to boot.  
3.Use serial port to connect FPGA.  
4.Set FPGA network to auto start.  
5.Configure FPGA IP address and test network.  
6.Use the 'lsusb' command to view the camera.  
7.Run jupyter notebook.    
8.Upload "Face detection project.ipynb" "Xml data" and compile it.


## Result
If the face is captured by the camera, the program will recognize the key points of eyes and mark them with rectangular box, and then recognize the face. When a face is detected, the LED turns on.



![Tag img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Tag%20img.png?raw=true)
![Original img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Original%20img.jpg?raw=true)
![Sobel img](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/image/Sobel%20img.png?raw=true)
