module Main where

--------------------
-- Global Imports --
import Control.Monad

-------------------
-- Local Imports --
import Dictionary
import TreeStuff

main :: IO ()
main = do
  strs <- loadDefaultDict
  let strs'  = map (reverse) strs
      strs'' = strs ++ strs'
  dict <- defaultDictTree

  forM_ strs'' $ \s ->
    print (s, findString dict s)
