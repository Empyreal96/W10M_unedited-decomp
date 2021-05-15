// KeInsertSchedulingGroup 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeInsertSchedulingGroup(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v6; // r6
  int v7; // r3
  int v8; // r9
  int v9; // r4 OVERLAPPED
  __int64 v10; // kr00_8
  char *v11; // r6
  _DWORD *v12; // r3
  int v13; // r2
  int v14; // r3 OVERLAPPED
  int v15; // r0
  int *v16; // r2
  _DWORD *v17; // r1
  unsigned int v18; // lr
  unsigned int v19; // r8
  void **v20; // r6
  int v21; // r9
  int v22; // r1
  int v23; // t1
  unsigned int *v24; // r0
  unsigned int v25; // r2
  int v26; // r1
  int *v27; // r4
  int v28; // r2
  unsigned int v29; // r0
  _DWORD *v30; // r2
  int v32; // r1
  unsigned int v33; // r1
  int v34; // r2
  int v35[2]; // [sp+0h] [bp-30h] BYREF
  char var28[44]; // [sp+8h] [bp-28h] BYREF
  int varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  _DWORD *varg_r3; // [sp+44h] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  varg_r1 = a2;
  varg_r2 = a3;
  if ( !KiGroupSchedulingEnabled )
  {
    KiEnableGroupScheduling();
    a2 = varg_r1;
    a3 = varg_r2;
  }
  *(_QWORD *)a1 = *(_QWORD *)&a2;
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  KeQueryPerformanceCounter(v35, 0);
  v6 = (_DWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 24) = v35[0];
  *(_DWORD *)(a1 + 28) = v35[1];
  *(_DWORD *)(a1 + 52) = a1 + 52;
  *(_DWORD *)(a1 + 56) = a1 + 52;
  v7 = KeMaximumProcessors;
  *(_DWORD *)(a1 + 40) = a1 + 40;
  *(_DWORD *)(a1 + 44) = a1 + 40;
  *(_DWORD *)(a1 + 60) = 0;
  v35[0] = v7;
  if ( v7 )
  {
    v8 = v35[0];
    v9 = a1 + 128;
    v10 = *(_QWORD *)&KiCycleDivisorShortTerm;
    v11 = (char *)a4 - a1;
    do
    {
      memset((_BYTE *)v9, 0, 100);
      v12 = (_DWORD *)(v9 + 100);
      v13 = 16;
      do
      {
        *v12 = v12;
        v12[1] = v12;
        v12 += 2;
        --v13;
      }
      while ( v13 );
      v14 = 0;
      *(_QWORD *)(v9 + 8) = v10;
      *(_QWORD *)(v9 + 16) = v10;
      *(_DWORD *)(v9 + 228) = 0;
      *(_DWORD *)(v9 + 232) = 0;
      if ( a4 )
      {
        *(_DWORD *)(v9 + 236) = &v11[v9];
        *(_DWORD *)(v9 + 240) = *(_DWORD *)&v11[v9 + 240];
        LOBYTE(v14) = v11[v9 + 93] + 1;
      }
      else
      {
        *(_QWORD *)(v9 + 236) = *(_QWORD *)(&v9 - 1);
      }
      *(_BYTE *)(v9 + 93) = v14;
      v9 += 248;
      --v8;
    }
    while ( v8 );
    v6 = (_DWORD *)(a1 + 40);
  }
  v15 = KeAcquireInStackQueuedSpinLock(&KiSchedulingGroupLock, var28);
  if ( a4 )
  {
    v16 = a4 + 13;
    *(_DWORD *)(a1 + 60) = a4;
    v17 = (_DWORD *)a4[14];
    *v6 = a4 + 13;
    v6[1] = v17;
    if ( (_DWORD *)*v17 != a4 + 13 )
      sub_50A198(v15);
  }
  else
  {
    v16 = &KiSchedulingGroupList;
    v17 = (_DWORD *)dword_624D9C;
    *v6 = &KiSchedulingGroupList;
    v6[1] = v17;
    if ( (int *)*v17 != &KiSchedulingGroupList )
      __fastfail(3u);
  }
  *v17 = v6;
  v16[1] = (int)v6;
  v18 = KeNumberProcessors_0;
  v19 = 0;
  if ( KeNumberProcessors_0 )
  {
    v20 = &KiProcessorBlock;
    v21 = a1 + 128;
    do
    {
      v23 = (int)*v20++;
      v22 = v23;
      v24 = (unsigned int *)(v23 + 24);
      while ( 1 )
      {
        do
          v25 = __ldrex(v24);
        while ( __strex(1u, v24) );
        __dmb(0xBu);
        if ( !v25 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v24 );
      }
      v26 = v22 + 1984;
      v27 = *(int **)(v26 + 4);
      v28 = v21 + 72;
      *(_DWORD *)(v21 + 72) = v26;
      *(_DWORD *)(v21 + 76) = v27;
      if ( *v27 != v26 )
        __fastfail(3u);
      *v27 = v28;
      *(_DWORD *)(v26 + 4) = v28;
      __dmb(0xBu);
      ++v19;
      *v24 = 0;
      v21 += 248;
    }
    while ( v19 < v18 );
  }
  if ( (*(_DWORD *)(a1 + 4) & 1) != 0 )
  {
    if ( a4 )
    {
      v29 = a4[3];
      if ( v29 && (unsigned __int16)varg_r1 >= v29 )
      {
LABEL_32:
        if ( !v29 )
          __brkdiv0();
        *(_DWORD *)(a1 + 8) = ((unsigned __int16)varg_r1 << 7) / v29;
        goto LABEL_25;
      }
      a4[3] = (unsigned __int16)varg_r1;
      v30 = a4;
    }
    else
    {
      v29 = KiGroupSchedulingMinimumRate;
      if ( KiGroupSchedulingMinimumRate && (unsigned __int16)varg_r1 >= (unsigned int)KiGroupSchedulingMinimumRate )
        goto LABEL_32;
      KiGroupSchedulingMinimumRate = (unsigned __int16)varg_r1;
      v30 = 0;
    }
    KiAssignSchedulingGroupWeights(1, 0, v30);
LABEL_25:
    KiUpdateCpuTargetByRate(a1, 0);
    return KeReleaseInStackQueuedSpinLock(var28);
  }
  if ( a4 )
  {
    v33 = a4[4];
    if ( !v33 || (v34 = (unsigned __int16)varg_r1, (unsigned __int16)varg_r1 < v33) )
    {
      v34 = (unsigned __int16)varg_r1;
      a4[4] = (unsigned __int16)varg_r1;
    }
    a4[5] += v34;
  }
  else
  {
    if ( !KiGroupSchedulingMinimumWeight
      || (v32 = (unsigned __int16)varg_r1, (unsigned __int16)varg_r1 < (unsigned int)KiGroupSchedulingMinimumWeight) )
    {
      v32 = (unsigned __int16)varg_r1;
      KiGroupSchedulingMinimumWeight = (unsigned __int16)varg_r1;
    }
    KiGroupSchedulingTotalWeight += v32;
  }
  KiAssignSchedulingGroupWeights(0, 0, a4);
  return KeReleaseInStackQueuedSpinLock(var28);
}
