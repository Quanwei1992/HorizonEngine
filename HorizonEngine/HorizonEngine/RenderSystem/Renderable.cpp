#include "Renderable.h"





Renderable::Renderable(const RenderOperation& _op, const Shader& _shader, const Material& _material, const glm::mat4x4 _model2world):
	op(nullptr),
	shader(nullptr),
	material(nullptr)
{
	op = &_op;
	shader = &_shader;
	material = &_material;
	model2world = _model2world;
}

Renderable::~Renderable()
{
}
