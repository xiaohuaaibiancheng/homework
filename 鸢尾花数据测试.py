from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
def datasets_demo():
    #sklearn数据集使用
    iris = load_iris()
    #print("鸢尾花数据类型：\n",iris)
    print("查看数据集描述：\n",iris['DESCR'])#字典形式
    print("查看特征值的名字：\n",iris.feature_names)#以键对值来表示
    print("查看特征值：\n",iris.data.shape)


#数据集划分
    x_train,x_text,y_train,y_test=train_test_split(iris.data,iris.target,test_size=0.2,random_state=22)
    #train_text_split()四个参数分别为，data特征值，target目标值,测试范围，随机数种子---最后两个可不要
    print('训练集的特征值：\n',x_train)
    print(x_train.shape)

    return None

if __name__ =="__main__":
    datasets_demo()