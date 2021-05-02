#include <stdarg.h>
#include <stdio.h>

#include <tui.h>

void
tui_print(const char *s, int x, int y, uint32_t fg, uint32_t bg)
{
	int i = -1;
	while (s[++i])
		tb_change_cell(x + i, y, (uint32_t)s[i], fg, bg);
}

void
tui_printf(const char *s, int x, int y, uint32_t fg, uint32_t bg, ...)
{
	va_list ap;
	char buf[640 * 1024], *bptr = buf, *t = bptr--;
	va_start(ap, bg);
	vsnprintf(buf, 640 * 1024, s, ap);
	va_end(ap);
	while (*(++bptr))
		tb_change_cell(x + (int)(bptr - t), y, (uint32_t)*bptr, fg, bg);
}

void
tui_drawbox(int x, int y, int w, int h, uint32_t fg, uint32_t bg, int filled)
{
	int i;

	/*
		0x250C => ┌
		0x2510 => ┐
		0x2514 => └
		0x2518 => ┘
		0x2502 => │
		0x2500 => ─
	*/

	tb_change_cell(x, y, 0x250C, fg, bg);
	tb_change_cell(x + (w - 1), y, 0x2510, fg, bg);
	tb_change_cell(x, y + (h - 1), 0x2514, fg, bg);
	tb_change_cell(x + (w - 1), y + (h - 1), 0x2518, fg, bg);

	for (i = x + 1; i < x + w - 1; ++i) {
		tb_change_cell(i, y, 0x2500, fg, bg);
		tb_change_cell(i, y + (h - 1), 0x2500, fg, bg);
	}

	for (i = y + 1; i < y + h - 1; ++i) {
		tb_change_cell(x, i, 0x2502, fg, bg);
		tb_change_cell(x + (w - 1), i, 0x2502, fg, bg);
	}

	if (filled) {
		for (i = x + 1; i < x + w - 1; ++i) {
#define j filled
			for (j = y + 1; j < y + h - 1; ++j) {
				tb_change_cell(i, j, (uint32_t)' ', fg, bg);
			}
#undef j
		}
	}
}
