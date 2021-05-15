// PiDqQueryApplyObjectEvent 
 
int __fastcall PiDqQueryApplyObjectEvent(int a1, _DWORD *a2)
{
  int v3; // r2
  _DWORD *v4; // r9
  int result; // r0
  int v6; // r8
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r9
  int v10; // r6
  unsigned int v11; // r7
  unsigned int v12; // r8
  _DWORD *v13; // r4
  unsigned int v14; // r6
  _DWORD *v15; // r4
  unsigned int v16; // r8
  int v17; // r7
  _DWORD *v18; // r5
  int v19; // r3
  unsigned int v20; // r8
  int v21; // r6
  unsigned int v22; // r7
  _DWORD *v23; // r5
  _DWORD *v24; // r4
  int v25; // r2
  unsigned int v26; // r2
  unsigned __int8 *v27; // r4
  int v28; // r0
  unsigned int v29; // r2
  BOOL v30; // r7
  int v31; // r1
  unsigned int v32; // r2
  unsigned int v33; // r1
  int v34; // r3
  int v35; // r3
  int v36; // r5
  int v37; // r6
  int v38; // r7
  unsigned int v39; // r2
  int v40; // r0
  unsigned int v41; // r2
  int v42; // r1
  unsigned int v43; // r2
  unsigned int v44; // r1
  int v45; // r3
  unsigned int v46; // r2
  int v47; // r0
  unsigned int v48; // r2
  int v49; // r0
  int v50; // r1
  unsigned int v51; // r2
  unsigned int v52; // r1
  int v53; // r3
  unsigned int v54; // r2
  int v55; // r0
  unsigned int v56; // r2
  int v57; // r1
  unsigned int v58; // r0
  unsigned int v59; // r2
  unsigned int v60; // r1
  int v61; // r3
  char v62[4]; // [sp+8h] [bp-38h] BYREF
  int v63; // [sp+Ch] [bp-34h]
  int v64; // [sp+10h] [bp-30h]
  _DWORD *v65; // [sp+14h] [bp-2Ch]
  int v66; // [sp+18h] [bp-28h]
  _DWORD *v67[9]; // [sp+1Ch] [bp-24h] BYREF

  v3 = a2[1];
  v4 = (_DWORD *)a1;
  v65 = (_DWORD *)a1;
  result = 0;
  v63 = 0;
  v64 = 0;
  v6 = 0;
  v66 = 0;
  v67[0] = 0;
  v62[0] = 0;
  if ( (v3 & 3) != 0 || (v3 & 8) == 0 && !a2[11] )
    goto LABEL_44;
  if ( (v3 & 4) != 0 )
    return sub_7C7A44();
  v7 = v4[3];
  if ( (*(_DWORD *)(v7 + 32) & 2) != 0 )
    JUMPOUT(0x7C7A66);
  v8 = *(_DWORD *)(v7 + 44);
  if ( (*(_DWORD *)(v7 + 32) & 4) == 0 )
  {
    v20 = 0;
    if ( !v8 )
      goto LABEL_16;
    v21 = 0;
    while ( 1 )
    {
      v22 = 0;
      v23 = (_DWORD *)(*(_DWORD *)(v4[3] + 48) + v21);
      if ( a2[11] )
      {
        v24 = a2 + 12;
        while ( 1 )
        {
          if ( v23[4] == v24[4] )
          {
            result = memcmp((unsigned int)v23, (unsigned int)v24, 16);
            if ( !result && v23[5] == v24[5] )
              break;
          }
          ++v22;
          v24 += 7;
          if ( v22 >= a2[11] )
            goto LABEL_39;
        }
        result = v23[6];
        if ( result != v24[6] )
          JUMPOUT(0x7C7B06);
        if ( v24[5] == 1 )
          JUMPOUT(0x7C7B20);
        v63 = 1;
      }
LABEL_39:
      ++v20;
      v21 += 28;
      if ( v20 >= *(_DWORD *)(v4[3] + 44) )
        goto LABEL_16;
    }
  }
  v9 = 0;
  if ( !v8 )
  {
    v4 = v65;
    goto LABEL_17;
  }
  v10 = 0;
  while ( 1 )
  {
    v11 = 0;
    v12 = *(_DWORD *)(v65[3] + 48) + v10;
    if ( a2[11] )
      break;
LABEL_14:
    ++v9;
    v10 += 28;
    if ( v9 >= *(_DWORD *)(v65[3] + 44) )
      goto LABEL_15;
  }
  v13 = a2 + 12;
  while ( *(_DWORD *)(v12 + 16) != v13[4] )
  {
LABEL_13:
    ++v11;
    v13 += 7;
    if ( v11 >= a2[11] )
      goto LABEL_14;
  }
  result = memcmp(v12, (unsigned int)v13, 16);
  if ( result || (v25 = v13[5], *(_DWORD *)(v12 + 20) != v25) )
  {
    result = v63;
    goto LABEL_13;
  }
  if ( v25 == 1 )
    JUMPOUT(0x7C7AC4);
  if ( v13[6] )
    JUMPOUT(0x7C7AD0);
  v63 = 1;
LABEL_15:
  v4 = v65;
LABEL_16:
  v6 = 0;
LABEL_17:
  if ( !*(_DWORD *)(v4[3] + 20) )
  {
    v6 = (a2[1] & 8) != 0;
    v67[0] = (_DWORD *)v6;
  }
  v14 = 0;
  if ( !v6 )
  {
    v15 = a2 + 12;
    do
    {
      if ( v14 >= a2[11] )
        break;
      v16 = 0;
      if ( *(_DWORD *)(v4[3] + 52) )
      {
        v17 = 0;
        while ( 1 )
        {
          v18 = (_DWORD *)(*(_DWORD *)(v4[3] + 56) + v17);
          if ( v18[5] == v15[4] )
          {
            result = memcmp((unsigned int)(v18 + 1), (unsigned int)v15, 16);
            if ( !result && v18[6] == v15[5] )
              break;
          }
          ++v16;
          v17 += 44;
          if ( v16 >= *(_DWORD *)(v4[3] + 52) )
            goto LABEL_26;
        }
        result = v18[7];
        if ( result != v15[6] )
          JUMPOUT(0x7C7B2C);
        if ( v15[5] == 1 )
          JUMPOUT(0x7C7B46);
        v6 = 1;
        v67[0] = (_DWORD *)1;
      }
      else
      {
LABEL_26:
        v6 = (int)v67[0];
      }
      ++v14;
      v15 += 7;
    }
    while ( !v6 );
  }
  if ( !v63 && !v6 )
  {
    v19 = v64;
    goto LABEL_31;
  }
LABEL_44:
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v26 + 308);
  v27 = (unsigned __int8 *)(v4 + 8);
  v28 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
  do
    v29 = __ldrex(v27);
  while ( __strex(v29 | 1, v27) );
  __dmb(0xBu);
  if ( (v29 & 1) != 0 )
    JUMPOUT(0x7C7B52);
  if ( v28 )
    *(_BYTE *)(v28 + 14) |= 1u;
  v67[0] = *((_DWORD **)a2 + 2);
  v30 = RtlLookupElementGenericTableAvl((int)(v4 + 9), (int)v67) != 0;
  __pld(v27);
  v31 = *(_DWORD *)v27;
  if ( (*(_DWORD *)v27 & 0xFFFFFFF0) > 0x10 )
    JUMPOUT(0x7C7B60);
  if ( (v31 & 2) != 0 )
    goto LABEL_138;
  __dmb(0xBu);
  do
    v32 = __ldrex((unsigned int *)v27);
  while ( v32 == v31 && __strex(0, (unsigned int *)v27) );
  if ( v32 != v31 )
LABEL_138:
    JUMPOUT(0x7C7B68);
  result = KeAbPostRelease((unsigned int)(v4 + 8));
  v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v34 = (__int16)(*(_WORD *)(v33 + 0x134) + 1);
  *(_WORD *)(v33 + 308) = v34;
  if ( !v34 )
    JUMPOUT(0x7C7B72);
  v35 = a2[1];
  if ( (v35 & 2) != 0 )
    JUMPOUT(0x7C7C7A);
  if ( (v35 & 1) == 0 && !v6 )
  {
    v36 = v30;
    goto LABEL_68;
  }
  if ( *(_DWORD *)(v4[3] + 20) )
    JUMPOUT(0x7C7B90);
  v36 = 1;
  v62[0] = 1;
  if ( !*(_DWORD *)(v4[3] + 20) )
  {
    result = PiPnpRtlApplyMandatoryFilters(
               PiPnpRtlCtx,
               *(_DWORD *)(a2[2] + 12),
               *(_DWORD *)(a2[2] + 20),
               0,
               v4 + 4,
               v62);
    v64 = result;
    if ( result == -1073741772 || result == -1073741275 )
      JUMPOUT(0x7C7BF8);
    v36 = (unsigned __int8)v62[0];
    if ( result < 0 )
      goto LABEL_143;
  }
  if ( !v36 )
  {
LABEL_69:
    if ( v30 )
    {
      v38 = 3;
      v37 = 1;
      v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v54 + 308);
      v55 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
      do
        v56 = __ldrex(v27);
      while ( __strex(v56 | 1, v27) );
      __dmb(0xBu);
      if ( (v56 & 1) != 0 )
        JUMPOUT(0x7C7C4E);
      if ( v55 )
        *(_BYTE *)(v55 + 14) |= 1u;
      PiDqQueryDeleteObjectFromResultSet(v4, a2[2]);
      __pld(v27);
      v57 = *(_DWORD *)v27;
      if ( (*(_DWORD *)v27 & 0xFFFFFFF0) > 0x10 )
        v58 = v57 - 16;
      else
        v58 = 0;
      if ( (v57 & 2) != 0 )
        goto LABEL_133;
      __dmb(0xBu);
      do
        v59 = __ldrex((unsigned int *)v27);
      while ( v59 == v57 && __strex(v58, (unsigned int *)v27) );
      if ( v59 != v57 )
LABEL_133:
        ExfReleasePushLock(v4 + 8, v57);
      result = KeAbPostRelease((unsigned int)(v4 + 8));
      v60 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v61 = (__int16)(*(_WORD *)(v60 + 0x134) + 1);
      *(_WORD *)(v60 + 308) = v61;
      if ( !v61 )
        JUMPOUT(0x7C7C5C);
    }
    else
    {
      v37 = 0;
      v38 = 0;
    }
    goto LABEL_71;
  }
  if ( *(_DWORD *)(v4[3] + 56) )
  {
    result = PiDqQueryEvaluateFilter(v4, *(_DWORD *)(a2[2] + 12), v62);
    v64 = result;
    if ( result == -1073741772 )
      JUMPOUT(0x7C7C06);
    v36 = (unsigned __int8)v62[0];
    if ( result < 0 )
LABEL_143:
      JUMPOUT(0x7C7D50);
  }
LABEL_68:
  if ( !v36 )
    goto LABEL_69;
  if ( !v30 )
  {
    v38 = 1;
    v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v46 + 308);
    v47 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
    do
      v48 = __ldrex(v27);
    while ( __strex(v48 | 1, v27) );
    __dmb(0xBu);
    if ( (v48 & 1) != 0 )
      JUMPOUT(0x7C7C10);
    if ( v47 )
      *(_BYTE *)(v47 + 14) |= 1u;
    v49 = PiDqQueryAddObjectToResultSet(v4, a2[2]);
    __pld(v27);
    v64 = v49;
    v50 = *(_DWORD *)v27;
    if ( (*(_DWORD *)v27 & 0xFFFFFFF0) > 0x10 )
      JUMPOUT(0x7C7C1E);
    if ( (v50 & 2) != 0 )
      goto LABEL_155;
    __dmb(0xBu);
    do
      v51 = __ldrex((unsigned int *)v27);
    while ( v51 == v50 && __strex(0, (unsigned int *)v27) );
    if ( v51 != v50 )
LABEL_155:
      JUMPOUT(0x7C7C26);
    result = KeAbPostRelease((unsigned int)(v4 + 8));
    v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v53 = (__int16)(*(_WORD *)(v52 + 0x134) + 1);
    *(_WORD *)(v52 + 308) = v53;
    if ( !v53 )
      JUMPOUT(0x7C7C30);
    goto LABEL_111;
  }
  v38 = 2;
  if ( v63 )
  {
LABEL_111:
    v37 = 1;
    goto LABEL_71;
  }
  v37 = 0;
LABEL_71:
  v19 = v64;
  if ( v64 < 0 )
    goto LABEL_143;
  if ( !v37 )
    goto LABEL_31;
  v64 = PiDqQueryActionQueueEntryCreate(v38, a2[2], a2, (int)v67);
  if ( v64 < 0 )
    goto LABEL_143;
  v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v39 + 308);
  v40 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
  do
    v41 = __ldrex(v27);
  while ( __strex(v41 | 1, v27) );
  __dmb(0xBu);
  if ( (v41 & 1) != 0 )
    JUMPOUT(0x7C7D12);
  if ( v40 )
    *(_BYTE *)(v40 + 14) |= 1u;
  PiDqQueryAppendActionEntry(v4, v67[0]);
  __pld(v27);
  v42 = *(_DWORD *)v27;
  if ( (*(_DWORD *)v27 & 0xFFFFFFF0) > 0x10 )
    JUMPOUT(0x7C7D20);
  if ( (v42 & 2) != 0 )
    goto LABEL_147;
  __dmb(0xBu);
  do
    v43 = __ldrex((unsigned int *)v27);
  while ( v43 == v42 && __strex(0, (unsigned int *)v27) );
  if ( v43 != v42 )
LABEL_147:
    JUMPOUT(0x7C7D28);
  result = KeAbPostRelease((unsigned int)(v4 + 8));
  v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v45 = (__int16)(*(_WORD *)(v44 + 0x134) + 1);
  *(_WORD *)(v44 + 308) = v45;
  if ( !v45 )
    JUMPOUT(0x7C7D32);
  v19 = v64;
LABEL_31:
  if ( v19 < 0 )
    JUMPOUT(0x7C7D52);
  return result;
}
