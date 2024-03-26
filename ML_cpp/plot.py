import numpy as np
import matplotlib.pyplot as plt

# Define the sigmoid function
def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# Generate a range of values for or_output and nand_output
or_output = np.linspace(-9, 9, 400)
nand_output = np.linspace(-9, 9, 400)

# Assuming some arbitrary weights for visualization
weights = [2.0, -1.5, 0.5]

# Calculate the value of the function for each pair of or_output and nand_output
Z = sigmoid(weights[0] * or_output**2 + weights[1] * nand_output + weights[2])

# Plot
plt.figure(figsize=(10, 6))
plt.plot(or_output, Z, label='Sigmoid Function Output')
plt.title('Sigmoid Function of Degree 2')
plt.xlabel('or_output (squared) + nand_output')
plt.ylabel('Sigmoid Output')
plt.legend()
plt.grid(True)
plt.show()