#pragma once
#include <memory>
#include <vector>
#include "Math/Math.h"
#include "RenderSystem/VertexData.h"
class Mesh
{
public:
	Mesh();
	~Mesh() = default;

	void setVertices(const std::vector<Vector3>& vertices);
	void setUV(const std::vector<Vector2>& uv);
	void setNormals(const std::vector<Vector3>& normals);
	void setTriangles(const std::vector<int>& triangles);

	const std::vector<Vector3> getVertices() const;
	const std::vector<Vector2> getUV() const;
	const std::vector<Vector3> getNormals() const;
	const std::vector<int> getTriangles() const;

	VertexDataPtr getVertexData();

private:
	std::vector<Vector3> mVertices;
	std::vector<Vector2> mUV;
	std::vector<Vector3> mNormals;
	std::vector<int> mTriangles;
	VertexDataPtr mData;
	bool mDirty;
};

using MeshPtr = std::shared_ptr<Mesh>;