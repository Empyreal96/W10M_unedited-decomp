// -StRegionFindCompact@-$ST_STORE@USM_TRAITS@@@@SAPAT_ST_REGION_STATE@1@PAU_ST_DATA_MGR@1@KK@Z 
 
__int16 *__fastcall ST_STORE<SM_TRAITS>::StRegionFindCompact(_DWORD *a1, int a2)
{
  int v3; // r3
  int v4; // lr
  int v5; // r3
  __int16 *v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r1
  int v9; // r0
  int v10; // r2
  int v11; // r8
  int v12; // r3
  __int16 *v13; // r5
  unsigned int v14; // r10
  unsigned int v15; // r9
  int v16; // r1
  unsigned int v17; // r2
  __int16 v19; // [sp+0h] [bp-30h] BYREF
  int v20; // [sp+4h] [bp-2Ch]
  int v21; // [sp+8h] [bp-28h]
  unsigned int v22; // [sp+Ch] [bp-24h]
  unsigned int v23; // [sp+10h] [bp-20h]

  v3 = a1[23];
  v4 = a2;
  v20 = a2;
  v5 = *(_DWORD *)(v3 + 3860);
  v6 = &v19;
  __dmb(0xBu);
  if ( v5 )
    v7 = 0;
  else
    v7 = (unsigned int)(a1[24] + 1) >> 1;
  v8 = a1[32];
  v9 = a1[76];
  v10 = a1[26];
  v11 = 0;
  v22 = v9 + 2 * v8;
  v23 = v8;
  v12 = a1[27];
  v21 = v9;
  v13 = (__int16 *)v9;
  v14 = 0;
  v19 ^= ((v10 - v12 + 1) ^ v19) & 0x1FFF;
  if ( !v8 )
    return 0;
  v15 = a1[18];
  while ( 1 )
  {
    if ( (unsigned int)v13 >= v22 )
    {
      v13 = (__int16 *)v9;
      v11 = 0;
    }
    if ( ((v15 >> 18) & 1) != 0 )
    {
      if ( SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(a1[23], v11) )
        goto LABEL_22;
      v4 = v20;
      v9 = v21;
    }
    v16 = (_BYTE)v15 ? 0 : (unsigned __int16)*v13 >> 13;
    v17 = *v13 & 0x1FFF;
    if ( v17 < v7 && (*v13 & 0x1FFF) != 0 && v16 == v4 )
      break;
    if ( v17 < (*v6 & 0x1FFFu) && (v16 == v4 || (*v13 & 0x1FFF) == 0 && v13 != (__int16 *)(v9 + 2 * a1[3 * v16 + 98])) )
      v6 = v13;
LABEL_22:
    ++v14;
    ++v13;
    ++v11;
    if ( v14 >= v23 )
      goto LABEL_25;
    v4 = v20;
    v9 = v21;
  }
  v6 = v13;
LABEL_25:
  if ( v6 == &v19 )
    return 0;
  return v6;
}
