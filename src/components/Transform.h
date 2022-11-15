#pragma once

#include "../internal/Component.h"
// #include "internal/GameObject.h"

#include "../math.h"

class Transform : public Component {
    public:
        Vector3 position;

        void Start() {}

        void translate(Vector3 translation) {
            position = position + translation;
        }
};