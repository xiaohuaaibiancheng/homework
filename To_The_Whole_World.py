#magicians=['alice','david','carelina',"canifoniya"]
# for magicina in magicians:
#     print(magicina)
#     print('they are great')

# numbers=[number for number in range(1,20,2)]
# print(numbers)
# print('the first three items in the list are:')
# print(magicians[:3])
# print(magicians[1:4])
# print(magicians[1:4])
# for magicina in magicians:
#     print(magicina)

# favorite_fruits=['apple','banana','pear']
# if 'apple' in favorite_fruits:
#     print("you really like apple")
# if 'banana' in favorite_fruits:
#     print('you indeed like banana')
# if 'pear' in favorite_fruits:
#     print('you really like pear')

# usernames=['admin','mash','colder','mama']
# username=['admin']
# if username:
#    for username1 in username:
#        if username1 == 'admin':
#           print("Hello admin,would you like to see a status report")
#        else:
#           print("Hello jaden,thank you for logging in again")
# else:
#    print("We need to find some users")

current_users=['A','b','c','d','e']
current_usersxal=current_users[:]
current_usersxal[0]='a'
new_users=['f','g','h','a','C']
for new_user in new_users:
    if new_user.lower() in current_usersxal:
        print('请输入其他名字')
    else:
        print(f'{new_user} has not been used.')