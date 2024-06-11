import psutil
import serial

ser = serial.Serial()                                           
ser.baudrate = 9600                                             
ser.port = "COM7"                                               
ser.open() 

while(1):
    totalMem = float("{:.1f}".format((((12228*psutil.virtual_memory().percent)/100))/1024)) #Memoria ram utilizada en GB
    mem = int((psutil.virtual_memory().percent)) #Porcentaje de la memoria ram utilizada
    ssd = int((111*(100-psutil.disk_usage("C:").percent))/100) #111 es la cadacidad del ssd
    
    """cpu1 = int((psutil.cpu_percent(interval=0.4)))
    cpu2 = int(max((psutil.cpu_percent(interval=0.4, percpu=True))))
    cpu3 = int((sum((psutil.cpu_percent(interval=0.4, percpu=True))))/4)
    totalcpu = (psutil.cpu_percent(interval=0.4, percpu=True))
    
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
    
    cpu = max(lista)"""
    #cpu = int(max((psutil.cpu_percent(interval=1.2, percpu=True))))
    cpu = int((psutil.cpu_percent(interval=1.2)))
    if cpu < 10:
        cpuStr = "  " + str(cpu) + " %"                             
    elif cpu < 100:
        cpuStr = " " + str(cpu) + " %"                             
    else:
        cpuStr = str(cpu) + " %"
    
    if ssd < 10:
        ssdStr = " " + str(ssd) + " G "
    elif ssd < 100:
        ssdStr = "" + str(ssd) + " G "

    if mem < 10:
        memStr = "  " + str(mem) + " %"                                 
    elif mem < 100:
        memStr = " " + str(mem) + " %"  
    else:
        memStr = str(mem) + " %"

    if totalMem < 10:
        totalMemStr = str(totalMem) + "G "                  
    else:
        totalMemStr = " " + str(totalMem)                               

    serialDataStr = cpuStr + ssdStr + memStr + totalMemStr
    serialDataBytes = serialDataStr.encode("UTF-8")       

    #print(serialDataBytes)                                      
    ser.write(serialDataBytes)                                  

ser.close()                     