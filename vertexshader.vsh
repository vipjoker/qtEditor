attribute highp vec4  vertexAttr;
uniform mediump mat4 matrix;
uniform mediump mat4 view_matrix;
uniform mediump mat4 model_matrix;
uniform lowp vec4 u_color;
varying lowp vec4 color;

void main()
{
    gl_Position = matrix * model_matrix * view_matrix * vertexAttr;
    color = u_color;
}
