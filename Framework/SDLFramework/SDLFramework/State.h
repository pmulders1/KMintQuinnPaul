#pragma once
#include <cstdint>
enum class State : std::int8_t { WANDERING = 1, CHASE = 2, IDLE = 3, SEARCHWEAPON = 4, SEARCHPILL = 5, SLEEPING = 6, STATICOBJECT = 7 };
