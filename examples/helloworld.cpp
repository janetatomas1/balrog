
#include <balrog/opengl/context.hpp>
#include <iostream>


int main() {
    GLContext ctx(1024, 768, "My GL App");
    ctx.show();
    return 0;
}
