// MiSetSystemCodeProtection 
 
int __fastcall MiSetSystemCodeProtection(int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r7
  unsigned int v5; // r5
  int v7; // r4
  unsigned int v8; // r10
  int v9; // r3
  unsigned int v10; // r6
  int v11; // r3
  int v12; // r2
  unsigned int *v13; // r9
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r6
  unsigned int v18; // r4
  _DWORD *v19; // r8
  int v20; // r2
  unsigned int v21; // r3
  int v22; // r2
  int v23; // r4
  unsigned int v24; // r7
  unsigned __int8 *v25; // r3
  unsigned int *v26; // r2
  unsigned int v27; // r4
  unsigned __int64 v28; // kr00_8
  unsigned int *v29; // r10
  int v30; // r4
  unsigned __int8 *v31; // r3
  unsigned int v32; // r1
  unsigned int v33; // r0
  int v34; // r2
  unsigned int v35; // r1
  int v36; // r0
  int v37; // r2
  int v38; // r3
  unsigned int v39; // r2
  int v40; // r7
  unsigned int v41; // r2
  unsigned int v42; // r3
  int v43; // r4
  int v44; // r0
  unsigned int *v45; // r2
  unsigned int v46; // r0
  int v47; // r2
  int v48; // r4
  int v49; // r0
  unsigned int v50; // [sp+Ch] [bp-ECh]
  unsigned int *v51; // [sp+10h] [bp-E8h]
  unsigned int v52; // [sp+14h] [bp-E4h]
  unsigned int v53; // [sp+18h] [bp-E0h]
  int v54; // [sp+1Ch] [bp-DCh]
  _DWORD *v55; // [sp+20h] [bp-D8h]
  int v56; // [sp+24h] [bp-D4h]
  unsigned int v57; // [sp+28h] [bp-D0h]
  int v59[2]; // [sp+30h] [bp-C8h] BYREF
  int v60; // [sp+38h] [bp-C0h]
  int v61; // [sp+40h] [bp-B8h] BYREF
  char v62; // [sp+44h] [bp-B4h]
  char v63; // [sp+45h] [bp-B3h]
  int v64; // [sp+48h] [bp-B0h]
  int v65; // [sp+4Ch] [bp-ACh]
  int v66; // [sp+50h] [bp-A8h]
  int v67; // [sp+54h] [bp-A4h]

  v4 = a4;
  v53 = a4;
  v57 = a3;
  v5 = a2;
  if ( (*(_DWORD *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000) & 0x400) != 0 )
    return sub_518C20();
  v7 = 1;
  v8 = a4;
  if ( a4 == 256 )
  {
    v51 = 0;
    v52 = 0;
    v55 = (_DWORD *)MiSectionControlArea(*(_DWORD *)(a1 + 60));
  }
  else
  {
    v55 = 0;
    v51 = 0;
    v52 = a3;
    if ( (a4 & 5) == 5 )
      v8 = a4 & 0xFFFFFFFE;
    v9 = 0;
    if ( (v8 & 4) != 0 )
      v9 = 2;
    if ( MiMakeDriverPagesPrivate(a1, a2, a3, 17, v9) < 0 )
      return 0;
  }
  v10 = v5 << 10;
  v50 = v5 << 10;
  if ( v5 << 10 >= dword_63389C
    && ((v11 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((v10 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v11 == 11)
     || v11 == 1) )
  {
    v12 = 2;
    v13 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 3248);
  }
  else
  {
    v12 = 0;
    v13 = (unsigned int *)&dword_634F00;
  }
  v65 = 0;
  v66 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 33;
  v67 = 0;
  v56 = v12;
  v61 = v12;
  v54 = KfRaiseIrql(2);
  v60 = 0x80000000;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v13);
  }
  else
  {
    v14 = (unsigned __int8 *)v13 + 3;
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 | 0x80, v14) );
    __dmb(0xBu);
    if ( v15 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v13);
    while ( 1 )
    {
      v16 = *v13;
      if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v16 & 0x40000000) == 0 )
      {
        do
          v15 = __ldrex(v13);
        while ( v15 == v16 && __strex(v16 | 0x40000000, v13) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v5 <= v57 )
  {
    while ( 1 )
    {
      v15 = 1070596096;
      if ( v5 > v52 )
      {
        v28 = (int)v10 - (__int64)*(int *)(a1 + 24);
        if ( v51 )
        {
          v29 = (unsigned int *)v51[2];
          v34 = 0;
          v51 = v29;
          v59[0] = 0;
          v59[1] = 0;
        }
        else
        {
          MiFlushTbList((unsigned int)&v61, *(_DWORD *)(a1 + 24));
          MiUnlockWorkingSetExclusive((int)v13, v54);
          v29 = MiOffsetToProtos(v55, v28, (int)v59);
          v51 = v29;
          v30 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v13);
          }
          else
          {
            v31 = (unsigned __int8 *)v13 + 3;
            do
              v32 = __ldrex(v31);
            while ( __strex(v32 | 0x80, v31) );
            __dmb(0xBu);
            if ( v32 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v13);
            while ( 1 )
            {
              v33 = *v13;
              if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v33 & 0x40000000) == 0 )
              {
                do
                  v35 = __ldrex(v13);
                while ( v35 == v33 && __strex(v33 | 0x40000000, v13) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
          v34 = v59[0];
          v54 = v30;
        }
        v15 = 1070596096;
        v52 = v5 + 4 * (v29[7] - v34 - 1);
        v8 = (*((unsigned __int16 *)v29 + 8) >> 1) & 0x1F;
        if ( (v8 & 5) == 5 )
          v8 &= 0xFFFFFFFE;
      }
      v17 = *(_DWORD *)v5;
      if ( (*(_DWORD *)v5 & 2) != 0 )
      {
        v15 = (unsigned int)&MmPfnDatabase;
        v18 = v17 >> 12;
        v19 = (_DWORD *)(MmPfnDatabase + 24 * (v17 >> 12));
        v20 = v19[5];
        if ( (v20 & 0x8000000) == 0 )
        {
          if ( (MiFlags & 0x30000) != 0 && (v4 & 4) != 0 && (v20 & 0x7000000) == 50331648 )
          {
            v7 = 0;
            break;
          }
          if ( v56 )
            v21 = MmProtectToPteMask[v8] & 0xFED | (v18 << 12) | MiDetermineUserGlobalPteMask(v5);
          else
            v21 = (MmProtectToPteMask[v8] & 0x3ED | (v18 << 12) | MiDetermineUserGlobalPteMask(v5)) & 0xFFFFF3FF;
          v22 = v21 | 0x12;
          if ( (v8 == 4 || v8 == 6) && (v17 & 0x200) == 0 )
            v22 &= 0xFFFFFDFF;
          if ( (v17 & 0x10) != 0 )
            v22 |= 0x10u;
          if ( v5 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v5 = v22;
          }
          else
          {
            v23 = 0;
            __dmb(0xBu);
            *(_DWORD *)v5 = v22;
            if ( (v17 & 2) == 0 )
              v23 = 1;
            if ( v5 >= 0xC0300000 && v5 <= 0xC0300FFF )
            {
              v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v36, (_DWORD *)(v36 + 4 * (v5 & 0xFFF)), v22);
            }
            if ( v23 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          MiInsertTbFlushEntry((int)&v61, v50, 1, 0);
          v24 = 0;
          v25 = (unsigned __int8 *)v19 + 15;
          do
            v15 = __ldrex(v25);
          while ( __strex(v15 | 0x80, v25) );
          __dmb(0xBu);
          if ( v15 >> 7 )
          {
            v15 = (unsigned int)v19 + 15;
            do
            {
              v37 = v60;
              do
              {
                __dmb(0xAu);
                __yield();
                v38 = v19[3];
                __dmb(0xBu);
              }
              while ( (v38 & v37) != 0 );
              do
                v39 = __ldrex((unsigned __int8 *)v15);
              while ( __strex(v39 | 0x80, (unsigned __int8 *)v15) );
              __dmb(0xBu);
            }
            while ( v39 >> 7 );
          }
          v19[2] ^= ((unsigned __int16)v19[2] ^ (unsigned __int16)(32 * v8)) & 0x3E0;
          if ( (v17 & 0x200) == 0 )
            v24 = MiCaptureDirtyBitToPfn((int)v19);
          __dmb(0xBu);
          v26 = v19 + 3;
          do
            v27 = __ldrex(v26);
          while ( __strex(v27 & 0x7FFFFFFF, v26) );
          if ( v24 )
            MiReleasePageFileInfo((int)MiSystemPartition, v24, 1, 0);
          v4 = v53;
        }
      }
      else if ( (v17 & 0x400) == 0 )
      {
        if ( (v17 & 0x800) != 0 )
        {
          if ( !MiLockTransitionLeafPage((unsigned int *)v5, 0) )
          {
            v10 = v50;
            goto LABEL_47;
          }
          v40 = MmPfnDatabase + 24 * (v17 >> 12);
          *(_DWORD *)(v40 + 8) = *(_DWORD *)(v40 + 8) & 0xFFFFFC1F | (32 * (v8 & 0x1F));
          v41 = v17 & 0xFFFFFC1F | (32 * (v8 & 0x1F));
          if ( v5 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v5 = v41;
          }
          else
          {
            v42 = *(_DWORD *)v5;
            v43 = 0;
            __dmb(0xBu);
            *(_DWORD *)v5 = v41;
            if ( (v42 & 2) == 0 && (v41 & 2) != 0 )
              v43 = 1;
            if ( v5 + 1070596096 <= 0xFFF )
            {
              v44 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v44, (_DWORD *)(v44 + 4 * (v5 & 0xFFF)), v41);
            }
            if ( v43 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          __dmb(0xBu);
          v45 = (unsigned int *)(v40 + 12);
          do
          {
            v46 = __ldrex(v45);
            v15 = v46 & 0x7FFFFFFF;
          }
          while ( __strex(v46 & 0x7FFFFFFF, v45) );
          v4 = v53;
        }
        else if ( v4 != 256 )
        {
          v15 = v5 + 1070596096;
          v47 = (v17 ^ (32 * v8)) & 0x3E0 ^ v17;
          if ( v5 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v5 = v47;
          }
          else
          {
            v48 = 0;
            __dmb(0xBu);
            *(_DWORD *)v5 = v47;
            if ( (v17 & 2) == 0 && (v47 & 2) != 0 )
              v48 = 1;
            if ( v15 <= 0xFFF )
            {
              v49 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v49, (_DWORD *)(v49 + 4 * (v5 & 0xFFF)), v47);
            }
            if ( v48 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
      }
      v5 += 4;
      v10 = v50 + 4096;
      v50 += 4096;
LABEL_47:
      if ( v5 > v57 )
      {
        v7 = 1;
        break;
      }
    }
  }
  MiFlushTbList((unsigned int)&v61, v15);
  MiUnlockWorkingSetExclusive((int)v13, v54);
  return v7;
}
