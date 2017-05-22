#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 posWorldspace;
in vec3 normalCameraspace; //normal in camera space
in vec3 eyeDirectionCameraspace; // eye direction in camera space
in vec3 lightDirectionCameraspace; // light direction in camera space

// Ouput data
out vec4 color;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 lightPosWorldspace;

// Light emission properties
uniform vec4 diffuseColor;
uniform vec4 ambientColor;
uniform vec4 specularColor;

vec3 ambientLightColor = vec3(1.0); //find these somehow - these will just be replaced! right??
vec3 diffuseLightColor = vec3(1.0);
vec3 specularLightColor = vec3(1.0);

uniform float opacity;
uniform float shininess;
uniform float renderMode; //depending on this number, change what we do to the color.

//Method which applies a sepia tone filter to the object.
vec4 SepiaFilter(in vec4 color){
   // sepiaR = color.rgb * 0.393; //integer value?
   // int sepiaR = color.r * 0.393;
    
    return vec4(
    clamp(color.r * 0.393 + color.g * 0.769 + color.b * 0.189, 0.0, 1.0) //makes a vec4
    , clamp(color.r * 0.349 + color.g * 0.686 + color.b * 0.168, 0.0, 1.0)
    , clamp(color.r * 0.272 + color.g * 0.534 + color.b * 0.131, 0.0, 1.0)
    , color.a
    );
}

void main(){
    
    
    // Material properties
    vec3 textureVal = texture(myTextureSampler, UV).rgb;  //texture map will be used for diffuse and ambient texture map, converts
    //the vec4 into a vec3!!

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
    float cosTheta = clamp( dot( N,L), 0.0, 1.0 );
    
    // Eye vector (towards the camera)
    vec3 E = normalize(eyeDirectionCameraspace);
    // Direction in which the triangle reflects the light
    vec3 R = reflect(-L,N);
    
    // Cosine of the angle between the Eye vector and the Reflect vector,
    // The cosine is clamped to contrain it between 0 and 1 to avoid negative values
    //  - Looking into the reflection -> 1
    //  - Looking elsewhere -> < 1
    
    //Halfway vector for Blinn-Phong model
    vec3 H = normalize(L+E);
    float cosAlpha = clamp( dot( H, N ), 0, 1);

   vec3 diffuseComponent = diffuseColor.rgb * diffuseLightColor * textureVal * cosTheta;
   vec3 ambientComponent = ambientColor.rgb * ambientLightColor *  textureVal; //for simplification we reuse the diffuse texture map for the ambient texture map
   vec3 specularComponent = specularColor.rgb * specularLightColor * pow(cosAlpha, shininess);
   color.rgb = ambientComponent.rgb + diffuseComponent.rgb+ specularComponent.rgb;
   color.a = opacity;
   
   if(renderMode == 2){
       //apply some filter in here!
       //color.rgb = vec3(1,0,0);
       color = SepiaFilter(color);
   }


}



