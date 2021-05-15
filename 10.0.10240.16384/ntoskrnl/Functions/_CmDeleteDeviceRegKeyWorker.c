// _CmDeleteDeviceRegKeyWorker 
 
int __fastcall CmDeleteDeviceRegKeyWorker(int a1, int a2, int a3, int a4, char a5)
{
  int *v5; // r10
  int v6; // r0
  unsigned __int16 *v8; // r7
  unsigned int v9; // r5
  int v11; // r1
  int v12; // r2
  int v13; // r4
  unsigned __int16 *v14; // r5
  int v15; // r9
  int v16; // r0
  int v17; // r10
  int *i; // r1
  int v19; // r2
  int v20; // r0
  unsigned __int16 *v21; // r0
  unsigned __int16 *v22; // r6
  int v23; // [sp+10h] [bp-58h] BYREF
  int v24; // [sp+14h] [bp-54h]
  unsigned int v25; // [sp+18h] [bp-50h] BYREF
  int v26[2]; // [sp+20h] [bp-48h] BYREF
  int v27; // [sp+28h] [bp-40h] BYREF
  int *v28; // [sp+2Ch] [bp-3Ch]
  int v29; // [sp+30h] [bp-38h]
  int v30[12]; // [sp+38h] [bp-30h] BYREF

  v28 = (int *)a1;
  v29 = a4;
  v5 = (int *)a1;
  v6 = 0;
  v8 = 0;
  v27 = 0;
  v23 = 0;
  v24 = a2;
  if ( !a3 || (a3 & 0xFFFFFCE8) != 0 )
    goto LABEL_60;
  v9 = 240;
  v25 = 240;
  if ( (a3 & 0x200) != 0 )
    return sub_81A0A0();
  v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 240, 1380994640);
  v12 = 0;
  if ( v8 )
  {
    while ( 1 )
    {
      v13 = CmGetDeviceRegKeyPath((int)v5, v24, a3, v29, 0, (int)v8, v9 >> 1, (int)v26);
      if ( v13 != -1073741789 )
        break;
      ExFreePoolWithTag((unsigned int)v8);
      v8 = 0;
      v13 = RtlULongLongToULong(2 * v26[0], (unsigned int)v26[0] >> 31, &v25);
      if ( v13 < 0 )
        goto LABEL_21;
      v9 = v25;
      v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v25, 1380994640);
      v12 = 0;
      if ( !v8 )
        goto LABEL_27;
    }
  }
  else
  {
LABEL_27:
    v13 = -1073741801;
  }
  if ( v13 < 0 )
    goto LABEL_21;
  if ( (a3 & 0x100) == 0 )
  {
    v13 = RtlInitUnicodeStringEx((int)v26, v8);
    if ( v13 < 0 )
      goto LABEL_21;
    if ( LOWORD(v26[0]) < v9
      && LOWORD(v26[0]) > 0x32u
      && RtlPrefixUnicodeString(
           (unsigned __int16 *)&`_CmDeleteDeviceRegKeyWorker'::`2'::ObjectPathRootPrefix,
           (unsigned __int16 *)v26,
           1) )
    {
      v14 = v8 + 25;
      v13 = PnpCtxGetCachedContextBaseKey(v5, 4, &v27);
      if ( v13 < 0 )
        goto LABEL_21;
      v15 = v27;
      goto LABEL_15;
    }
    v6 = v23;
LABEL_60:
    v13 = -1073741811;
    goto LABEL_22;
  }
  v14 = v8;
  v13 = PnpCtxRegOpenCurrentUserKey(v5, v11, v12, &v23);
  if ( v13 < 0 )
    goto LABEL_21;
  v15 = v23;
LABEL_15:
  if ( (unsigned __int8)a3 != 18 || (a3 & 0xF00) != 0 )
    goto LABEL_19;
  v30[0] = 786;
  v30[1] = 530;
  v30[2] = 274;
  v17 = 0;
  for ( i = v30; ; i = (int *)v26[0] )
  {
    v19 = *i;
    v26[0] = (int)(i + 1);
    v20 = CmDeleteDeviceRegKey((int)v28, v24, v19, 0);
    if ( v20 )
    {
      if ( v20 != -1073741772 && v20 != -1073741811 && v20 != -1073741637 )
        break;
    }
    if ( (unsigned int)++v17 >= 3 )
      goto LABEL_42;
  }
  v13 = v20;
LABEL_42:
  if ( v13 < 0 )
    goto LABEL_21;
  v5 = v28;
  CmDeleteDeviceMappedPropertyForAllDriverKeyRegValues(v28, v24);
  v16 = CmSetDeviceRegProp((int)v5, v24, 0, 10, 1, 0, 0, 0);
  if ( !v16 || v16 == -1073741275 || v16 == -1073741810 )
  {
LABEL_19:
    if ( a5 )
      v16 = PnpCtxRegDeleteTree(v5, v15, v14);
    else
      v16 = PnpCtxRegDeleteKey(v5, v15, v14);
    if ( v16 == -1073741444 )
      goto LABEL_21;
    if ( v16 >= 0 )
    {
      if ( (unsigned __int8)a3 == 18 || (unsigned __int8)a3 == 17 && (a3 & 0xF00) == 0 )
        goto LABEL_21;
      v21 = wcsrchr(v14, 92);
      if ( !v21 || (*v21 = 0, (v22 = wcsrchr(v14, 92)) == 0) )
      {
        v13 = -1073741595;
        goto LABEL_21;
      }
      v16 = PnpCtxRegDeleteKey(v5, v15, v14);
      if ( v16 == -1073741535 )
        goto LABEL_21;
      if ( v16 >= 0 )
      {
        *v22 = 0;
        v16 = PnpCtxRegDeleteKey(v5, v15, v14);
        if ( v16 == -1073741535 || v16 >= 0 )
          goto LABEL_21;
      }
    }
  }
  v13 = v16;
LABEL_21:
  v6 = v23;
LABEL_22:
  if ( v6 )
    ZwClose();
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  return v13;
}
