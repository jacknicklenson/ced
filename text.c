#define RSGL_RENDER_LEGACY
#define RGFW_IMPLEMENTATION
#include "RGFW.h"

#define RSGL_INT_DEFINED
#define RSGL_IMPLEMENTATION
#include "RSGL.h"
#include "RSGL_gl.h"

int main(void) {
  RGFW_window *win = RGFW_createWindow(
      "CED", (RGFW_rect){500, 500, 500, 500},
      RGFW_windowCenter | RGFW_windowFocusOnShow | RGFW_windowFocus);

  RSGL_init(RSGL_AREA(win->r.w, win->r.h), RGFW_getProcAddress,
            RSGL_GL_renderer());

  RSGL_font *font = RSGL_loadFont("Hack-Regular.ttf");
  RSGL_setFont(font);

  while (RGFW_window_shouldClose(win) == false) {
    RGFW_window_checkEvent(win);

    if (win->event.type == RGFW_quit) break;

    RSGL_clear(RSGL_RGB(100, 100, 100));

    /* RSGL_drawText("Text example\nnewlines too", RSGL_CIRCLE(200, 200, 20),
     * RSGL_RGB(255, 0, 0)); */

    /* RSGL_drawText(RSGL_strFmt("FPS : %i\nOpenGL %s", fps, RSGL_GL_legacy ?
     * "legacy (2-)" : "modern (3.3 +)"), RSGL_CIRCLE(0, 40, 40), RSGL_RGB(255,
     * 0, 0)); */

    RSGL_drawRect(RSGL_RECT(0, 0, 3, 3), RSGL_RGB(255, 0, 0));
    RSGL_draw();
    RGFW_window_swapBuffers(win);
  }
  RSGL_freeFont(font);

  RSGL_free();
  RGFW_window_close(win);
}
