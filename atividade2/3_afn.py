import sys

def main():
    nEstados = int(input())
    nSimbolos = int(input())
    dic = {}
    for i in range(nEstados):
        dic[i] = {}
        for j in range(nSimbolos):
            if j == 52 and i == 8: #tratando espaço em branco
                dic[i][' '] = [8] 
            elif j == 52: #tratando espaço em branco
                dic[i][' '] = [0] 
            else:
                x = list(map(str,input().split()))
                if len(x) == 2:
                    dic[i][x[0]] = [int(x[1])]
                else:
                    dic[i][x[0]] = [int(x[1]),int(x[2])]

    estadoInicial = int(input())
    estadosFinais = list(map(int,input().split()))

    entrada = input()
    entrada = list(entrada)

    trans(dic, entrada, estadosFinais, estadoInicial)
    print("nao aceito")

def trans(tabtrans, entrada, final, inicial):
    for i in tabtrans[inicial][entrada[0]]: 
        inicial = i
        if len(entrada)==1:
            if (str(inicial) in str(final)):
                print("aceito")
                sys.exit()
            else:
                continue
        trans(tabtrans, entrada[1:], final, inicial) 

main()



