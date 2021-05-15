// _CmGetDevicesInBaseContainerList 
 
int __fastcall CmGetDevicesInBaseContainerList(int *a1, int a2, int a3, unsigned int *a4)
{
  _WORD *v7; // r6
  int v9; // r4
  int v10; // r0
  int v11; // r8
  int v12; // r0
  int i; // r7
  int v15; // r0
  int v16; // [sp+1Ch] [bp-24h] BYREF
  int v17[8]; // [sp+20h] [bp-20h] BYREF

  v7 = 0;
  v16 = 0;
  *a4 = 0;
  v9 = PnpCtxGetCachedContextBaseKey(a1, 9, &v16);
  if ( v9 >= 0 )
  {
    v9 = PnpCtxRegOpenKey(a1, v16, a2, 0);
    if ( v9 >= 0 )
    {
      v9 = PnpCtxRegOpenKey(a1, 0, (int)L"BaseContainers", 0);
      if ( v9 >= 0 )
      {
        v10 = PnpCtxRegOpenKey(a1, 0, a3, 0);
        v9 = v10;
        if ( v10 >= 0 )
        {
          v9 = PnpCtxRegQueryInfoKey(v10, 0, 0, (int)v17, (int)v17);
          if ( v9 >= 0 )
          {
            v11 = (v16 + 1) * v17[0] + 1;
            v12 = ExAllocatePoolWithTag(1, 2 * v11, 1380994640);
            v7 = (_WORD *)v12;
            *a4 = v12;
            if ( !v12 )
            {
              v9 = -1073741801;
              goto LABEL_8;
            }
            for ( i = 0; ; ++i )
            {
              v16 = v11 - 1;
              v12 = PnpCtxRegEnumValue(v12, 0, i, (int)v7, (int)&v16, 0, 0, 0);
              v9 = v12;
              if ( v12 == -2147483622 )
                break;
              if ( v12 < 0 )
                goto LABEL_17;
              v7 += v16 + 1;
              v11 -= v16 + 1;
            }
            v9 = 0;
          }
        }
      }
    }
  }
LABEL_17:
  if ( v9 == -1073741772 || v9 == -1073741444 )
    v9 = 0;
  if ( v9 >= 0 )
  {
    if ( *a4 )
    {
      *v7 = 0;
      return v9;
    }
    v15 = ExAllocatePoolWithTag(1, 2, 1380994640);
    *a4 = v15;
    if ( !v15 )
      return -1073741801;
    goto LABEL_10;
  }
LABEL_8:
  if ( *a4 )
  {
    ExFreePoolWithTag(*a4);
LABEL_10:
    *a4 = 0;
  }
  return v9;
}
