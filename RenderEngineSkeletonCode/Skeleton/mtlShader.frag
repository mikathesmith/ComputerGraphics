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

// Light emission properties
uniform vec4 diffuseColor;
uniform vec4 ambientColor;
uniform vec4 specularColor;

const float ns = 1.0; //specular exponent

//Do I have to do this for each light? 
void main(){
    
    // Material properties
    vec3 textureVal = texture(myTextureSampler, UV).rgb;  //texture map will be used for diffuse and ambient texture map, converts
    //the vec4 into a vec3!!
    vec3 ambientMatColor = vec3(0.6,0.6,0.6); //find these somehow - these will just be replaced! right??
    vec3 diffuseMatColor = vec3(1.0,1.0,1.0);
    vec3 specularMatColor = vec3(0.3,0.3,0.3);
  
    
    // Distance to the light we could use this to diminish the amount of light the further away but we do not for simplification
    float distance = length( lightPosWorldspace - posWorldspace );
    
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
    
    // Eye vector (towards the camera)
    vec3 E = normalize(eyeDirectionCameraspace);
    // Direction in which the triangle reflects the light
    vec3 R = reflect(-L,N);
    
    // Cosine of the angle between the Eye vector and the Reflect vector,
    // The cosine is clamped to contrain it between 0 and 1 to avoid negative values
    //  - Looking into the reflection -> 1
    //  - Looking elsewhere -> < 1
    float cosAlpha = clamp( dot( E,R ), 0,1 );
    
    vec3 diffuseComponent = diffuseColor.rgb * diffuseMatColor * textureVal * cosTheta;
    vec3 ambientComponent = ambientColor.rgb * ambientMatColor *  textureVal; //for simplification we reuse the diffuse texture map for the ambient texture map
    vec3 specularComponent = specularColor.rgb * specularMatColor * pow(cosAlpha, ns);
    
    color.rgb = ambientComponent.rgb + diffuseComponent.rgb + specularComponent.rgb;
    //color.a = transparency - need to enable blending using glEnable and GL_BLEND, and
    //setting up the way to use blend by using glBlendFunc - GL_SRC_ALPHA, GL_ONE_MINUS
    //_SRC_ALPHA? - use AI_MATKEY_OPACITY
    
    
}



