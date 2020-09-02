{-# LANGUAGE RecordWildCards #-}
import qualified Options.Applicative as O
import Options.Applicative ((<**>))

data Config = Config { inputPath :: String
                     , savePath :: String
                     } deriving (Eq, Show)

pConfig :: O.Parser Config
pConfig = Config <$> O.strOption ( O.long "input"
                                <> O.help "Input metadata file path."
                                <> O.metavar "PATH"
                                <> O.short 'i' )
                 <*> O.strOption ( O.long "output"
                                <> O.help "Write path for generated code."
                                <> O.metavar "PATH"
                                <> O.short 'o' )

app :: Config -> IO ()
app Config{..} = print =<< readLines inputPath

main :: IO ()
main = app =<< O.execParser opts
    where opts = O.info (pConfig <**> O.helper) ( O.fullDesc
                                               <> O.progDesc "Generate cpp code for PokemonOf."
                                               <> O.header "GenTypeTemplate.hs - A simple code gen tool" )

readLines :: String -> IO [String]
readLines = fmap (filter $ (/= 0) . length) . fmap lines . readFile
