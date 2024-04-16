import psutil
import os

while(True):
    #cpu = (((psutil.cpu_percent(interval=1.2, percpu=True))))
    #lista = int(sum(lista) / len(lista))
    #print(psutil.cpu_percent(interval=1.2, percpu=False))
    #print(int(max(cpu)))
    #print(int((psutil.cpu_percent(interval=1.2))))
    load1, load5, load15 = psutil.getloadavg()
 
    cpu_usage = (load15/os.cpu_count()) * 100
 
    print("The CPU usage is : ", cpu_usage)