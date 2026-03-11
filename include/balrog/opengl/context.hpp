
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

class GLContext {
private:
    GLFWwindow* window_ = nullptr;
    bool initialized_ = false;

    static void framebuffer_size_callback(GLFWwindow* w, int wpx, int hpx) {
        glViewport(0, 0, wpx, hpx);
    }

public:
    GLContext(int width = 1280, int height = 720, const char* title = "GL Window") {
        if (!glfwInit()) throw std::runtime_error("GLFW init failed");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!window_) {
            glfwTerminate();
            throw std::runtime_error("Window creation failed");
        }

        glfwMakeContextCurrent(window_);
        glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

        glewExperimental = GL_TRUE;
        if(glewInit() != GLEW_OK) {
            throw std::runtime_error("GLEW init failed");
        }

        glViewport(0, 0, width, height);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        initialized_ = true;
    }

    ~GLContext() {
        if (window_) glfwDestroyWindow(window_);
        glfwTerminate();
    }

    GLContext(const GLContext&) = delete;
    GLContext& operator=(const GLContext&) = delete;
    GLContext(GLContext&&) = default;
    GLContext& operator=(GLContext&&) = default;

    void render() {
        glfwPollEvents();
        if (!initialized_) return;

        if(glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window_, 1);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window_);
    }

    bool should_close() const {
        return window_ && glfwWindowShouldClose(window_);
    }

    GLFWwindow* window() const { return window_; }

    void show() {
        while (!should_close()) {
            render();
        }
    }
};
