#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "Menu.h"

Menu::Menu(LiquidCrystal_I2C &lcd, bool repeat = false)
{
    this->lcd = &lcd;
    this->length = 0;
    this->position = 0;
    this->is_selected = false;
    this->repead = repeat;
}

void Menu::update()
{
    this->lcd->clear();

    if (this->position % 2 == 0)
    {
        this->lcd->setCursor(0, 0);
        this->lcd->print("> " + handlers[position].name);
        this->lcd->setCursor(0, 1);

        if (this->repead)
        {
            this->lcd->print("  " + handlers[(position + 1) % this->length].name);
        }
        else
        {
            this->lcd->print("  " + handlers[position + 1].name);
        }
    }
    else
    {
        this->lcd->setCursor(0, 0);

        if (this->repead)
        {
            this->lcd->print("  " + handlers[(position - 1) % this->length].name);
        }
        else
        {
            this->lcd->print("  " + handlers[position - 1].name);
        }

        this->lcd->setCursor(0, 1);
        this->lcd->print("> " + handlers[position].name);
    }
}

void Menu::register_option(String name, event_handler handler)
{
    if (this->length <= MAX_OPTIONS)
    {
        this->handlers[this->length].name = name;
        this->handlers[this->length].handler = handler;
        this->handlers[this->length].sub_menu = false;
        this->length++;
    }
}

void Menu::register_option(String name, event_handler handler, String sub_name, event_handler_return sub_handler, int sub_value = 0, int sub_steps = 1)
{
    if (this->length <= MAX_OPTIONS)
    {
        this->handlers[this->length].name = name;
        this->handlers[this->length].handler = handler;
        this->handlers[this->length].sub_menu = true;
        this->handlers[this->length].sub_name = sub_name;
        this->handlers[this->length].sub_handler = sub_handler;
        this->handlers[this->length].sub_value = sub_value;
        this->handlers[this->length].sub_steps = sub_steps;
        this->length++;
    }
}

void Menu::select()
{
    if (this->is_selected)
    {
        if (this->handlers[position].sub_menu)
        {

            if (this->sub_selected)
            {
                this->sub_edit = !this->sub_edit;
            }
            else
            {
                this->handlers[this->position].sub_handler(this->handlers[this->position].sub_value);
                this->go_back();
            }
        }
        else
        {
            this->go_back();
        }
    }
    else
    {
        this->is_selected = true;
        this->handlers[position].handler();

        if (this->handlers[position].sub_menu)
        {
            this->sub_selected = true;
            this->sub_edit = false;

            this->print_sub_menu();
        }
    }
}

void Menu::go(int step)
{
    if (this->is_selected)
    {
        if (this->handlers[position].sub_menu)
        {

            if (this->sub_edit)
            {
                this->handlers[position].sub_value += step * this->handlers[position].sub_steps * -1;
                this->print_sub_menu();
            }
            else
            {
                if ((step < 0 && !this->sub_selected) || (step > 0 && this->sub_selected) || this->repead)
                {
                    this->sub_selected = !this->sub_selected;
                    this->print_sub_menu();
                }
            }
        }
        else
        {
            // handle later, if rotating in not-submenu
        }
    }
    else
    {
        if ((this->position + step >= 0 && this->position + step <= this->length - 1) || this->repead)
        {
            this->position = (this->position + step + this->length) % this->length;
            this->update();
        }
    }
}

void Menu::go_back()
{
    this->is_selected = false;
    this->update();
}

void Menu::print_sub_menu()
{
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print((this->sub_selected ? "> " : "  ") +
                     this->handlers[position].sub_name + ": " +
                     this->handlers[position].sub_value);
    this->lcd->setCursor(0, 1);
    this->lcd->print(this->sub_selected ? "  Back" : "> Back");
}
