
#pragma once

#include <GL/glew.h>
#include <vector>

#include "balrog/vertex.hpp"

namespace balrog {

struct Buffer {
    GLuint vbo = 0, vao = 0;
    size_t capacity = 0, count = 0;

    Buffer() {
    }

    void init() {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
    }

    ~Buffer() {
        if (vbo)
            glDeleteBuffers(1, &vbo);

        if (vao)
            glDeleteVertexArrays(1, &vao);
    }

    void upload(const std::vector<Vertex> &verts, GLenum usage = GL_DYNAMIC_DRAW) {
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), verts.data(), usage);

        capacity = verts.size();
        count = verts.size();
        layout();
    }

    static void layout() {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8, (void*)0);
        glEnableVertexAttribArray(0);
    }

    void bind() {
        glBindVertexArray(vao);
        // No need to bind VBO explicitly; VAO handles attributes via glVertexAttribPointer calls during setup
    }

    void unbind() {
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};

}
