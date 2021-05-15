// VfPnpDumpIrpStack 
 
int __fastcall VfPnpDumpIrpStack(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r2
  const char *v6; // r0
  int result; // r0
  int v8; // r3
  int v9; // r3
  const char *v10; // r0
  const char *v11; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r3

  DbgPrintEx(93, 0, (int)"IRP_MJ_PNP.", a4);
  v5 = *(unsigned __int8 *)(a1 + 1);
  if ( v5 > 0x18 )
  {
    if ( v5 == 255 )
      v6 = "IRP_MN_BOGUS";
    else
      v6 = "(Bogus)";
  }
  else
  {
    v6 = PnPIrpNames[v5];
  }
  result = VfUtilDbgPrint((int)v6);
  v8 = *(unsigned __int8 *)(a1 + 1);
  if ( v8 == 7 )
  {
    v14 = *(_DWORD *)(a1 + 8);
    switch ( v14 )
    {
      case 0:
        v11 = "(BusRelations)";
        return VfUtilDbgPrint((int)v11);
      case 1:
        v11 = "(EjectionRelations)";
        return VfUtilDbgPrint((int)v11);
      case 2:
        v11 = "(PowerRelations)";
        return VfUtilDbgPrint((int)v11);
      case 3:
        v11 = "(RemovalRelations)";
        return VfUtilDbgPrint((int)v11);
      case 4:
        v11 = "(TargetDeviceRelation)";
        return VfUtilDbgPrint((int)v11);
    }
  }
  else if ( v8 == 12 )
  {
    v13 = *(_DWORD *)(a1 + 8);
    if ( !v13 )
    {
      v11 = "(DeviceTextDescription)";
      return VfUtilDbgPrint((int)v11);
    }
    if ( v13 == 1 )
    {
      v11 = "(DeviceTextLocationInformation)";
      return VfUtilDbgPrint((int)v11);
    }
  }
  else
  {
    if ( *(unsigned __int8 *)(a1 + 1) <= 0xEu )
      return result;
    if ( *(unsigned __int8 *)(a1 + 1) <= 0x10u )
      return DbgPrintEx(93, 0, (int)"(WhichSpace=%x, Buffer=%p, Offset=%x, Length=%x)", *(_DWORD *)(a1 + 8));
    if ( v8 == 18 )
    {
      if ( *(_BYTE *)(a1 + 8) )
        v11 = "(True)";
      else
        v11 = "(False)";
      return VfUtilDbgPrint((int)v11);
    }
    if ( v8 != 19 )
    {
      if ( v8 != 22 )
        return result;
      v9 = *(_DWORD *)(a1 + 12);
      if ( v9 )
      {
        switch ( v9 )
        {
          case 1:
            v10 = "(DeviceUsageTypePaging";
            break;
          case 2:
            v10 = "(DeviceUsageTypeHibernation";
            break;
          case 3:
            v10 = "(DeviceUsageTypeDumpFile";
            break;
          default:
            v10 = "(Bogus)";
            break;
        }
      }
      else
      {
        v10 = "(DeviceUsageTypeUndefined";
      }
      VfUtilDbgPrint((int)v10);
      if ( *(_BYTE *)(a1 + 8) )
        v11 = ", InPath=TRUE)";
      else
        v11 = ", InPath=FALSE)";
      return VfUtilDbgPrint((int)v11);
    }
    v12 = *(_DWORD *)(a1 + 8);
    switch ( v12 )
    {
      case 0:
        v11 = "(BusQueryDeviceID)";
        return VfUtilDbgPrint((int)v11);
      case 1:
        v11 = "(BusQueryHardwareIDs)";
        return VfUtilDbgPrint((int)v11);
      case 2:
        v11 = "(BusQueryCompatibleIDs)";
        return VfUtilDbgPrint((int)v11);
      case 3:
        v11 = "(BusQueryInstanceID)";
        return VfUtilDbgPrint((int)v11);
    }
  }
  v11 = "(Bogus)";
  return VfUtilDbgPrint((int)v11);
}
