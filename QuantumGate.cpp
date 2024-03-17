#include "QuantumGate.h"
#include <cmath>

void QuantumGate::applyXGate(VirtualQubit& qubit) {
    qubit.applyXGate();
}

void QuantumGate::applyHGate(VirtualQubit& qubit) {
    qubit.applyHGate();
}

void QuantumGate::applyZGate(VirtualQubit& qubit) {
    qubit.state1 = -qubit.state1; // Flip phase of |1>
}

void QuantumGate::applyCNOTGate(VirtualQubit& controlQubit, VirtualQubit& targetQubit) {
    if (std::norm(controlQubit.state1) > 0.5) { // Assuming |1> state has higher probability
        std::swap(targetQubit.state0, targetQubit.state1); // Flip target qubit
    }
}