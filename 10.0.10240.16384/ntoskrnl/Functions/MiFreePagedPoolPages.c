// MiFreePagedPoolPages 
 
int __fastcall MiFreePagedPoolPages(unsigned int a1, unsigned int a2, int a3)
{
  unsigned int v4; // r7
  int v5; // r3
  int *v6; // r6
  int *v7; // r10
  int v8; // lr
  unsigned int v9; // r1
  int v10; // r3
  int v11; // lr
  int result; // r0
  unsigned int v13; // r10
  __int16 v14; // r3
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  char v18; // r3
  unsigned int v19; // r8
  unsigned int v20; // r0
  unsigned int v21; // r4
  int v22; // r5
  unsigned int v23; // lr
  _DWORD *v24; // r1
  int v25; // r3
  unsigned int v26; // r4
  int v27; // r9
  unsigned int v28; // r1
  unsigned int v29; // r1
  unsigned int v30; // r8
  int v31; // r9
  unsigned int v32; // r4
  unsigned int v33; // r1
  __int16 v34; // r3
  int v35; // r3
  unsigned int v36; // r4
  int v37; // r2
  int *v38; // lr
  int *v39; // r9
  unsigned int v40; // r2
  int v41; // r3
  unsigned int v42; // r1
  unsigned int v43; // r0
  int v44; // r3
  unsigned int v45; // lr
  int v46; // t1
  unsigned int v47; // r1
  int v48; // r0
  __int16 v49; // r3
  unsigned int *v50; // r2
  unsigned int v51; // r4
  unsigned int v52; // r5
  unsigned int v53; // r4
  int v54; // r4
  unsigned int v55; // r0
  unsigned int v56; // r8
  unsigned int v57; // lr
  int v58; // r9
  unsigned int v59; // r0
  _DWORD *v60; // r4
  int v61; // r3
  unsigned int v62; // r0
  unsigned int v63; // r0
  int v64; // r3
  unsigned int v65; // [sp+8h] [bp-F0h]
  int v66; // [sp+Ch] [bp-ECh]
  unsigned int v67; // [sp+10h] [bp-E8h]
  unsigned int v68; // [sp+14h] [bp-E4h]
  unsigned int v69; // [sp+18h] [bp-E0h]
  int v70; // [sp+1Ch] [bp-DCh]
  unsigned int v71; // [sp+20h] [bp-D8h]
  int v72; // [sp+24h] [bp-D4h]
  int v73[2]; // [sp+28h] [bp-D0h] BYREF
  int v74; // [sp+30h] [bp-C8h] BYREF
  int v75; // [sp+34h] [bp-C4h]
  int v76; // [sp+38h] [bp-C0h]
  int v77; // [sp+3Ch] [bp-BCh]
  int v78; // [sp+40h] [bp-B8h] BYREF
  char v79; // [sp+44h] [bp-B4h]
  char v80; // [sp+45h] [bp-B3h]
  int v81; // [sp+48h] [bp-B0h]
  int v82; // [sp+4Ch] [bp-ACh]
  int v83; // [sp+50h] [bp-A8h]
  int v84; // [sp+54h] [bp-A4h]

  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  v4 = ((a2 & 0xFFF) != 0) + (a2 >> 12);
  v72 = 0;
  if ( a1 < dword_63389C )
    JUMPOUT(0x54BB46);
  v5 = *((unsigned __int8 *)&MiState[2423]
       + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  switch ( v5 )
  {
    case 14:
      v6 = (int *)&unk_632CF4;
      v70 = 14;
      v41 = 0;
      v7 = &dword_634E80;
      break;
    case 6:
      v6 = dword_634D34;
      v66 = 0;
      v70 = 6;
      v7 = &dword_634E80;
      goto LABEL_5;
    case 1:
      v70 = 1;
      v41 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
      v72 = 2;
      v6 = (int *)(v41 + 3220);
      v7 = (int *)(v41 + 3248);
      break;
    default:
      return sub_54BB40();
  }
  v66 = v41;
LABEL_5:
  v69 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v8 = (int)(v69 - v6[3]) >> 2;
  v73[0] = v8 + v4;
  v9 = v8 + v4 - 1;
  v67 = v8;
  if ( v9 >= v6[1] )
    goto LABEL_154;
  if ( v4 > 1 )
  {
    v37 = v6[2];
    v38 = (int *)(v37 + 4 * ((unsigned int)v8 >> 5));
    v39 = (int *)(v37 + 4 * (v9 >> 5));
    if ( v38 == v39 )
    {
      v40 = 0xFFFFFFFF >> (32 - v4) << (v67 & 0x1F);
LABEL_62:
      v10 = (*v38 & v40) == v40;
      goto LABEL_9;
    }
    if ( (*v38 & (-1 << (v67 & 0x1F))) == -1 << (v67 & 0x1F) )
    {
      if ( ++v38 == v39 )
      {
LABEL_65:
        v40 = 0xFFFFFFFF >> (31 - (v9 & 0x1F));
        goto LABEL_62;
      }
      while ( 1 )
      {
        v46 = *v38++;
        if ( v46 != -1 )
          break;
        if ( v38 == v39 )
          goto LABEL_65;
      }
    }
LABEL_154:
    KeBugCheck2(194, 80, a1, v67, dword_634D54 << 12, 0);
  }
  if ( v4 != 1 )
    goto LABEL_154;
  v10 = (*(unsigned __int8 *)((v8 >> 3) + v6[2]) >> (v8 & 7)) & 1;
LABEL_9:
  if ( !v10 )
    goto LABEL_154;
  if ( v4 == 1 && !v66 && v6 != (int *)&unk_632CF4 && a3 != 1951624525 && a3 != 1816358221 )
  {
    v11 = dword_6337E8 + 176 * *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
    if ( *(unsigned __int16 *)(v11 + 4) < (unsigned int)dword_632D10 )
    {
      *(_DWORD *)a1 = dword_634C80 ^ a1;
      return RtlpInterlockedPushEntrySList((unsigned __int64 *)v11, (_DWORD *)(a1 + 8));
    }
  }
  MiDeleteSystemPagableVm(v7, 0, v69, v4, 0, &v74);
  if ( !v66 )
  {
    if ( (dword_681250 & 2) != 0 )
    {
      v54 = v74;
      MiReturnResidentAvailable(v74);
      do
        v55 = __ldrex(&dword_634A2C[24]);
      while ( __strex(v55 + v54, &dword_634A2C[24]) );
    }
    else
    {
      MiChargeWsles((int)&dword_634E80, -v4, 0);
    }
  }
  MiReturnCommit((int)MiSystemPartition, v77 - v75);
  v65 = v67 & 0xFFFFFC00;
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x136);
  if ( v6 == (int *)&unk_632CF4 )
  {
    *(_WORD *)(v13 + 310) = v14 - 1;
    v16 = KeAbPreAcquire((unsigned int)dword_634D34, 0, 0);
    do
      v42 = __ldrex((unsigned __int8 *)dword_634D34);
    while ( __strex(v42 | 1, (unsigned __int8 *)dword_634D34) );
    __dmb(0xBu);
    if ( (v42 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(dword_634D34, v16, (unsigned int)dword_634D34);
    if ( !v16 )
      goto LABEL_29;
    v18 = *(_BYTE *)(v16 + 14) | 1;
  }
  else
  {
    *(_WORD *)(v13 + 310) = v14 - 1;
    v15 = KeAbPreAcquire((unsigned int)v6, 0, 0);
    v16 = v15;
    do
      v17 = __ldrex((unsigned __int8 *)v6);
    while ( __strex(v17 | 1, (unsigned __int8 *)v6) );
    __dmb(0xBu);
    if ( (v17 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v6, v15, (unsigned int)v6);
    if ( !v16 )
      goto LABEL_29;
    v18 = *(_BYTE *)(v16 + 14) | 1;
  }
  *(_BYTE *)(v16 + 14) = v18;
LABEL_29:
  RtlClearBits((_BYTE *)v6 + 4, v67, v4);
  v19 = v6[1];
  v20 = v67 & 0xFFFFFC00;
  v68 = v6[5];
  if ( v65 >= v19 )
    v21 = 0;
  else
    v21 = v67 & 0xFFFFFC00;
  v22 = v6[2];
  v23 = v19 - 1;
  while ( 1 )
  {
    v71 = v21;
    if ( v23 - v21 == -1 )
    {
      v26 = -1;
    }
    else
    {
      v24 = (_DWORD *)(v22 + 4 * (v21 >> 5));
      v25 = ~*v24;
      v26 = -1;
      if ( v25 == -1 )
      {
        while ( (unsigned int)++v24 <= v22 + 4 * (v23 >> 5) )
        {
          v25 = ~*v24;
          if ( v25 != -1 )
            goto LABEL_34;
        }
      }
      else
      {
LABEL_34:
        v26 = __clz(__rbit(~v25)) + 32 * (((int)v24 - v22) >> 2);
        if ( v26 > v23 )
        {
          v26 = -1;
        }
        else if ( v26 != -1 )
        {
          break;
        }
      }
    }
    if ( !v71 )
      break;
    v45 = v65 + 1;
    if ( v65 + 1 > v19 )
      v45 = v6[1];
    v23 = v45 - 1;
    v21 = 0;
  }
  v27 = v66;
  if ( v26 == -1 )
  {
    v26 = v6[1];
LABEL_102:
    v52 = v6[5];
    goto LABEL_103;
  }
  if ( v26 < v65 )
    goto LABEL_102;
  v28 = v65 + 1024;
  if ( v26 >= v65 + 1024 )
    goto LABEL_102;
  if ( v73[0] <= v28 )
  {
    v69 = 0;
LABEL_41:
    v29 = 0;
    v30 = 0;
    v65 = 0;
    if ( v67 < v68 )
      v6[5] = v67;
    goto LABEL_43;
  }
  v56 = v6[1];
  v65 += 1024;
  if ( v28 < v56 )
    v57 = v20 + 1024;
  else
    v57 = 0;
  v58 = v6[2];
  v59 = v56 - 1;
  while ( 1 )
  {
    if ( v59 - v57 == -1 )
      goto LABEL_131;
    v60 = (_DWORD *)(v58 + 4 * (v57 >> 5));
    v61 = ~*v60;
    if ( v61 == -1 )
    {
      while ( (unsigned int)++v60 <= v58 + 4 * (v59 >> 5) )
      {
        v61 = ~*v60;
        if ( v61 != -1 )
          goto LABEL_129;
      }
LABEL_131:
      v26 = -1;
      goto LABEL_133;
    }
LABEL_129:
    v26 = __clz(__rbit(~v61)) + 32 * (((int)v60 - v58) >> 2);
    if ( v26 <= v59 )
    {
      if ( v26 != -1 )
        break;
    }
    else
    {
      v26 = -1;
    }
LABEL_133:
    if ( !v57 )
      break;
    v62 = v28 + 1;
    if ( v28 + 1 > v56 )
      v62 = v6[1];
    v59 = v62 - 1;
    v57 = 0;
  }
  if ( v26 >= v28 && v26 < v28 + 1024 )
  {
    v27 = v66;
    v69 = 0;
    goto LABEL_41;
  }
  v52 = v6[5];
  v20 = v65;
  v27 = v66;
  if ( v67 < v68 )
  {
    v52 = v67;
    v6[5] = v67;
  }
LABEL_103:
  if ( v26 >= v20 )
    v53 = v26 & 0xFFFFFC00;
  else
    v53 = v6[1];
  v30 = v53 - v20;
  RtlSetBits((_BYTE *)v6 + 4, v20, v53 - v20);
  if ( v53 < v73[0] && v53 < v52 )
  {
    v29 = v65;
    goto LABEL_108;
  }
  v29 = v65;
  if ( v52 >= v65 && v52 < v53 )
LABEL_108:
    v6[5] = v53;
LABEL_43:
  v6[6] -= v4;
  if ( v6 == (int *)&unk_632CF4 )
    dword_634D4C -= v4;
  if ( v27 )
  {
    if ( v69 )
    {
      v73[1] = v27 + 8196;
      v73[0] = 512;
      RtlClearBits(v73, v29 >> 10, v30 >> 10);
      *(_DWORD *)(v27 + 8308) -= v30 >> 10;
    }
    __dmb(0xBu);
    if ( v6 == (int *)&unk_632CF4 )
    {
      do
        v63 = __ldrex((unsigned int *)dword_634D34);
      while ( __strex(v63 - 1, (unsigned int *)dword_634D34) );
      if ( (v63 & 2) != 0 && (v63 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)dword_634D34);
      v48 = KeAbPostRelease((unsigned int)dword_634D34);
      v64 = (__int16)(*(_WORD *)(v13 + 310) + 1);
      *(_WORD *)(v13 + 310) = v64;
      if ( v64 || *(_DWORD *)(v13 + 100) == v13 + 100 )
        goto LABEL_99;
    }
    else
    {
      do
        v47 = __ldrex((unsigned int *)v6);
      while ( __strex(v47 - 1, (unsigned int *)v6) );
      if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v6);
      v48 = KeAbPostRelease((unsigned int)v6);
      v49 = *(_WORD *)(v13 + 310) + 1;
      *(_WORD *)(v13 + 310) = v49;
      if ( v49 || *(_DWORD *)(v13 + 100) == v13 + 100 )
        goto LABEL_99;
    }
    KiCheckForKernelApcDelivery(v48);
LABEL_99:
    result = -v4;
    v50 = (unsigned int *)(v27 + 32);
    do
      v51 = __ldrex(v50);
    while ( __strex(v51 - v4, v50) );
    v31 = v70;
    goto LABEL_58;
  }
  v31 = v70;
  if ( v70 == 6 )
  {
    v32 = MiFreePoolPagesLeft(6);
    if ( v32 > dword_632AE8 )
    {
      if ( *(_DWORD *)(dword_63F7C4 + 4) )
        KeResetEvent(dword_63F7C4);
      if ( v32 >= dword_632AEC && !*(_DWORD *)(dword_63F7C8 + 4) )
        KeSetEvent(dword_63F7C8, 0, 0);
    }
  }
  __dmb(0xBu);
  if ( v6 != (int *)&unk_632CF4 )
  {
    do
      v33 = __ldrex((unsigned int *)v6);
    while ( __strex(v33 - 1, (unsigned int *)v6) );
    if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v6);
    result = KeAbPostRelease((unsigned int)v6);
    v34 = *(_WORD *)(v13 + 310) + 1;
    *(_WORD *)(v13 + 310) = v34;
    if ( v34 || *(_DWORD *)(v13 + 100) == v13 + 100 )
      goto LABEL_58;
LABEL_81:
    result = KiCheckForKernelApcDelivery(result);
    goto LABEL_58;
  }
  do
    v43 = __ldrex((unsigned int *)dword_634D34);
  while ( __strex(v43 - 1, (unsigned int *)dword_634D34) );
  if ( (v43 & 2) != 0 && (v43 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)dword_634D34);
  result = KeAbPostRelease((unsigned int)dword_634D34);
  v44 = (__int16)(*(_WORD *)(v13 + 310) + 1);
  *(_WORD *)(v13 + 310) = v44;
  if ( !v44 && *(_DWORD *)(v13 + 100) != v13 + 100 )
    goto LABEL_81;
LABEL_58:
  if ( v69 )
  {
    v35 = v6[3];
    v82 = 0;
    v36 = v35 + 4 * v65;
    v78 = v72;
    v79 = 0;
    v83 = 0;
    v84 = 0;
    v81 = 33;
    v80 = 0;
    MiInsertTbFlushEntry((int)&v78, v36 << 10, v30, 0);
    result = MiReturnSystemVa(v36 << 10, (v30 << 12) + (v36 << 10), v31, &v78);
  }
  return result;
}
