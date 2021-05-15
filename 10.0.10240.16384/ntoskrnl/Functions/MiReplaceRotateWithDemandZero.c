// MiReplaceRotateWithDemandZero 
 
int __fastcall MiReplaceRotateWithDemandZero(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // r5
  int v4; // r9
  int v5; // r10
  int v6; // r4
  unsigned int v7; // r6
  unsigned int *v8; // r4
  unsigned int v9; // r7
  int v10; // r2
  _QWORD *v11; // r1
  int v12; // r3
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // r1
  int *v18; // r7
  int v19; // r0
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned __int8 *v22; // r1
  int v23; // r3
  unsigned int v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r0
  int v27; // r7
  unsigned __int8 *v28; // r3
  unsigned int v29; // r1
  unsigned int v30; // r0
  unsigned int v31; // r1
  unsigned int v33; // [sp+0h] [bp-180h]
  _DWORD *v34; // [sp+4h] [bp-17Ch]
  int v35; // [sp+8h] [bp-178h]
  int v37; // [sp+14h] [bp-16Ch] BYREF
  int v38; // [sp+18h] [bp-168h] BYREF
  char v39; // [sp+1Ch] [bp-164h]
  char v40; // [sp+1Dh] [bp-163h]
  int v41; // [sp+20h] [bp-160h]
  int v42; // [sp+24h] [bp-15Ch]
  int v43; // [sp+28h] [bp-158h]
  int v44; // [sp+2Ch] [bp-154h]
  _DWORD v45[52]; // [sp+B0h] [bp-D0h] BYREF

  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v7 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v33 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v34 = (_DWORD *)(((v7 >> 10) & 0x3FFFFC) - 0x40000000);
  v42 = 0;
  v38 = 1;
  v39 = 0;
  v40 = 0;
  v43 = 0;
  v41 = 33;
  v44 = 0;
  v8 = (unsigned int *)(v6 + 492);
  v35 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v8);
  }
  else
  {
    v13 = (unsigned __int8 *)v8 + 3;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v8);
    while ( 1 )
    {
      v15 = *v8;
      if ( (*v8 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v16 = __ldrex(v8);
        while ( v16 == v15 && __strex(v15 | 0x40000000, v8) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( MiIsProbeActive((unsigned int *)v7, ((int)(v33 - v7) >> 2) + 1, 3) )
    v4 = 1;
  v9 = v33;
  if ( v7 <= v33 )
  {
    while ( 1 )
    {
      do
      {
        if ( MiUnmapFrameBuffer(v7, a3, v4, &v37) )
          v4 = 1;
        v10 = v37;
        if ( v37 != -1 )
        {
          if ( v3 && (v11 = &v45[2 * v3], v12 = *((_DWORD *)v11 - 1), v12 == v37) )
          {
            *((_DWORD *)v11 - 1) = v12 + 1;
          }
          else
          {
            v45[2 * v3] = v37;
            v45[2 * v3++ + 1] = v10 + 1;
          }
        }
        MiInsertTbFlushEntry((int)&v38, v7 << 10, 1, 0);
        v7 += 4;
        ++v5;
      }
      while ( (v7 & 0xFFF) != 0 && v7 <= v9 && v3 != 22 );
      MiFlushTbList((unsigned int)&v38, v17);
      if ( v3 )
      {
        v18 = v45;
        do
        {
          MiDereferenceIoPages(1, *v18, v18[1] - *v18);
          v18 += 2;
          --v3;
        }
        while ( v3 );
        v9 = v33;
      }
      v19 = MmPfnDatabase + 24 * (*v34 >> 12);
      v20 = (unsigned __int8 *)(v19 + 15);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 | 0x80, v20) );
      __dmb(0xBu);
      if ( v21 >> 7 )
      {
        v22 = (unsigned __int8 *)(v19 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v19 + 12);
            __dmb(0xBu);
          }
          while ( (v23 & 0x80000000) != 0 );
          do
            v24 = __ldrex(v22);
          while ( __strex(v24 | 0x80, v22) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
      }
      *(_DWORD *)(v19 + 12) = *(_DWORD *)(v19 + 12) & 0xC0000000 | (*(_DWORD *)(v19 + 12) - v5) & 0x3FFFFFFF;
      __dmb(0xBu);
      v25 = (unsigned int *)(v19 + 12);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0x7FFFFFFF, v25) );
      MiUnlockWorkingSetExclusive((int)v8, v35);
      if ( v7 > v9 )
        break;
      v3 = 0;
      v34 = (_DWORD *)(((v7 >> 10) & 0x3FFFFC) - 0x40000000);
      v5 = 0;
      v27 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v8);
      }
      else
      {
        v28 = (unsigned __int8 *)v8 + 3;
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 | 0x80, v28) );
        __dmb(0xBu);
        if ( v29 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v8);
        while ( 1 )
        {
          v30 = *v8;
          if ( (*v8 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v30 & 0x40000000) == 0 )
          {
            do
              v31 = __ldrex(v8);
            while ( v31 == v30 && __strex(v30 | 0x40000000, v8) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v35 = v27;
      v9 = v33;
    }
  }
  return v4;
}
