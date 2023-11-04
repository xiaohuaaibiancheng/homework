import pandas as pd
import numpy as np

# date=pd.date_range('20231104',periods=6)
# print(date)
# df=pd.DataFrame(np.random.randn(6,4),index=date,columns=list('abcd'))
# print(df)
# df2=pd.DataFrame({'A':1.,'B':pd.Timestamp(20231105),'c':pd.Series(1,index=list(range(4)),dtype=float),'D':np.array([3]*4,dtype=int),'E':pd.Categorical(['test','train','test','train']),'F':'abd'})
# print(df2)
# print(df2.values)
# print(df2.index)
df=pd.read_excel(r"C:\Users\大大大帅\Desktop\databases\archive\douban.xlsx")
# print(df.tail())
# dit={'序号':251,'片名':'了不起的盖茨比','评分':np.nan,"导演":'肖俊华','主演':'肖俊华','一句话点评':'简直不要太精彩'}
# s=pd.Series(dit)
# s.name=250
# df=df.append(s)

# df['评分'].fillna(np.mean(df['评分']),inplace=True)
# print(df[df.评分>9][:5])
# print(df[df['评分']>9][:5])
print(df.tail())
df=df.drop(df.iloc[-1:-3])

print(df)
# print(df.tail())
# df.to_excel(r"C:\Users\大大大帅\Desktop\databases\archive\douban.xlsx")
# print(df.iloc[0])#第一行数据或者用loc
# df=df.drop([250])

# print(df[df['主演']=='陆运坤'])
# print(df[(df.主演=='陆运坤')&(df.评分>9)])