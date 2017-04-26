#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
void main(){
//incoming vertices are multiplied with the MVP matrix that is passed to the shader. 

    gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
    
    //this is a GLSL builtin variable - contains the clip-space output position of the current vertex that is then passed to the fragment shader. 
}

