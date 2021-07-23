#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define MAX_OPTIONS 11

class Menu
{
private:
    typedef void (*event_handler)(void);
    typedef void (*event_handler_return)(int);
    typedef struct handler_type
    {
        String name;
        event_handler handler;
        String sub_name;
        event_handler_return sub_handler;
        bool sub_menu;
        int sub_value;
        int sub_steps;
    } handler_type;

    LiquidCrystal_I2C *lcd;
    handler_type handlers[MAX_OPTIONS];

    unsigned int length;
    int position;
    bool is_selected;
    bool sub_selected;
    bool sub_edit;
    bool repead;

public:
    Menu(LiquidCrystal_I2C &lcd, bool repead = false);

    void update();
    void register_option(String name, event_handler function);
    void register_option(String name, event_handler function, String sub_name, event_handler_return sub_handler, int sub_value = 0, int sub_steps = 1);
    void select();
    void go(int step);
    void go_back();

    void print_sub_menu();
};
