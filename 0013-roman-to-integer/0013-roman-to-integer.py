class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        tup = list(s)
        count = 0

        for i in range(len(tup)):
            t = tup[i]

            if t == "I":
                if i + 1 < len(tup) and tup[i + 1] in ("V", "X"):
                    count -= 1
                else:
                    count += 1

            elif t == "V":
                count += 5

            elif t == "X":
                if i + 1 < len(tup) and tup[i + 1] in ("L", "C"):
                    count -= 10
                else:
                    count += 10

            elif t == "L":
                count += 50

            elif t == "C":
                if i + 1 < len(tup) and tup[i + 1] in ("D", "M"):
                    count -= 100
                else:
                    count += 100

            elif t == "D":
                count += 500

            elif t == "M":
                count += 1000

        return count

"""
best recommended solution

class Solution(object):
    def romanToInt(self, s):
        values = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        count = 0

        for i in range(len(s)):
            if i + 1 < len(s) and values[s[i]] < values[s[i + 1]]:
                count -= values[s[i]]
            else:
                count += values[s[i]]

        return count
"""