import psutil
import serial

ser = serial.Serial()                                           
ser.baudrate = 9600                                             
ser.port = "COM "                                               
ser.open() 

while(1):
    totalMem = float("{:.1f}".format((((12228*psutil.virtual_memory().percent)/100))/1024))
    cpu = psutil.cpu_percent(interval=1.2)
    mem = psutil.virtual_memory().percent
    procesos= len(psutil.pids())
    
    if cpu < 10:
        cpuStr = "  " + str(cpu)                                
    elif cpu < 100:
        cpuStr = " " + str(cpu)                                 
    else:
        cpuStr = str(cpu) 
    
    if procesos < 100:
        procesosStr = "  " + str(procesos) + "P"
    elif procesos < 1000:
        procesosStr = " " + str(procesos) + "P"
    else:
        procesosStr = " " + str(procesos)

    if mem < 10:
        memStr = "  " + str(mem)                                
    elif mem < 100:
        memStr = " " + str(mem)
    else:
        memStr = str(mem)

    if totalMem < 10:
        totalMemStr = " " + str(totalMem) + "G"                  
    else:
        totalMemStr = " " + str("{:.1f}".format(totalMem))                                

    serialDataStr = cpuStr + procesosStr + memStr + totalMemStr 
    serialDataBytes = serialDataStr.encode("UTF-8")       

    print(serialDataBytes)                                      
    ser.write(serialDataBytes)                                  

ser.close()                     