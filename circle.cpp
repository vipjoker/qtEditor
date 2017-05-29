#include "circle.h"
#include <QColor>
Circle::Circle(QOpenGLShaderProgram *program,int vertexAtr,int colorAttr,int modelMatrixAttr):
    m_program(program),m_vertexAttr(vertexAtr),m_colorAttr(colorAttr),m_modelMatrixAttr(modelMatrixAttr)
{
    initVertices();

}

void Circle::initVertices(){
    m_vertices.resize(12);
    int segments = 32;
    int radius = 20;
    m_vertices.push_back(0);
    m_vertices.push_back(0);
    for(int i = 0 ; i <= segments; i++){

        float angle = (float)i/(float)segments * M_PI * 2;

        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        m_vertices.push_back(x);
        m_vertices.push_back(y);
    }


}

void Circle::draw(){
    static float angle = 0;
    m_program->setAttributeArray(m_vertexAttr,m_vertices.data(),2);

    QMatrix4x4 m;
   // m.translate(angle,0,0);

    m_program->setUniformValue(m_modelMatrixAttr,m);
    m_program->setUniformValue(m_colorAttr,QColor::fromRgb(0,0,125));

    m_program->enableAttributeArray(m_vertexAttr);


    glDrawArrays(GL_TRIANGLE_FAN,0,m_vertices.size()/2);
    m_program->setUniformValue(m_colorAttr,QColor::fromRgb(255,0,0));
    glDrawArrays(GL_LINE_STRIP,0,m_vertices.size()/2);
    angle+= 1;
    m_program->disableAttributeArray(m_vertexAttr);


}

Circle::~Circle(){

}

