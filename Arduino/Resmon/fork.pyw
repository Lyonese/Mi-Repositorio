import psutil
import serial

ser = serial.Serial()                                           
ser.baudrate = 9600                                             
ser.port = "COM3"                                               
ser.open() 

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
        ssdStr = " " + str(ssd) + " G "
    elif ssd < 100:
        ssdStr = "" + str(ssd) + " G "

    if mem < 10:
        memStr = "  " + str(mem) + " %"                                 
    elif mem < 100:
        memStr = " " + str(mem) + " %"  
    else:
        memStr = " " + str(mem) + "%"

    if totalMem < 10:
        totalMemStr = "" + str(totalMem) + "G "                  
    else:
        totalMemStr = " " + str(totalMem)                               

    serialDataStr = cpuStr + ssdStr + memStr + totalMemStr
    serialDataBytes = serialDataStr.encode("UTF-8")       

    #print(serialDataBytes)                                      
    ser.write(serialDataBytes)                                  

ser.close()                     