// VfPowerDumpIrpStack 
 
int __fastcall VfPowerDumpIrpStack(int a1)
{
  unsigned int v2; // r2
  int result; // r0
  int v4; // r3
  int v5; // r2
  char *v6; // r0
  int v7; // r3
  int v8; // r3
  const char *v9; // r0

  VfUtilDbgPrint((int)"IRP_MJ_POWER.");
  v2 = *(unsigned __int8 *)(a1 + 1);
  if ( v2 > 3 )
  {
    if ( v2 == 255 )
      v9 = "IRP_MN_BOGUS";
    else
      v9 = "(Bogus)";
    return VfUtilDbgPrint((int)v9);
  }
  result = VfUtilDbgPrint((int)PowerIrpNames[v2]);
  v4 = *(unsigned __int8 *)(a1 + 1);
  if ( v4 == 3 || v4 == 2 )
  {
    result = VfUtilDbgPrint((int)"(");
    if ( *(_DWORD *)(a1 + 12) )
    {
      v7 = *(_DWORD *)(a1 + 16);
      if ( v7 <= 4 )
      {
        if ( v7 < 0 )
          return result;
        v6 = DeviceStateNames[v7];
        goto LABEL_11;
      }
    }
    else
    {
      v5 = *(_DWORD *)(a1 + 16);
      if ( v5 <= 6 )
      {
        if ( v5 < 0 )
          return result;
        v6 = SystemStateNames[v5];
LABEL_11:
        result = VfUtilDbgPrint((int)v6);
        goto LABEL_12;
      }
    }
LABEL_12:
    v8 = *(_DWORD *)(a1 + 20);
    if ( v8 <= 7 )
    {
      if ( v8 < 0 )
        return result;
      VfUtilDbgPrint((int)ActionNames[v8]);
    }
    v9 = ")";
    return VfUtilDbgPrint((int)v9);
  }
  return result;
}
