#include "gameplay.h"

using namespace::gameplay;
 



inline Node* getManualCamera()
{
	Node* cameraNode = Node::create("Camera");

	cameraNode->setTranslationX(3);
	cameraNode->setTranslationY(5);
	cameraNode->setTranslationZ(10);

	Matrix roationMatrix;
	Quaternion Test(-0.142, 0.126, 0, 1);
	Matrix::createRotation(Test, &roationMatrix);
	cameraNode->setRotation(roationMatrix);

	Camera* cam = cameraNode->getCamera();

	cam = Camera::createPerspective(0, 0, 0, 0);

	float camMatrix[4][4];
	Matrix projectionMatrix(camMatrix[0][0], camMatrix[1][0], camMatrix[2][0], camMatrix[3][0],
		camMatrix[0][1], camMatrix[1][1], camMatrix[2][1], camMatrix[3][1],
		camMatrix[0][2], camMatrix[1][2], -camMatrix[2][2], -camMatrix[3][2],
		camMatrix[0][3], camMatrix[1][3], camMatrix[2][3], camMatrix[3][3]);

	cam->setProjectionMatrix(projectionMatrix);
	cam->resetProjectionMatrix();


	cam->setNearPlane(0.25);
	cam->setFarPlane(100);
	cam->setFieldOfView(27);

	cameraNode->setCamera(cam);
	return cameraNode;
}

struct Vertex
{
	Vector3 pos;
	Vector3 norm;
	Vector2 UV;
};

inline Model* getManualModel()
{
	VertexFormat::Element elements[] = {
		VertexFormat::Element(VertexFormat::POSITION, 3),
		VertexFormat::Element(VertexFormat::NORMAL, 3),
		VertexFormat::Element(VertexFormat::TEXCOORD0, 2)
	};
	int numVertecies = 3;

	
	Vector3 one(1, 0, 0);
	Vector3 two(1, 3, 0);
	Vector3 three(0, 0, 0);
	Vector3 four(0, 3, 0);


	Vertex triangle[6];

	Vertex temp1;
	temp1.pos = Vector3(1, 0, 0);
	temp1.norm = Vector3(0, 1, 0);
	temp1.UV = Vector2(0, 0);

	triangle[0] = temp1;

	Vertex temp2;
	temp2.pos = Vector3(1, 3, 0);
	temp2.norm = Vector3(0, 1, 0);
	temp2.UV = Vector2(0, 0);

	triangle[1] = temp2;

	Vertex temp3;
	temp3.pos = Vector3(0, 0, 0);
	temp3.norm = Vector3(0, 1, 0);
	temp3.UV = Vector2(0, 0);

	triangle[2] = temp3;

	Vertex temp4;
	temp3.pos = Vector3(0, 3, 0);
	temp3.norm = Vector3(0, 1, 0);
	temp3.UV = Vector2(0, 0);

	triangle[3] = temp4;

	Vertex temp5;
	temp3.pos = Vector3(0, 0, 0);
	temp3.norm = Vector3(0, 1, 0);
	temp3.UV = Vector2(0, 0);

	triangle[4] = temp5;

	Vertex temp6;
	temp1.pos = Vector3(1, 0, 0);
	temp1.norm = Vector3(0, 1, 0);
	temp1.UV = Vector2(0, 0);

	triangle[5] = temp6;


	const VertexFormat vertFormat(elements, numVertecies);

	Mesh* mesh = Mesh::createMesh(vertFormat, numVertecies, false);
	mesh->setPrimitiveType(Mesh::TRIANGLE_STRIP);
	mesh->setVertexData(triangle);

	Model* model = Model::create(mesh);
	return model;
	
}