#pragma once

#include "../internal/Component.h"
// #include "internal/GameObject.h"

#include "../math/Vector2.h"

class Transform : public Component {
    public:
        Vector2 position;

        void Start() {}

        void translate(Vector2 translation) {
            position = position + translation;
        }
};