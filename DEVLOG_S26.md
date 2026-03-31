# Developer Log (DEVLOG.md)

## Infix to Postfix (Spring 2026)

Minimum **6 entries** required.

Each entry must document learning and reasoning. Fabricated bugs are not expected.

\---

## Allowed Entry Types

Each entry may be one of the following:

1. **Bug Fix Entry**
* The issue encountered.
* Error messages or symptoms.
* Attempts made.
* Final resolution.
2. **Edge Case / Testing Entry**
* A failure discovered through testing.
* The specific input/state that caused it.
* The change you made to handle it correctly.
3. **Engineering Decision Entry (up to 2 allowed)**
* A design decision you made.
* An alternative approach you considered.
* Why you chose one approach over another (tradeoffs).

\---

### Entry 1

**Date**: 2026-03-26

**Entry Type:** Bug Fix

**Task worked on:** Infix validation

**Issue or decision:** Function returned too early during iteration

**Error message / symptom (if applicable):** Expressions were classified as valid infix after only reading the first token

**What I tried:** Used inline checks for parenBalance and expectOperand inside loop

**Fix / resolution (or final decision):** Moved validation checks to after loop. Implemented proper state tracking with expectOperand and ensured parentheses are balanced at end

**Commit(s):** Implemented isValidInfix



### Entry 2

**Date:** 2026-03-28

**Entry Type:** Engineering Decision

**Task worked on:** Data flow between functions

**Issue or decision:** Whether to pass both original tokens and converted output into evaluation

**Error message / symptom (if applicable):** Confusion about where postfix vector should be used

**What I tried:** Considered modifying evalPostfix to take multiple parameters

**Fix / resolution (or final decision):** Decided to keep functions modular:

\-tokenize → produces tokens

\-infixToPostfix → returns new vector

\-evalPostfix → takes only postfix vector

This keeps responsibilities clear and avoids unnecessary coupling

**Commit(s):** Would have been part of same commit as entry 3 but I forgot

\---

### Entry 3

**Date:** 2026-03-28

**Entry Type:** Bug Fix

**Task worked on:** Postfix evaluation

**Issue or decision:** Confusion about why two values need to be popped for each operator

**Error message / symptom (if applicable):** Incorrect results when evaluating subtraction and division

**What I tried:** Initially unsure about popping twice; considered only using one operand

**Fix / resolution (or final decision):** Learned that postfix operators are binary and require two operands. Implemented correct order: pop b first, then a, then compute a op b. Verified correctness with test expressions

**Commit(s):** Forgot to Commit this fix tbh

\---

### Entry 4

**Date:** 2026-03-30

**Entry Type:** Bug Fix

**Task worked on:** Infix to postfix conversion

**Issue or decision:** Infinite loop and incorrect parentheses handling

**Error message / symptom (if applicable):** Program would hang during conversion or crash due to stack access

**What I tried:** Used while (!tokens.empty()) and attempted to loop until encountering )

**Fix / resolution (or final decision):** Removed outer while loop. Replaced with single for loop over tokens. Implemented proper handling of ( and ) using stack and ensured operators are popped correctly based on precedence

**Commit(s):** InfixtoPostifx() completed

**---**---



### Entry 5



**Date:** 2026-03-30

**Entry Type:** Bug Fix

**Task worked on:** Implementing ArrayStack methods

**Issue or decision:** empty() function was behaving incorrectly and causing logic failures

**Error message / symptom (if applicable):** Unknown

**What I tried:** Initially implemented empty() to loop through and pop all elements, thinking it should “empty” the stack

**Fix / resolution (or final decision): R**ealized empty() should only check if the stack is empty, not modify it. Replaced implementation with return data.empty();.

**Commit(s):** Bug Fixes

\---

### Entry 6

**Date:** 2026-03-30

**Entry Type:** Bug Fix

**Task worked on:** Infix to postfix conversion (operator stack handling)

**Issue or decision:** Program was crashing or behaving inconsistently when accessing opstack.top()

**Error message / symptom (if applicable):** Runtime error or crash when evaluating expressions with operators, especially at the beginning of conversion

**What I tried:** Initially accessed opstack.top() directly inside the while condition without checking if the stack was empty

**Fix / resolution (or final decision):** Added a safety check using !opstack.empty() before accessing top(). Updated condition to:
**Commit(s):** Bug Fixes

\---



