module Main where

-------------------
-- Local Imports --
import Dictionary
import TreeStuff

data Arrow a = Arrow { stepArrow :: (a -> (a, Arrow a)) }

type CountPair = (Int, Int)

incRight :: CountPair -> CountPair
incRight (r, w) = (r + 1, w)

incWrong :: CountPair -> CountPair
incWrong (r, w) = (r, w + 1)

incBool :: Bool -> CountPair -> CountPair
incBool  True = incRight
incBool False = incWrong

--insertStrings :: Tree -> [String] -> Tree
main :: IO ()
main = do
  words <- loadDefaultDict
  let tree = insertStrings emptyTree words
  print $ foldl (flip incBool) (0, 0) $ map (findString tree) words
