# 66. Plus One

**Difficulty:** Easy  
**Topic:** Array, Math  
**Pattern:** Right-to-Left Carry Propagation  

---

## 📌 Problem Description
You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the $i^{\text{th}}$ digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`s.

Increment the large integer by one and return *the resulting array of digits*.

---

## 💡 Examples & Edge Cases

### Example 1: Standard Case (No Carry)
```text
Input:  digits = [1, 2, 3]
Output: [1, 2, 4]
Explanation: 123 + 1 = 124.
