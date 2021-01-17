着色器
=============
>: 着色器是运行在GPU上的小程序。他们之间相互独立，不能互相沟通，唯一的沟通只有通过输入与输出

## GLSL
着色器使用叫做GLSL的类C语言写成。开头声明版本、输入输出、uniform变量和main函数。典型的结构如下：
```
#version version_number
in type in_variable_name;
in type in_variable_name;

out type out_variable_name;

uniform type uniform_name;

int main()
{
  // 处理输入并进行一些图形操作
  ...
  // 输出处理过的结果到输出变量
  out_variable_name = weird_stuff_we_processed;
}
```

## 数据类型

|  类型   | 含义  |
|  ----  | ----  |
| vecn  | 包含n个float分量的默认向量 |
| bvecn  | 包含n个bool分量的向量 |
| ivecn  | 包含n个int分量的向量 |
| uvecn  | 包含n个unsigned int分量的向量 |
| dvecn  | 包含n个double分量的向量 |

## uniform
uniform是全局变量，意味着uniform变量必须在每个着色器程序对象中都是独一无二的，而且它可以被着色器程序的任意着色器在任意阶段访问。无论你把uniform值设置成什么，uniform会一直保存它们的数据，直到它们被重置或更新。

## 更多属性
顶点的坐标与颜色可以放在同一数组中。
```cpp
float vertices[] = {
    // 位置              // 颜色
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
};
```
这时传给顶点着色器的数据会变多，需要用layout标识新的的属性
```GLSL
#version 330 core
layout (location = 0) in vec3 aPos;   // 位置变量的属性位置值为 0 
layout (location = 1) in vec3 aColor; // 颜色变量的属性位置值为 1

out vec3 ourColor; // 向片段着色器输出一个颜色

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor; // 将ourColor设置为我们从顶点数据那里得到的输入颜色
}
```
更新后的VBO内存中的数据看起来像这样：
![avatar](./image/vertex_attribute_pointer_interleaved.png)





