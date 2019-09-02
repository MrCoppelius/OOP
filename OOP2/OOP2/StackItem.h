#pragma once
#include "Hexagon.h"
struct StackItem {
    Hexagon hexagon;
    StackItem *next;
};