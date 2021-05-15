// _CmSetDeviceMappedProperty 
 
int __fastcall CmSetDeviceMappedProperty(int a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8)
{
  int v10; // r4
  int (**v11)[5]; // r10
  int v12; // r8
  unsigned int v13; // r1
  int (*v14)[5]; // t1
  int v15; // r2
  int (**v16)[5]; // r10
  int v17; // r8
  unsigned int v18; // r1
  int (*v19)[5]; // t1
  int v20; // r2
  int (**v21)[5]; // r10
  int v22; // r8
  unsigned int v23; // r1
  int (*v24)[5]; // t1
  int v25; // r8
  int (**v26)[5]; // r7
  int v27; // r6
  unsigned int v28; // r1
  int (*v29)[5]; // t1
  int v31; // r6
  int v32; // r0
  int v34; // [sp+14h] [bp-24h]
  int v35; // [sp+14h] [bp-24h]

  v10 = -1073741802;
  if ( a4 )
    return v10;
  if ( CmIsRootDevice(a2, (int)a2, -1073741802, 0) )
    return -1073741790;
  v11 = &CmDeviceRegPropMap;
  v12 = 0;
  while ( 1 )
  {
    v14 = *v11;
    v11 += 4;
    v13 = (unsigned int)v14;
    if ( v14 )
    {
      if ( *(_DWORD *)(a5 + 16) == *(_DWORD *)(v13 + 16) && !memcmp(a5, v13, 16) )
        break;
    }
    if ( (unsigned int)++v12 >= 0x21 )
      goto LABEL_7;
  }
  v10 = CmSetDeviceMappedPropertyFromRegProp(a1, a2, a3, a5, a6, a7, a8);
  if ( v10 != -1073741802 )
    return v10;
LABEL_7:
  v15 = *(_DWORD *)(a5 + 16);
  v16 = &off_8C97B0;
  v17 = 0;
  v34 = v15;
  while ( 1 )
  {
    v19 = *v16;
    v16 += 4;
    v18 = (unsigned int)v19;
    if ( v15 == (*v19)[4] )
      break;
LABEL_9:
    if ( (unsigned int)++v17 >= 0xD )
      goto LABEL_10;
  }
  if ( memcmp(a5, v18, 16) )
  {
    v15 = v34;
    goto LABEL_9;
  }
  if ( !a6 || a6 == 1 )
    return sub_7C8B98();
  CmSetDeviceMappedPropertyFromDriverKeyRegValue(a1, a2, a5, a6, a7, a8);
  v10 = -1073741802;
LABEL_10:
  v20 = *(_DWORD *)(a5 + 16);
  v21 = &off_8C94D0;
  v22 = 0;
  v35 = v20;
  while ( 2 )
  {
    v24 = *v21;
    v21 += 4;
    v23 = (unsigned int)v24;
    if ( v20 != (*v24)[4] )
    {
LABEL_12:
      if ( (unsigned int)++v22 >= 2 )
        goto LABEL_13;
      continue;
    }
    break;
  }
  if ( memcmp(a5, v23, 16) )
  {
    v20 = v35;
    goto LABEL_12;
  }
  if ( !a6 || a6 == 1 )
  {
    v31 = a3;
    v32 = CmDeleteDeviceMappedPropertyFromInstanceKeyRegValue(a1, a2, a3, a5);
  }
  else
  {
    v31 = a3;
    v32 = CmSetDeviceMappedPropertyFromInstanceKeyRegValue(a1, a2, a3, a5, a6, a7, a8);
  }
  v10 = v32;
  if ( v32 >= 0 )
    PnpObjectRaisePropertyChangeEvent(a1, (int)a2, 1, v31, 0, a5);
  if ( v10 != -1073741802 )
    return v10;
LABEL_13:
  v25 = *(_DWORD *)(a5 + 16);
  v26 = &off_8C9318;
  v27 = 0;
  while ( 1 )
  {
    v29 = *v26;
    v26 += 2;
    v28 = (unsigned int)v29;
    if ( v25 == (*v29)[4] && !memcmp(a5, v28, 16) )
      break;
    if ( (unsigned int)++v27 >= 0x18 )
      return v10;
  }
  return -1073741790;
}
