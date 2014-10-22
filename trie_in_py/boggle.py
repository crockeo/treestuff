import datrie
import string

board = [
    'tllboi',
    'eonvz',
    'tomws',
    'agnup',
    'sdijt']

dictionary = '../dictionaries/dictionary.txt'

words = {}
trie = datrie.Trie(string.ascii_lowercase)
first_letters = {}

with open(dictionary, 'r') as f:
    for line in f.readlines():
        line = line.strip()
        words[line] = True
        trie[unicode(line)] = True
        if len(line) >= 1:
            first_letters[line[0]] = True

def isPrefix(word):
    if len(word) == 0:
        return True
    # Hack! Need this because datrie doesn't properly search for single letters.
    if len(word) == 1:
        return word in first_letters
    return unicode(word.strip()) in trie

def isExact(word):
    return word in words

def getLocs(loc):
    (x, y) = loc
    possible = [(x + 1, y),
                (x - 1, y),
                (x, y + 1),
                (x, y - 1)]
    return filter(lambda (x, y): x >= 0 and x < 5 and y >= 0 and y < 5,
                  possible)

def searchBoard(loc, curWord):
    if not isPrefix(curWord):
        return []
    ret = []
    newWord = curWord + board[loc[0]][loc[1]]
    if isExact(newWord):
        ret = [newWord]
    for newLoc in getLocs(loc):
        ret += searchBoard(newLoc, newWord)
    return ret

findings = []
for x in range(5):
    for y in range(5):
        findings.append(searchBoard((x, y), ''))
flattened = [word for words in findings for word in words]

print flattened
