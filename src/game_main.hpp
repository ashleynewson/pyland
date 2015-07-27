#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include <string>
#include <memory>
#include <utility>
#include <functional>
#include <chrono>
#include <vector>
#include <glm/vec2.hpp>
#include "interpreter.hpp"
#include "game_window.hpp"
#include "gui_manager.hpp"
#include "callback_state.hpp"
#include "map_viewer.hpp"
#include "typeface.hpp"
#include "text_font.hpp"
#include "text.hpp"
#include "gui_window.hpp"
#include "button.hpp"
#include "lifeline.hpp"

class Challenge;
class ChallengeData;
class InputManager;
class EventManager;
class NotificationBar;
class MouseCursor;

class GameMain{
private:

    //Part of the game window interface
    GameWindow embedWindow;
    Interpreter interpreter;
    InputManager* input_manager;
    GUIManager gui_manager;
    CallbackState callbackstate;
    MapViewer map_viewer;
    EventManager *em;
    std::shared_ptr<GUIWindow> sprite_window;
    NotificationBar *notification_bar;
    std::pair<int,int> original_window_size;
    MouseCursor *cursor;

    //Styles for buttons
    Typeface buttontype;
    TextFont buttonfont;

    //Buttons on the screen
    std::shared_ptr<Text> stoptext;
    std::shared_ptr<Text> runtext;
    std::shared_ptr<Button> run_button;
    std::shared_ptr<Button> stop_button;

    //Actions that can be performed on the game window
    std::function<void(GameWindow*)> gui_resize_func;
    Lifeline gui_resize_lifeline;
    Lifeline map_resize_lifeline;
    Lifeline stop_callback;
    Lifeline restart_callback;
    Lifeline editor_callback;
    Lifeline back_callback;
    Lifeline fast_start_ease_callback;
    Lifeline fast_ease_callback;
    Lifeline fast_finish_ease_callback;
    Lifeline up_callback;
    Lifeline down_callback;
    Lifeline right_callback;
    Lifeline left_callback;
    Lifeline monologue_callback;
    Lifeline mouse_button_lifeline;
    Lifeline zoom_in_callback;
    Lifeline zoom_out_callback;
    Lifeline zoom_zero_callback;
    Lifeline help_callback;
    Lifeline switch_char;
    Lifeline text_lifeline_char;

    glm::ivec2 tile_identifier_old_tile;
    std::chrono::steady_clock::time_point start_time;
    std::vector<Lifeline> digit_callbacks;
    Text tile_identifier_text;
    std::function<void (GameWindow*)> func_char;

    //Variable to run/stop the game
    bool run_game;

    //Data for the present challenge
    ChallengeData *challenge_data;
    Challenge* challenge;
    std::chrono::time_point<std::chrono::steady_clock> last_clock;

public:
    GameMain(int &argc, char **argv);
    ~GameMain();

    void game_loop(bool showMouse);
    Challenge* pick_challenge(ChallengeData* challenge_data);
    GameWindow* getGameWindow();
};

#endif // GAME_MAIN_H
