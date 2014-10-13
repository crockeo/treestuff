module Dictionary where


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
