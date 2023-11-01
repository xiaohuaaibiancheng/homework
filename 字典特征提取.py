from sklearn.feature_extraction import DictVectorizer
from sklearn.feature_extraction.text import CountVectorizer
def dict_demo():
    #字典特征提取
    

    data = [{'city':'北京','temperature':100},{'city':'上海','temperature':60},{'city':'深圳','temperature':30}]
    #1.实例化一个转换器类
    trans=DictVectorizer(sparse=False)
    #2.调用fit_trasform(data)
    data_new=trans.fit_transform(data)
    #one-hot 编码
    print("data_new:\n",data_new)
    print('数据的名字：',trans.get_feature_names_out())
    return None

def count_text():
    data=['life is too short,i want to enjoy life','i like you,and you like me']
    #实例化一个转换器类型
    transfer=CountVectorizer()
    #调用fit_transform
    data_new=transfer.fit_transform(data)
    #记录所含单词的数量而不是是否存在
    print("data:\n",data_new.toarray())
   



def count_Chinese_text():
    data=['我喜欢你，你喜欢我吗','是的，我喜欢你']
    #实例化一个转换器类型
    transfer=CountVectorizer()
    #调用fit_transform
    data_new=transfer.fit_transform(data)
    #记录所含单词的数量而不是是否存在
    print("data:\n",data_new.toarray())
    print('特征名字:\n',transfer.get_feature_names_out())
   

#dict_demo()
#count_text()
count_Chinese_text()
