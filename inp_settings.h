#ifndef _GAMEOFLIFE_INP_SETTINGS_H_
#define _GAMEOFLIFE_INP_SETTINGS_H_

void set_noncanonical(struct termios *init, struct termios *ne);
void set_canon(struct termios *init);

#endif //_GAMEOFLIFE_INP_SETTINGS_H_