#pragma once

class RenderTarget
{
public:
	RenderTarget();
	~RenderTarget();
};
typedef std::shared_ptr<RenderTarget> RenderTargetPtr;