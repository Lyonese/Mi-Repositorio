# Inicialización de variables
NroCliente = 1
MesActual = 0
MesTransaccion = 0
TipoTransaccion = ""
MontoTransaccion = 0.0
Cliente = 1

SaldoCliente = 0.0
HaberEmpresa = 0.0
NroClienteMayorDeudor = 0
MontoMayorDeuda = 0.0
NroClienteMayorCompra = 0
MontoMayorCompra = 0.0

# Lectura del MesActual
MesActual = int(input("Ingrese el mes actual: "))

# Lectura inicial de NroCliente
NroCliente = int(input("Ingrese el número de cliente (0 para terminar): "))

while NroCliente != 0:
    Cliente = NroCliente

    while NroCliente == Cliente:
        MesTransaccion = int(input("Ingrese el mes de transacción: "))
        if MesTransaccion == MesActual:
            TipoTransaccion = input("Ingrese el tipo de transacción (compra/pago): ")
            MontoTransaccion = float(input("Ingrese el monto de la transacción: "))
            
            if TipoTransaccion == "compra":
                SaldoCliente -= MontoTransaccion
                if MontoTransaccion > MontoMayorCompra:
                    MontoMayorCompra = MontoTransaccion
                    NroClienteMayorCompra = Cliente
            else:
                SaldoCliente += MontoTransaccion
        
        NroCliente = int(input("Ingrese el número de cliente : "))
    
    if SaldoCliente < MontoMayorDeuda:
        MontoMayorDeuda = SaldoCliente
        NroClienteMayorDeudor = Cliente
    
    HaberEmpresa += SaldoCliente
    
    print(Cliente)
    print(SaldoCliente)

# Mostrar resultados
print("Haber de la empresa:", ((-1) * HaberEmpresa))
print("Cliente con mayor deuda:", NroClienteMayorDeudor, "con deuda de:", ((-1) * MontoMayorDeuda))
print("Cliente con mayor compra:", NroClienteMayorCompra, "con compra de:", MontoMayorCompra)
