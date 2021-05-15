// PiDmObjectProcessPropertyChange 
 
int __fastcall PiDmObjectProcessPropertyChange(int result, int a2, unsigned __int8 *a3, int a4, unsigned int a5, _BYTE *a6)
{
  unsigned __int8 *v7; // r4
  int v8; // r5
  int v9; // r7
  unsigned int *v10; // r9
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r6
  unsigned int v15; // r2
  unsigned __int8 *v16; // r6
  int v17; // r0
  int v18; // r5
  int v19; // r10
  _BYTE *v20; // r7
  _BYTE *v21; // r6
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // r3
  unsigned int v27; // r1
  unsigned int v28; // r6
  int v29; // r10
  int *v30; // r7
  unsigned __int8 *v31; // r6
  int *v32; // r6
  int v33; // r7
  unsigned int v34; // r2
  int v35; // r0
  int v36; // r6
  unsigned int v37; // r2
  unsigned int v38; // r3
  int v39; // r2
  char *v40; // r5
  int v41; // r1
  unsigned int v42; // r0
  unsigned int v43; // r2
  unsigned int v44; // r1
  int v45; // r3
  _BYTE *v46; // [sp+20h] [bp-58h]
  int v47; // [sp+24h] [bp-54h]
  int v48; // [sp+28h] [bp-50h]
  int v49; // [sp+2Ch] [bp-4Ch] BYREF
  int v50; // [sp+30h] [bp-48h]
  _BYTE *v51; // [sp+34h] [bp-44h]
  int v52; // [sp+38h] [bp-40h] BYREF
  _BYTE *v53; // [sp+3Ch] [bp-3Ch]
  int v54; // [sp+40h] [bp-38h]
  unsigned __int8 *v55; // [sp+44h] [bp-34h]
  int v56; // [sp+48h] [bp-30h]
  int v57; // [sp+4Ch] [bp-2Ch]
  int v58; // [sp+50h] [bp-28h]
  unsigned int v59; // [sp+54h] [bp-24h]
  unsigned int *v60; // [sp+58h] [bp-20h]
  int varg_r0; // [sp+80h] [bp+8h]
  int varg_r1; // [sp+84h] [bp+Ch]
  unsigned __int8 *varg_r2; // [sp+88h] [bp+10h]
  int varg_r3; // [sp+8Ch] [bp+14h]

  varg_r0 = result;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v51 = 0;
  v52 = 0;
  v46 = 0;
  v47 = 0;
  v56 = 0;
  v57 = result;
  v58 = 0;
  v53 = 0;
  v54 = a2;
  v49 = 0;
  v50 = 0;
  v48 = 0;
  v7 = 0;
  v8 = 0;
  *a6 = 0;
  v55 = 0;
  if ( a4 )
    return result;
  result = PiDmGetCacheKeys();
  if ( !v59 )
    return result;
  result = PiDmGetCachedKeyIndex(v60, v59, a5);
  v9 = result;
  if ( result >= v59 )
    return result;
  if ( !a3 )
    return sub_7C5BDC();
  v10 = &v60[4 * result];
  if ( v10[3] == 1 )
  {
    v8 = ((int (__fastcall *)(int, int, int, int, _DWORD))PnpGetObjectProperty)(1517317712, 16, v54, v57, 0);
    if ( v8 == -1073741275 )
    {
      v8 = 0;
      v11 = 0;
      v48 = 0;
    }
    else
    {
      v11 = v56;
    }
    v47 = v11;
    v46 = v53;
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = KeAbPreAcquire((unsigned int)a3, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex(a3);
  while ( __strex(v15 | 1, a3) );
  __dmb(0xBu);
  if ( (v15 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a3, v13, (unsigned int)a3);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v16 = &a3[20 * v9];
  if ( !*((_DWORD *)v16 + 16) )
  {
    if ( !v10[3] )
    {
LABEL_59:
      v21 = a6;
      goto LABEL_30;
    }
    goto LABEL_53;
  }
  if ( v8 < 0 || !v10[3] )
  {
LABEL_53:
    v19 = v47;
    goto LABEL_54;
  }
  v17 = PiDmCacheDataDecode(v16 + 64, &v49, 0, 0, &v52);
  v8 = v17;
  if ( v17 != -1073741275 )
  {
    if ( v17 >= 0 || v17 == -1073741789 )
    {
      v18 = v52;
      if ( v52 && (v51 = (_BYTE *)ExAllocatePoolWithTag(1, v52, 1517317712)) == 0 )
      {
        v8 = -1073741670;
      }
      else
      {
        v8 = PiDmCacheDataDecode(v16 + 64, &v49, v51, v18, &v52);
        if ( v8 >= 0 )
        {
          v19 = v47;
          v50 = v49;
          if ( v49 == v48 && v52 == v47 )
          {
            if ( !v52 )
              goto LABEL_29;
            v20 = v46;
            if ( !memcmp((unsigned int)v51, (unsigned int)v46, v52) )
              goto LABEL_29;
            goto LABEL_55;
          }
LABEL_54:
          v20 = v46;
LABEL_55:
          v31 = v16 + 64;
          PiDmCacheDataFree(v31);
          if ( v8 >= 0 && v10[3] == 1 && !v10[2] )
            v8 = PiDmCacheDataEncode(v48, v20, v19, v10[1], 0, v31);
          goto LABEL_59;
        }
      }
    }
    v50 = v49;
    goto LABEL_53;
  }
  v50 = 0;
  v8 = 0;
  if ( v48 )
    goto LABEL_53;
LABEL_29:
  v21 = a6;
  *a6 = 1;
LABEL_30:
  __pld(a3);
  v22 = *(_DWORD *)a3;
  if ( (*(_DWORD *)a3 & 0xFFFFFFF0) > 0x10 )
    v23 = v22 - 16;
  else
    v23 = 0;
  if ( (v22 & 2) != 0 )
    goto LABEL_104;
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned int *)a3);
  while ( v24 == v22 && __strex(v23, (unsigned int *)a3) );
  if ( v24 != v22 )
LABEL_104:
    ExfReleasePushLock(a3, v22);
  result = KeAbPostRelease((unsigned int)a3);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
  *(_WORD *)(v25 + 308) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( !v10[3] || *v21 )
    goto LABEL_40;
  v27 = a5;
  v28 = 0;
  v29 = *(_DWORD *)(a5 + 16);
  v30 = PiDmAggregatedBooleanDefs;
  while ( 1 )
  {
    result = v30[1];
    if ( *(_DWORD *)(result + 16) == v29 )
      break;
LABEL_50:
    ++v28;
    v30 += 7;
    if ( v28 >= 3 )
      goto LABEL_40;
  }
  result = memcmp(result, v27, 16);
  if ( result || (result = v57, v57 != *v30) )
  {
    v27 = a5;
    goto LABEL_50;
  }
  v32 = &PiDmAggregatedBooleanDefs[7 * v28];
  if ( v32 )
  {
    result = PiDmGetReferencedObjectFromProperty(v57, v54, a3);
    v7 = v55;
    if ( result >= 0 )
    {
      v33 = v32[6];
      v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v34 + 308);
      v35 = KeAbPreAcquire((unsigned int)v7, 0, 0);
      v36 = v35;
      do
        v37 = __ldrex(v7);
      while ( __strex(v37 | 1, v7) );
      __dmb(0xBu);
      if ( (v37 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v7, v35, (unsigned int)v7);
      if ( v36 )
        *(_BYTE *)(v36 + 14) |= 1u;
      v38 = 0x80000000;
      if ( v8 < 0 || (v39 = *(_DWORD *)&v7[v33], v39 == 0x80000000) )
      {
LABEL_79:
        *(_DWORD *)&v7[v33] = v38;
      }
      else
      {
        if ( v50 != 17 )
        {
          v40 = v46;
          goto LABEL_76;
        }
        if ( (char)*v51 != -1 )
        {
          v40 = v46;
          goto LABEL_75;
        }
        if ( v48 != 17 || (v40 = v46, !*v46) )
        {
          v38 = v39 - 1;
          goto LABEL_79;
        }
LABEL_75:
        if ( !*v51 )
        {
LABEL_76:
          if ( v48 == 17 && *v40 == -1 )
          {
            v38 = v39 + 1;
            goto LABEL_79;
          }
        }
      }
      __pld(v7);
      v41 = *(_DWORD *)v7;
      if ( (*(_DWORD *)v7 & 0xFFFFFFF0) > 0x10 )
        v42 = v41 - 16;
      else
        v42 = 0;
      if ( (v41 & 2) != 0 )
        goto LABEL_100;
      __dmb(0xBu);
      do
        v43 = __ldrex((unsigned int *)v7);
      while ( v43 == v41 && __strex(v42, (unsigned int *)v7) );
      if ( v43 != v41 )
LABEL_100:
        ExfReleasePushLock(v7, v41);
      result = KeAbPostRelease((unsigned int)v7);
      v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v45 = (__int16)(*(_WORD *)(v44 + 0x134) + 1);
      *(_WORD *)(v44 + 308) = v45;
      if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
        result = KiCheckForKernelApcDelivery(result);
    }
  }
LABEL_40:
  if ( v51 )
    result = ExFreePoolWithTag((unsigned int)v51);
  if ( v46 )
    result = ExFreePoolWithTag((unsigned int)v46);
  if ( v7 )
    result = PiDmObjectRelease(v7);
  if ( v58 )
    result = PiDmObjectRelease(a3);
  return result;
}
