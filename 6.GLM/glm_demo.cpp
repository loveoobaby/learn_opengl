#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

int main() {
    glm::vec4 vec(1.0, 0.0, 0.0, 1.0);
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(1.0, 1.0, 0.0));
    vec = trans * vec;

    std::cout << vec.x << vec.y << vec.z << std::endl;

}