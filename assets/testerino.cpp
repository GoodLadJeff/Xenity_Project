#include "testerino.h"
#include "../xenity.h"

/**
* Constructor
*/
Testerino::Testerino() : my_float(0)
{
    // Register class name
    componentName = "Testerino";
}

/**
* Called once when the script is enabled
*/
void Testerino::Start()
{
    my_transform = GetTransform();
    my_rigidbody = GetGameObject()->GetComponent<RigidBody>();
}

/**
* Called every frame
*/
void Testerino::Update()
{
    float speed = 10;
    Vector2 input = Vector2(0);

    if (InputSystem::GetKey(UP))
    {
        input.x = -1;
    }
    else if (InputSystem::GetKey(DOWN))
    {
        input.x = 1;
    }
    if (InputSystem::GetKey(LEFT))
    {
        input.y = -1;
    }
    else if (InputSystem::GetKey(RIGHT))
    {
        input.y = 1;
    }

    if(InputSystem::GetKeyDown(SPACE))
    {
        my_rigidbody.lock()->velocity.y = 10.f;
    }

    //Debug::Print();
    input = input.Normalized();
    input *= speed * Time::GetDeltaTime();

    if(my_transform.lock())
    {
        Vector3 newPosition = Vector3(my_transform.lock()->GetPosition().x + input.x,my_transform.lock()->GetPosition().y, my_transform.lock()->GetPosition().z + input.y);
        my_transform.lock()->SetPosition(Vector3(newPosition));
    }
}

/**
* Lists all variables to show in inspector
*/
ReflectiveData Testerino::GetReflectiveData()
{
    ReflectiveData reflectedVariables;
    Reflective::AddVariable(reflectedVariables, my_float, "myfloat", true); // true = isVisibleInInspector

    return reflectedVariables;
}
