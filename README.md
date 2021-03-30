# Video2FrameConverter


 - This example program shows how to convert and save video as frames.
 - Its made using openCV. Thanks for all openCV contributors.

 You can easly compile this program using cmake. Just follow these:
 
 ```
 mkdir build
 cd build
 cmake ..
 cmake --build . --config Release
 
 ```
 
  - I added the exe file that created with exact same code under Release folder.

  - You should name your video file as vid.mp4.

  - Call the program like this: 

```
Video2FrameConverter.exe wherever:/your/video/file/ 1
```
  - The number stands for frame skip interval. 
  - If you want to reduce image count you should give a number like 10 or 100.
