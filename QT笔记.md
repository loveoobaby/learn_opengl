## 环境问题
1. GL/gl.h: No such file or directory  
   这是由于没有OpenGL头文件，缺少OpenGL库。使用以下命令安装即可：  
   `sudo apt-get install mesa-common-dev`

2. pri子工程   
   如果一个控件具有通用性，可以将其头文件、源文件、资源文件放入单独的目录中，并用pri文件进行描述。如果新工程使用这个控件可以直接include这个pri文件即可。   