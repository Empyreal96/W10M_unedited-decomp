// AslRegistryGetUInt32 
 
int __fastcall AslRegistryGetUInt32(int a1, int a2, unsigned __int16 *a3)
{
  int v5; // r4
  char v7[24]; // [sp+8h] [bp-18h] BYREF

  v5 = RtlInitUnicodeStringEx((int)v7, a3);
  if ( v5 >= 0 )
    return AslRegistryGetUInt32_UStr(a1, a2, v7);
  AslLogCallPrintf(1, (int)"AslRegistryGetUInt32", 775, "RtlInitUnicodeStringEx failed [%x]", v5);
  return v5;
}
