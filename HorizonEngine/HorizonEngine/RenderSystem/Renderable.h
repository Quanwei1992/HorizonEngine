#pragma once
#include "RenderSystem/RenderOperation.h"
#include "Shader.h"
#include "Material.h"
#include "ThirdPart/Includes/glm/glm.hpp"
using namespace HorizonEngine;
//����Ⱦ����
//������Ⱦ��Ҫ��һЩ������Ϣ��
//���ʣ�����
class Renderable
{
public:
	Renderable(const RenderOperation& _op,const Shader& _shader,const Material& _material,const glm::mat4x4 _model2world);
	~Renderable();

public:
	const RenderOperation* op;
	const Shader* shader;
	const Material* material;
	glm::mat4x4 model2world;

};

