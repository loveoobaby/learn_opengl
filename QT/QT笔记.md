## 环境问题
1. GL/gl.h: No such file or directory  
   这是由于没有OpenGL头文件，缺少OpenGL库。使用以下命令安装即可：  
   `sudo apt-get install mesa-common-dev`

2. pri子工程   
   如果一个控件具有通用性，可以将其头文件、源文件、资源文件放入单独的目录中，并用pri文件进行描述。如果新工程使用这个控件可以直接include这个pri文件即可。

## QT使用
1. 绑定控件间到伙伴关系  
   伙伴关系是指界面上有一个Label标签与一个组件相关联，在窗体上使用快捷键时焦点快速切换到伙伴组件上。绑定伙伴关系后&将不再显示。
   ```cpp
      ui->label->setText("&Age"); //& Qlabel设置快捷键 Alt+A 
      ui->label->setBuddy(ui->lineEdit);  //设置和QLable伙伴关系
      ui->label_2->setText("&Open");  //快捷键 Alt+O
      ui->label_2->setBuddy(ui->lineEdit_2);
   ```   