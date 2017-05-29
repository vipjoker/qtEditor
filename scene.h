#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include "triangle.h"
#include "circle.h"
#include <QDebug>
#include <QTimer>
#include <QList>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QPoint>

#include <QDateTime>
class Scene : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = 0);
    ~Scene();
protected:
    int counter ;
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    QPoint *translateToWidget(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    QList list;
    Circle *m_circle;
    QOpenGLShaderProgram m_program;
    QTimer *timer;
    int m_vertexAttr;
    int m_colorAttr;
    int m_matricUniform;
    int m_viewMatrix;
signals:

public slots:
    void updateC();
    void drawCircle();
    void drawPolygon();
    void drawPolyline();
};

#endif // MYOPENGLWIDGET_H
