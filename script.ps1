$archivoEjecutable = "D:\Descargas\Cosas\Deej\deej.exe"
$directorioTrabajo = "D:\Descargas\Cosas\Deej"

while ($true) {
    Start-Process -FilePath $archivoEjecutable -WorkingDirectory $directorioTrabajo
    Start-Sleep -Seconds 300  # Espera x segundos
    #Stop-Process -Name "deej"
    #Start-Sleep -Seconds 1
}