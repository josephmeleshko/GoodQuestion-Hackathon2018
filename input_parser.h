#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>
using namespace std;

static inline string &ltrim(string &s);
static inline string &rtrim(string &s);
static inline string &trim(string &s);
bool InGameBuildFunc(string args);
bool InGameDestroyFunc(string args);
bool InGameChangeLevelFunc(string arg);
bool InGameChangeSettingFunc(string args);
bool InGameChangeSpeedFunc(string arg);
bool InGameHelpFunc();
bool InGameListLevelsFunc();
bool InGameSettingsFunc();
bool InGameCheckResourcesFunc();
bool InGamePauseFunc();
bool InGameContinueFunc();
bool InGameResetFunc();
bool InGameStartFunc();
bool InGameQuitFunc();
bool InGameSaveFunc();
void parse_editor_input();
void parse_terminal_input();
string InputFile(string filename);
string InputLine(string filename);

#endif
