import psutil
import time

while(1):
    totalMem = float("{:.1f}".format((((12228*psutil.virtual_memory().percent)/100))/1024)) #Memoria ram utilizada en GB
    #cpu = int((psutil.cpu_percent(interval=1.2))) #Porcentaje del cpu utilizado
    mem = int((psutil.virtual_memory().percent)) #Porcentaje de la memoria ram utilizada
    ssd = int((111*(100-psutil.disk_usage("C:").percent))/100) #111 es la cadacidad del ssd
    
    cpu1 = int((psutil.cpu_percent(interval=0.3)))
    cpu2 = int(max((psutil.cpu_percent(interval=0.3, percpu=True))))
    cpu3 = int((sum((psutil.cpu_percent(interval=0.3, percpu=True))))/4)
    totalcpu = (psutil.cpu_percent(interval=0.3, percpu=True))
    
    for num in totalcpu:
        if 0.0 in totalcpu:
            totalcpu.remove(0.0)
        if 0.1 in totalcpu:
            totalcpu.remove(0.1)
        if 0.2 in totalcpu:
            totalcpu.remove(0.2)
        if 0.3 in totalcpu:
            totalcpu.remove(0.3)
        if 0.4 in totalcpu:
            totalcpu.remove(0.4)
        if 0.5 in totalcpu:
            totalcpu.remove(0.5)
        if 0.6 in totalcpu:
            totalcpu.remove(0.6)
        if 0.7 in totalcpu:
            totalcpu.remove(0.7)
        if 0.8 in totalcpu:
            totalcpu.remove(0.8)
        if 0.9 in totalcpu:
            totalcpu.remove(0.9)
    totalcpu = int((sum(totalcpu))/len(totalcpu))
    
    lista = []
    lista.append(cpu1)
    lista.append(cpu2)
    lista.append(cpu3)
    lista.append(totalcpu)
    
    print(lista)
    cpu = max(lista)
    #cpu = int(max((psutil.cpu_percent(interval=1.2, percpu=True))))
    
    if cpu < 10:
        cpuStr = "  " + str(cpu) + " %"                             
    elif cpu < 100:
        cpuStr = " " + str(cpu) + " %"                             
    else:
        cpuStr = str(cpu) + " %"
    
    if ssd < 10:
        ssdStr = "  " + str(ssd) + "GB"
    elif ssd < 100:
        ssdStr = " " + str(ssd) + "GB"

    if mem < 10:
        memStr = "  " + str(mem) + " %"                                 
    elif mem < 100:
        memStr = " " + str(mem) + " %"  
    else:
        memStr = " " + str(mem) + "%"

    if totalMem < 10:
        totalMemStr = " " + str(totalMem) + "G"                  
    else:
        totalMemStr = " " + str(totalMem)
        


    serialDataStr = cpuStr + ssdStr + memStr + totalMemStr
    
    ###########################################################
    #print(len(serialDataStr))
    CPUstat = serialDataStr[0:5]
    SSDstat = serialDataStr[5:10]
    RAMstat = serialDataStr[10:15]
    RAMtotal = serialDataStr[15:20]
    
    print("12345abcde")
    #print (cpuStr + procesosStr + memStr + totalMemStr)
    #print(CPUstat + PROCstat + RAMstat + RAMtotal)
    print(CPUstat + SSDstat)
    print(RAMstat + RAMtotal)
    #print(len(cpuStr))
    #print(len(procesosStr))
    #print(len(memStr))
    #print(len(totalMemStr))
    print("")
    
    #fila1 = "CPU:" + cpuStr + "%" + procesosStr
    #fila2 = "RAM:" + memStr + "%" + totalMemStr
    
    #print(fila1)
    #print(fila2)
    
    
