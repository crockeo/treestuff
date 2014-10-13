module Main where

-------------------
-- Local Imports --
import Dictionary
import TreeStuff
import qualified FastTrie as FT
import qualified Data.Trie as T

data Arrow a = Arrow { stepArrow :: (a -> (a, Arrow a)) }

type CountPair = (Int, Int)

incRight :: CountPair -> CountPair
incRight (r, w) = (r + 1, w)

incWrong :: CountPair -> CountPair
incWrong (r, w) = (r, w + 1)

incBool :: Bool -> CountPair -> CountPair
incBool  True = incRight
incBool False = incWrong

main :: IO ()
main = do
  dicWords <- loadDefaultDict
  let tree = makeTree dicWords
  print $ foldl (flip incBool) (0, 0) $ map (findString tree) dicWords

  byteWords <- loadDefaultByteStringDict
  let fastTree = FT.makeTree byteWords
  print $ foldl (flip incBool) (0, 0) $ map (FT.findString fastTree) dicWords

