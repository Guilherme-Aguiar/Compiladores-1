def main():
    N = int(input())
    emailList = []
    for i in range(N):
        flag = False
        localpartTwo = ""
        email = str(input())
        localpartOne = email.split("@")[0].split("+")[0].split(".")
        for k in range(len(localpartOne)):
            localpartTwo += localpartOne[k] 
        provider = email.split("@")[1]
        if(i == 0):
            emailList.append(localpartTwo)
            emailList.append(provider)
        else:
            for j in range(0,len(emailList),2):
                if(localpartTwo == emailList[j] and provider == emailList[j+1]):
                    flag = True
            if(flag == False):
                emailList.append(localpartTwo)
                emailList.append(provider)
    print(int(len(emailList)/2))


main()

