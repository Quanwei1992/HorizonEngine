#pragma once
#include "RenderSystem/RenderOperation.h"
#include "RenderSystem/GL/GPUPragram.h"
#include "Shader.h"
#include "Material.h"

#include "ThirdPart/Includes/glm/glm.hpp"
using namespace HorizonEngine;
//可渲染对象。
//包含渲染需要的一些基本信息。
//材质，矩阵，
class Renderable
{
public:
	Renderable(const RenderOperation& _op,const GPUPragram& _program,const glm::mat4x4 _model2world);
	~Renderable();
public:
	const RenderOperation* op;
	const GPUPragram* program;
	glm::mat4x4 model2world;

};

