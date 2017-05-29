#include "scene.h"





Scene::Scene(QWidget *parent) : QOpenGLWidget(parent)
{

    QSurfaceFormat format;
    format.setSamples(4);    // Set the number of samples used for multisampling
    setFormat(format);
    qDebug() << "Constructor works";
       counter = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateC()));


    timer -> start(1000/60);

}
    void Scene::initializeGL(){





        glClearColor(0.1f,0.1,0.2f,1.0f);

        QOpenGLShader vShader (QOpenGLShader::Vertex);
        vShader.compileSourceFile(":shaders/vertexshader.vsh");
        QOpenGLShader fShader (QOpenGLShader::Fragment);
        fShader.compileSourceFile(":shaders/fragmentshader.fsh");
        m_program.addShader(&vShader);
        m_program.addShader((&fShader));
        if(!m_program.link()){
            qWarning("Error: unable to link a shader program");
            return;
        }

        m_vertexAttr = m_program.attributeLocation("vertexAttr");
        m_colorAttr = m_program.uniformLocation("u_color");
        m_matricUniform = m_program.uniformLocation("matrix");
        m_viewMatrix = m_program.uniformLocation("view_matrix");
        int modelMatrix = m_program.uniformLocation("model_matrix");

        m_circle = new Circle(&m_program,m_vertexAttr,m_colorAttr,modelMatrix);

    }


    void Scene::paintGL(){

         glClear(GL_COLOR_BUFFER_BIT);



         if(!m_program.bind()){
             qDebug() << "Failed to bind program";
             return;
         }
         QMatrix4x4 matrix;
         matrix.ortho(-width()/2,width()/2,height()/2,-height()/2,2.0f,-2.0f);

         QMatrix4x4 viewMat;


       //  viewMat.translate(100.0f,0.0f,-1.0f);

         m_program.setUniformValue(m_matricUniform,matrix);
         m_program.setUniformValue(m_viewMatrix,viewMat);

         m_circle->draw();

         QPainterPath path;
         glDisable(GL_LIGHTING);
         QFont font("Arial", 400);
         path.addText(QPointF(0, 0), font, QString(tr("This is a test")));
         QList<QPolygonF> poly = path.toSubpathPolygons();
         for (QList<QPolygonF>::iterator i = poly.begin(); i != poly.end(); i++){
             glBegin(GL_LINES);
             for (QPolygonF::iterator p = (*i).begin(); p != i->end(); p++)
                 glVertex3f(p->rx()*0.1f, -p->ry()*0.1f, 0);
             glEnd();
         }


         m_program.release();
    }

     void Scene::mouseReleaseEvent(QMouseEvent *event){

         QPoint *point = translateToWidget(event);

         delete point;
     }



    QPoint *Scene::translateToWidget(QMouseEvent *event){

        QMatrix4x4 matrix;

        matrix.translate(-width()/2,-height()/2,0);

        QPoint p(event->x(),event->y());

        p = matrix * p;

        qDebug() << "x " << p.x()<< " y " << p.y() ;
        return new QPoint(p.x(),p.y());

    }
     void Scene::mousePressEvent(QMouseEvent *event){
        QPoint *point  =translateToWidget(event);


        delete point;
     }

     void Scene::mouseMoveEvent(QMouseEvent *event) {
        QPoint *point = translateToWidget(event);
        delete point;
     }

     void Scene::updateC(){
         update();
         qint64 time = QDateTime::currentMSecsSinceEpoch();
       //  qDebug() << "update" << time;
     }

     void Scene::drawCircle()
     {
         qDebug() << "draw circle";

     }

     void Scene::drawPolygon()
     {
        qDebug() << "draw polygon";
     }

     void Scene::drawPolyline()
     {
        qDebug() << "draw polyline";
     }

    void Scene::resizeGL(int width, int height){
       glViewport(0,0,width,height);
    }

    Scene::~Scene(){
        delete m_circle;
    }

