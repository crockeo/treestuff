module FastTrie ( findString
				, makeTree
				) where

import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as BC
import qualified Data.Trie as T

findString :: T.Trie Integer -> String -> Bool
findString tree s = 
	let bs = BC.pack s
	in (length (T.toList (T.submap bs tree))) > 0

makeTree :: [B.ByteString] -> T.Trie Integer
makeTree byteWords = T.fromList (zip byteWords (repeat 1))
