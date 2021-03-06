#ifndef MODEL_H
#define MODEL_H
#include <QtGui/QOpenGLFunctions_4_3_Core>
#include <QtGui/QOpenGLVertexArrayObject>
#include <QtGui/QOpenGLBuffer>
#include <QtGui/QOpenGLShader>
#include <QtGui/QOpenGLShaderProgram>
#include <QVector>
#include <QVector3D>
#include <QFileInfo>
#include <QDebug>
#include <QString>
#include <QtCore/QString>
#include <QtCore/QVector>

#include <math.h>

#include "point3d.h"

class Model
{
public:
	Model() {}
	Model(const QString &filePath, int s, Point3d p);

	void Paint(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix);

	QString fileName() const { return m_fileName; }
	int faces() const { return m_pointIndices.size() / 3; }
	int edges() const { return m_edgeIndices.size() / 2; }
	int points() const { return m_points.size(); }
	void Init();
	void InitVAO();
	void InitVBO();
	void InitShader(QString vertexShaderPath, QString fragmentShaderPath);
private:
	QOpenGLShaderProgram * shaderProgram;
	QOpenGLShader* vertexShader;
	QOpenGLShader* fragmentShader;
	QOpenGLVertexArrayObject vao;
	QOpenGLBuffer vvbo;
	QOpenGLBuffer cvbo;

	QString m_fileName;
	QVector<Point3d> m_points;
	QVector<Point3d> m_normals;
	QVector<int> m_edgeIndices;
	QVector<int> m_pointIndices;
	QVector<QVector3D> vertices;
	QVector<QVector3D> normals;
};

#endif