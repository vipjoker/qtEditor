#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>
#include <QOpenGLShaderProgram>
#include <QPoint>
#include <QMatrix4x4>
#include <QDebug>
class Triangle
{
public:
    Triangle(QOpenGLShaderProgram *program,int vertexAtr,int colorAttr,int modelMatrix);
    void draw();
    void addPoint(int x ,int y);
    void addPoint(QPoint *point);
    void updateLastPoint(QPoint *point);
private:
    bool isEditing;
    std::vector<float> m_vertices;
    std::vector<float> m_colors;
    void initVertices();
    void initColors();

    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_colorAttr;
    int m_modelMatrixAttr;


};

#endif // TRIANGLE_H
