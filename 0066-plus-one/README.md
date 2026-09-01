# 66. Plus One

**LeetCode #66 — Plus One**

> **Difficulty:** Easy
> **Topics:** Array, Math
> **Pattern:** Right-to-Left Carry Propagation

---

## 📌 Problem Statement

You are given a large integer represented as an integer array `digits`, where `digits[i]` is the `i`-th digit of the integer.

The digits are ordered from the **most significant digit to the least significant digit**, from left to right.

The integer does not contain any leading zeroes.

Your task is to **increment the integer by one** and return the resulting array of digits.

### Example

```text
Input:  digits = [1, 2, 3]
Output: [1, 2, 4]
```

The array represents the number `123`.

After adding `1`:

```text
123 + 1 = 124
```

Therefore, the result is:

```text
[1, 2, 4]
```

---

## 💡 Examples

### Example 1 — Standard Case

No carry propagation is required because the last digit is less than `9`.

```text
Input:  digits = [1, 2, 3]
Output: [1, 2, 4]

Explanation:
123 + 1 = 124
```

---

### Example 2 — Middle Carry

The last digit is `9`, so the carry propagates to the previous digit.

```text
Input:  digits = [1, 2, 9]
Output: [1, 3, 0]
```

#### Step-by-step

```text
129 + 1
```

1. `9 + 1 = 10`

   * Write `0`
   * Carry `1` to the previous digit

2. `2 + 1 = 3`

   * Write `3`
   * Carry is resolved

3. The first digit remains unchanged.

Result:

```text
[1, 3, 0]
```

---

### Example 3 — All Nines

This is the important edge case where every digit is `9`.

```text
Input:  digits = [9, 9, 9]
Output: [1, 0, 0, 0]
```

#### Step-by-step

```text
999 + 1 = 1000
```

The carry propagates through every digit:

```text
[9, 9, 9]
      ↓
[9, 9, 0]
      ↓
[9, 0, 0]
      ↓
[0, 0, 0]
```

Since every original digit was `9`, we need an additional digit at the beginning:

```text
[1, 0, 0, 0]
```

---

## 🧠 Key Intuition

The key observation is that **addition starts from the least significant digit**.

Instead of converting the entire array into an integer, we can simulate normal addition directly on the array.

We traverse the array **from right to left**:

```text
[1, 2, 9]
       ↑
    Start here
```

For every digit:

* If the digit is **less than `9`**, simply increment it and return.
* If the digit is **`9`**, change it to `0` and continue carrying `1` to the left.
* If every digit was `9`, prepend `1` to the array.

This avoids unnecessary integer conversion and naturally handles arbitrarily large numbers.

---

## ⚙️ Algorithm

1. Start from the last element of the array.
2. Traverse the array from **right to left**.
3. For each digit:

   * If `digits[i] < 9`:

     * Increment `digits[i]`.
     * Return the array immediately.
   * Otherwise:

     * Set `digits[i] = 0`.
     * Continue to the previous digit.
4. If the loop finishes, every digit was `9`.
5. Insert `1` at the beginning of the array.
6. Return the resulting array.

---

## 🛠️ C++ Implementation

```cpp
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        // Traverse from the least significant digit
        for (int i = n - 1; i >= 0; i--) {

            // No carry is required
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Current digit is 9, so carry propagates left
            digits[i] = 0;
        }

        // All digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
```

---

## 🔍 Dry Run

Consider:

```text
digits = [1, 2, 9]
```

### Iteration 1

```text
digits[2] = 9
```

Since it is `9`:

```text
digits[2] = 0
```

Array becomes:

```text
[1, 2, 0]
```

Carry continues left.

### Iteration 2

```text
digits[1] = 2
```

Since `2 < 9`:

```text
digits[1]++
```

Array becomes:

```text
[1, 3, 0]
```

The carry is resolved, so we return immediately.

Final result:

```text
[1, 3, 0]
```

---

## 🚨 Important Edge Case

### Input

```text
[9, 9, 9]
```

Every digit is `9`, so every digit becomes `0`:

```text
[9, 9, 9]
   ↓
[0, 0, 0]
```

The loop finishes without returning.

Therefore, we insert `1` at the beginning:

```text
[1, 0, 0, 0]
```

This correctly represents:

```text
999 + 1 = 1000
```

---

## 📊 Complexity Analysis

| Metric             | Complexity       | Explanation                                                       |
| ------------------ | ---------------- | ----------------------------------------------------------------- |
| **Time**           | `O(N)`           | In the worst case, every digit must be visited.                   |
| **Space**          | `O(1)` auxiliary | The array is modified in-place.                                   |
| **Best-Case Time** | `O(1)`           | If the last digit is less than `9`, only one element is modified. |

> **Note:** In the all-`9`s case, inserting `1` at the beginning may require shifting the existing elements, which takes `O(N)` time. The algorithm still remains `O(N)` overall.

---

## 🎯 Pattern to Remember

This problem demonstrates a common **carry propagation pattern**.

Whenever you need to perform addition on a number represented as an array:

```text
Start → Rightmost Digit
          ↓
      Check Carry
          ↓
      Move Left
          ↓
      Repeat
```

### General Rule

```text
digit < 9
    ↓
increment digit
    ↓
done

digit == 9
    ↓
set digit to 0
    ↓
carry to the left
```

If the carry reaches beyond the first digit:

```text
[9, 9, 9]
    ↓
[0, 0, 0]
    ↓
[1, 0, 0, 0]
```

---

## 🔑 Takeaways

* Always start from the **least significant digit** when performing addition.
* A digit of `9` causes a **carry**.
* A digit below `9` resolves the carry immediately.
* The **all-9s case** requires increasing the array size.
* Avoid converting the array into an integer because the number may be extremely large.
* Early return makes the common case very efficient.

---

## 🔗 Related Problem

The same carry-propagation idea can be extended to:

**LeetCode #67 — Add Binary**

The main difference is that instead of adding `1` to a digit array, we perform binary addition using strings.

---

## 📚 Concepts Practiced

* Arrays
* Arithmetic
* Carry propagation
* Reverse traversal
* In-place modification
* Edge-case handling
* Time and space complexity

---

### ⭐ Difficulty: Easy

**Pattern:** Right-to-Left Carry Propagation
**Language:** C++
**Problem:** LeetCode #66 — Plus One
