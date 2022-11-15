#pragma once

#include "../internal/Component.h"
#include "../internal/GameObject.h"

#include "Transform.h"

#include "../math.h"

class Player : public Component {
    public:
        void Start() {
            cout << "setting up :)" << endl;

            Transform transform = gameObject->GetComponent<Transform>();

            transform.translate(Vector3(1,2,0));

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