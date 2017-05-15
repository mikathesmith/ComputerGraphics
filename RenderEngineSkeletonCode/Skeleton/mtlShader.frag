#version 330 core

// Interpolated values from the vertex shaders
// e.g.
//in vec2 UV;
/*in vec2 UV; 
in vec3 posWorldspace; 
in vec3 normalCameraspace; 
in vec3 eyeDirectionCameraspace;
in vec3 lightDirectionspace; */ 

// Ouput data
out vec4 color;

// Values that stay constant for the whole mesh.
uniform vec4 diffuseColor;
uniform vec4 ambientColor;
uniform vec4 specularColor;

/*uniform sampler2D myTextureSampler; 
uniform mat4 MV;
uniform vec3 lightPosWorldSpace; */ 

void main(){
	
	// Material properties
	//TODO: compute light model here
 //   color.rgb = diffuseColor.rgb;
  //  color.a = 1.0;
    
    //Material properties 
  //  vec3 textureVal = texture( myTextureSampler, UV ).rgb;  //texture map will be used for diffuse and ambient texture map
//	vec3 ambientMatColor = vec3(0.6,0.6,0.6);
//	vec3 diffuseMatColor = vec3(1.0,1.0,1.0);
//	vec3 specularMatColor = vec3(0.3,0.3,0.3);
	
  //Work in camera space, normal of the computed fragment in camera space. 
  vec3 N = normalize(normalCameraSpace);
  vec3 L = normalize(lightDirectionCameraSpace); //Direction of the light in camera space 
  
  float cosTheta = clamp(dot(N,L), 0,1);
  
  //Eye vector towards the camera
  vec3 E = normalize(eyeDirectionCameraspace);
  
  //Direction in which the triangle reflects the light 
  vec3 R = reflect(-L,N);

  float cosAlpha = clamp(dot(E,R),0,1);
  
  vec3 diffuseComponent = diffuseLightColor* diffuseMatColor * textureVal * cosTheta;
	vec3 ambientComponent = ambientLightColor * ambientMatColor * textureVal; //for simplification we reuse the diffuse texture map for the ambient texture map
    vec3 specularComponent = specularLightColor * specularMatColor  * pow(cosAlpha,ns);

  color = ambientCoponent + diffuseComponent + specularComponent; 

}
