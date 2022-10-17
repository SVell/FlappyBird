#pragma once

struct Vector2 {
    int x;
    int y;

    Vector2() {
        x = 0;
        y = 0;
    }

    Vector2(int newX, int newY) : x(newX), y(newY){};

    Vector2& operator=(const Vector2& vector){
        x = vector.x;
        y = vector.y;
    }

    Vector2& operator+=(const Vector2& vector){
        x += vector.x;
        y += vector.y;
    }
};