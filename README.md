## Face-detection-in-PYNQ
This project will use ZYNQ 7020 to build the PYNQ framework, and build face detection algorithm, and finally use USB camera to detect face.

PS：Face detection algorithm using Python call OpenCV library construction.

## Device
-	ZYNQ 7020  
-	TF Card 8G C10  
-	USB Camera  
-	Network cable  
-	Power Supply  


## Preparation work
1.Make TF Card Image boot card. [References](https://blog.csdn.net/quhai1340/article/details/102799896)  
2.Set the FPGA to TF card to boot.  
3.Use serial port to connect FPGA.  
4.Set FPGA network to auto start.  
5.Configure FPGA IP address and test network.  
6.Use the 'lsusb' command to view the camera.  
7.Run jupyter notebook.    
8.Upload "Face detection project.ipynb" "Xml data" and compile it.


## Result
![python](https://github.com/XS30/Face-detection-in-PYNQ/blob/main/Output%20image/img1.png?raw=true)
