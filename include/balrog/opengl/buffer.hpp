
#pragma once

#include <GL/glew.h>
#include <vector>

namespace balrog {

struct Buffer {
    GLuint VAO, VBOx, VBOy;

    Buffer() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBOx);
        glGenBuffers(1, &VBOy);
    }

    void bindx() {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBOx);
    }

    void bindy() {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBOy);
    }

    void unbind() {
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void uploadx(const std::vector<float> &vertices) {
        bindx();
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        layout(0);
    }

    void uploady(const std::vector<float> &vertices) {
        bindy();
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        layout(1);
    }

    void layout(size_t idx) {
        glVertexAttribPointer(idx, 1, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glEnableVertexAttribArray(idx);
    }

    ~Buffer() {}
    void destroy() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBOx);
        glDeleteBuffers(1, &VBOy);
    }

    void bind() { glBindVertexArray(VAO); }
};

}
