#pragma once

#include <SDL3/SDL.h>
#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>

class App {
public:
    App() = default;
    ~App() { cleanup(); }

    bool init();
    void drawBlueFrame();
    void run();
    void cleanup();

private:
    SDL_Window* window = nullptr;
    VkInstance instance = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
};

