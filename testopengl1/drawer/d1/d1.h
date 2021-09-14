//
//  d1.h
//  testopengl1
//
//  Created by 郑天省 on 2021/9/14.
//

#ifndef d1_h
#define d1_h

#include "../../headers/myShader.h"

unsigned int VBO, VAO;

void initDrawer() {
    initMyShader("/Users/zhengtiansheng/Documents/testopengl1/testopengl1/drawer/d1/shader/d1.vs", "/Users/zhengtiansheng/Documents/testopengl1/testopengl1/drawer/d1/shader/d1.fs");
    float vertices[] = {
        // 第一个三角形
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, 0.5f, 0.0f,  // 左上角
        // 第二个三角形
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f   // 左上角
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void displayDrawer() {
    useMyShader();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void realseDrawer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

#endif /* d1_h */
