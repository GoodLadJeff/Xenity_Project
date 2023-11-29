//-------------- {pc}
//-------------- {vertex}

#version 330 core

layout (location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 camera;
uniform mat4 projection;

uniform mat4 model; //Model matrice position, rotation and scale

void main()
{
	gl_Position = projection * camera * model * vec4(position, 1);
	TexCoord = uv;
}

//-------------- {fragment}

#version 330 core

out vec4 FragColor;
uniform vec3 color;
uniform vec3 cameraPos;

in vec2 TexCoord;

struct Material {
	sampler2D diffuse;
	vec3 ambient;
};

uniform Material material;

void main()
{
	// Ambient

	vec3 ambient = color * vec3(texture(material.diffuse, TexCoord)); //Get ambient intensity and color

	//Result
	vec3 result = ambient; //Set face result

	float alpha = texture(material.diffuse, TexCoord).a;
	FragColor = vec4(result, alpha); //Add texture color
}

//-------------- {psvita}
//-------------- {vertex}

attribute vec3 position;
attribute vec2 uv;
attribute vec3 normal;

varying vec2 TexCoord;
varying vec3 Normal;
varying vec3 FragPos;

uniform mat4 camera;
uniform mat4 projection;

uniform mat4 model; //Model matrice position, rotation and scale

void main()
{
	//gl_Position = projection * camera * model * vec4(position, 1);
	gl_Position = mul(float4(position, 1.0f), mul(model, mul(camera, projection)));
	TexCoord = uv;
}

{fragment}

uniform vec3 color;

varying vec2 TexCoord;

struct Material {
	sampler2D diffuse;
	vec3 ambient;
};

uniform Material material;

void main()
{
	// Ambient

	vec3 ambient = color * vec3(tex2D(material.diffuse, TexCoord)); //Get ambient intensity and color

	//Result
	vec3 result = ambient; //Set face result

	float alpha = tex2D(material.diffuse, TexCoord).a;
	gl_FragColor = vec4(result, alpha); //Add texture color
}