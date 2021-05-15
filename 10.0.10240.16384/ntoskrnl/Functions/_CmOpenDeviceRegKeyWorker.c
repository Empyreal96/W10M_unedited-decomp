// _CmOpenDeviceRegKeyWorker 
 
int __fastcall CmOpenDeviceRegKeyWorker(int *a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int *a7, _DWORD *a8)
{
  unsigned int v10; // r5
  int v11; // r0
  int v12; // r1
  int v13; // r2
  unsigned __int16 *v14; // r9
  int v15; // r4
  unsigned __int16 *v17; // r6
  int v18; // r1
  int v19; // r0
  int v20; // r5
  int v21; // r0
  int v22; // r0
  int v23; // r5
  int v24; // r6
  unsigned int v25; // r10
  int v26; // r0
  int v27; // r0
  int v28; // r0
  int v29; // r3
  int v30; // [sp+10h] [bp-50h] BYREF
  int v31; // [sp+14h] [bp-4Ch] BYREF
  int v32; // [sp+18h] [bp-48h] BYREF
  unsigned int v33; // [sp+1Ch] [bp-44h]
  unsigned int v34; // [sp+20h] [bp-40h] BYREF
  unsigned int v35; // [sp+24h] [bp-3Ch] BYREF
  int v36; // [sp+28h] [bp-38h] BYREF
  int v37; // [sp+2Ch] [bp-34h]
  int v38; // [sp+30h] [bp-30h]
  int v39[10]; // [sp+38h] [bp-28h] BYREF

  v37 = a2;
  v38 = a4;
  v35 = 0;
  v36 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  if ( !a3 || (a3 & 0xFFFFFCE8) != 0 )
    JUMPOUT(0x7C670A);
  v10 = 240;
  v34 = 240;
  if ( (a3 & 0x200) != 0 )
  {
    v10 = 360;
    v34 = 360;
  }
  v11 = ExAllocatePoolWithTag(1, v10, 1380994640);
  v13 = a6;
  v14 = (unsigned __int16 *)v11;
  if ( v11 )
  {
    while ( 1 )
    {
      v15 = CmGetDeviceRegKeyPath(a1, v37, a3, v38, v13, v14, v10 >> 1, v39);
      if ( v15 != -1073741789 )
        break;
      ExFreePoolWithTag((unsigned int)v14);
      v14 = 0;
      v15 = RtlULongLongToULong(2 * v39[0], (unsigned int)v39[0] >> 31, &v34);
      if ( v15 < 0 )
        goto LABEL_20;
      v10 = v34;
      v28 = ExAllocatePoolWithTag(1, v34, 1380994640);
      v13 = a6;
      v14 = (unsigned __int16 *)v28;
      if ( !v28 )
        goto LABEL_55;
    }
  }
  else
  {
LABEL_55:
    v15 = -1073741801;
  }
  if ( v15 < 0 )
    goto LABEL_51;
  if ( (a3 & 0x100) != 0 )
  {
    v17 = v14;
    v34 = (unsigned int)v14;
    v15 = PnpCtxRegOpenCurrentUserKey(a1, v12, v13, &v31);
    if ( v15 < 0 )
      goto LABEL_51;
    v18 = v31;
  }
  else
  {
    v15 = RtlInitUnicodeStringEx((int)v39, v14);
    if ( v15 < 0 )
      goto LABEL_51;
    if ( LOWORD(v39[0]) >= v10
      || LOWORD(v39[0]) <= 0x32u
      || !RtlPrefixUnicodeString(&`_CmDeleteDeviceRegKeyWorker'::`2'::ObjectPathRootPrefix, v39, 1) )
    {
      return sub_7C6700();
    }
    v17 = v14 + 25;
    v34 = (unsigned int)(v14 + 25);
    v15 = PnpCtxGetCachedContextBaseKey(a1, 4, &v36);
    if ( v15 < 0 )
      goto LABEL_51;
    v18 = v36;
  }
  v36 = v18;
  if ( a1 )
    v19 = *a1;
  else
    v19 = 0;
  v20 = a5;
  v21 = SysCtxRegOpenKey(v19, v18, v17, 0);
  if ( v21 )
  {
    if ( v21 == -1073741444 )
    {
      v15 = -1073741595;
      goto LABEL_20;
    }
    if ( v21 != -1073741772 )
    {
      v15 = v21;
      goto LABEL_20;
    }
    if ( !a6 )
    {
      if ( (unsigned __int8)a3 != 16 || (a3 & 0xF00) != 0 )
        v15 = -1073741772;
      else
        v15 = -1073741810;
      goto LABEL_20;
    }
    if ( (unsigned __int8)a3 != 16 || (a3 & 0xF00) != 0 )
    {
      v15 = CmOpenDeviceRegKey((int)a1, v37, 16, 0, 1, 0, (int)&v32, 0);
      if ( v15 < 0 )
        goto LABEL_20;
    }
    v15 = CmGetDeviceRegKeySecurityDescriptor(a1, a3, &v35);
    if ( v15 < 0 )
    {
      v22 = v30;
      v23 = v31;
      v24 = v32;
      v25 = v35;
      goto LABEL_21;
    }
    v33 = v35;
    if ( v35 )
      v20 = 917510;
    v26 = PnpCtxRegCreateTree(a1, v36, v34, (unsigned __int8)a3 == 19, v20, v35, &v30, a8);
    if ( v26 == -1073741444 )
    {
      v15 = -1073741595;
    }
    else
    {
      if ( v26 < 0 )
        goto LABEL_62;
      if ( v20 == a5 )
      {
        v29 = v30;
        v22 = 0;
        v30 = 0;
        *a7 = v29;
        goto LABEL_52;
      }
      if ( a1 )
        v27 = *a1;
      else
        v27 = 0;
      v26 = SysCtxRegOpenKey(v27, v30, 0, 0);
      if ( v26 == -1073741444 )
      {
        v15 = -1073741772;
        goto LABEL_51;
      }
      if ( v26 < 0 )
LABEL_62:
        v15 = v26;
    }
LABEL_51:
    v22 = v30;
LABEL_52:
    v23 = v31;
    v24 = v32;
    v25 = v33;
    goto LABEL_21;
  }
  *a8 = 2;
LABEL_20:
  v22 = v30;
  v23 = v31;
  v24 = v32;
  v25 = 0;
LABEL_21:
  if ( v24 )
  {
    ZwClose();
    v22 = v30;
    v23 = v31;
  }
  if ( v23 )
  {
    ZwClose();
    v22 = v30;
  }
  if ( v22 )
    ZwClose();
  if ( v25 )
    ExFreePoolWithTag(v25);
  if ( v14 )
    ExFreePoolWithTag((unsigned int)v14);
  return v15;
}
