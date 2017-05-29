#include "triangle.h"
#include <QColor>
Triangle::Triangle(QOpenGLShaderProgram *program,int vertexAttr,int colorAttr,int modelMatrixAttr):
    m_program(program),m_vertexAttr(vertexAttr),m_colorAttr(colorAttr),m_modelMatrixAttr(modelMatrixAttr),isEditing(false)
{
    initVertices();
    initColors();
}

void Triangle::draw()
{
    m_program->setAttributeArray(m_vertexAttr,m_vertices.data(),2);
    m_program->setAttributeArray(m_colorAttr,m_colors.data(),3);

    QMatrix4x4 m;
    m_program->setUniformValue(m_modelMatrixAttr,m);
    m_program->setUniformValue(m_colorAttr,QColor::fromRgb(225,135,125));

    m_program->enableAttributeArray(m_vertexAttr);

    glLineWidth(4);
    glDrawArrays(GL_TRIANGLE_FAN,0,m_vertices.size()/2);

    m_program->setUniformValue(m_colorAttr,QColor::fromRgb(255,255,0));
    glDrawArrays(GL_LINE_LOOP,0,m_vertices.size()/2);

    m_program->disableAttributeArray(m_vertexAttr);

}

void Triangle::initVertices()
{

    addPoint(-50.0f,-50.0f);
    addPoint(50.0f,-50.0f);
    addPoint(0.0f,50.0f);
           
}

void Triangle::initColors()
{
    m_colors.resize(9);
    m_colors[0] = 0.0f;
    m_colors[1] = 1.0f;
    m_colors[2] = 0.0f;

    m_colors[3] = 0.0f;
    m_colors[4] = 1.0f;
    m_colors[5] = 0.0f;

    m_colors[6] = 0.0f;
    m_colors[7] = 1.0f;
    m_colors[8] = 0.0f;
}

void Triangle::addPoint(int x, int y)
{
    qDebug() << "added x = " << x << " y " << y;
    m_vertices.push_back(x);
    m_vertices.push_back(y);
}

void Triangle::addPoint(QPoint *point)
{
    addPoint(point->x(),point->y());
}
