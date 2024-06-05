#include "EnemyTypes.hpp"

// storing textures here
Animation batAnimation = Animation("..\\Resourses\\Animations\\bat.png", 54, {AnimationState("move_right", 4, true), AnimationState("attack_right", 7, false), AnimationState("hit_right", 5, false), AnimationState("death_right", 11, false), AnimationState("move_left", 4, true) ,AnimationState("attack_left", 7, false), AnimationState("hit_left", 5, false), AnimationState("death_left", 11, false)});