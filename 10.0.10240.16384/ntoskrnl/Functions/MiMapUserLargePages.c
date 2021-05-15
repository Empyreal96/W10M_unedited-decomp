// MiMapUserLargePages 
 
// local variable allocation has failed, the output may be wrong!
int *__fastcall MiMapUserLargePages(int a1, int a2, int a3)
{
  int v3; // r8
  int v4; // r10
  unsigned int v5; // r6
  int v6; // r4
  unsigned int v7; // r3
  unsigned int v8; // r7
  int **v9; // r5
  int ***v10; // r1
  int v11; // r2
  int v12; // r3
  int *result; // r0
  int *v14; // r5
  int *v15; // r1 OVERLAPPED
  __int64 v16; // r2
  unsigned int v17; // r4
  unsigned int *v18; // r8
  unsigned int *v19; // r8
  unsigned int v20; // r9
  unsigned int v21; // r10
  unsigned int *v22; // r5
  int v23; // r0
  unsigned int *v24; // r4
  unsigned __int8 *v25; // r1
  unsigned int v26; // r2
  unsigned __int8 *v27; // r3
  unsigned int v28; // r1
  unsigned int v29; // r0
  unsigned int v30; // r1
  unsigned int v31; // r3
  unsigned int v32; // r3
  unsigned int v33; // r1
  int v34; // r3
  int v35; // r4
  int v36; // r0
  int v37; // r0
  int v38; // [sp+0h] [bp-60h]
  int v39; // [sp+4h] [bp-5Ch]
  unsigned int *v41; // [sp+Ch] [bp-54h]
  unsigned int v42; // [sp+14h] [bp-4Ch]
  int *v43; // [sp+18h] [bp-48h]
  int v44; // [sp+20h] [bp-40h]
  int v46; // [sp+28h] [bp-38h]
  int *v47; // [sp+30h] [bp-30h] BYREF
  int ***v48; // [sp+34h] [bp-2Ch]
  int v49; // [sp+38h] [bp-28h]
  int v50; // [sp+3Ch] [bp-24h]

  v3 = a1;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = ((*(_DWORD *)(a1 + 12) << 12 >> 20) & 0xFFC) - 1070596096;
  v38 = 0;
  v39 = v4;
  v46 = *(_DWORD *)(a1 + 12) << 12;
  v6 = MmMakeProtectNotWriteCopy[(unsigned __int8)*(_DWORD *)(a1 + 28) >> 3];
  v7 = MmProtectToPteMask[v6] | MiDetermineUserGlobalPteMask(((4 * *(_DWORD *)(a1 + 12)) & 0x3FFFFC) - 0x40000000) | 0xFFFFF012;
  if ( (v6 & 4) != 0 )
    LOWORD(v7) = v7 & 0xFDFF;
  LOWORD(v8) = v7 | 0x410;
  MiLockVad(v4 & 0xFFFFFFC0, v3);
  v9 = (int **)MiLocateVadEvent(v3, 16)[2];
  v10 = (int ***)v9[1];
  v11 = (int)v9[2];
  v12 = (int)v9[3];
  v47 = *v9;
  v48 = v10;
  v49 = v11;
  v50 = v12;
  if ( (int **)(*v9)[1] != v9 || (int **)*v9[1] != v9 )
    __fastfail(3u);
  v47[1] = (int)&v47;
  *v48 = &v47;
  *v9 = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  for ( result = (int *)MiUnlockVad(v4 & 0xFFFFFFC0, v3); ; result = (int *)ExFreePoolWithTag(v14) )
  {
    v14 = v47;
    v43 = v47;
    if ( v47 == (int *)&v47 )
      break;
    *(_QWORD *)&v15 = *(_QWORD *)v47;
    if ( (int **)v47[1] != &v47 || (int *)v15[1] != v47 )
      __fastfail(3u);
    v47 = v15;
    v15[1] = (int)&v47;
    v16 = *((_QWORD *)v14 + 1);
    v8 = v8 & 0xFFF | ((_DWORD)v16 << 12);
    v17 = v5 + 4 * (HIDWORD(v16) >> 10);
    v38 += HIDWORD(v16);
    v41 = (unsigned int *)(MmPfnDatabase + 24 * v16);
    v42 = v17;
    MiLockVad(v39 & 0xFFFFFFC0, v3);
    v18 = (unsigned int *)(a3 + 492);
    v44 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v18);
    }
    else
    {
      v27 = (unsigned __int8 *)(a3 + 495);
      do
        v28 = __ldrex(v27);
      while ( __strex(v28 | 0x80, v27) );
      __dmb(0xBu);
      if ( v28 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v18);
      while ( 1 )
      {
        v29 = *v18;
        if ( (*v18 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v29 & 0x40000000) == 0 )
        {
          do
            v30 = __ldrex(v18);
          while ( v30 == v29 && __strex(v29 | 0x40000000, v18) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v5 < v17 )
    {
      v19 = v41;
      do
      {
        v20 = v5 << 10;
        v21 = *(_DWORD *)(((v5 >> 10) & 0x3FFFFC) - 0x40000000);
        v22 = v19 + 6144;
        do
        {
          v19[2] = 0;
          v23 = KfRaiseIrql(2);
          v24 = v19 + 3;
          v25 = (unsigned __int8 *)v19 + 15;
          do
            v26 = __ldrex(v25);
          while ( __strex(v26 | 0x80, v25) );
          while ( 1 )
          {
            __dmb(0xBu);
            if ( !(v26 >> 7) )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
              v31 = *v24;
              __dmb(0xBu);
            }
            while ( (v31 & 0x80000000) != 0 );
            do
              v26 = __ldrex(v25);
            while ( __strex(v26 | 0x80, v25) );
          }
          v32 = v19[5];
          v19[1] = v20;
          v19[5] = v32 & 0xFFF00000 | (v21 >> 12);
          __dmb(0xBu);
          do
            v33 = __ldrex(v24);
          while ( __strex(v33 & 0x7FFFFFFF, v24) );
          KfLowerIrql(v23);
          v19 += 6;
          v20 += 4;
        }
        while ( v19 < v22 );
        if ( v5 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v5 = v8;
        }
        else
        {
          v34 = *(_DWORD *)v5;
          v35 = 0;
          __dmb(0xBu);
          *(_DWORD *)v5 = v8;
          if ( (v34 & 2) == 0 && (v8 & 2) != 0 )
            v35 = 1;
          if ( v5 + 1070596096 <= 0xFFF )
          {
            v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v36, (_DWORD *)(v36 + 4 * (v5 & 0xFFF)), v8);
          }
          if ( v35 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        v8 = v8 & 0xFFF ^ ((v8 & 0xFFFFF000) + 0x400000);
        v5 += 4;
      }
      while ( v5 < v42 );
      v14 = v43;
      v18 = (unsigned int *)(a3 + 492);
    }
    MiUnlockWorkingSetExclusive((int)v18, v44);
    v3 = a1;
    MiUnlockVad(v39 & 0xFFFFFFC0, a1);
  }
  if ( (dword_682604 & 1) != 0 )
  {
    v37 = MiInitPerfMemoryFlags(1, 13);
    result = MiLogPerfMemoryRangeEvent(v46, a3, v37, v38);
  }
  return result;
}
