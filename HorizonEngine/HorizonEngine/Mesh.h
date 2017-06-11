#pragma once
#include <vector>
class Mesh
{

public:
	void Submit();
	void SetData(std::vector<float> vertices,std::vector<unsigned int> indices);
	void Use();
	unsigned int GetNumOfTrangles();
	unsigned int GetVerticesCount();
	unsigned int GetIndicesCount();
	bool IsSubmited();
public:
	Mesh();
	~Mesh();
private:
	std::vector<float> mVertices;
	std::vector<unsigned int> mIndices;

	unsigned int mVAO;
	unsigned int mVBO;
	unsigned int mEBO;
	unsigned int mNumOfTrangles;
	bool mSubmited;
};

