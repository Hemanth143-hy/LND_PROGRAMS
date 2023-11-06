int index = 0;  // Index to track the new length

    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            // Update the value at the current index
            nums[index] = nums[i];

            // Move to the next index
            index++;
        }
    }

    return index;
