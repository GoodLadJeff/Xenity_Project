#pragma once

#include "../engine/monobehaviour.h"
#include "../engine/component.h"

class RigidBody;

class Testerino : public MonoBehaviour
{
public:
    Testerino();

    void Start() override;
    void Update() override;

    ReflectiveData GetReflectiveData() override;

private:
    float my_float;
    std::weak_ptr<Transform> my_transform;
    std::weak_ptr<RigidBody> my_rigidbody;

};
