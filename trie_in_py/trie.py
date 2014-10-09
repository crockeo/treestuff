import string
import datrie
trie = datrie.Trie(string.ascii_lowercase)

with open('dictionary.txt', 'r') as f:
    for line in f.readlines():
        trie[unicode(line.strip())] = True

with open('dictionary.txt', 'r') as f:
    exists = 0
    for line in f.readlines():
        if unicode(line.strip()) in trie:
            exists += 1
    print exists
        
