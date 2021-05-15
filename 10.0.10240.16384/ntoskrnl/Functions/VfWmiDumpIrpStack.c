// VfWmiDumpIrpStack 
 
int __fastcall VfWmiDumpIrpStack(int a1)
{
  unsigned int v2; // r2
  const char *v3; // r0

  VfUtilDbgPrint((int)"IRP_MJ_SYSTEM_CONTROL.");
  v2 = *(unsigned __int8 *)(a1 + 1);
  if ( v2 > 9 )
  {
    if ( v2 == 255 )
      v3 = "IRP_MN_BOGUS";
    else
      v3 = "(Bogus)";
  }
  else
  {
    v3 = WmiIrpNames[v2];
  }
  return VfUtilDbgPrint((int)v3);
}
