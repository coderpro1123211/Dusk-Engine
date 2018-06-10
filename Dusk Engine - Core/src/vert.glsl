uniform mat4 DUSK_MATRIX_MVP;

void main()
{
	gl_Position = DUSK_MATRIX_MVP * gl_Vertex;
}