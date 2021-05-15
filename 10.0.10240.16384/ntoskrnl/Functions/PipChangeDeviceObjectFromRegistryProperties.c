// PipChangeDeviceObjectFromRegistryProperties 
 
int __fastcall PipChangeDeviceObjectFromRegistryProperties(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  int v7; // r7
  int v8; // r0
  int v9; // r1
  int v10; // r0
  int v11; // r1
  int v12; // r0
  _DWORD *v13; // r2
  int v14; // r1
  int v15; // r3
  int v16; // r6
  int v17; // r0
  int v18; // r7
  int v19; // r10
  int v20; // r4
  int v21; // r4
  int v22; // r2
  int v23; // r0
  _DWORD *v24; // r1
  char v25; // [sp+10h] [bp-68h] BYREF
  bool v26[3]; // [sp+11h] [bp-67h] BYREF
  int v27; // [sp+14h] [bp-64h]
  int v28[2]; // [sp+18h] [bp-60h] BYREF
  int v29[2]; // [sp+20h] [bp-58h] BYREF
  int v30; // [sp+28h] [bp-50h]
  int v31; // [sp+2Ch] [bp-4Ch]
  int v32; // [sp+30h] [bp-48h]
  int v33; // [sp+34h] [bp-44h]
  int v34; // [sp+38h] [bp-40h]
  int v35; // [sp+3Ch] [bp-3Ch]
  char v36[20]; // [sp+40h] [bp-38h] BYREF

  v28[1] = a2;
  v29[0] = a4;
  if ( !a1 )
    return sub_7CB640();
  v7 = *(_DWORD *)(a1[44] + 20);
  v30 = 0;
  v31 = 0;
  v29[1] = 0;
  v27 = 0;
  v28[0] = 0;
  v33 = 0;
  v8 = PipGetRegistryDwordWithFallback(26, *(_DWORD *)(v7 + 24));
  v9 = *(_DWORD *)(v7 + 24);
  v34 = v8;
  v10 = PipGetRegistryDwordWithFallback(27, v9);
  v11 = *(_DWORD *)(v7 + 24);
  v35 = v10;
  v12 = PipGetRegistryDwordWithFallback(28, v11);
  if ( a5 || (v13 = (_DWORD *)a1[4]) == 0 )
    v13 = a1;
  v14 = 0;
  while ( v13 )
  {
    v15 = v13[8];
    v13 = (_DWORD *)v13[4];
    v14 |= v15;
  }
  v16 = 0;
  v32 = 0;
  v27 = (v14 | v27) & 0x5010F;
  v17 = PipGetRegistrySecurityWithFallback(v12);
  v18 = v17;
  v19 = v30;
  if ( v17 )
  {
    v20 = RtlGetOwnerSecurityDescriptor(v17, v28, v26);
    if ( v20 < 0 )
      goto LABEL_48;
    if ( v28[0] )
      v16 = 1;
    v20 = RtlGetGroupSecurityDescriptor(v18, v28, v26);
    if ( v20 < 0 )
      goto LABEL_48;
    if ( v28[0] )
      v16 |= 2u;
    v20 = RtlGetSaclSecurityDescriptor(v18, &v25, v29, v26);
    if ( v20 < 0 )
      goto LABEL_48;
    if ( v25 )
      v16 |= 8u;
    v20 = RtlGetDaclSecurityDescriptor(v18, &v25, v29, v26);
    if ( v20 < 0 )
    {
LABEL_48:
      v23 = 0;
LABEL_34:
      if ( v18 )
      {
        if ( !v23 )
          ExFreePoolWithTag(v18);
      }
      return v20;
    }
    v21 = v27;
    if ( v25 )
      v16 |= 4u;
    goto LABEL_21;
  }
  if ( !v34 )
  {
    v21 = v27;
LABEL_23:
    if ( v35 && v33 )
      a1[7] |= 8u;
    v22 = a1[4];
    a1[8] = a1[8] & 0xFFFAFEF0 | v21;
    while ( v22 )
    {
      *(_DWORD *)(v22 + 32) |= v21;
      v22 = *(_DWORD *)(v22 + 16);
    }
    v20 = 0;
    if ( v18 )
      v20 = ObSetSecurityObjectByPointer((int)a1, v16, v18);
    v23 = v31;
    v24 = a1;
    do
    {
      if ( (*(_DWORD *)(v24[2] + 8) & 0x100) != 0 )
        *(_DWORD *)(*(_DWORD *)(a1[44] + 20) + 268) |= 0xC00000u;
      if ( v23 && v24[38] )
        *(_DWORD *)(v24[44] + 16) |= 0x800u;
      v24 = (_DWORD *)v24[4];
    }
    while ( v24 );
    goto LABEL_34;
  }
  memset(v36, 0, sizeof(v36));
  v21 = v27;
  v18 = IopCreateDefaultDeviceSecurityDescriptor(v30, v27);
  if ( v18 )
  {
    v16 = v32;
    v31 = 1;
LABEL_21:
    if ( v34 )
      a1[11] = v19;
    goto LABEL_23;
  }
  return -1073741823;
}
