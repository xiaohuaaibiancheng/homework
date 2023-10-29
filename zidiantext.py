# people1={
#     'first_name' : '大1',
#     'last_name'  : '帅哥',
#     'age' : '18',
#     'city' : '中国',
# }
# people2={
#     'first_name' : '大2',
#     'last_name'  : '帅哥',
#     'age' : '18',
#     'city' : '中国',
# }

# people3={
#     'first_name' : '大3',
#     'last_name'  : '帅哥',
#     'age' : '18',
#     'city' : '中国',
# }
# people=[people1,people2,people3]
# for person in people:
#     print(person['city'])
#     print(person['age'])

# favorite_numbers={
#     'mili':'3',
#     'bdyd':'5',
#     "some":'8',
#     'skom':'9',
#     'skddas':'10',
# }
# people=['mili','bdyd','skom']
# for friend in favorite_numbers.keys():#items()表示键值对
#     if friend in people:
#         print(f'{friend},thanks for you joining')
#     else:
#         print(f'{friend},please join us')
# shuyu={
#     '元组':'不可修改的列表',
#     '字典':'描述键对值',
#     'range()函数':'表示一个范围括号里是范围参数',
#     'rstrip':'删除字符串右边空白函数',
#     'lstrip':'删除字符串左边空白函数',
# }

# for s,v in shuyu.items():
#     print('The Nile runs throuhg Egypt')
#     print(s.title())
#     print(v.title())
#     print('\n')

# like_places={
#     'xiao':['lasa','beijing','shanghai'],
#     'zhang':['gansu','meiguo','bubei'],
#     'gan':['hubei','zhoguo','anhui'],
# }
# for name,places in like_places.items():
#     print(f'\n{name} like place are these:')
#     for place in places:
#         print(f'\t{place}')

cities={
    'city1':{
        'country':'china',
        'popolation':'1.88万',
        'fact':'beautiful',
    },
    
    'city2':{
        'country':'china',
        'popolation':'2.88万',
        'fact':'beautiful',
    },
    
    'city3':{
        'country':'china',
        'popolation':'3.88万',
        'fact':'beautiful',
    },
}
for city,imformations in cities.items():
    print(f'\n{city.title()} 的信息：')
    for title,imformation in imformations.items():
       print(f'{title}:{imformation}')