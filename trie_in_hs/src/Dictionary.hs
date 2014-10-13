module Dictionary where
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as BC

----------
-- Code --

-- | The name of the default dictionary.
defaultName :: String
defaultName = "../dictionaries/dictionary.txt"

-- | Loading a dictionary from a file.
loadDict :: FilePath -> IO [String]
loadDict = fmap (lines) . readFile

-- | Loading the default dictionary.
loadDefaultDict :: IO [String]
loadDefaultDict = loadDict defaultName

-- | Loading a dictionary from a file.
loadByteStringDict :: FilePath -> IO [B.ByteString]
loadByteStringDict = fmap (BC.lines) . B.readFile

-- | Loading the default dictionary.
loadDefaultByteStringDict :: IO [B.ByteString]
loadDefaultByteStringDict = loadByteStringDict defaultName