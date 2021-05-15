// sub_804D5C 
 
// local variable allocation has failed, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_804D5C(int a1, int a2, int a3, unsigned int *a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  _BYTE *v13; // r4
  unsigned int v14; // r6
  unsigned int v15; // r1
  _BYTE *v16; // r5
  int v17; // t1
  unsigned int v18; // r7
  unsigned int v19; // r2
  int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r2
  unsigned __int64 *v25; // r6
  int v26; // r7
  int *v27; // r9
  int *v28; // r10
  unsigned int v29; // r8
  int v30; // r4
  int v31; // r5
  unsigned int v32; // r2
  _QWORD *v33; // r5
  int v34; // r0
  __int64 v35; // kr00_8
  _DWORD *v36; // r4 OVERLAPPED
  unsigned __int8 v37; // r4
  unsigned int v38; // r1
  int v39; // [sp-4Ch] [bp-4Ch]
  _BYTE v40[68]; // [sp-44h] [bp-44h] BYREF

  while ( 1 )
  {
    v29 = 0;
    v30 = KeAbPreAcquire((unsigned int)a4, 0, 0);
    v31 = KfRaiseIrql(1);
    do
      v32 = __ldrex((unsigned __int8 *)&CmpDelayedCloseTableLock);
    while ( __strex(v32 & 0xFE, (unsigned __int8 *)&CmpDelayedCloseTableLock) );
    __dmb(0xBu);
    if ( (v32 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpDelayedCloseTableLock, v30);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    dword_6322E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_6322FC = v31;
    v33 = v40;
    do
    {
      v21 = *v27;
      if ( *v27 <= (unsigned int)*v28 && (!v26 || !v21) )
        break;
      v34 = dword_632304;
      v35 = *(_QWORD *)dword_632304;
      v36 = (_DWORD *)(dword_632304 - 116);
      if ( *(int **)dword_632304 != &CmpDelayedLRUListHead || *(_DWORD *)HIDWORD(v35) != dword_632304 )
        __fastfail(3u);
      dword_632304 = *(_DWORD *)(dword_632304 + 4);
      *(_DWORD *)HIDWORD(v35) = &CmpDelayedLRUListHead;
      v22 = *((_DWORD *)v25 + 2);
      *((_DWORD *)v25 + 2) = v22 - 1;
      *v27 = v21 - 1;
      *((_DWORD *)v25 + 3) = (v22 != 0) + *((_DWORD *)v25 + 3) - 1;
      v23 = *(_DWORD *)(v34 - 96);
      *v33 = *(_QWORD *)(&v36 - 1);
      v33 += 2;
      __dmb(0xBu);
      ++v29;
      *((_BYTE *)v33 - 8) = 0;
      *((_DWORD *)v33 - 1) = v36[3];
      v24 = v36[2];
      v36[29] = v33 - 1;
      v36[2] = v24 | 4;
    }
    while ( v29 < 4 );
    dword_6322E4 = 0;
    v37 = dword_6322FC;
    __dmb(0xBu);
    do
      v38 = __ldrex(&CmpDelayedCloseTableLock);
    while ( !v38 && __strex(1u, &CmpDelayedCloseTableLock) );
    if ( v38 )
      ExpReleaseFastMutexContended(&CmpDelayedCloseTableLock, v38);
    KfLowerIrql(v37);
    KeAbPostRelease((unsigned int)&CmpDelayedCloseTableLock);
    v18 = 0;
    if ( v29 )
    {
      v16 = v40;
      do
      {
        CmpLockHashEntryExclusive(*(_DWORD *)v16, *((_DWORD *)v16 + 3));
        if ( v18 < v29 )
        {
          v13 = v16;
          v14 = v29 - v18;
          do
          {
            if ( *((_DWORD *)v13 + 3) == *((_DWORD *)v16 + 3) && *(_DWORD *)v13 == *(_DWORD *)v16 )
            {
              v20 = (unsigned __int8)v13[8];
              __dmb(0xBu);
              if ( !v20 )
              {
                CmpLockKcbExclusive(*((_DWORD **)v13 + 1));
                CmpCleanUpKcbCacheWithLock(*((_DWORD **)v13 + 1), 0);
                CmpUnlockKcb(*((_DWORD **)v13 + 1));
                __dmb(0xBu);
                v13[8] = 1;
              }
            }
            v13 += 16;
            --v14;
          }
          while ( v14 );
        }
        v15 = *((_DWORD *)v16 + 3);
        v17 = *(_DWORD *)v16;
        v16 += 16;
        CmpUnlockHashEntry(v17, v15);
        ++v18;
      }
      while ( v18 < v29 );
      v28 = &CmpDelayedCloseSize;
      v25 = &CmPerfCounters;
    }
    v26 = v39;
    a4 = &CmpDelayedCloseTableLock;
    if ( v29 != 4 )
    {
      if ( !v39 )
      {
        __dmb(0xBu);
        do
          v19 = __ldrex(&CmpDelayCloseWorkItemActive);
        while ( v19 == 2 && __strex(0, &CmpDelayCloseWorkItemActive) );
        __dmb(0xBu);
        if ( v19 != 2 )
          JUMPOUT(0x74E2AE);
      }
      CmpUnlockRegistry();
      __asm { POP.W           {R4-R11,PC} }
    }
  }
}
