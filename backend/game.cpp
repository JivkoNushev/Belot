#include <emscripten/emscripten.h>
#include <GLES2/gl2.h>
#include <emscripten/html5.h>

EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context;

void initWebGL() {
    EmscriptenWebGLContextAttributes attr;
    emscripten_webgl_init_context_attributes(&attr);
    attr.alpha = true;
    attr.depth = true;
    attr.stencil = true;
    attr.antialias = true;
    attr.premultipliedAlpha = false;
    attr.preserveDrawingBuffer = false;
    attr.powerPreference = EM_WEBGL_POWER_PREFERENCE_HIGH_PERFORMANCE;
    context = emscripten_webgl_create_context("#canvas", &attr);
    if (!context) {
        emscripten_log(EM_LOG_ERROR, "Failed to create WebGL context");
        return;
    }
    emscripten_webgl_make_context_current(context);
}

void render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // Your drawing code here
}

int main() {
    initWebGL();
    emscripten_set_main_loop(render, 0, 1);
    return 0;
}
