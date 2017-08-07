#pragma once
#include <memory>
#include "Component.h"
class Light : public Component
{
public:
	Light() = default;
	~Light() override = default;
};

