#ifndef CIRCLE_H
#define CIRCLE_H
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include<vector>
#include<math.h>

class Circle
{
public:

    Circle(QOpenGLShaderProgram *program,int vertexAtr,int colorAttr,int modelMatixAttr);
    void draw();

    ~Circle();

private:
    void initVertices();
    std::vector<float> m_vertices;
    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_colorAttr;
    int m_modelMatrixAttr;

};

#endif // CIRCLE_H
