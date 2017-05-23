#include "RenderSystem.h"



RenderSystem::RenderSystem()
{
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::Render(Scene & scene)
{
	// 获得相机投影矩阵和观察矩阵
	// 遍历场景中的每个物体.
		// 由物体的RenderComponent执行下面的操作.
		// 获得物体世界矩阵.
		// 设置物体Shader.
		// 绑定物体VAO,
		// glDraw.

	// swapbuffers.
}
