import pandas as pd
import os
mainpath = "sample_data"
filename = "limon.csv"
fullpath = os.path.join(mainpath,filename)
  df = pd.read_csv(filename, index_col=0, encoding='latin-1')
df.head()