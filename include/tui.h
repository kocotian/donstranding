#ifndef _TUI_H
#define _TUI_H

#include <termbox.h>

void tui_print(const char *s, int x, int y, uint32_t fg, uint32_t bg);
void tui_printf(const char *s, int x, int y, uint32_t fg, uint32_t bg, ...);
void tui_drawbox(int x, int y, int w, int h, uint32_t fg, uint32_t bg, int filled);

#endif
