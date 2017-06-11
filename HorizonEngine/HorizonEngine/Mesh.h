#pragma once
#include <vector>
class Mesh
{

public:
	void vertices(const std::vector<float> vertices);
	const std::vector<float>& vectices();
	void indices(const std::vector<unsigned int> indices);
	const std::vector<unsigned int>& indices();
public:
	Mesh();
	~Mesh();
private:
	std::vector<float> mVertices;
	std::vector<unsigned int> mIndices;
};

