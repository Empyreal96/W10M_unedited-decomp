// PiDmObjectCreate 
 
int __fastcall PiDmObjectCreate(int a1, unsigned __int16 *a2, _DWORD *a3)
{
  unsigned int v5; // r10
  int v6; // r4
  _BYTE *v7; // r0
  _DWORD *v8; // r5
  int v10; // r0
  int v11; // r4
  int v12; // r1
  int v13; // r1
  unsigned __int16 *v14; // r7
  __int16 v15; // r3
  _DWORD *v16; // r3
  int *v17; // r7
  unsigned int *v18; // r9
  unsigned int v19; // r8
  unsigned int v20; // r0
  int v21; // r1
  int v22; // r3
  char v23[4]; // [sp+8h] [bp-40h] BYREF
  unsigned int v24; // [sp+Ch] [bp-3Ch] BYREF
  int v25; // [sp+10h] [bp-38h] BYREF
  int v26; // [sp+14h] [bp-34h] BYREF
  unsigned int *v27; // [sp+18h] [bp-30h] BYREF
  _DWORD *v28; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 v29; // [sp+20h] [bp-28h] BYREF
  __int16 v30; // [sp+22h] [bp-26h]
  unsigned __int16 *v31; // [sp+24h] [bp-24h]

  v23[0] = 0;
  *a3 = 0;
  v28 = a3;
  PiDmGetCacheKeys(a1, &v27, (int *)&v24);
  v5 = v24;
  v6 = 20 * v24;
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, 20 * v24 + 64, 1517317712);
  v8 = v7;
  if ( !v7 )
    return sub_7C9018();
  memset(v7, 0, v6 + 64);
  *v8 = 0;
  __dmb(0xBu);
  v8[1] = 1;
  v8[5] = a1;
  v10 = PnpAllocatePWSTR(a2, 0x7FFFFFFFu, 1517317712, v8 + 3);
  v11 = v10;
  if ( v10 < 0 )
    goto LABEL_25;
  v12 = v8[3];
  if ( a1 == 3 )
  {
    v11 = CmSetDeviceInterfacePathFormat(v10, v12, 0);
    if ( v11 < 0 )
      goto LABEL_25;
    v22 = v8[3];
    v29 = 0;
    v14 = (unsigned __int16 *)(v22 + 8);
    v31 = 0;
    v30 = 0;
    if ( v22 != -8 )
    {
      v11 = sub_455E68(v14, v21, &v25);
      if ( v11 < 0 )
        goto LABEL_25;
      v15 = v25;
LABEL_9:
      v29 = 2 * v15;
      v30 = 2 * v15 + 2;
      v31 = v14;
      goto LABEL_10;
    }
  }
  else
  {
    v11 = PnpValidateObjectName(PiPnpRtlCtx, v12, a1, 0);
    if ( v11 < 0 )
      goto LABEL_25;
    v14 = (unsigned __int16 *)v8[3];
    v29 = 0;
    v30 = 0;
    v31 = 0;
    if ( v14 )
    {
      v11 = sub_455E68(v14, v13, &v26);
      if ( v11 < 0 )
        goto LABEL_25;
      v15 = v26;
      goto LABEL_9;
    }
  }
LABEL_10:
  v11 = RtlHashUnicodeString(&v29, 1, 0, v8 + 4);
  switch ( a1 )
  {
    case 1:
      v16 = v8 + 11;
      goto LABEL_16;
    case 4:
    case 2:
      v16 = v8 + 7;
      goto LABEL_16;
    case 5:
      v8[7] = v8 + 7;
      v8[8] = v8 + 7;
      v16 = v8 + 10;
LABEL_16:
      *v16 = v16;
      v16[1] = v16;
      break;
  }
  v17 = PiDmAggregatedBooleanDefs;
  v18 = v27;
  v19 = 0;
  while ( a1 != *v17 )
  {
LABEL_19:
    ++v19;
    v17 += 7;
    if ( v19 >= 3 )
      goto LABEL_20;
  }
  v20 = PiDmGetCachedKeyIndex(v18, v5, v17[1]);
  if ( v20 < v5 )
  {
    v11 = PiDmCacheDataEncode(17, v23, 1, v18[4 * v20 + 1], v18[4 * v20 + 2], &v8[5 * v20 + 16]);
    if ( v11 < 0 )
      goto LABEL_25;
    goto LABEL_19;
  }
  v11 = -1073741595;
LABEL_20:
  if ( v11 >= 0 )
  {
    *v28 = v8;
    return v11;
  }
LABEL_25:
  PiDmObjectRelease((int)v8);
  return v11;
}
