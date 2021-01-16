#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const char *vertexShaderSource = "#version 330 core\n" // 指定opengl的版本，并使用核心模式
    "layout (location = 0) in vec3 aPos;\n" // in声明输入的顶点属性，是3坐标矢量，变量名为aPos
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" // gl_Position是预定义的输出变量，实际是vec4类型，由于输入是3分量，要转换成4分量
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"   // out指定片段着色器的输出
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "learnopengl", nullptr, nullptr);
    if (window == nullptr){
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /**
     * glBufferData是专门用于将用户定义的数据复制到当前绑定的缓冲中；
     * 参数解释： 1. 目标缓冲的类型 
     *          2. 数据的大小，以字节为单位 
     *          3. 要发送的实际数据 
     *          4. 指定希望显卡如何管理指定的数据，它有三种形式
     *               a. GL_STATIC_DRAW ：数据不会或几乎不会改变
     *               b. GL_DYNAMIC_DRAW：数据会被改变很多
     *               c. GL_STREAM_DRAW ：数据每次绘制时都会改变
    */
    /********* 编译着色器 *********/
     // 创建顶点着色器对象
     unsigned int vertexShader;
     vertexShader = glCreateShader(GL_VERTEX_SHADER);
     // 将顶点着色器源码附加到着色器对象上，然后编译
     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
     /**
      * 第一个参数是着色器对象
      * 第二个是源码字符串数量
      * 第三个是源码字符串地址
     */
     glCompileShader(vertexShader);
     
     // 获取编译的状态
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
    }

    // 创建片段着色器，并编译，检查编译错误
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    /*********着色器程序：由多个着色器合并之后并最终链接之后形成的对象 ***********/
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }
    //激活这个着色器程序
    glUseProgram(shaderProgram);

    //删除着色器对象
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f   // 左上角
    };

    unsigned int indices[] = {
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };

    /***
     *  顶点数组对象（Verctor Array Object, VAO）
     *  当一个VAO对象被创建绑定之后，任何随后的顶点属性调用都会存储到这个VAO上。这样一来如果有多个VBO对象，在渲染时只需执行一次
     *  绑定的VAO的渲染API即可。
     *  
     *  一个VAO会存储以下内容：
     *    a. glEnableVertexAttribArray和glDisableVertexAttribArray的调用
     *    b. 通过glVertexAttribPointer设置的顶点属性配置
     *    c. 通过glVertexAttribPointer调用与顶点属性关联的顶点缓冲对象
     * 
     */
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    /**
     * 顶点缓冲对象（Vertex Buffer Objects, VBO）,GPU的内存通过顶点缓冲对象来管理，它会在GPU内存中存储大量顶点
     * 使用VBO的好处是可以一次性发送大批数据到显卡上，而不是每个顶点发送一次。
    */
    unsigned int VBO;
    glGenBuffers(1, &VBO); // 生成缓冲区对象，第一个参数是生成的数量，第二个是ID，如果数量大于1，需要使用数组
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // 把新创建的缓冲对象设置成GL_ARRAY_BUFFER类型
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 将顶点坐标复制到缓冲的内存中

    /***
     * 索引缓冲对象(Element Buffer Object，EBO)
     */
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    // glVertexAttribPointer函数告诉OpenGL该如何解析顶点数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // 1. 第一个参数是顶点着色器中layout (location=0) in vec3 position;中的location的值；
    // 2. 第二个参数是指定顶点属性的维数，如果是vec3，它由三个值组成，所以大小是3；
    // 3. 第三个参数为数据的类型
    // 4. 第四个参数为是否希望数据被标准化
    // 5. 第五个参数是步长
    // 6. 最后一个参数是缓冲区的起始位置

    // 使VBO中的内存变成可用状态，glVertexAttribPointer之前绑定的是先前定义的VBO对象，顶点属性0现在会链接到它的顶点数据
    glEnableVertexAttribArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram); // 调用着色器程序
        glBindVertexArray(VAO); // 
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}