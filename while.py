# sandwish_orders=['a','b','c','d','e']
# finish_sandiwiches=[]
# while sandwish_orders:
#     sandwish=sandwish_orders.pop()
#     finish_sandiwiches.append(sandwish)
#     print(f'\n{sandwish.title()},your sandwish has been finished')
# print(finish_sandiwiches)

# sandwich_orders=['a','b','c','a','e','a']
# print('a has been sold out')
# for food in sandwich_orders:
#     if food == 'a':
#         sandwich_orders.remove('a')
# print(sandwich_orders)

favorite_place=[]
flag=''

while flag!='no':
    place = input('if you could vist a place ,where would you go :')
    favorite_place.append(place)
    flag=input('if you agree to answer again(yes/no) :')
    

for places in favorite_place:
    print(places)