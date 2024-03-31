import psutil
import time

while(1):
    totalMem = float("{:.1f}".format((((12228*psutil.virtual_memory().percent)/100))/1024)) #Memoria ram utilizada en GB
    cpu = int((psutil.cpu_percent(interval=1.2))) #Porcentaje del cpu utilizado
    mem = int((psutil.virtual_memory().percent)) #Porcentaje de la memoria ram utilizada
    ssd = int((111*(100-psutil.disk_usage("C:").percent))/100) #111 es la cadacidad del ssd
    
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
    
    
