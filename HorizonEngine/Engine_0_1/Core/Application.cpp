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

	// ����VertexData
	// ����VAO
	float vertices[] = {
		0.5f, 0.5f, 0.0f,   // ���Ͻ�
		0.5f, -0.5f, 0.0f,  // ���½�
		-0.5f, -0.5f, 0.0f, // ���½�
		-0.5f, 0.5f, 0.0f   // ���Ͻ�
	};

	unsigned int indices[] = { // ע��������0��ʼ! 
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
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

	// ����Program
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
	// ����RenderOperation.
	RenderOperationPtr op = std::make_shared<RenderOperation>(RenderOperation::OperationType::TriangleList,data);

	// �����ӿ�,�����.
	mRenderSystem->setViewport(0, 0, 800, 600);
	// ����Program.
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

