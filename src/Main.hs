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

main :: IO ()
main = do
  strs <- loadDefaultDict
  dict <- defaultDictTree

  print $ foldl (flip incBool) (0, 0) $ map (findString dict) strs
