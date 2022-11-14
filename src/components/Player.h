#pragma once

#include "../internal/Component.h"
#include "../internal/GameObject.h"

#include "Transform.h"

#include "../math/Vector2.h"

class Player : public Component {
    public:
        void Start() {
            cout << "setting up :)" << endl;

            Transform transform = gameObject->GetComponent<Transform>();

            transform.translate(Vector2(1,2));

            cout << transform.position << endl;

            cout << gameObject->scene->name << endl;
        }

        void Update() {
            cout << "update :)))" << endl;
        }

        void Die() {
            cout << "*dies*" << endl;
        }
};