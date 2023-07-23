#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

// Algoritmo de ordenamiento Selection Sort (ascendente)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}

// Algoritmo de ordenamiento Selection Sort (descendente)
void selectionSortDesc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int max_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            swap(arr[i], arr[max_index]);
        }
    }
}

// Algoritmo de ordenamiento Bubble Sort (ascendente)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Algoritmo de ordenamiento Bubble Sort (descendente)
void bubbleSortDesc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Algoritmo de ordenamiento Insertion Sort (ascendente)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Algoritmo de ordenamiento Insertion Sort (descendente)
void insertionSortDesc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Algoritmo de ordenamiento Shell Sort (ascendente)
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            
            arr[j] = temp;
        }
    }
}

// Algoritmo de ordenamiento Shell Sort (descendente)
void shellSortDesc(vector<int>& arr) {
    int n = arr.size();
    
    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            
            while (j >= gap && arr[j - gap] < temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            
            arr[j] = temp;
        }
    }
}

// Función para combinar dos sub-arreglos ordenados en un solo arreglo ordenado (ascendente)
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int left_index = 0;
    int right_index = 0;
    int arr_index = low;

    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] <= right[right_index]) {
            arr[arr_index++] = left[left_index++];
        } else {
            arr[arr_index++] = right[right_index++];
        }
    }

    while (left_index < left.size()) {
        arr[arr_index++] = left[left_index++];
    }

    while (right_index < right.size()) {
        arr[arr_index++] = right[right_index++];
    }
}

// Función para combinar dos sub-arreglos ordenados en un solo arreglo ordenado (descendente)
void mergeDesc(vector<int>& arr, int low, int mid, int high) {
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int left_index = 0;
    int right_index = 0;
    int arr_index = low;

    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] >= right[right_index]) {
            arr[arr_index++] = left[left_index++];
        } else {
            arr[arr_index++] = right[right_index++];
        }
    }

    while (left_index < left.size()) {
        arr[arr_index++] = left[left_index++];
    }

    while (right_index < right.size()) {
        arr[arr_index++] = right[right_index++];
    }
}

// Algoritmo de ordenamiento Merge Sort (ascendente)
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Algoritmo de ordenamiento Merge Sort (descendente)
void mergeSortDesc(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSortDesc(arr, low, mid);
        mergeSortDesc(arr, mid + 1, high);
        mergeDesc(arr, low, mid, high);
    }
}

// Función auxiliar para Quick Sort con recursión en cola
void quickSortTailRecursive(vector<int>& arr, int low, int high) {
    while (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pivot_index = i + 1;

        if (pivot_index - low < high - pivot_index) {
            quickSortTailRecursive(arr, low, pivot_index - 1);
            low = pivot_index + 1;
        } else {
            quickSortTailRecursive(arr, pivot_index + 1, high);
            high = pivot_index - 1;
        }
    }
}

// Algoritmo de ordenamiento Quick Sort con recursión en cola (ascendente)
void quickSortTailRecursive(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    quickSortTailRecursive(arr, low, high);
}

// Función auxiliar para Quick Sort con recursión en cola (descendente)
void quickSortTailRecursiveDesc(vector<int>& arr, int low, int high) {
    while (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arr[j] > pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pivot_index = i + 1;

        if (pivot_index - low < high - pivot_index) {
            quickSortTailRecursiveDesc(arr, low, pivot_index - 1);
            low = pivot_index + 1;
        } else {
            quickSortTailRecursiveDesc(arr, pivot_index + 1, high);
            high = pivot_index - 1;
        }
    }
}

// Algoritmo de ordenamiento Quick Sort con recursión en cola (descendente)
void quickSortTailRecursiveDesc(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    quickSortTailRecursiveDesc(arr, low, high);
}

// Función para ajustar un subárbol en un heap binario (orden ascendente)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] > arr[largest]) {
        largest = left_child;
    }

    if (right_child < n && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Algoritmo de ordenamiento Heap Sort (ascendente)
void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

// Función para ajustar un subárbol en un heap binario (orden descendente)
void heapifyDesc(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] < arr[smallest]) {
        smallest = left_child;
    }

    if (right_child < n && arr[right_child] < arr[smallest]) {
        smallest = right_child;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyDesc(arr, n, smallest);
    }
}

// Algoritmo de ordenamiento Heap Sort (descendente)
void heapSortDesc(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapifyDesc(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {

        swap(arr[0], arr[i]);

        heapifyDesc(arr, i, 0);
    }
}

void addUniqueRandomValues(vector<int>& arr) {
    int n = arr.size();
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> value_distribution(1, n);

    unordered_set<int> unique_values;

    for (int i = 0; i < n; ++i) {
        int value = value_distribution(generator);

        // Asegurarse de que el valor sea único
        while (unique_values.count(value) > 0) {
            value = value_distribution(generator);
        }

        arr[i] = value;
        unique_values.insert(value);
    }
}


// Función para agregar valores aleatorios al arreglo (permitiendo repeticiones)
void addRandomValues(vector<int>& arr) {
    int n = arr.size();
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> value_distribution(1, n);

    for (int i = 0; i < n; ++i) {
        arr[i] = value_distribution(generator);
    }
}

// Función para agregar valores ordenados de menor a mayor al arreglo
void addSortedValues(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
}

// Función para agregar valores ordenados de mayor a menor al arreglo
void addReverseSortedValues(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr[i] = n - i;
    }
}

// Función para comparar los tiempos y encontrar el ganador
void compareTimes(duration<double> selectionSortTime, duration<double> bubbleSortTime, duration<double> insertionSortTime, duration<double> shellSortTime,
    duration<double> mergeSortTime, duration<double> quickSortTime, duration<double> heapSortTime) {
    
    // Imprimir los tiempos de ejecución de todos los algoritmos
    cout << "1. Selection Sort, " << selectionSortTime.count() << endl;
    cout << "2. Bubble Sort, " << bubbleSortTime.count() << endl;
    cout << "3. Insertion Sort, " << insertionSortTime.count() << endl;
    cout << "4. Shell Sort, " << shellSortTime.count() << endl;
    cout << "5. Merge Sort, " << mergeSortTime.count() << endl;
    cout << "6. Quick Sort, " << quickSortTime.count() << endl;
    cout << "7. Heap Sort, " << heapSortTime.count() << endl << endl;

    // Comprobar el ganador
    if (selectionSortTime <= bubbleSortTime && selectionSortTime <= insertionSortTime && selectionSortTime <= shellSortTime &&
        selectionSortTime <= mergeSortTime && selectionSortTime <= quickSortTime && selectionSortTime <= heapSortTime) {
        cout << "El ganador es: Selection Sort con un tiempo de " << selectionSortTime.count() << " segundos." << endl;
    } else if (bubbleSortTime <= insertionSortTime && bubbleSortTime <= shellSortTime &&
        bubbleSortTime <= mergeSortTime && bubbleSortTime <= quickSortTime && bubbleSortTime <= heapSortTime) {
        cout << "El ganador es: Bubble Sort con un tiempo de " << bubbleSortTime.count() << " segundos." << endl;
    } else if (insertionSortTime <= shellSortTime && insertionSortTime <= mergeSortTime && insertionSortTime <= quickSortTime &&
        insertionSortTime <= heapSortTime) {
        cout << "El ganador es: Insertion Sort con un tiempo de " << insertionSortTime.count() << " segundos." << endl;
    } else if (shellSortTime <= mergeSortTime && shellSortTime <= quickSortTime && shellSortTime <= heapSortTime) {
        cout << "El ganador es: Shell Sort con un tiempo de " << shellSortTime.count() << " segundos." << endl;
    } else if (mergeSortTime <= quickSortTime && mergeSortTime <= heapSortTime) {
        cout << "El ganador es: Merge Sort con un tiempo de " << mergeSortTime.count() << " segundos." << endl;
    } else if (quickSortTime <= heapSortTime) {
        cout << "El ganador es: Quick Sort con un tiempo de " << quickSortTime.count() << " segundos." << endl;
    } else {
        cout << "El ganador es: Heap Sort con un tiempo de " << heapSortTime.count() << " segundos." << endl;
    }
}

int main() {
	
	auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
	
	// Variables para almacenar los tiempos de ejecución
    duration<double> selectionSortTime;
    duration<double> bubbleSortTime;
    duration<double> insertionSortTime;
    duration<double> shellSortTime;
    duration<double> mergeSortTime;
    duration<double> quickSortTime;
    duration<double> heapSortTime;
	
	// Generar un tamaño aleatorio para el arreglo de puntaje entre 90,000 y 100,000
    random_device rd_1;
    mt19937 generator_1(rd_1());
    uniform_int_distribution<int> size_distribution_1(90000, 100000);
    int array_size_1 = size_distribution_1(generator_1);
    vector<int> puntaje_1(array_size_1);
    vector<int> puntaje_2;
    vector<int> puntaje_3;
    vector<int> puntaje_4;
    vector<int> puntaje_5;
    vector<int> puntaje_6;
    vector<int> puntaje_7;
    
    // Generar un tamaño aleatorio para el arreglo de caminos entre 90,000 y 100,000
    random_device rd_2;
    mt19937 generator_2(rd_2());
    uniform_int_distribution<int> size_distribution_2(50000, 70000);
    int array_size_2 = size_distribution_2(generator_2);
    vector<int> caminos_1(array_size_2);
    vector<int> caminos_2;
    vector<int> caminos_3;
    vector<int> caminos_4;
    vector<int> caminos_5;
    vector<int> caminos_6;
    vector<int> caminos_7;
    
    // Generar un tamaño aleatorio para el arreglo de caminos entre 90,000 y 100,000
    random_device rd_3;
    mt19937 generator_3(rd_3());
    uniform_int_distribution<int> size_distribution_3(500, 1000);
    int array_size_3 = size_distribution_3(generator_3);
    int total_size = 15 * array_size_3;
    vector<int> objetos_1(total_size);
    vector<int> objetos_2;
    vector<int> objetos_3;
    vector<int> objetos_4;
    vector<int> objetos_5;
    vector<int> objetos_6;
    vector<int> objetos_7;
	
    int opcion;
    
    // Elegir ordenamiento de los arreglos
    cout << "Carrera de algoritmos" << endl; 
    cout << "1. Ascendente." << endl;  
    cout << "2. Descendente." << endl;
    cout << "Opcion elegida: ";
    
    cin >> opcion;
    
    cout << endl;
    
    while (opcion < 1 || opcion > 2) {
        cout << "*ERROR AL ELEGIR LA OPCION*" << endl << endl;
        cout << "Carrera de algoritmos" << endl;   	
        cout << "1. Ascendente." << endl;
        cout << "2. Descendente." << endl;
        cout << "Opcion elegida: ";
        cin >> opcion;
    }
    
    if (opcion == 1) {
    	
        addUniqueRandomValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
         
        cout << "Tablero de puntaje: Modo Aleatorio" << endl << endl;
        
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		addRandomValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
        
        cout << endl;
		
		cout << "Tablero de puntaje: Modo Aleatorio con duplicados" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
        
        addSortedValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
        
        cout << endl;
		
		cout << "Tablero de puntaje: Modo Ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	addReverseSortedValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
        
        cout << endl;
		
		cout << "Tablero de puntaje: Modo Inversamente ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	cout << endl;
    	
    	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    	
    	addUniqueRandomValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
         
        cout << "Caminos entre aldeas: Modo Aleatorio" << endl << endl;
        
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		addRandomValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
        
        cout << endl;
		
		cout << "Caminos entre aldeas: Modo Aleatorio con duplicados" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
        
        addSortedValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
        
        cout << endl;
		
		cout << "Caminos entre aldeas: Modo Ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	addReverseSortedValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
        
        cout << endl;
		
		cout << "Caminos entre aldeas: Modo Inversamente ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		cout << endl;
    	
    	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    	
		addUniqueRandomValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
         
        cout << "Renderizado de objetos: Modo Aleatorio" << endl << endl;
        
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		addRandomValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
        
        cout << endl;
		
		cout << "Renderizado de objetos: Modo Aleatorio con duplicados" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
        
        addSortedValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
        
        cout << endl;
		
		cout << "Renderizado de objetos: Modo Ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	addReverseSortedValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
        
        cout << endl;
		
		cout << "Renderizado de objetos: Modo Inversamente ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSort(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSort(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSort(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSort(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSort(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursive(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSort(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
    } else {
        
        addUniqueRandomValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
         
        cout << "Tablero de puntaje: Modo Aleatorio" << endl << endl;
        
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		addRandomValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
        
        cout << endl;
		
		cout << "Tablero de puntaje: Modo Aleatorio con duplicados" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
        
        addReverseSortedValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
        
        cout << endl;
		
		cout << "Tablero de puntaje: Modo Ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	addSortedValues(puntaje_1);
        
        puntaje_2 = puntaje_1;
        puntaje_3 = puntaje_1;
        puntaje_4 = puntaje_1;
        puntaje_5 = puntaje_1;
        puntaje_6 = puntaje_1;
        puntaje_7 = puntaje_1;
        
        cout << endl;
		
		cout << "Tablero de puntaje: Modo Inversamente ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(puntaje_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(puntaje_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(puntaje_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(puntaje_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(puntaje_5, 0, puntaje_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(puntaje_6, 0, puntaje_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(puntaje_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	cout << endl;
    	
    	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    	
    	addUniqueRandomValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
         
        cout << "Caminos entre aldeas: Modo Aleatorio" << endl << endl;
        
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		addRandomValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
        
        cout << endl;
		
		cout << "Caminos entre aldeas: Modo Aleatorio con duplicados" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
        
        addReverseSortedValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
        
        cout << endl;
		
		cout << "Caminos entre aldeas: Modo Ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	addSortedValues(caminos_1);
        
        caminos_2 = caminos_1;
        caminos_3 = caminos_1;
        caminos_4 = caminos_1;
        caminos_5 = caminos_1;
        caminos_6 = caminos_1;
        caminos_7 = caminos_1;
        
        cout << endl;
		
		cout << "Caminos entre aldeas: Modo Inversamente ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(caminos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(caminos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(caminos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(caminos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(caminos_5, 0, caminos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(caminos_6, 0, caminos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(caminos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		cout << endl;
    	
    	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    	
		addUniqueRandomValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
         
        cout << "Renderizado de objetos: Modo Aleatorio" << endl << endl;
        
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
		
		addRandomValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
        
        cout << endl;
		
		cout << "Renderizado de objetos: Modo Aleatorio con duplicados" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
        
        addReverseSortedValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
        
        cout << endl;
		
		cout << "Renderizado de objetos: Modo Ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
    	
    	addSortedValues(objetos_1);
        
        objetos_2 = objetos_1;
        objetos_3 = objetos_1;
        objetos_4 = objetos_1;
        objetos_5 = objetos_1;
        objetos_6 = objetos_1;
        objetos_7 = objetos_1;
        
        cout << endl;
		
		cout << "Renderizado de objetos: Modo Inversamente ordenado" << endl << endl;
		
		// Medir el tiempo de ejecución para Selection Sort
    	start = high_resolution_clock::now();
    	selectionSortDesc(objetos_1);
    	end = high_resolution_clock::now();
    	selectionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Bubble Sort
    	start = high_resolution_clock::now();
    	bubbleSortDesc(objetos_2);
    	end = high_resolution_clock::now();
    	bubbleSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Insertion Sort
    	start = high_resolution_clock::now();
    	insertionSortDesc(objetos_3);
    	end = high_resolution_clock::now();
    	insertionSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Shell Sort
    	start = high_resolution_clock::now();
    	shellSortDesc(objetos_4);
    	end = high_resolution_clock::now();
    	shellSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Merge Sort
    	start = high_resolution_clock::now();
    	mergeSortDesc(objetos_5, 0, objetos_5.size() - 1);
    	end = high_resolution_clock::now();
    	mergeSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Quick Sort
    	start = high_resolution_clock::now();
    	quickSortTailRecursiveDesc(objetos_6, 0, objetos_6.size() - 1);
    	end = high_resolution_clock::now();
    	quickSortTime = duration_cast<duration<double>>(end - start);

    	// Medir el tiempo de ejecución para Heap Sort
    	start = high_resolution_clock::now();
    	heapSortDesc(objetos_7);
    	end = high_resolution_clock::now();
    	heapSortTime = duration_cast<duration<double>>(end - start);

    	// Llamar a la función compareTimes para comparar los tiempos de ejecución
    	compareTimes(selectionSortTime, bubbleSortTime, insertionSortTime, shellSortTime, mergeSortTime, quickSortTime, heapSortTime);
        
    }

    return 0;
}
