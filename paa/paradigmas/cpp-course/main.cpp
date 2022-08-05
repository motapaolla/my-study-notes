#include<iostream>  // fazer stream de dados input e output
#include<string>  // tipo de dados customizado


// std: pacotão de código e outros utilitarios

int main(int argc, char** argv) {
	
	int x;
	// Input e output
	std::cout << "Hello world\n";
	std::cin >> x;

	// Tipos padrões: int, char, float, double (float com mais precisão), bool
	float myFloat = 0.0f;  // tem que colcoar o f no final se não vai pensar que é double
	int myInt = -10;
	bool myBool = false;
	char myChar = 'c';  // Um só caractere

	// Outros tipos combinando os padrões
	size_t mySizeT = 0;  // tamanhos de coisa. Não tem valores negativos, qtd de valores que consegue representar é diferente
	unsigned int myUint = 1; // int que não pode ser negativo
	int myArray[5] = {1,2,3,4,5}  // array normal
	char myString[11] = "0123456789";  // como se faz uma string (ultimo caractere é sempre o \0 viu!)

	// Tipos incluidos de libs
	std::string myString = "Teste"; // string que veio da biblioteca chamada lá em cima 
	int 


	// Operadores de atribuição
	// +=, -=, *=, /=, var++, var--

	// Operador condicional
	if (myInt >= 0) {
		// algo
	} else if {
		// algo
	} else {
		// algo
	}

	// Operador comparador
	// && || 

	// Loops
	while (true) {
		break;
	}

	for (int i=0; i<10; i++){
		break;
	}

	// Array manipulation
	myArray[1] = 0;  // atribuição manual em um array

	for (int i=0; i<10; i++){  // printando o array
		std::cout << myArray[i] << '\n';  // detalhe: se tentar acessar uma posição que não existe no array dá erro de memória
	}

	return 0;
}



// Funções
<tipo da saida> nomeDaFuncao (<tipo da variavel de entrada> variavel) {
	return 0;
}

nomeDaFuncao();  // chama no codigo

// OBS: Passar a variavel por referencia, usa o & na variavel no argumento da funcao. 
// Fazer isso faz com que mude o valor da variavel que é passada na função.

// Vetores

	// // Lib
	// #include<vector>

	// // Declaração:
	// vector<object_type> vector_variable_name;
	// vector<object_type> vector_name (number_of_repetition, element_value);   // This method is used to populate a vector with multiple times the same value.
	// vector<object_type> vector_name {val1,val2,val3,....,valn};  // Se quiser já passar um parametro

	// // Métodos:
 //    begin() –  It returns an iterator pointing to the first element in the vector.
 //    end() – It returns an iterator pointing to the last element in the vector.
 //    rbegin() – It returns a reverse iterator pointing to the last element in the vector.
 //    rend() – It returns a reverse iterator pointing to the element preceding the first element in the vector. Basically considered as a reverse end.
 //    cbegin() – It returns a constant iterator pointing to the first element in the vector.
 //    cend() – It returns a constant iterator pointing to the element that follows the last element in the vector.
 //    crbegin() – It returns a constant reverse iterator pointing to the last element in the vector.
 //    crend() – It returns a constant reverse iterator pointing to the element preceding the first element in the vector.

 //    size() – It returns the number of elements currently present in the vector.
 //    max_size() – It returns the maximum number of elements that a vector can hold.
 //    capacity() – It returns the storage capacity currently allocated to the vector.
 //    resize(n) – It resizes the container to store ‘n’ elements.
 //    empty() – It returns whether the container is empty or not.

 //    assign() – It assigns a new value to the existing elements of the vector.
 //    push_back() – It pushes the element from back in the vector.
 //    pop_back() – It removes elements from the back of the vector.
 //    insert() – It inserts an element before a specified element in the vector.
 //    erase() – It is used to remove elements from a specified element or a range in the vector.
 //    swap() – It is used to swap the contents of two vectors of the same datatype. The sizes of vectors may differ.
 //    clear() – It is used to remove all the elements from the vector.

 //    reference_operator[g]: It returns a reference to the ‘g’ element in the vetor.
 //    at(g): It returns a reference to the element at position ‘g’ in the vector.
 //    front(): It returns a reference to the first element in the vector.
 //    back(): It returns a reference to the last element in the vector.
 //    data(): It returns a direct pointer to the memory array which is used internally by the vector to store its owned elements.
// https://www.mygreatlearning.com/blog/vectors-in-c/


// Matrizes


