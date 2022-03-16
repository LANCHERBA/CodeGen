def main():
    input = np.arange(10)
    print("Please insert an array size: ")
    input = input.reshape(input.shape[0], input.shape[1])
    array = np.zeros(input.shape)
    for i in range(input.shape[0]):
        array[i] = i * 2 + 1
    print("Initialized values")
    for i in range(input.shape[0]):
        print(array[i])
    print("Done")


# Translator does not familiar with c++'s input style.
# Translator does not know to import related library automatically.

# Translator does understand it is trying to create an array + insert element into the array + print out the array.
