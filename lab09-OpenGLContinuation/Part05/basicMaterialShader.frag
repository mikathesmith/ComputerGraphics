#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 posWorldspace;
in vec3 normalCameraspace; //normal in camera space
in vec3 eyeDirectionCameraspace; // eye direction in camera space
in vec3 lightDirectionCameraspace; // light direction in camera space

// Ouput data
out vec3 color;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 lightPosWorldspace;
uniform vec3 diffuseLightColor;

const float ns = 6.0; //specular exponent

// Light emission properties
const vec3 ambientLightColor = vec3(0.4,0.4,0.4);
const vec3 specularLightColor = vec3(1.0,1.0,1.0);


//comptes the Phong reflection model, describing the reflection of light from a surface as a combination of diffuse reflection, ambient reflection and specular reflection.

void main(){
	
	
	// Material properties
	vec3 textureVal = texture( myTextureSampler, UV ).rgb;  //texture map will be used for diffuse and ambient texture map
	vec3 ambientMatColor = vec3(0.6,0.6,0.6);
	vec3 diffuseMatColor = vec3(1.0,1.0,1.0);
	vec3 specularMatColor = vec3(0.3,0.3,0.3);
	
	// Distance to the light we could use this to diminish the amount of light the further away but we do not for simplification
	//float distance = length( lightPosWorldspace - posWorldspace );
	
	// We now work in camera space
	// Normal of the computed fragment, in camera space
	vec3 N = normalize( normalCameraspace );
	// Direction of the light (from the fragment to the light) in camera space
	vec3 L = normalize( lightDirectionCameraspace );
	
	// We use the cosine of the angle theta between the normal and the light direction to compute the diffuse component.
	// The cosine is clamped to contrain it between 0 and 1
	//  - light is at the vertical of the triangle -> 1
	//  - light is perpendicular to the triangle -> 0
	//  - light is behind the triangle -> 0
	float cosTheta = clamp( dot( N,L), 0,1 );
	
    //The diffuse component describes all light that is reflexected in all directions when light hits a surface. The reflected light depends on the angle theta between the incoming light ray L and the surface normal N, as well as on the diffuse material colour kd, the diffuse texture map and the colour of the light Id. When computing the angle between the light direction and the normal, we have to clamp the angle to 0, to avoid light that comes from behind the surface.
    
    
    
	// Eye vector (towards the camera)
	vec3 E = normalize(eyeDirectionCameraspace);
	// Direction in which the triangle reflects the light
	vec3 R = reflect(-L,N);
	
	// Cosine of the angle between the Eye vector and the Reflect vector,
	// The cosine is clamped to contrain it between 0 and 1 to avoid negative values
	//  - Looking into the reflection -> 1
	//  - Looking elsewhere -> < 1
	float cosAlpha = clamp( dot( E,R ), 0,1 );
	
    vec3 diffuseComponent = diffuseLightColor* diffuseMatColor * textureVal * cosTheta;
	vec3 ambientComponent = ambientLightColor * ambientMatColor * textureVal; //for simplification we reuse the diffuse texture map for the ambient texture map.
    //Ambient component of the phong reflection model defines a minimum brightness and prevents the surface from being completely black. It creates an effect that lets the surface simply emit light. We multiply the colour value from the texture as well.
    
    //Specular component describes behaviour of shiny surfaces. Instead of light being reflected in all directions, the specular component describes the amount of light that is reflected from a surface in the direction of the reflection vector. According to the law of reflection, the reflection vector has the same angle to the surface normal as the incident ray
    vec3 specularComponent = specularLightColor * specularMatColor  * pow(cosAlpha,ns);
    
	color =
	// Ambient : simulates indirect lighting
	ambientComponent + 
	// Diffuse : "color" of the object
	diffuseComponent +
	// Specular : reflective highlight, like a mirror
	specularComponent;
	

}


