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

int main() {
    GLFWwindow* window = createWindow(SCR_WIDTH, SCR_HEIGHT);
    initDrawer();
    while (!glfwWindowShouldClose(window)) {
        proccessInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        displayDrawer();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    realseDrawer();
    
    glfwTerminate();
    return 0;
}
