// AslRegistryGetUInt32_UStr 
 
int __fastcall AslRegistryGetUInt32_UStr(_DWORD *a1)
{
  int v2; // r0
  int v3; // r4
  int v5[12]; // [sp+8h] [bp-30h] BYREF

  v5[0] = 0;
  *a1 = 0;
  v2 = ZwQueryValueKey();
  v3 = v2;
  if ( v2 >= 0 )
  {
    if ( v5[3] == 4 && v5[4] == 4 )
    {
      v3 = 0;
      *a1 = v5[5];
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslRegistryGetUInt32_UStr", 725, "Invalid value type", 20, v5);
      v3 = -1073741788;
    }
  }
  else if ( v2 != -1073741772 )
  {
    AslLogCallPrintf(1, (int)"AslRegistryGetUInt32_UStr", 718, "Failed to query key value [%x]", v2);
  }
  return v3;
}
