// _CmOpenDeviceInterfaceRegKeyWorker 
 
int __fastcall CmOpenDeviceInterfaceRegKeyWorker(int *a1, unsigned __int16 *a2, int a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int v9; // r0
  unsigned __int16 *v11; // r6
  unsigned int v12; // r5
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r4
  int v18; // r5
  int v19; // r1
  int v20; // r0
  int v21; // r0
  int v22; // [sp+0h] [bp-50h]
  int v23; // [sp+10h] [bp-40h] BYREF
  unsigned int v24; // [sp+14h] [bp-3Ch] BYREF
  int v25; // [sp+18h] [bp-38h] BYREF
  int v26; // [sp+1Ch] [bp-34h]
  unsigned __int16 *v27; // [sp+20h] [bp-30h]
  unsigned int v28[10]; // [sp+28h] [bp-28h] BYREF

  v26 = a4;
  v27 = a2;
  v9 = 0;
  v11 = 0;
  v25 = 0;
  v23 = 0;
  if ( !a3 || (a3 & 0xFFFFFCCC) != 0 )
    goto LABEL_38;
  v12 = 480;
  v24 = 480;
  if ( (a3 & 0x200) != 0 )
    return sub_7C70A4();
  v14 = ExAllocatePoolWithTag(1, 480, 1380994640);
  v11 = (unsigned __int16 *)v14;
  if ( v14 )
  {
    while ( 1 )
    {
      v17 = CmGetDeviceInterfaceRegKeyPath(v14, v27, a3, v26, v22, v11, v12 >> 1, v28);
      if ( v17 != -1073741789 )
        break;
      ExFreePoolWithTag((unsigned int)v11);
      v11 = 0;
      v17 = RtlULongLongToULong(2 * v28[0], v28[0] >> 31, &v24);
      if ( v17 < 0 )
        goto LABEL_23;
      v12 = v24;
      v14 = ExAllocatePoolWithTag(1, v24, 1380994640);
      v11 = (unsigned __int16 *)v14;
      if ( !v14 )
        goto LABEL_35;
    }
  }
  else
  {
LABEL_35:
    v17 = -1073741801;
  }
  if ( v17 < 0 )
    goto LABEL_23;
  if ( (a3 & 0x100) == 0 )
  {
    v17 = RtlInitUnicodeStringEx((int)v28, v11);
    if ( v17 < 0 )
      goto LABEL_23;
    if ( LOWORD(v28[0]) < v12
      && LOWORD(v28[0]) > 0x32u
      && RtlPrefixUnicodeString(
           (unsigned __int16 *)&`_CmDeleteDeviceRegKeyWorker'::`2'::ObjectPathRootPrefix,
           (unsigned __int16 *)v28,
           1) )
    {
      v18 = (int)(v11 + 25);
      v17 = PnpCtxGetCachedContextBaseKey(a1, 4, &v25);
      if ( v17 >= 0 )
      {
        v19 = v25;
LABEL_15:
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
        goto LABEL_23;
      }
      goto LABEL_23;
    }
    v9 = v23;
LABEL_38:
    v17 = -1073741811;
    goto LABEL_24;
  }
  v18 = (int)v11;
  v17 = PnpCtxRegOpenCurrentUserKey(a1, v15, v16, &v23);
  if ( v17 >= 0 )
  {
    v19 = v23;
    goto LABEL_15;
  }
LABEL_23:
  v9 = v23;
LABEL_24:
  if ( v9 )
    ZwClose();
  if ( v11 )
    ExFreePoolWithTag((unsigned int)v11);
  return v17;
}
