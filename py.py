import psutil
while(1):
    ssd = int((111*(100-psutil.disk_usage("C:").percent))/100)
    #print(ssd)
    print (float("{:.1f}".format((psutil.disk_usage("C:").free/1000000000) - 4.6)))