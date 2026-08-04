#ifndef ANSI_H
#define ANSI_H

#include <stdio.h>


#ifndef ANSI_DEF
#define ANSI_DEF
#endif

#ifndef ESC_SEQ
#define ESC_SEQ "\033"
#endif
#ifndef WESC_SEQ
#define WESC_SEQ L"\033"
#endif

// TODO: use DEC and SCO and add a way to change cursor color
// TODO: have 'ansi_' prefix and add an option to strip it

#define COLOR_CODE_STANDARD_BLACK      0
#define COLOR_CODE_STANDARD_RED        1
#define COLOR_CODE_STANDARD_GREEN      2
#define COLOR_CODE_STANDARD_YELLOW     3
#define COLOR_CODE_STANDARD_BLUE       4
#define COLOR_CODE_STANDARD_MAGENTA    5
#define COLOR_CODE_STANDARD_CYAN       6
#define COLOR_CODE_STANDARD_WHITE      7

#define COLOR_CODE_BLACK_FG           30
#define COLOR_CODE_BLACK_BG           40
#define COLOR_CODE_RED_FG             31
#define COLOR_CODE_RED_BG             41
#define COLOR_CODE_GREEN_FG           32
#define COLOR_CODE_GREEN_BG           42
#define COLOR_CODE_YELLOW_FG          33
#define COLOR_CODE_YELLOW_BG          43
#define COLOR_CODE_BLUE_FG            34
#define COLOR_CODE_BLUE_BG            44
#define COLOR_CODE_MAGENTA_FG         35
#define COLOR_CODE_MAGENTA_BG         45
#define COLOR_CODE_CYAN_FG            36
#define COLOR_CODE_CYAN_BG            46
#define COLOR_CODE_WHITE_FG           37
#define COLOR_CODE_WHITE_BG           47
#define COLOR_CODE_DEFAULT_FG         39
#define COLOR_CODE_DEFAULT_BG         49

#define COLOR_CODE_BRIGHT_BLACK_FG    90
#define COLOR_CODE_BRIGHT_BLACK_BG   100
#define COLOR_CODE_BRIGHT_RED_FG      91
#define COLOR_CODE_BRIGHT_RED_BG     101
#define COLOR_CODE_BRIGHT_GREEN_FG    92
#define COLOR_CODE_BRIGHT_GREEN_BG   102
#define COLOR_CODE_BRIGHT_YELLOW_FG   93
#define COLOR_CODE_BRIGHT_YELLOW_BG  103
#define COLOR_CODE_BRIGHT_BLUE_FG     94
#define COLOR_CODE_BRIGHT_BLUE_BG    104
#define COLOR_CODE_BRIGHT_MAGENTA_FG  95
#define COLOR_CODE_BRIGHT_MAGENTA_BG 105
#define COLOR_CODE_BRIGHT_CYAN_FG     96
#define COLOR_CODE_BRIGHT_CYAN_BG    106
#define COLOR_CODE_BRIGHT_WHITE_FG    97
#define COLOR_CODE_BRIGHT_WHITE_BG   107

#define CUR_STYLE_DEFAULT              0
#define CUR_STYLE_BLINKING_BLOCK       1
#define CUR_STYLE_STEADY_BLOCK         2
#define CUR_STYLE_BLINKING_UNDERLINE   3
#define CUR_STYLE_STEADY_UNDERLINE     4
#define CUR_STYLE_BLINKING_BEAM        5
#define CUR_STYLE_STEADY_BEAM          6

#define COLOR_COMMODORE_FG 149, 134, 216
#define COLOR_COMMODORE_BG  66,  49, 142

#define COLOR_WORDLE_GREEN   83, 141,  78
#define COLOR_WORDLE_YELLOW 181, 159,  59
#define COLOR_WORDLE_GRAY    58,  58,  60

ANSI_DEF void set_fg_8bit(unsigned char color, FILE* stream);
ANSI_DEF void set_bg_8bit(unsigned char color, FILE* stream);
ANSI_DEF void set_fg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream);
ANSI_DEF void set_bg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream);

ANSI_DEF unsigned char standard_color_to_8bit(unsigned char color);
ANSI_DEF unsigned char standard_color_to_high_intensity_8bit(unsigned char color);
ANSI_DEF unsigned char rgb5_to_8bit_color(unsigned char r, unsigned char g, unsigned char b);
ANSI_DEF unsigned char rgb255_to_8bit_color(unsigned char r, unsigned char g, unsigned char b);
ANSI_DEF unsigned char grayscale_to_8bit(unsigned char color);

ANSI_DEF void set_cur_home(FILE* stream);
ANSI_DEF void set_cur_pos(unsigned line, unsigned column, FILE* stream);
ANSI_DEF void move_cur_up(unsigned count, FILE* stream);
ANSI_DEF void move_cur_down(unsigned count, FILE* stream);
ANSI_DEF void move_cur_right(unsigned count, FILE* stream);
ANSI_DEF void move_cur_left(unsigned count, FILE* stream);

ANSI_DEF void erase_screen_from_cur(FILE* stream);
ANSI_DEF void erase_screen_until_cur(FILE* stream);
ANSI_DEF void erase_screen(FILE* stream);
ANSI_DEF void erase_line_from_cur(FILE* stream);
ANSI_DEF void erase_line_until_cur(FILE* stream);
ANSI_DEF void erase_line(FILE* stream);

ANSI_DEF void reset_styles(FILE* stream);
ANSI_DEF void set_style_bold(FILE* stream);
ANSI_DEF void reset_style_bold(FILE* stream);
ANSI_DEF void set_style_dim(FILE* stream);
ANSI_DEF void reset_style_dim(FILE* stream);
ANSI_DEF void set_style_italic(FILE* stream);
ANSI_DEF void reset_style_italic(FILE* stream);
ANSI_DEF void set_style_underline(FILE* stream);
ANSI_DEF void reset_style_underline(FILE* stream);
ANSI_DEF void set_style_blinking(FILE* stream);
ANSI_DEF void reset_style_blinking(FILE* stream);
ANSI_DEF void set_style_inverse(FILE* stream);
ANSI_DEF void reset_style_inverse(FILE* stream);
ANSI_DEF void set_style_hidden(FILE* stream);
ANSI_DEF void reset_style_hidden(FILE* stream);
ANSI_DEF void set_style_strikethrough(FILE* stream);
ANSI_DEF void reset_style_strikethrough(FILE* stream);

ANSI_DEF void hide_cur(FILE* stream);
ANSI_DEF void show_cur(FILE* stream);
ANSI_DEF void restore_screen(FILE* stream);
ANSI_DEF void save_screen(FILE* stream);
ANSI_DEF void enable_alt_buf(FILE* stream);
ANSI_DEF void disable_alt_buf(FILE* stream);

ANSI_DEF void set_cur_style(unsigned char style, FILE* stream);

ANSI_DEF void wset_fg_8bit(unsigned char color, FILE* stream);
ANSI_DEF void wset_bg_8bit(unsigned char color, FILE* stream);
ANSI_DEF void wset_fg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream);
ANSI_DEF void wset_bg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream);

ANSI_DEF void wset_cur_home(FILE* stream);
ANSI_DEF void wset_cur_pos(unsigned line, unsigned column, FILE* stream);
ANSI_DEF void wmove_cur_up(unsigned count, FILE* stream);
ANSI_DEF void wmove_cur_down(unsigned count, FILE* stream);
ANSI_DEF void wmove_cur_right(unsigned count, FILE* stream);
ANSI_DEF void wmove_cur_left(unsigned count, FILE* stream);

ANSI_DEF void werase_screen_from_cur(FILE* stream);
ANSI_DEF void werase_screen_until_cur(FILE* stream);
ANSI_DEF void werase_screen(FILE* stream);
ANSI_DEF void werase_line_from_cur(FILE* stream);
ANSI_DEF void werase_line_until_cur(FILE* stream);
ANSI_DEF void werase_line(FILE* stream);

ANSI_DEF void wreset_styles(FILE* stream);
ANSI_DEF void wset_style_bold(FILE* stream);
ANSI_DEF void wreset_style_bold(FILE* stream);
ANSI_DEF void wset_style_dim(FILE* stream);
ANSI_DEF void wreset_style_dim(FILE* stream);
ANSI_DEF void wset_style_italic(FILE* stream);
ANSI_DEF void wreset_style_italic(FILE* stream);
ANSI_DEF void wset_style_underline(FILE* stream);
ANSI_DEF void wreset_style_underline(FILE* stream);
ANSI_DEF void wset_style_blinking(FILE* stream);
ANSI_DEF void wreset_style_blinking(FILE* stream);
ANSI_DEF void wset_style_inverse(FILE* stream);
ANSI_DEF void wreset_style_inverse(FILE* stream);
ANSI_DEF void wset_style_hidden(FILE* stream);
ANSI_DEF void wreset_style_hidden(FILE* stream);
ANSI_DEF void wset_style_strikethrough(FILE* stream);
ANSI_DEF void wreset_style_strikethrough(FILE* stream);

ANSI_DEF void whide_cur(FILE* stream);
ANSI_DEF void wshow_cur(FILE* stream);
ANSI_DEF void wrestore_screen(FILE* stream);
ANSI_DEF void wsave_screen(FILE* stream);
ANSI_DEF void wenable_alt_buf(FILE* stream);
ANSI_DEF void wdisable_alt_buf(FILE* stream);

ANSI_DEF void wset_cur_style(unsigned char style, FILE* stream);

#endif // ANSI_H

#ifdef ANSI_IMPLEMENTATION

#include <stdio.h>
#include <wchar.h>

ANSI_DEF void set_fg_8bit(unsigned char color, FILE* stream) { fprintf(stream, ESC_SEQ "[38;5;%um", color); }
ANSI_DEF void set_bg_8bit(unsigned char color, FILE* stream) { fprintf(stream, ESC_SEQ "[48;5;%um", color); }
ANSI_DEF void set_fg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream) { fprintf(stream, ESC_SEQ "[38;2;%u;%u;%um", r, g, b); }
ANSI_DEF void set_bg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream) { fprintf(stream, ESC_SEQ "[48;2;%u;%u;%um", r, g, b); }

ANSI_DEF unsigned char standard_color_to_8bit(unsigned char color) { return color; }
ANSI_DEF unsigned char standard_color_to_high_intensity_8bit(unsigned char color) { return 8 + color; }
ANSI_DEF unsigned char rgb5_to_8bit_color(unsigned char r, unsigned char g, unsigned char b) { return (unsigned char) (16 + 36 * r + 6 * g + b); }
ANSI_DEF unsigned char rgb255_to_8bit_color(unsigned char r, unsigned char g, unsigned char b) { return (unsigned char) (16 + 36 * r / 51 + 6 * g / 51 + b / 51); }
ANSI_DEF unsigned char grayscale_to_8bit(unsigned char color) { return 232 + color; }

ANSI_DEF void set_cur_home(FILE* stream) { fputs(ESC_SEQ "[H", stream); }
ANSI_DEF void set_cur_pos(unsigned line, unsigned column, FILE* stream) { fprintf(stream, ESC_SEQ "[%u;%uH", line, column); }
ANSI_DEF void move_cur_up(unsigned count, FILE* stream) { if (count) fprintf(stream, ESC_SEQ "[%uA", count); }
ANSI_DEF void move_cur_down(unsigned count, FILE* stream) { if (count) fprintf(stream, ESC_SEQ "[%uB", count); }
ANSI_DEF void move_cur_right(unsigned count, FILE* stream) { if (count) fprintf(stream, ESC_SEQ "[%uC", count); }
ANSI_DEF void move_cur_left(unsigned count, FILE* stream) { if (count) fprintf(stream, ESC_SEQ "[%uD", count); }

ANSI_DEF void erase_screen_from_cur(FILE* stream) { fputs(ESC_SEQ "[0J", stream); }
ANSI_DEF void erase_screen_until_cur(FILE* stream) { fputs(ESC_SEQ "[1J", stream); }
ANSI_DEF void erase_screen(FILE* stream) { fputs(ESC_SEQ "[2J", stream); }
ANSI_DEF void erase_line_from_cur(FILE* stream) { fputs(ESC_SEQ "[0K", stream); }
ANSI_DEF void erase_line_until_cur(FILE* stream) { fputs(ESC_SEQ "[1K", stream); }
ANSI_DEF void erase_line(FILE* stream) { fputs(ESC_SEQ "[2K", stream); }

ANSI_DEF void reset_styles(FILE* stream) { fputs(ESC_SEQ "[0m", stream); }
ANSI_DEF void set_style_bold(FILE* stream) { fputs(ESC_SEQ "[1m", stream); }
ANSI_DEF void reset_style_bold(FILE* stream) { fputs(ESC_SEQ "[22m", stream); }
ANSI_DEF void set_style_dim(FILE* stream) { fputs(ESC_SEQ "[2m", stream); }
ANSI_DEF void reset_style_dim(FILE* stream) { fputs(ESC_SEQ "[22m", stream); }
ANSI_DEF void set_style_italic(FILE* stream) { fputs(ESC_SEQ "[3m", stream); }
ANSI_DEF void reset_style_italic(FILE* stream) { fputs(ESC_SEQ "[23m", stream); }
ANSI_DEF void set_style_underline(FILE* stream) { fputs(ESC_SEQ "[4m", stream); }
ANSI_DEF void reset_style_underline(FILE* stream) { fputs(ESC_SEQ "[24m", stream); }
ANSI_DEF void set_style_blinking(FILE* stream) { fputs(ESC_SEQ "[5m", stream); }
ANSI_DEF void reset_style_blinking(FILE* stream) { fputs(ESC_SEQ "[25m", stream); }
ANSI_DEF void set_style_inverse(FILE* stream) { fputs(ESC_SEQ "[7m", stream); }
ANSI_DEF void reset_style_inverse(FILE* stream) { fputs(ESC_SEQ "[27m", stream); }
ANSI_DEF void set_style_hidden(FILE* stream) { fputs(ESC_SEQ "[8m", stream); }
ANSI_DEF void reset_style_hidden(FILE* stream) { fputs(ESC_SEQ "[28m", stream); }
ANSI_DEF void set_style_strikethrough(FILE* stream) { fputs(ESC_SEQ "[9m", stream); }
ANSI_DEF void reset_style_strikethrough(FILE* stream) { fputs(ESC_SEQ "[29m", stream); }

ANSI_DEF void hide_cur(FILE* stream) { fputs(ESC_SEQ "[?25l", stream); }
ANSI_DEF void show_cur(FILE* stream) { fputs(ESC_SEQ "[?25h", stream); }
ANSI_DEF void restore_screen(FILE* stream) { fputs(ESC_SEQ "[?47l", stream); }
ANSI_DEF void save_screen(FILE* stream) { fputs(ESC_SEQ "[?47h", stream); }
ANSI_DEF void enable_alt_buf(FILE* stream) { fputs(ESC_SEQ "[?1049h", stream); }
ANSI_DEF void disable_alt_buf(FILE* stream) { fputs(ESC_SEQ "[?1049l", stream); }

ANSI_DEF void set_cur_style(unsigned char style, FILE* stream) { fprintf(stream, ESC_SEQ "[%u q", style); }

ANSI_DEF void wset_fg_8bit(unsigned char color, FILE* stream) { fwprintf(stream, WESC_SEQ L"[38;5;%um", color); }
ANSI_DEF void wset_bg_8bit(unsigned char color, FILE* stream) { fwprintf(stream, WESC_SEQ L"[48;5;%um", color); }
ANSI_DEF void wset_fg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream) { fwprintf(stream, WESC_SEQ L"[38;2;%u;%u;%um", r, g, b); }
ANSI_DEF void wset_bg_rgb(unsigned char r, unsigned char g, unsigned char b, FILE* stream) { fwprintf(stream, WESC_SEQ L"[48;2;%u;%u;%um", r, g, b); }

ANSI_DEF void wset_cur_home(FILE* stream) { fputws(WESC_SEQ L"[H", stream); }
ANSI_DEF void wset_cur_pos(unsigned line, unsigned column, FILE* stream) { fwprintf(stream, WESC_SEQ L"[%u;%uH", line, column); }
ANSI_DEF void wmove_cur_up(unsigned count, FILE* stream) { if (count) fwprintf(stream, WESC_SEQ L"[%uA", count); }
ANSI_DEF void wmove_cur_down(unsigned count, FILE* stream) { if (count) fwprintf(stream, WESC_SEQ L"[%uB", count); }
ANSI_DEF void wmove_cur_right(unsigned count, FILE* stream) { if (count) fwprintf(stream, WESC_SEQ L"[%uC", count); }
ANSI_DEF void wmove_cur_left(unsigned count, FILE* stream) { if (count) fwprintf(stream, WESC_SEQ L"[%uD", count); }

ANSI_DEF void werase_screen_from_cur(FILE* stream) { fputws(WESC_SEQ L"[0J", stream); }
ANSI_DEF void werase_screen_until_cur(FILE* stream) { fputws(WESC_SEQ L"[1J", stream); }
ANSI_DEF void werase_screen(FILE* stream) { fputws(WESC_SEQ L"[2J", stream); }
ANSI_DEF void werase_line_from_cur(FILE* stream) { fputws(WESC_SEQ L"[0K", stream); }
ANSI_DEF void werase_line_until_cur(FILE* stream) { fputws(WESC_SEQ L"[1K", stream); }
ANSI_DEF void werase_line(FILE* stream) { fputws(WESC_SEQ L"[2K", stream); }

ANSI_DEF void wreset_styles(FILE* stream) { fputws(WESC_SEQ L"[0m", stream); }
ANSI_DEF void wset_style_bold(FILE* stream) { fputws(WESC_SEQ L"[1m", stream); }
ANSI_DEF void wreset_style_bold(FILE* stream) { fputws(WESC_SEQ L"[22m", stream); }
ANSI_DEF void wset_style_dim(FILE* stream) { fputws(WESC_SEQ L"[2m", stream); }
ANSI_DEF void wreset_style_dim(FILE* stream) { fputws(WESC_SEQ L"[22m", stream); }
ANSI_DEF void wset_style_italic(FILE* stream) { fputws(WESC_SEQ L"[3m", stream); }
ANSI_DEF void wreset_style_italic(FILE* stream) { fputws(WESC_SEQ L"[23m", stream); }
ANSI_DEF void wset_style_underline(FILE* stream) { fputws(WESC_SEQ L"[4m", stream); }
ANSI_DEF void wreset_style_underline(FILE* stream) { fputws(WESC_SEQ L"[24m", stream); }
ANSI_DEF void wset_style_blinking(FILE* stream) { fputws(WESC_SEQ L"[5m", stream); }
ANSI_DEF void wreset_style_blinking(FILE* stream) { fputws(WESC_SEQ L"[25m", stream); }
ANSI_DEF void wset_style_inverse(FILE* stream) { fputws(WESC_SEQ L"[7m", stream); }
ANSI_DEF void wreset_style_inverse(FILE* stream) { fputws(WESC_SEQ L"[27m", stream); }
ANSI_DEF void wset_style_hidden(FILE* stream) { fputws(WESC_SEQ L"[8m", stream); }
ANSI_DEF void wreset_style_hidden(FILE* stream) { fputws(WESC_SEQ L"[28m", stream); }
ANSI_DEF void wset_style_strikethrough(FILE* stream) { fputws(WESC_SEQ L"[9m", stream); }
ANSI_DEF void wreset_style_strikethrough(FILE* stream) { fputws(WESC_SEQ L"[29m", stream); }

ANSI_DEF void whide_cur(FILE* stream) { fputws(WESC_SEQ L"[?25l", stream); }
ANSI_DEF void wshow_cur(FILE* stream) { fputws(WESC_SEQ L"[?25h", stream); }
ANSI_DEF void wrestore_screen(FILE* stream) { fputws(WESC_SEQ L"[?47l", stream); }
ANSI_DEF void wsave_screen(FILE* stream) { fputws(WESC_SEQ L"[?47h", stream); }
ANSI_DEF void wenable_alt_buf(FILE* stream) { fputws(WESC_SEQ L"[?1049h", stream); }
ANSI_DEF void wdisable_alt_buf(FILE* stream) { fputws(WESC_SEQ L"[?1049l", stream); }

ANSI_DEF void wset_cur_style(unsigned char style, FILE* stream) { fwprintf(stream, WESC_SEQ L"[%u q", style); }

#endif // ANSI_IMPLEMENTATION

