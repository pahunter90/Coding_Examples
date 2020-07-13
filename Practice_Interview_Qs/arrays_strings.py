
# This file solves the problems in chapter 1 of Cracking the Coding Interview 
# which all have to do with strings and arrays

# Problem 1.1
def isUnique(s):
    for i in xrange(len(s)):
        if s.count(s[i])>1:
            return False
    return True

# Problem 1.2
def isPermutation(s1, s2):
    if len(s1) != len(s2):
        return False
    s1 = sorted(s1)
    s2 = sorted(s2)
    if s1 == s2:
        return True
    else:
        return False

# Problem 1.3
def replaceSpace(s, l):
    s = s[0:l]
    return s.replace(' ','%20')

# Problem 1.4
def palindromePermutation(s):
    alpha = filter(str.isalpha, s)
    s = "".join(alpha)
    slen = len(s)
    allow_single = True
    if(slen%2 == 0):
        allow_single = False
    s = sorted(s)
    i = 0
    while i < len(s):
        if i == len(s)-1:
            if allow_single:
                return True
            else:
                return False
        elif s[i] == s[i+1]:
            i += 2
        else:
            if allow_single:
                i += 1
            else:
                return False
    return True

# Problem 1.5
def removeChar(s, i):
    if i == 0:
        return s[1:]
    elif i == len(s) - 1:
        return s[:i]
    else:
        return s[:i] + s[i+1:]
def oneAway(s1, s2):
    if s1 == s2:
        return True
    which_longer = len(s2) - len(s1)   # 0 if equal, -1 if s1 longer, 1 if s2 longer
    if which_longer < -1 or which_longer > 1:
        return False
    elif which_longer == -1:
        for i in xrange(len(s1)):
            s = removeChar(s1, i)
            if s == s2:
                return True
    elif which_longer == 0:
        for i in xrange(len(s1)):
            if removeChar(s1, i) == removeChar(s2, i):
                return True
    else:
        for i in xrange(len(s2)):
            if s1 == removeChar(s2, i):
                return True
    return False


# Test cases
def main():
    print("Running test cases for isUnique:")
    s = ""
    assert(isUnique(s) == True)
    s = "abcdefghijklmnopqrstuvwxyz"
    assert(isUnique(s) == True)
    s = "aa"
    assert(isUnique(s) == False)
    s = "aba"
    assert(isUnique(s) == False)
    s = "a"
    assert(isUnique(s) == True)
    print("all test cases passed!")
    print("")
    print("")

    print("Running test cases for isPermutation:")
    s1 = s2 = ""
    assert(isPermutation(s1,s2) == True)
    s1 = "a"
    s2 = "b"
    assert(isPermutation(s1,s2) == False)
    s1 = "aa"
    s2 = "a"
    assert(isPermutation(s1,s2) == False)
    s1 = "abac"
    s2 = "cbaa"
    assert(isPermutation(s1,s2) == True)
    s1 = "abbc"
    s2 = "bacc"
    assert(isPermutation(s1,s2) == False)
    print("all test cases passed!")
    print("")
    print("")

    print("Running test cases for replaceSpace:")
    s = " "
    l = len(s)
    assert(replaceSpace(s,l) == "%20")
    s = "Hello World  "
    l = len(s)-2
    assert(replaceSpace(s,l) == "Hello%20World")
    print("all test cases passed!")
    print("")
    print("")

    print("Running test cases for palindromePermutation:")
    s = ""
    assert(palindromePermutation(s) == True)
    s = "aa"
    assert(palindromePermutation(s) == True)
    s = "aba"
    assert(palindromePermutation(s) == True)
    s = "abab"
    assert(palindromePermutation(s) == True)
    s = "abcdab"
    assert(palindromePermutation(s) == False)
    print("all test cases passed!")
    print("")
    print("")

    print("Running test cases for oneAway:")
    s1 = ""
    s2 = ""
    assert(oneAway(s1, s2) == True)
    s1 = ""
    s2 = "a"
    assert(oneAway(s1, s2) == True)
    s1 = "a"
    s2 = ""
    assert(oneAway(s1, s2) == True)
    s1 = "aa"
    s2 = ""
    assert(oneAway(s1, s2) == False)
    s1 = "baba"
    s2 = "bacd"
    assert(oneAway(s1, s2) == False)
    s1 = "baca"
    s2 = "bacd"
    assert(oneAway(s1, s2) == True)
    print("all test cases passed!")
    print("")
    print("")

if __name__ == "__main__":
    main()
