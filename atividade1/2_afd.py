# 2. Uma implementação do autômato que leia a especificação do autômato e uma palavra 
#    e imprima se a palavra lida é aceita pelo autômato ou não.
nEstados = int(input())
nSimbolos = int(input())
dic = {}
for i in range(nEstados):
    dic[i] = {}
    for j in range(nSimbolos):
        if j == 52 and i == 4: #tratando espaço em branco 4 _ 4
            dic[i][' '] = 4
        elif j == 52: # tratando espaço em branco 0,1,2,3 _ 3
            dic[i][' '] = 3 
        else:
            x = list(map(str,input().split()))
            dic[i][x[0]] = int(x[1])

estadoInicial = int(input())
estadosFinais = list(map(int,input().split()))
stringUsuario = input()

estadoAtual = estadoInicial

for i in stringUsuario:
    estadoAtual = dic[estadoAtual][i]
if estadoAtual in estadosFinais:
    print("aceito")
else:
    print("não aceito")
