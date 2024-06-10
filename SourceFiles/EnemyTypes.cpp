#include "EnemyTypes.hpp"

// storing textures here
Animation batAnimation = Animation("..\\Resourses\\Animations\\bat.png", 54, {AnimationState("move_right", 4, true), AnimationState("attack_right", 7, false), AnimationState("hit_right", 5, false), AnimationState("death_right", 11, false), AnimationState("move_left", 4, true) ,AnimationState("attack_left", 7, false), AnimationState("hit_left", 5, false), AnimationState("death_left", 11, false)});

Animation crabAnimation = Animation("..\\Resourses\\Animations\\crab.png", 48, {AnimationState("move_right", 6, true), AnimationState("attack_right", 10, false), AnimationState("hit_right", 3, false), AnimationState("death_right", 5, false), AnimationState("move_left", 6, true) ,AnimationState("attack_left", 10, false), AnimationState("hit_left", 3, false), AnimationState("death_left", 5, false)});

Animation slimeAnimation = Animation("..\\Resourses\\Animations\\slime.png", 36, {AnimationState("move_right", 4, true), AnimationState("attack_right", 4, false), AnimationState("hit_right", 4, false), AnimationState("death_right", 6, false), AnimationState("move_left", 4, true) ,AnimationState("attack_left", 4, false), AnimationState("hit_left", 4, false), AnimationState("death_left", 6, false)});