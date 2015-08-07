#ifndef GUI_MAIN_H
#define GUI_MAIN_H

#include <memory>
#include <deque>

#include "button.hpp"
#include "config.hpp"
#include "event_manager.hpp"
#include "gui_manager.hpp"
#include "gui_window.hpp"
#include "map_viewer.hpp"
#include "text_box.hpp"

///
/// The entire GUI, which consists of all the components in it.
/// Created by GameMain and contained in it
///

typedef Button Board;

class GUIMain {

private:

    ///refer to the config.jsonnet under "scales" for these variables:

    ///****************Config variables start
    float x_scale;
    float y_scale;

    float left_x_offset;
    float right_x_offset;
    float bottom_y_offset;
    float top_y_offset;

    float title_x_offset;
    float title_y_offset;

    float menu_x_offset;
    float menu_y_offset;

	float notification_width;
	float notification_height;

	float notification_text_width;
	float notification_text_height;
	float notification_text_x;
	float notification_text_y;

	float notification_button_width;
	float notification_button_height;
	float notification_button_x;
	float notification_button_y;

	float py_help_width;
	float py_help_height;
	float py_help_x;
	float py_help_y;

	float py_next_width;
	float py_next_height;
	float py_next_x;
	float py_next_y;

	float py_back_width;
	float py_back_height;
	float py_back_x;
	float py_back_y;

	float button_width;
	float button_height;

    float horizontal_button_spacing;
    float vertical_button_spacing;

    unsigned int button_max;
    ///****************Config variables end

    GameWindow * embedWindow;
    GUIManager gui_manager;
    MapViewer map_viewer;
    EventManager *em;

    std::shared_ptr<GUIWindow> gui_window;

    void create_notification_bar();
    std::shared_ptr<TextBox> notification_bar;

	void create_pause_menu();
    //The button to pause the game
    std::shared_ptr<Button> pause_button;
    void open_pause_window();
    void close_pause_window();

	void create_bag();

    bool bag_open; //whether or not the bag is open
    std::shared_ptr<Button> bag_button;
    std::shared_ptr<Board> bag_window;
    std::shared_ptr<Button> pyguide_button;
    std::deque<std::shared_ptr<Button>> bag_items;
    void open_bag();
    void close_bag();

	void create_pyguide();
    bool pyguide_open; //whether or not the PyGuide is open
    std::shared_ptr<Board> pyguide_window;
    std::shared_ptr<TextBox> py_help;
    std::deque<std::shared_ptr<Button>> pyguide_commands;
    void open_pyguide();
    void close_pyguide();

    //The gameplay buttons for the gui displayed on the screen
    //created by GameEngine
    std::deque<std::shared_ptr<Button>> buttons;
    //While cycling through sprites, this is the index of the first button on the visible page
    unsigned int display_button_start;
    //A button used to cycle through the sprite heads
    std::shared_ptr<Button> cycle_button;

    //Gets the config variables from config.jsonnet
    void config_gui();

public:

    GUIMain(GameWindow * embedWindow);
    ~GUIMain();

    std::shared_ptr<GUIWindow> get_gui_window(){
        return gui_window;
    }

    GUIManager * get_gui_manager(){
        return &gui_manager;
    }

    std::shared_ptr<TextBox> get_notification_bar(){
        return notification_bar;
    }

    MapViewer * get_map_viewer(){
        return &map_viewer;
    }

    //To add a button to the screen- is called from game engine
    //file path is the location of the image in gui.png, and name is the name to be displayed on screen
    //callback is added to the event manager when the button is pressed
    void add_button(std::string file_path, std::string name, std::function<void (void)> callback);


	//To add a message to the notification bar
	void add_message(std::string text);

	void open_notification_bar();
	void close_notification_bar();


    //This is used to render the components to the screen after any changes have made to the gui
    void refresh_gui();
};
#endif
