// PiPnpRtlApplyMandatoryDeviceContainerFilters 
 
int __fastcall PiPnpRtlApplyMandatoryDeviceContainerFilters(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int v8; // r5
  unsigned int *v10; // r4
  unsigned int *v11; // [sp+0h] [bp-28h] BYREF
  int v12; // [sp+8h] [bp-20h] BYREF
  int v13; // [sp+Ch] [bp-1Ch]
  int v14; // [sp+10h] [bp-18h]

  v8 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  if ( wcsicmp(a2, L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}") )
  {
    v8 = PiDmGetObject(5, a2, (int *)&v11);
    v10 = v11;
    if ( v8 >= 0 )
    {
      LOBYTE(v14) = 0;
      v12 = a1;
      v13 = a4;
      v8 = PiDmListEnumObjectsWithCallback(3, v11, (int)PiPnpRtlApplyMandatoryDeviceContainerFiltersCallback, (int)&v12);
      if ( v8 >= 0 )
        *a5 = v14;
    }
    if ( v10 )
      PiDmObjectRelease((int)v10);
  }
  else
  {
    *a5 = 1;
  }
  return v8;
}
