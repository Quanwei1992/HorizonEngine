#include "stdafx.h"
#include "RenderOperation.h"

RenderOperation::RenderOperation(OperationType type, VertexDataPtr data) :
	mType(type),
	mVertexData(data)
{

}

RenderOperation::OperationType RenderOperation::getType() const
{
	return mType;
}

VertexDataPtr RenderOperation::getData() const
{
	return mVertexData;
}

