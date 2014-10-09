module Main where

--------------------
-- Global Imports --
import Control.Lens
import Data.Char

----------
-- Code --

-- The tree type
newtype Tree = Tree [(Bool, Tree)]

-- Being able to display the Tree without going down EVERY SINGLE PATH
instance Show Tree where
  show (Tree l) =
    "( Tree " ++ showTree l ++ ") "

-- The more raw function for displaying the tree.
showTree :: [(Bool, Tree)] -> String
showTree []              = ""
showTree ((False, _):ts) = "end " ++ showTree ts
showTree ((True , t):ts) = show t ++ showTree ts

-- Getting the index in the array for the char.
charIndex :: Char -> Int
charIndex c =
  fromEnum (toUpper c) - 65

-- Creating an empty tree
emptyTree :: Tree
emptyTree =
  Tree $ zip (repeat False)
             (replicate 26 emptyTree)

-- Inserting a single char into a tree.
insertChar :: Tree -> Char -> Tree
insertChar (Tree l) c =
  Tree $ l & ix ci .~ (l !! ci & _1 .~ True)
  where ci = charIndex c

-- Inserting a string into a tree.
insert :: Tree -> String -> Tree
insert t           []  = t
insert t        (c:[]) = insertChar t c
insert t        (c:cs) =
  let (Tree l) = insertChar t c in
    Tree $ l & ix ci .~ (l !! ci & _2 .~ insert (snd $ l !! ci) cs)
  where ci = charIndex c

-- Inserting a list of strings into a tree.
insertStrings :: Tree -> [String] -> Tree
insertStrings = foldl insert

-- Checking if a Char in a given Tree is valid.
findChar :: Tree -> Char -> Bool
findChar (Tree l) c = fst $ l !! charIndex c

-- Finding if a String is valid in a given Tree.
findString :: Tree -> String -> Bool
findString _             []  = False
findString t          (c:[]) = findChar t c
findString t@(Tree l) (c:cs)
  | findChar t c = findString (snd $ l !! charIndex c) cs
  | otherwise    = False

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
defaultDictTree :: IO [String]
defaultDictTree = dictTree "dictionary.txt"
