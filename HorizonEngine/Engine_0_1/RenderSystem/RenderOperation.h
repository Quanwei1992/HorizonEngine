#pragma once
#include <memory>
#include "VertexData.h"

class RenderOperation
{

public:
	enum class OperationType
	{
		PointList,
		LineList,
		LineStrip,
		TriangleList,
		TriangleStrip,
		TriangleFan
	};
public:
	RenderOperation(OperationType type, VertexDataPtr data);
	~RenderOperation() = default;
	OperationType getType() const;
	VertexDataPtr getData() const;
private:
	OperationType mType;
	VertexDataPtr mVertexData;
};
using  RenderOperationPtr = std::shared_ptr<RenderOperation>;