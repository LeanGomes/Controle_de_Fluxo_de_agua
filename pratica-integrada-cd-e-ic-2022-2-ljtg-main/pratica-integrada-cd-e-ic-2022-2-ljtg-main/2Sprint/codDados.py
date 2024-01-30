import serial
porta = "COM5"
baud = 9600
arquivo = "Dados.csv"

# Estabelecendo a Conexão
try:
    ser = serial.Serial(porta, baud) 
    #Abrindo Serial
    ser.flushInput()
    #Quantidade de Amostras coletadas 
    amostra = 600
    linha = 0
    #Adicionando Linha ao Arquivo
    while linha <= amostra:
        data = str(ser.readline().decode("utf-8"))
        #Inserindo os dados no Arquivo 
        print(data)
        file = open(arquivo, "a")
        file.write(data)
        file.close()
        linha+=1

    print("Final de Leitura")
    #Fechando Conexão
    ser.close()
except serial.SerialException:
    print("Porta USB nao detectada")