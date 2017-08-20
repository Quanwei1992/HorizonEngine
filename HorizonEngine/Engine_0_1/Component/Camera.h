#pragma once
#include <memory>
#include "Component.h"
#include "Math/Math.h"
class Camera : public Component
{
public:

	/// 投影类型
	enum class  Projection {
		Perspective, Orthographic
	};
	enum class ClearFlags {
		SolidColor,
		Depth,
		ColorAndDepth,
		Nothing
	};

	Camera();
	~Camera() override = default;

	const float getDepth() const;
	void  setDepth(float depth);
	const Vector4 getViewport() const;
	void setViewport(const Vector4& rect);

	void setFOV(float fov);
	const float getFOV() const;

	void setAspect(float aspect);
	const float getAspect() const;

	void setNearClipPanle(float near);
	const float getNearClipPanle() const;

	void setFarClipPanle(float far);
	const float getFarClipPanle() const;

	void setProjection(Camera::Projection projection);
	const Camera::Projection getProjection() const;

	void setClearColor(const Color4f& color);
	const Color4f getClearColor() const;

	const Matrix4x4 getViewMatrix() const;
	const Matrix4x4 getProjectionMatrix() const;

	void setOrthoRect(Vector4 rect);
	const Vector4 getOrthoRect() const;

	void setClearFlag(ClearFlags rect);
	const ClearFlags getClearFlag() const;

private:
	float mDepth;
	float mFOV;
	float mAspect;
	float mNearClipPlane;
	float mFarClipPanle;
	Vector4 mViewport;
	Vector4 mOrthoRect;
	Camera::Projection mProjectionType;
	Color4f mClearColor;
	ClearFlags mClearFlag;
};

using CameraPtr = std::shared_ptr<Camera>;