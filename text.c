#define RSGL_RENDER_LEGACY
#define RGFW_IMPLEMENTATION
#include "RGFW.h"
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

#define RSGL_INT_DEFINED
#define RSGL_IMPLEMENTATION
#include "RSGL.h"
#include "RSGL_gl.h"
#define CC_NO_SHORT_NAMES
#include "cc.h"

int main(void) {
  cc_vec(int) data_point;
  cc_init(&data_point);
  cc_push(&data_point, 23);
  cc_push(&data_point, 10);
  cc_push(&data_point, 109);
  cc_for_each(&data_point, el)
    printf("%d\n", *el);
  cc_cleanup(&data_point);

  RGFW_window* win = RGFW_createWindow("name", (RGFW_rect){500, 500, 500, 500}, RGFW_windowCenter | RGFW_windowFocusOnShow | RGFW_windowFocus);
  RSGL_init(RSGL_AREA(win->r.w, win->r.h), RGFW_getProcAddress, RSGL_GL_renderer());
  RSGL_font* font = RSGL_loadFont("Hack-Regular.ttf");
  RSGL_setFont(font);
  int *num = NULL;
  arrput(num, 32);
  arrput(num, 23);
  arrput(num, 92);
  arrput(num, 18);
  arrput(num, 22);

  for (size_t i = 0; i < arrlenu(num); i++)
    printf("nums[%zu]: %d\n", i, num[i]);

  while (RGFW_window_shouldClose(win) == false) {
    RGFW_window_checkEvent(win);

    if (win->event.type == RGFW_quit)
      break;

    RSGL_clear(RSGL_RGB(100, 100, 100));

    /* RSGL_drawText("Text example\nnewlines too", RSGL_CIRCLE(200, 200, 20), RSGL_RGB(255, 0, 0)); */
    /* RSGL_drawText(RSGL_strFmt("FPS : %i\nOpenGL %s", fps, RSGL_GL_legacy ? "legacy (2-)" : "modern (3.3 +)"), RSGL_CIRCLE(0, 40, 40), RSGL_RGB(255, 0, 0)); */
    RSGL_drawRect(RSGL_RECT(10, 10, 10, 10), RSGL_RGB(247, 148, 54));
    RSGL_draw();
    RGFW_window_swapBuffers(win);
  }
  RSGL_freeFont(font);

  RSGL_free();
  RGFW_window_close(win);
  arrfree(num);
}
