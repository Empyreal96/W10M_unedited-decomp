// PiInitCacheGroupInformation 
 
int PiInitCacheGroupInformation()
{
  __int16 v0; // r7
  int v1; // r4
  int v2; // r6
  unsigned int v3; // r5
  int v4; // r0
  int v6; // [sp+0h] [bp-28h] BYREF
  int v7; // [sp+4h] [bp-24h] BYREF
  int v8; // [sp+8h] [bp-20h] BYREF
  unsigned int v9; // [sp+Ch] [bp-1Ch] BYREF
  __int16 v10; // [sp+10h] [bp-18h]
  __int16 v11; // [sp+12h] [bp-16h]
  const __int16 *v12; // [sp+14h] [bp-14h]

  v11 = 138;
  v10 = 136;
  v0 = 0;
  v12 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ServiceGroupOrder";
  v7 = 0;
  v1 = IopOpenRegistryKeyEx(&v6);
  if ( v1 >= 0 )
  {
    v1 = IopGetRegistryValue(v6, L"List", 0, (int *)&v9);
    ZwClose();
    v2 = 0;
    v8 = 0;
    if ( v1 >= 0 )
    {
      v3 = v9;
      if ( *(_DWORD *)(v9 + 4) == 7 && *(_DWORD *)(v9 + 12) )
      {
        v4 = PnpRegMultiSzToUnicodeStrings(v9, &v8, &v7);
        v0 = v7;
        v2 = v8;
        v1 = v4;
      }
      else
      {
        v1 = -1073741823;
      }
      ExFreePoolWithTag(v3);
      if ( v1 >= 0 )
      {
        v1 = 0;
        PiInitGroupOrderTable = v2;
        PiInitGroupOrderTableCount = v0;
      }
    }
  }
  return v1;
}
