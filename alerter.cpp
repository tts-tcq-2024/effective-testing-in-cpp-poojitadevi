#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

// Stub function to simulate different network responses
int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Simulate failure if temperature is above a certain threshold
    if (celcius > 150.0) {
        return 500; // Simulate a failure response
    }
    return 200; // Simulate a success response
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment failure count on non-200 response
        alertFailureCount++;
    }
}

int main() {
    // Test case 1: Temperature that should cause failure
    alertInCelcius(400.5); 
    assert(alertFailureCount == 1 && "Alert failure count should be 1 for high temperature");

    // Test case 2: Temperature that should not cause failure
    alertInCelcius(303.6);
    assert(alertFailureCount == 1 && "Alert failure count should remain 1 for normal temperature");

    // Test case 3: Another high temperature to verify count increments
    alertInCelcius(500.0);
    assert(alertFailureCount == 2 && "Alert failure count should be 2 for second high temperature");

    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
