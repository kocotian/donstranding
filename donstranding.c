#include <stdio.h>
#include <string.h>

#include <tui.h>
#include <util.h>

#include "config.h"

typedef enum {
	MSSingle, MSMulti, MSQuit,
	MSLen
} MenuSelections;

static void drawoption(int w, int y, const char *label, int focused);
static void drawmenu(void);
static int mainmenu(void);

static const char *title[] = {
	"    ____  ____  _   __   _______________  ___    _   ______  _____   ________",
	"   / __ \\/ __ \\/ | / /  / ___/_  __/ __ \\/   |  / | / / __ \\/  _/ | / / ____/",
	"  / / / / / / /  |/ /   \\__ \\ / / / /_/ / /| | /  |/ / / / // //  |/ / / __  ",
	" / /_/ / /_/ / /|  /   ___/ // / / _, _/ ___ |/ /|  / /_/ // // /|  / /_/ /  ",
	"/_____/\\____/_/ |_/   /____//_/ /_/ |_/_/  |_/_/ |_/_____/___/_/ |_/\\____/   ",
	NULL
};

static const char *modes[] = {
	[MSSingle] = "single don mode",
	[MSMulti] = "army of dons mode",
	[MSQuit] = "slp slp",
	NULL
};

static int selmode;

static void
drawoption(int w, int y, const char *label, int focused)
{
	tui_print(label, ((w - 2) / 2) - ((int)strlen(label) / 2),
			y, focused ? ColorLWhite | TB_BOLD : ColorWhite, ColorBlack);
}

static void
drawmenu(void)
{
	int i, bh;
	tui_drawbox(0, 0, tb_width(), tb_height(), ColorWhite, ColorBlack, 1);
	i = -1;
	while (title[++i] != NULL) {
		tui_print(title[i], ((tb_width() - 2) / 2) - ((int)strlen(title[i]) / 2),
				2 + i, ColorYellow, ColorBlack);
	}
	bh = ++i;
	i = -1;
	while (modes[++i] != NULL) {
		drawoption(tb_width(), 2 + bh + i, modes[i], i == selmode);
	}
	tb_present();
}

static int
mainmenu(void)
{
	struct tb_event event;
	selmode = 0;
	while (1) {
		drawmenu();
		tb_poll_event(&event);
		if (event.key == TB_KEY_ESC) {
			return 0;
		} else if (event.key == TB_KEY_ARROW_UP || event.ch == (uint32_t)'k') {
			if (selmode > 0) --selmode;
		} else if (event.key == TB_KEY_ARROW_DOWN || event.ch == (uint32_t)'j') {
			if (selmode < MSLen - 1) ++selmode;
		}
	}
}

int
main(void)
{
	if (tb_init() < 0)
		die("termbox init failed");

	tb_select_input_mode(TB_INPUT_ESC);
	tb_select_output_mode(TB_OUTPUT_TRUECOLOR);

	if (tb_width() < 69 || tb_height() < 24)
		die("terminal is too small: %dx%d, expected %dx%d",
				tb_width(), tb_height(), 69, 24);

	tb_clear();
	while (mainmenu());

	tb_shutdown();
	return 0;
}
