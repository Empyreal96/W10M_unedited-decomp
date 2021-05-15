// _CmOpenCommonClassRegKeyWorker 
 
int __fastcall CmOpenCommonClassRegKeyWorker(int *a1, unsigned __int16 *a2, __int16 a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int v8; // r4
  unsigned int v9; // r6
  int v13; // r0
  int v14; // r1
  int v15; // r2
  unsigned __int16 *v16; // r5
  int v17; // r4
  int v18; // r6
  int v19; // r1
  int v20; // r0
  int v21; // r0
  int v22; // [sp+0h] [bp-50h]
  unsigned int v23; // [sp+10h] [bp-40h] BYREF
  int v24; // [sp+14h] [bp-3Ch] BYREF
  int v25; // [sp+18h] [bp-38h] BYREF
  unsigned __int16 *v26; // [sp+1Ch] [bp-34h]
  unsigned int v27; // [sp+20h] [bp-30h] BYREF
  int v28[10]; // [sp+28h] [bp-28h] BYREF

  v8 = a4;
  v9 = 200;
  v24 = 0;
  v25 = 0;
  v28[0] = a4;
  v26 = a2;
  v23 = 200;
  if ( (a3 & 0x200) != 0 )
    return sub_7C7270();
  v13 = ExAllocatePoolWithTag(1, 200, 1380994640);
  v16 = (unsigned __int16 *)v13;
  if ( v13 )
  {
    while ( 1 )
    {
      v17 = CmGetCommonClassRegKeyPath(v13, v26, a3, v8, v22, (int)v16, v9 >> 1, &v27);
      if ( v17 != -1073741789 )
        break;
      ExFreePoolWithTag((unsigned int)v16);
      v16 = 0;
      v17 = RtlULongLongToULong(2 * v27, v27 >> 31, &v23);
      if ( v17 < 0 )
        goto LABEL_21;
      v9 = v23;
      v13 = ExAllocatePoolWithTag(1, v23, 1380994640);
      v16 = (unsigned __int16 *)v13;
      v8 = v28[0];
      if ( !v13 )
        goto LABEL_32;
    }
  }
  else
  {
LABEL_32:
    v17 = -1073741801;
  }
  if ( v17 >= 0 )
  {
    if ( (a3 & 0x100) != 0 )
    {
      v18 = (int)v16;
      v17 = PnpCtxRegOpenCurrentUserKey(a1, v14, v15, &v24);
      if ( v17 >= 0 )
      {
        v19 = v24;
        goto LABEL_13;
      }
    }
    else
    {
      v17 = RtlInitUnicodeStringEx((int)v28, v16);
      if ( v17 >= 0 )
      {
        if ( LOWORD(v28[0]) < v9
          && LOWORD(v28[0]) > 0x32u
          && RtlPrefixUnicodeString(
               (unsigned __int16 *)&`_CmDeleteDeviceRegKeyWorker'::`2'::ObjectPathRootPrefix,
               (unsigned __int16 *)v28,
               1) )
        {
          v18 = (int)(v16 + 25);
          v17 = PnpCtxGetCachedContextBaseKey(a1, 4, &v25);
          if ( v17 >= 0 )
          {
            v19 = v25;
LABEL_13:
            if ( a6 )
            {
              v21 = PnpCtxRegCreateTree(a1, v19, v18, 0, a5, 0, a7, a8);
            }
            else
            {
              if ( a1 )
                v20 = *a1;
              else
                v20 = 0;
              v21 = SysCtxRegOpenKey(v20, v19, v18, 0, a5);
              if ( v21 >= 0 )
                *a8 = 2;
            }
            if ( v21 == -1073741444 )
            {
              v17 = -1073741595;
            }
            else if ( v21 < 0 )
            {
              v17 = v21;
            }
            goto LABEL_21;
          }
        }
        else
        {
          v17 = -1073741811;
        }
      }
    }
  }
LABEL_21:
  if ( v24 )
    ZwClose();
  if ( v16 )
    ExFreePoolWithTag((unsigned int)v16);
  return v17;
}
