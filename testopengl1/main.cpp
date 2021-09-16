//
//  main.cpp
//  testopengl1
//
//  Created by 郑天省 on 2021/9/8.
//

#include "headers/myWindow.h"
#include "drawer/d2/d2.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int count = 0;

int main() {
    GLFWwindow* window = createWindow(SCR_WIDTH, SCR_HEIGHT);
    initDrawer(window);
    while (!glfwWindowShouldClose(window)) {
        proccessInput(window);
        
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            count++;
        }
        
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            count--;
            if (count < 0) {
                count = 500;
            }
        }
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        displayDrawer(window, count);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    realseDrawer();
    
    glfwTerminate();
    return 0;
}
