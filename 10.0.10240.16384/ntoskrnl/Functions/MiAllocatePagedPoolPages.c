// MiAllocatePagedPoolPages 
 
int __fastcall MiAllocatePagedPoolPages(int a1, unsigned int a2)
{
  unsigned int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r6
  int *v9; // r8
  int v10; // r6
  int v11; // r4
  int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r10
  int v16; // r3
  int v17; // lr
  unsigned int v18; // r6
  unsigned int v19; // r10
  unsigned int v20; // r5
  unsigned int *v21; // r4
  int v22; // r2
  unsigned int v23; // r6
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r2
  unsigned int v27; // r4
  unsigned int v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r1
  int v31; // r0
  __int16 v32; // r3
  int v33; // r2
  unsigned int v34; // r4
  unsigned int v35; // r8
  unsigned int v36; // r5
  int v37; // r0
  unsigned int *v38; // lr
  unsigned int v39; // r1
  unsigned int v40; // r1
  unsigned int v41; // r6
  int v42; // r2
  unsigned int v43; // r6
  unsigned int v44; // r3
  int v45; // t1
  unsigned int v46; // r1
  unsigned int v47; // r0
  int v48; // r3
  unsigned int v49; // r1
  int v50; // r0
  __int16 v51; // r3
  unsigned int *v52; // r2
  unsigned int v53; // r0
  unsigned int v54; // r3
  unsigned int v55; // r2
  int v56; // r2
  char v57; // r1
  unsigned int *v58; // r2
  unsigned int v59; // r1
  unsigned int v60; // r2
  unsigned int v61; // r3
  int v62; // r2
  unsigned int v63; // r1
  int v64; // t1
  unsigned int v65; // r0
  unsigned int v66; // r3
  unsigned int v67; // r0
  unsigned int v68; // r0
  int v69; // r0
  __int16 v70; // r3
  unsigned int v71; // r1
  __int16 v72; // r3
  unsigned int v73; // r0
  unsigned int v74; // r0
  int v75; // r3
  int v76; // r0
  int v77; // r0
  unsigned int v78; // [sp+8h] [bp-40h]
  unsigned int v79; // [sp+Ch] [bp-3Ch]
  unsigned int v80; // [sp+10h] [bp-38h]
  int *v81; // [sp+14h] [bp-34h]
  int v82; // [sp+18h] [bp-30h]
  unsigned int v83; // [sp+1Ch] [bp-2Ch]
  unsigned int v84; // [sp+24h] [bp-24h]
  int v85; // [sp+28h] [bp-20h]

  v3 = ((a2 & 0xFFF) != 0) + (a2 >> 12);
  v4 = *(unsigned __int16 *)(*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C))
                             + 590)
                           + 266);
  v85 = v4;
  if ( (a1 & 0x20) != 0 )
  {
    v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v82 = v10;
    v9 = (int *)(v10 + 3220);
    goto LABEL_88;
  }
  if ( (unsigned int)MiFreePoolPagesLeft(6) < 0x500 || (unsigned int)MiFreePoolPagesLeft(14) < 0x500 )
    return sub_5466C4();
  if ( v3 == 1 && (a1 & 0x80000000) == 0 )
  {
    v6 = dword_6337E8 + 176 * v4;
    if ( *(_WORD *)(v6 + 4) )
    {
      v7 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v6);
      if ( v7 )
      {
        v8 = v7 - 8;
        if ( *(_DWORD *)(v7 - 8) != (dword_634C80 ^ (v7 - 8)) )
          KeBugCheckEx(26, 21248, v7 - 8);
        return v8;
      }
    }
  }
  v9 = dword_634D34;
  v10 = 0;
  v81 = dword_634D34;
  v82 = 0;
  if ( (a1 & 0x80000000) != 0 )
  {
    v9 = (int *)&unk_632CF4;
LABEL_88:
    v81 = v9;
  }
  v11 = 0;
  if ( !MiChargeCommit((int)MiSystemPartition, v3, 1) )
    goto LABEL_204;
  v83 = 0;
  if ( !v10 )
  {
    if ( (dword_681250 & 2) != 0 )
    {
      if ( !MiChargeResident(MiSystemPartition, v3, 0) )
        goto LABEL_185;
      do
        v67 = __ldrex(&dword_634A2C[23]);
      while ( __strex(v67 + v3, &dword_634A2C[23]) );
      v83 = v3;
    }
    else if ( !MiChargeWsles((int)&dword_634E80, v3, 0) )
    {
      goto LABEL_185;
    }
  }
  v12 = __mrc(15, 0, 13, 0, 3);
  v13 = v9[5];
  v14 = v9[1];
  v15 = v12 & 0xFFFFFFC0;
  v84 = v12 & 0xFFFFFFC0;
  v78 = v13;
  v79 = v14;
  if ( v13 >= v14 )
    v16 = 0;
  else
    v16 = v9[5];
  v17 = v9[2];
  v18 = v14 - 1;
  if ( !v3 )
  {
    v23 = v16 & 0xFFFFFFF8;
    goto LABEL_28;
  }
  v19 = v16;
LABEL_20:
  if ( v18 - v19 + 1 < v3 )
  {
    v23 = -1;
    goto LABEL_70;
  }
  v20 = v17 + 4 * ((v18 - v3 + 1) >> 5);
  v80 = v18 - v3 + 1;
  v21 = (unsigned int *)(v17 + 4 * (v19 >> 5));
  v22 = *v21 | ((1 << (v19 & 0x1F)) - 1);
  if ( v3 <= 0x3F )
  {
    if ( v3 < 0x20 )
    {
      if ( v3 > 1 )
      {
        v37 = 0;
        v38 = (unsigned int *)(v17 + 4 * (v18 >> 5));
        while ( 1 )
        {
          if ( v22 == -1 )
          {
            while ( 1 )
            {
              if ( (unsigned int)++v21 > v20 )
                goto LABEL_68;
              v22 = *v21;
              if ( *v21 != -1 )
              {
                v37 = 0;
                break;
              }
            }
          }
          v39 = __clz(__rbit(v22));
          if ( 1 == (unsigned __int8)(v39 >> 5) )
            v39 = 32;
          if ( v39 + v37 >= v3 )
            break;
          v40 = ~v22;
          v41 = v3;
          while ( 1 )
          {
            v40 &= v40 >> (v41 >> 1);
            if ( !v40 )
              break;
            v41 -= v41 >> 1;
            if ( v41 <= 1 )
            {
              v42 = __clz(__rbit(v40));
              goto LABEL_67;
            }
          }
          if ( v21 == v38 )
            goto LABEL_68;
          v44 = __clz(v22);
          if ( 1 == (unsigned __int8)(v44 >> 5) )
            v37 = 32;
          else
            v37 = v44;
          v45 = v21[1];
          ++v21;
          v22 = v45;
        }
        v42 = -v37;
LABEL_67:
        v23 = v42 + 32 * (((int)v21 - v9[2]) >> 2);
        if ( v23 <= v80 )
          goto LABEL_26;
        goto LABEL_68;
      }
      if ( v22 == -1 )
      {
        do
        {
          if ( (unsigned int)++v21 > v20 )
            goto LABEL_68;
          v22 = *v21;
        }
        while ( *v21 == -1 );
      }
      v23 = __clz(__rbit(~v22)) + 32 * (((int)v21 - v17) >> 2);
      if ( v23 > v80 )
      {
        v23 = -1;
        goto LABEL_69;
      }
      goto LABEL_26;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v22 < 0 )
        {
          while ( (unsigned int)++v21 <= v20 )
          {
            v22 = *v21;
            if ( (*v21 & 0x80000000) == 0 )
              goto LABEL_132;
          }
LABEL_68:
          v23 = -1;
LABEL_69:
          v13 = v78;
          v14 = v79;
LABEL_70:
          if ( !v19 )
            goto LABEL_27;
          v43 = v13 + v3;
          if ( v13 + v3 > v14 )
            v43 = v14;
          v17 = v9[2];
          v18 = v43 - 1;
          v19 = 0;
          goto LABEL_20;
        }
LABEL_132:
        v61 = __clz(v22);
        if ( 1 == (unsigned __int8)(v61 >> 5) )
          v62 = 32;
        else
          v62 = v61;
        v23 = 32 * ((((int)v21 - v17) >> 2) + 1) - v62;
        if ( v23 > v80 )
          goto LABEL_68;
        v63 = v3 - v62;
        if ( v3 == v62 )
          goto LABEL_26;
        v64 = v21[1];
        ++v21;
        v22 = v64;
        if ( v63 >= 0x20 )
          break;
LABEL_137:
        v65 = __clz(__rbit(v22));
        if ( 1 == (unsigned __int8)(v65 >> 5) )
          v65 = 32;
        if ( v65 >= v63 )
          goto LABEL_26;
      }
      if ( !v22 )
      {
        v63 -= 32;
        if ( !v63 )
          goto LABEL_26;
        v22 = *++v21;
        goto LABEL_137;
      }
    }
  }
  if ( (v80 & 0x1F) != 0 )
    v20 += 4;
  if ( !v22 )
  {
    v56 = 0;
    goto LABEL_117;
  }
  if ( !*++v21 )
  {
    v66 = __clz(v22);
    v55 = 31 - v66;
    if ( 1 == (unsigned __int8)(v66 >> 5) )
      goto LABEL_148;
    goto LABEL_116;
  }
  do
  {
    while ( 1 )
    {
      do
      {
        if ( (unsigned int)v21 > v20 )
          goto LABEL_68;
        ++v21;
      }
      while ( *v21 );
      v54 = __clz(*(v21 - 1));
      v55 = 31 - v54;
      if ( 1 == (unsigned __int8)(v54 >> 5) )
LABEL_148:
        v56 = 32;
      else
LABEL_116:
        v56 = 31 - v55;
LABEL_117:
      v23 = 32 * (((int)v21 - v17) >> 2) - v56;
      if ( v23 > v80 )
        goto LABEL_68;
      v57 = v3 - v56;
      v58 = &v21[(v3 - v56) >> 5];
      if ( ++v21 == v58 )
        break;
      while ( !*v21 )
      {
        if ( ++v21 == v58 )
          goto LABEL_121;
      }
    }
LABEL_121:
    v59 = v57 & 0x1F;
    if ( !v59 )
      break;
    v60 = __clz(__rbit(*v21));
    if ( 1 == (unsigned __int8)(v60 >> 5) )
      v60 = 32;
  }
  while ( v60 < v59 );
LABEL_26:
  if ( v23 == -1 )
    goto LABEL_69;
LABEL_27:
  v9 = v81;
  v15 = v84;
LABEL_28:
  if ( v9 == (int *)&unk_632CF4 )
  {
    --*(_WORD *)(v15 + 310);
    v25 = KeAbPreAcquire((unsigned int)dword_634D34, 0, 0);
    do
      v46 = __ldrex((unsigned __int8 *)dword_634D34);
    while ( __strex(v46 | 1, (unsigned __int8 *)dword_634D34) );
    __dmb(0xBu);
    if ( (v46 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(dword_634D34, v25, dword_634D34);
    if ( v25 )
      goto LABEL_34;
  }
  else
  {
    --*(_WORD *)(v15 + 310);
    v24 = KeAbPreAcquire((unsigned int)v9, 0, 0);
    v25 = v24;
    do
      v26 = __ldrex((unsigned __int8 *)v9);
    while ( __strex(v26 | 1, (unsigned __int8 *)v9) );
    __dmb(0xBu);
    if ( (v26 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v9, v24, v9);
    if ( v25 )
    {
LABEL_34:
      *(_BYTE *)(v25 + 14) |= 1u;
      goto LABEL_35;
    }
  }
LABEL_35:
  v27 = v9[5];
  if ( v23 < v27 )
    v23 = v9[5];
  v28 = RtlFindClearBitsAndSet(v9 + 1, v3, v23);
  if ( v28 != -1 )
  {
LABEL_38:
    if ( v28 != v27 && (v3 != 1 || v23 != v27) )
    {
LABEL_40:
      v9[6] += v3;
      if ( v9 == (int *)&unk_632CF4 )
        dword_634D4C += v3;
      v8 = (v9[3] + 4 * v28) << 10;
      if ( !v82 )
      {
        v29 = MiFreePoolPagesLeft(6);
        if ( v29 < dword_632AEC )
        {
          if ( *(_DWORD *)(dword_63F7C8 + 4) )
            KeResetEvent(dword_63F7C8);
          if ( v29 <= dword_632AE8 && !*(_DWORD *)(dword_63F7C4 + 4) )
            KeSetEvent(dword_63F7C4, 0, 0);
        }
        __dmb(0xBu);
        if ( v9 == (int *)&unk_632CF4 )
        {
          do
            v47 = __ldrex((unsigned int *)dword_634D34);
          while ( __strex(v47 - 1, (unsigned int *)dword_634D34) );
          if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
            ExfTryToWakePushLock(dword_634D34);
          v31 = KeAbPostRelease((unsigned int)dword_634D34);
          v48 = (__int16)(*(_WORD *)(v15 + 310) + 1);
          *(_WORD *)(v15 + 310) = v48;
          if ( v48 || *(_DWORD *)(v15 + 100) == v15 + 100 )
            goto LABEL_49;
        }
        else
        {
          do
            v30 = __ldrex((unsigned int *)v9);
          while ( __strex(v30 - 1, (unsigned int *)v9) );
          if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
            ExfTryToWakePushLock(v9);
          v31 = KeAbPostRelease((unsigned int)v9);
          v32 = *(_WORD *)(v15 + 310) + 1;
          *(_WORD *)(v15 + 310) = v32;
          if ( v32 || *(_DWORD *)(v15 + 100) == v15 + 100 )
            goto LABEL_49;
        }
        KiCheckForKernelApcDelivery(v31);
LABEL_49:
        v33 = 0;
        goto LABEL_50;
      }
      __dmb(0xBu);
      if ( v9 == (int *)&unk_632CF4 )
      {
        do
          v74 = __ldrex((unsigned int *)dword_634D34);
        while ( __strex(v74 - 1, (unsigned int *)dword_634D34) );
        if ( (v74 & 2) != 0 && (v74 & 4) == 0 )
          ExfTryToWakePushLock(dword_634D34);
        v50 = KeAbPostRelease((unsigned int)dword_634D34);
        v75 = (__int16)(*(_WORD *)(v15 + 310) + 1);
        *(_WORD *)(v15 + 310) = v75;
        if ( v75 || *(_DWORD *)(v15 + 100) == v15 + 100 )
          goto LABEL_106;
      }
      else
      {
        do
          v49 = __ldrex((unsigned int *)v9);
        while ( __strex(v49 - 1, (unsigned int *)v9) );
        if ( (v49 & 2) != 0 && (v49 & 4) == 0 )
          ExfTryToWakePushLock(v9);
        v50 = KeAbPostRelease((unsigned int)v9);
        v51 = *(_WORD *)(v15 + 310) + 1;
        *(_WORD *)(v15 + 310) = v51;
        if ( v51 || *(_DWORD *)(v15 + 100) == v15 + 100 )
          goto LABEL_106;
      }
      KiCheckForKernelApcDelivery(v50);
LABEL_106:
      v52 = (unsigned int *)(v82 + 32);
      do
        v53 = __ldrex(v52);
      while ( __strex(v53 + v3, v52) );
      v33 = 2;
LABEL_50:
      v34 = ((v8 >> 10) & 0x3FFFFC) - 0x40000000;
      MiFlushTbAsNeeded(v34, v3, v33);
      if ( v83 )
      {
        MiFillPagedPoolLockedDown(v34, v3, v85);
      }
      else
      {
        v35 = v34 + 4 * v3;
        v36 = (v8 >> 10) & 0x3FFFFC;
        do
        {
          if ( v36 > 0x3FFFFF )
          {
            *(_DWORD *)v34 = 128;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v34 = 128;
            if ( v34 >= 0xC0300000 && v34 <= 0xC0300FFF )
            {
              v76 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v76, (_DWORD *)(v76 + 4 * (v34 & 0xFFF)), 128);
            }
          }
          v34 += 4;
          v36 += 4;
        }
        while ( v34 < v35 );
      }
      return v8;
    }
LABEL_57:
    v9[5] = v28 + v3;
    goto LABEL_40;
  }
  v28 = MiExpandPagedPool(v9, v3);
  if ( v28 != -1 )
  {
    if ( (v3 & 0x3FF) != 0 && (v3 == 1 || v28 < v27) )
      goto LABEL_57;
    goto LABEL_38;
  }
  __dmb(0xBu);
  if ( v9 == (int *)&unk_632CF4 )
  {
    do
      v68 = __ldrex((unsigned int *)dword_634D34);
    while ( __strex(v68 - 1, (unsigned int *)dword_634D34) );
    if ( (v68 & 2) != 0 && (v68 & 4) == 0 )
      ExfTryToWakePushLock(dword_634D34);
    v69 = KeAbPostRelease((unsigned int)dword_634D34);
    v70 = *(_WORD *)(v15 + 310) + 1;
    *(_WORD *)(v15 + 310) = v70;
    if ( v70 || *(_DWORD *)(v15 + 100) == v15 + 100 )
      goto LABEL_179;
  }
  else
  {
    do
      v71 = __ldrex((unsigned int *)v9);
    while ( __strex(v71 - 1, (unsigned int *)v9) );
    if ( (v71 & 2) != 0 && (v71 & 4) == 0 )
      ExfTryToWakePushLock(v9);
    v69 = KeAbPostRelease((unsigned int)v9);
    v72 = *(_WORD *)(v15 + 310) + 1;
    *(_WORD *)(v15 + 310) = v72;
    if ( v72 || *(_DWORD *)(v15 + 100) == v15 + 100 )
      goto LABEL_179;
  }
  KiCheckForKernelApcDelivery(v69);
LABEL_179:
  v11 = 1;
  v10 = v82;
  if ( !v82 )
  {
    if ( v83 )
    {
      MiReturnResidentAvailable(v3);
      do
        v73 = __ldrex(&dword_634A2C[24]);
      while ( __strex(v73 + v3, &dword_634A2C[24]) );
    }
    else
    {
      MiChargeWsles((int)&dword_634E80, -v3, 0);
    }
  }
LABEL_185:
  MiReturnCommit((int)MiSystemPartition, v3);
  if ( !v11 )
  {
LABEL_204:
    if ( v10 )
    {
      ++dword_632AB0;
      ++dword_632ADC;
      ++*(_DWORD *)(v10 + 64);
    }
    else
    {
      ++dword_632AA4;
      ++dword_632AD8;
    }
  }
  v77 = MiIssuePageExtendRequestNoWait(MiSystemPartition, v3, 0);
  MiTrimSegmentCache(v77);
  return 0;
}
