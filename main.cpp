#include "QuantumGate.h"
#include "VirtualQubit.h"
#include <vector>
#include <iostream>

class EntropyGenerator {
public:
    static std::vector<int> generateBits(int numberOfBits, int batchSize) {
        std::vector<int> bits;
        bits.reserve(numberOfBits); // Pre-allocate memory for efficiency

        // Calculate the number of batches needed
        int batches = numberOfBits / batchSize + (numberOfBits % batchSize != 0);

        for (int i = 0; i < batches; ++i) {
            std::vector<VirtualQubit> qubits;
            // Prepare a batch of qubits in superposition
            for (int j = 0; j < batchSize && (i * batchSize + j) < numberOfBits; ++j) {
                qubits.emplace_back(); // Default constructor
QuantumGate::applyHGate(qubits.back()); // This assumes QuantumGate::applyHGate adjusts the qubit state accordingly
            }

            // Measure qubits in the batch and collect bits
            for (auto& qubit : qubits) {
                int bit = qubit.measure(); // Measure qubit
                bits.push_back(bit);
            }
        }

        return bits;
    }
};

int main() {
    int numberOfBits = 4456; // Desired number of bits
    int batchSize = 160; // Number of qubits to process in each batch

    auto bits = EntropyGenerator::generateBits(numberOfBits, batchSize); // Generate bits with batching

    std::cout << "Generated Bits: ";
    for (auto bit : bits) {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;
}
