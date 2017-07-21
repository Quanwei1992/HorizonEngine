#include "stdafx.h"
#include "Application.h"
#include <typeinfo>

Application::Application()
{
}

Application::~Application()
{
}

void Application::init()
{
	mLogSystem = std::make_shared<LogSystem>();
	mRenderSystem = std::make_shared<RenderSystem>();
	mSceneSystem = std::make_shared<SceneSystem>();

	mLogSystem->startUp();
	mRenderSystem->startUp();
	mSceneSystem->startUp();
}

void Application::run()
{

	mLogSystem->log(typeid(this).name());
	
	//auto scene = mSceneSystem->getScene();
	//if (auto s = scene.lock()) {
	//	s->createGameObject();
	//}

	auto renderWindow = mRenderSystem->getRenderWindow();

	// 创建VertexData
	// 创建VAO
	float vertices[] = {
		0.5f, 0.5f, 0.0f,   // 右上角
		0.5f, -0.5f, 0.0f,  // 右下角
		-0.5f, -0.5f, 0.0f, // 左下角
		-0.5f, 0.5f, 0.0f   // 左上角
	};

	unsigned int indices[] = { // 注意索引从0开始! 
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	GLVertexArrayObjectPtr vao = std::make_shared<GLVertexArrayObject>();
	GLBufferPtr vbo = std::make_shared<GLBuffer>(GL_ARRAY_BUFFER);
	vbo->write(sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLBufferPtr ebo = std::make_shared<GLBuffer>(GL_ELEMENT_ARRAY_BUFFER);
	ebo->write(sizeof(indices),indices,GL_STATIC_DRAW);

	vao->setIndicesBuffer(ebo);
	vao->addVertexAttrib(0, "Position", vbo, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	vao->apply();
	VertexDataPtr data = std::make_shared<VertexData>(vao,true,GL_UNSIGNED_INT,6,3);

	// 创建Program
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	GLShaderPtr vsShader = std::make_shared<GLShader>(GL_VERTEX_SHADER);
	vsShader->setSource(vertexShaderSource);
	vsShader->compile();
	GLShaderPtr fsShader = std::make_shared<GLShader>(GL_FRAGMENT_SHADER);
	fsShader->setSource(fragmentShaderSource);
	fsShader->compile();
	GLProgramPtr program = std::make_shared<GLProgram>();
	program->attachShader(vsShader);
	program->attachShader(fsShader);
	program->link();
	if (!program->getLinkStatus()) {
		getLogSystem()->log("Program link failed.\n" + program->getProgramInfoLog());
	}
	// 创建RenderOperation.
	RenderOperationPtr op = std::make_shared<RenderOperation>(RenderOperation::OperationType::TriangleList,data);

	// 设置视口,矩阵等.
	mRenderSystem->setViewport(0, 0, 800, 600);
	// 设置Program.
	mRenderSystem->setProgram(program);
	// 

	while (!renderWindow->shouldClose())
	{
		renderWindow->pollEvents();
		mRenderSystem->render(op);
		renderWindow->swapBuffers();
	}
}

void Application::shutdown()
{
	if(mRenderSystem)mRenderSystem->shutDown();
	if (mLogSystem)mLogSystem->shutDown();
	if (mSceneSystem)mSceneSystem->shutDown();
}

std::shared_ptr<LogSystem> Application::getLogSystem()
{
	return mLogSystem;
}

std::shared_ptr<SceneSystem> Application::getSceneSystem()
{
	return mSceneSystem;
}

