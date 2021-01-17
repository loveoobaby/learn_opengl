#version 330 core
in vec4 vertexColor;
out vec4 FragColor;  // out指定片段着色器的输出
void main()
{
   FragColor = vertexColor;
}