// MiMapPageFileHash 
 
int __fastcall MiMapPageFileHash(int result, int a2, int a3, int a4, unsigned int a5)
{
  _DWORD *v5; // r7
  int v6; // r4
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r9
  int v12; // r4
  int v13; // r8
  unsigned int v14; // r2
  unsigned int v15; // r4
  unsigned int v16; // r10
  int v17; // r1
  unsigned int v18; // r1
  int v19; // t1
  unsigned int v20; // r2
  int v21; // r4
  char *v22; // r2
  int v23; // r3
  int v24; // r0
  int v25; // r9
  int v26; // r6
  int v27; // r1
  unsigned __int8 *v28; // r3
  unsigned int v29; // r1
  unsigned int v30; // r1
  unsigned int v31; // r10
  unsigned int v32; // r1
  int v33; // r2
  unsigned int v34; // r2
  unsigned int v35; // r3
  int v36; // r8
  unsigned int v37; // r2
  unsigned int v38; // r3
  unsigned int *v39; // r2
  unsigned int v40; // r0
  int v41; // r3
  int v42; // r4
  int v43; // r0
  unsigned __int8 *v44; // r1
  int v45; // r3
  unsigned int v46; // r2
  int v47; // r2
  unsigned int *v48; // r2
  unsigned int v49; // r0
  __int16 *v50; // r3
  unsigned int v51; // r0
  unsigned int *v52; // r2
  unsigned int v53; // r0
  unsigned int v54; // r1
  unsigned int v55; // r2
  int v56; // r6
  int v57; // r0
  int v58; // r3
  int v59; // r8
  int v60; // r0
  int v61; // r0
  int v63; // [sp+Ch] [bp-5Ch]
  unsigned int v64; // [sp+10h] [bp-58h]
  int v65; // [sp+1Ch] [bp-4Ch]
  unsigned int v66; // [sp+20h] [bp-48h]
  int v67; // [sp+28h] [bp-40h]
  int v68; // [sp+2Ch] [bp-3Ch]
  _WORD *v69; // [sp+38h] [bp-30h] BYREF
  int v70; // [sp+3Ch] [bp-2Ch]
  char v71[40]; // [sp+40h] [bp-28h] BYREF

  v5 = (_DWORD *)result;
  v6 = *(_DWORD *)(result + 108);
  v69 = 0;
  v70 = 0;
  if ( v6 )
  {
    v9 = MI_INITIALIZE_COLOR_BASE((int)&dword_634F00, 0, (int)&v69);
    if ( !a2 )
      return sub_549070(v9);
    if ( (*(_WORD *)(a2 + 6) & 5) == 0 )
      MmMapLockedPagesSpecifyCache(a2, 0, 1, 0, 0, -1073741808);
    v10 = a2 + 4 * (a3 + 7);
    v11 = a5;
    v12 = a4;
    v67 = HIWORD(v70);
    v63 = v10;
    v64 = a5;
    v68 = (unsigned __int16)v70;
    while ( 1 )
    {
      KeAcquireInStackQueuedSpinLock(v5 + 29, (unsigned int)v71);
      v13 = v5[27];
      v14 = v13 + 4 * v12;
      v15 = ((v14 >> 10) & 0x3FFFFC) - 0x40000000;
      v16 = (4096 - (v14 & 0xFFF)) >> 2;
      v66 = v16;
      if ( v16 > v11 )
      {
        v16 = v11;
        v66 = v11;
      }
      if ( (*(_DWORD *)v15 & 2) != 0 )
      {
        v17 = MmPfnDatabase + 24 * (*(_DWORD *)v15 >> 12);
        v19 = *(_DWORD *)(v17 + 8);
        v18 = v17 + 8;
        v20 = v19 & 0x1FFF ^ ((v19 & 0xFFFFE000) + (v16 << 13));
        if ( v18 < 0xC0000000 || v18 > 0xC03FFFFF )
        {
          *(_DWORD *)v18 = v20;
        }
        else
        {
          v41 = *(_DWORD *)v18;
          v42 = 0;
          __dmb(0xBu);
          *(_DWORD *)v18 = v20;
          if ( (v41 & 2) == 0 && (v20 & 2) != 0 )
            v42 = 1;
          if ( v18 + 1070596096 <= 0xFFF )
          {
            v43 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v43, (_DWORD *)(v43 + 4 * (v18 & 0xFFF)), v20);
          }
          if ( v42 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        KeReleaseInStackQueuedSpinLock((int)v71);
        v21 = a4;
        result = MiWritePageFileHash(v5, a2, v10, a4, v16);
      }
      else
      {
        KeReleaseInStackQueuedSpinLock((int)v71);
        v23 = (unsigned __int16)(*v69 + 1);
        *v69 = v23;
        v24 = MiGetFileHashPage((int)v5, v23 & v68 | v67, v67, v23 & v68);
        v25 = v24;
        if ( v24 == -1 )
        {
          v26 = 0;
          v65 = 17;
        }
        else
        {
          v26 = MmPfnDatabase + 24 * v24;
          __dmb(0xFu);
          v27 = KiTbFlushTimeStamp;
          __dmb(0xBu);
          MiSetPfnTbFlushStamp(v26, v27, 0);
          MiInitializePfnForOtherProcess(v25, v15, -1, 0);
          *(_DWORD *)(v26 + 20) = *(_DWORD *)(v26 + 20) & 0xFFF00000 | ((unsigned __int16)HIWORD(*(_DWORD *)(((v15 >> 10) & 0x3FFFFC) - 0x40000000)) >> 4);
          v65 = KfRaiseIrql(2);
          v28 = (unsigned __int8 *)(v26 + 15);
          do
            v29 = __ldrex(v28);
          while ( __strex(v29 | 0x80, v28) );
          __dmb(0xBu);
          if ( v29 >> 7 )
          {
            v44 = (unsigned __int8 *)(v26 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v45 = *(_DWORD *)(v26 + 12);
                __dmb(0xBu);
              }
              while ( v45 < 0 );
              do
                v46 = __ldrex(v44);
              while ( __strex(v46 | 0x80, v44) );
              __dmb(0xBu);
            }
            while ( v46 >> 7 );
          }
          *(_BYTE *)(v26 + 18) = *(_BYTE *)(v26 + 18) & 0xF8 | 6;
          v67 = HIWORD(v70);
          v68 = (unsigned __int16)v70;
        }
        KeAcquireInStackQueuedSpinLock(v5 + 29, (unsigned int)v71);
        if ( v13 != v5[27] )
        {
          result = KeReleaseInStackQueuedSpinLock((int)v71);
          if ( v25 != -1 )
          {
            v47 = MmPfnDatabase + 24 * v25;
            *(_DWORD *)(v47 + 12) &= 0xC0000000;
            *(_WORD *)(v47 + 16) = 0;
            MiInsertPageInFreeOrZeroedList(v25, 2);
            __dmb(0xBu);
            v48 = (unsigned int *)(v26 + 12);
            do
              v49 = __ldrex(v48);
            while ( __strex(v49 & 0x7FFFFFFF, v48) );
            KfLowerIrql(v65);
            v50 = (__int16 *)v5[32];
            if ( v50 == MiSystemPartition )
            {
              MiReturnResidentAvailable(1);
              do
                v51 = __ldrex(&dword_634A2C[26]);
              while ( __strex(v51 + 1, &dword_634A2C[26]) );
            }
            else
            {
              v52 = (unsigned int *)(v50 + 1920);
              do
                v53 = __ldrex(v52);
              while ( __strex(v53 + 1, v52) );
            }
            result = MiReturnCommit(v5[32], 1);
            v22 = algn_634F8C;
            do
              v54 = __ldrex((unsigned int *)algn_634F8C);
            while ( __strex(v54 - 1, (unsigned int *)algn_634F8C) );
          }
          v12 = a4;
          v10 = v63;
          v11 = v64;
          goto LABEL_16;
        }
        v30 = *(_DWORD *)v15;
        if ( v25 == -1 )
        {
          v55 = ((*(_DWORD *)v15 & 0xFFFFE000) + (v16 << 13)) ^ *(_DWORD *)v15 & 0x1FFF;
          if ( v15 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v15 = v55;
          }
          else
          {
            v56 = 0;
            __dmb(0xBu);
            *(_DWORD *)v15 = v55;
            if ( (v30 & 2) == 0 && (v55 & 2) != 0 )
              v56 = 1;
            if ( v15 + 1070596096 <= 0xFFF )
            {
              v57 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v57, (_DWORD *)(v57 + 4 * (v15 & 0xFFF)), v55);
            }
            if ( v56 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          result = KeReleaseInStackQueuedSpinLock((int)v71);
          v21 = a4;
          v10 = v63;
        }
        else
        {
          v31 = v30 >> 13;
          v32 = v26 + 8;
          v33 = *(_DWORD *)(v26 + 8) & 0x1FFF ^ ((v31 + v66) << 13);
          if ( (unsigned int)(v26 + 8) < 0xC0000000 || v32 > 0xC03FFFFF )
          {
            *(_DWORD *)v32 = v33;
          }
          else
          {
            v58 = *(_DWORD *)v32;
            v59 = 0;
            __dmb(0xBu);
            *(_DWORD *)v32 = v33;
            if ( (v58 & 2) == 0 && (v33 & 2) != 0 )
              v59 = 1;
            if ( (unsigned int)(v26 + 1070596104) <= 0xFFF )
            {
              v60 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v60, (_DWORD *)(v60 + 4 * (v32 & 0xFFF)), v33);
            }
            if ( v59 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          if ( v31 )
            *(_BYTE *)(v26 + 18) &= 0xEFu;
          v34 = (dword_681120 & 0x1ED | (v25 << 12) | MiDetermineUserGlobalPteMask(v15)) & 0xFFFFF1FF | 0x12;
          if ( v15 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v15 = v34;
          }
          else
          {
            v35 = *(_DWORD *)v15;
            v36 = 0;
            __dmb(0xBu);
            *(_DWORD *)v15 = v34;
            if ( (v35 & 2) == 0 )
              v36 = 1;
            if ( v15 >= 0xC0300000 && v15 <= 0xC0300FFF )
            {
              v61 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v61, (_DWORD *)(v61 + 4 * (v15 & 0xFFF)), v34);
            }
            if ( v36 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          v37 = v5[25] + 1;
          v38 = v5[26];
          v5[25] = v37;
          if ( v37 > v38 )
            v5[26] = v37;
          KeReleaseInStackQueuedSpinLock((int)v71);
          __dmb(0xBu);
          v39 = (unsigned int *)(v26 + 12);
          do
            v40 = __ldrex(v39);
          while ( __strex(v40 & 0x7FFFFFFF, v39) );
          KfLowerIrql(v65);
          v21 = a4;
          v10 = v63;
          v16 = v66;
          result = MiWritePageFileHash(v5, a2, v63, a4, v66);
        }
        v11 = v64;
      }
      if ( v10 )
      {
        v10 += 4 * v16;
        v63 = v10;
      }
      v12 = v21 + v16;
      v11 -= v16;
      a4 = v12;
      v64 = v11;
LABEL_16:
      if ( !v11 )
      {
        if ( (*(_WORD *)(a2 + 6) & 1) != 0 )
          result = (int)MmUnmapLockedPages(*(_DWORD *)(a2 + 12), a2, (int)v22);
        return result;
      }
    }
  }
  return result;
}
