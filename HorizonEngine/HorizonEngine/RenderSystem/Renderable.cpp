#include "Renderable.h"






Renderable::Renderable(const RenderOperation & _op, const GPUPragram& _program, const glm::mat4x4 _model2world) :
	op(nullptr),
	program(nullptr)
{
	op = &_op;
	program = &_program;
	model2world = _model2world;
}

Renderable::~Renderable()
{
}

