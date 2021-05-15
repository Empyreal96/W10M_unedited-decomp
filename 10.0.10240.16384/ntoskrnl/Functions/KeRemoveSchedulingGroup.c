// KeRemoveSchedulingGroup 
 
unsigned int __fastcall KeRemoveSchedulingGroup(unsigned __int16 *a1)
{
  __int64 v2; // r0
  unsigned int v3; // r8
  _DWORD *v4; // r5
  unsigned int v5; // r10
  unsigned int v6; // r9
  void **v7; // r7
  unsigned __int16 *v8; // lr
  int v9; // t1
  unsigned int *v10; // r0
  unsigned int v11; // r2
  __int64 v12; // kr00_8
  __int64 v13; // kr08_8
  unsigned int v14; // r6
  _DWORD *v16; // r2
  int v17; // r2
  unsigned int v18; // [sp+0h] [bp-30h]
  char v19[40]; // [sp+8h] [bp-28h] BYREF

  KeAcquireInStackQueuedSpinLock(&KiSchedulingGroupLock, v19);
  v2 = *((_QWORD *)a1 + 5);
  if ( *(unsigned __int16 **)(v2 + 4) != a1 + 20 || *(unsigned __int16 **)HIDWORD(v2) != a1 + 20 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v2) = v2;
  *(_DWORD *)(v2 + 4) = HIDWORD(v2);
  v3 = KeNumberProcessors_0;
  v4 = (_DWORD *)*((_DWORD *)a1 + 15);
  v5 = 0;
  v18 = 0;
  v6 = 0;
  if ( KeNumberProcessors_0 )
  {
    v7 = &KiProcessorBlock;
    v8 = a1 + 64;
    do
    {
      v9 = (int)*v7++;
      v10 = (unsigned int *)(v9 + 24);
      while ( 1 )
      {
        do
          v11 = __ldrex(v10);
        while ( __strex(1u, v10) );
        __dmb(0xBu);
        if ( !v11 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v10 );
      }
      v12 = *((_QWORD *)v8 + 9);
      if ( *(unsigned __int16 **)(v12 + 4) != v8 + 36 || *(unsigned __int16 **)HIDWORD(v12) != v8 + 36 )
        sub_514CFC();
      *(_DWORD *)HIDWORD(v12) = v12;
      *(_DWORD *)(v12 + 4) = HIDWORD(v12);
      __dmb(0xBu);
      *v10 = 0;
      v13 = *((_QWORD *)v8 + 7);
      ++v6;
      v8 += 124;
      v14 = (__PAIR64__(v18, v5) + v13) >> 32;
      v5 += v13;
      v18 = v14;
    }
    while ( v6 < v3 );
  }
  if ( (*((_DWORD *)a1 + 1) & 1) == 0 )
  {
    v17 = *a1;
    if ( v4 )
      v4[5] -= v17;
    else
      KiGroupSchedulingTotalWeight -= v17;
  }
  if ( !v4 )
  {
    if ( (int *)KiSchedulingGroupList == &KiSchedulingGroupList )
    {
      KiGroupSchedulingMinimumWeight = 0;
      KiGroupSchedulingMinimumRate = 0;
      goto LABEL_17;
    }
    if ( !KiUpdateMinimumWeight(*((_DWORD *)a1 + 1) & 1, 0, 0) && (*((_DWORD *)a1 + 1) & 1) != 0 )
      goto LABEL_17;
    v16 = 0;
LABEL_22:
    KiAssignSchedulingGroupWeights(*((_DWORD *)a1 + 1) & 1, 0, v16);
    goto LABEL_17;
  }
  if ( (_DWORD *)v4[13] == v4 + 13 )
  {
    v4[3] = 0;
    v4[4] = 0;
    goto LABEL_17;
  }
  if ( KiUpdateMinimumWeight(*((_DWORD *)a1 + 1) & 1, 0, v4) || (*((_DWORD *)a1 + 1) & 1) == 0 )
  {
    v16 = v4;
    goto LABEL_22;
  }
LABEL_17:
  KeReleaseInStackQueuedSpinLock(v19);
  return v5;
}
