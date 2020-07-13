
# This file solves the problems in chapter 1 of Cracking the Coding Interview 
# which all have to do with strings and arrays

# Problem 1.1
def isUnique(s):
    for i in xrange(len(s)):
        if s.count(s[i])>1:
            return False
    return True

# Test cases
def main():
    s = ""
    assert(isUnique(s) == True)

if __name__ == "__main__":
    main()
