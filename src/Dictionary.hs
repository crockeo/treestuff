module Dictionary where

-------------------
-- Local Imports --
import TreeStuff

----------
-- Code --

-- | Loading a dictionary from a file.
loadDict :: FilePath -> IO [String]
loadDict = fmap (lines) . readFile

-- | Loading the default dictionary.
loadDefaultDict :: IO [String]
loadDefaultDict = loadDict "dictionary.txt"

-- | Making a dictionary tree.
dictTree :: FilePath -> IO Tree
dictTree = fmap (insertStrings emptyTree) . loadDict

-- | Loading the default dictionary.
defaultDictTree :: IO Tree
defaultDictTree = dictTree "dictionary.txt"
