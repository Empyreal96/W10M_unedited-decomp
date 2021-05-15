// ExpOsProductCacheProviderHelper 
 
int __fastcall ExpOsProductCacheProviderHelper(int a1, _DWORD *a2, int a3, unsigned int a4, _DWORD *a5, _BYTE *a6)
{
  int v6; // r9
  int v9; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  int v14; // [sp+Ch] [bp-24h]

  v6 = 0;
  *a6 = 1;
  v9 = ZwOpenKey();
  if ( v9 >= 0 )
  {
    v6 = 1;
    v10 = ZwQueryValueKey();
    v9 = v10;
    if ( v10 >= 0 || v10 == -1073741789 )
    {
      v11 = ExAllocatePoolWithTag(1, v14, 542329939);
      if ( v11 )
      {
        v9 = ZwQueryValueKey();
        if ( v9 >= 0 )
        {
          *a5 = *(_DWORD *)(v11 + 8);
          if ( a2 )
            *a2 = *(_DWORD *)(v11 + 4);
          v12 = *(_DWORD *)(v11 + 8);
          if ( a4 >= v12 )
          {
            if ( a3 )
              memmove(a3, v11 + 12, v12);
          }
          else
          {
            v9 = -1073741789;
          }
        }
        ExFreePoolWithTag(v11);
      }
      else
      {
        v9 = -1073741801;
      }
    }
  }
  if ( v6 == 1 )
    ZwClose();
  return v9;
}
