module TreeStuff ( Tree ()
                 , emptyTree
                 , insertChar
                 , insert
                 , insertStrings
                 , makeTree
                 , findChar
                 , findString
                 ) where

--------------------
-- Global Imports --
import Control.Lens
import Data.Char

----------
-- Code --

-- | The tuple type.
type TreeTuple = (Bool, Tree)

-- | The tree type
newtype Tree = Tree [TreeTuple]

-- | Being able to display the Tree without going down EVERY SINGLE PATH
instance Show Tree where
  show (Tree l) =
    "( Tree " ++ showTree l ++ ") "

-- | The more raw function for displaying the tree.
showTree :: [(Bool, Tree)] -> String
showTree []              = ""
showTree ((False, _):ts) = "end " ++ showTree ts
showTree ((True , t):ts) = show t ++ showTree ts

-- | Getting the bool of a @'TreeTuple'@.
getBool :: TreeTuple -> Bool
getBool = fst

-- | Getting the tree of a @'TreeTuple'@.
getTree :: TreeTuple -> Tree
getTree = snd

-- | Setting the value of the @'Bool'@ in a @'TreeTuple'@.
setBool :: TreeTuple -> Bool -> TreeTuple
setBool (_, t) b = (b, t)

-- | Setting the value of the @'Tree'@ in a @'TreeTuple'@.
setTree :: TreeTuple -> Tree -> TreeTuple
setTree (b, _) t = (b, t)

-- | Getting the index in the array for the char.
charIndex :: Char -> Int
charIndex c =
  fromEnum (toUpper c) - 65

-- | Creating an empty tree
emptyTree :: Tree
emptyTree =
  Tree $ zip (repeat False)
             (replicate 26 emptyTree)

-- | Inserting a single char into a tree.
insertChar :: Tree -> Char -> Tree
insertChar (Tree l) c =
  Tree $ l & ix ci .~ (setBool (l !! ci) True)
  where ci = charIndex c

-- | Inserting a string into a tree.
insert :: Tree -> String -> Tree
insert t           []  = t
insert t        (c:[]) = insertChar t c
insert t        (c:cs) =
  Tree $ tus & ix ci .~ (setTree targetTuple $ insert (getTree $ targetTuple) cs)
  where ci          = charIndex c
        (Tree tus)  = insertChar t c
        targetTuple = tus !! ci

-- | Inserting a list of strings into a tree.
insertStrings :: Tree -> [String] -> Tree
insertStrings = foldl insert

-- | Given a list of words, makes a tree from them
makeTree :: [String] -> Tree
makeTree = insertStrings emptyTree

-- | Checking if a Char in a given Tree is valid.
findChar :: Tree -> Char -> Bool
findChar (Tree l) c = getBool $ l !! charIndex c

-- | Finding if a String is valid in a given Tree.
findString :: Tree -> String -> Bool
findString _             []  = False
findString t          (c:[]) = findChar t c
findString t@(Tree l) (c:cs)
  | findChar t c = findString (getTree $ l !! charIndex c) cs
  | otherwise    = False
