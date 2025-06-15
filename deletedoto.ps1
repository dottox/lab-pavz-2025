# Recorre todas las carpetas y borra archivos .o
Get-ChildItem -Path . -Recurse -Filter *.o | ForEach-Object {
    Write-Host "Eliminando: $($_.FullName)"
    Remove-Item $_.FullName -Force
}

Write-Host "Todos los archivos .o fueron eliminados."
