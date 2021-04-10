#pragma once

#include "global_variables.hpp"
#include "user.hpp"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>


#define ps_err_img ""
#define ps_two_img ""
#define ps_three_img ""

std::string countdown(int count);

void wait_sign(screen::Background &window, int H, int W);

void change_password();

void change_info();

void change_ava();

void change_melody();

void change_nickname();

void change_name();

void change_data(screen::Background &window, int W, int H);

void check(int &H, int &W);

void personal_settings();
