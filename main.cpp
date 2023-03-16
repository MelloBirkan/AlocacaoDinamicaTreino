#include <iostream>


void printVector(int pIntSize[], int size) {
    for(int i = 0; i < size;++i) {
        std::cout<<"Array[" <<i<< "]" << pIntSize[i] << "\n";
    }
}


void defalutArray(int *pIntSize, int size){
    for(int i = 0; i < size;++i) {
        pIntSize[i] = -1;
    }
}


int* moreSpace(int* pIntSize, int* size, int size2) {
    std::cout << "Qual o tamanho novo do vetor?: ";
    std::cin >> *size;
    int *pIntSize2 = new int[*size];
    defalutArray(pIntSize2, *size);

    if(*size > size2) {
        for(int i = 0; i < size2; i++) {
            pIntSize2[i] = pIntSize[i];
        }

    } else {
      delete [] pIntSize2;
        std::cout << "Não pode diminuir o tamanho do vetor\n";
        return pIntSize;
    }
  delete [] pIntSize;
    return pIntSize2;
}
int main() {
    int  size, count = 0, n = 1;

    char opcao;

    std::cout << "Vector size:";
    std::cin >> size;
    int *pIntSize = new int[size];

    defalutArray(pIntSize, size);

    while(1) {
        if(count >= size) {
            std::cout << "\nLimite do vetor atingido, deseja aumentar o vetor? (s/n): ";
            std::cin >> opcao;
            if(opcao == 's') {
                pIntSize = moreSpace(pIntSize, &size, size);
            } else break;
        }

        if(count < size) {
            std::cout << "\nDigite um número positivo para adicionar ao vetor: ";
            std::cin >> n;
        }

        if(n < 0) break;
        pIntSize[count] = n;
        count++;
    }
    printVector(pIntSize, size);
    delete[] pIntSize;
}