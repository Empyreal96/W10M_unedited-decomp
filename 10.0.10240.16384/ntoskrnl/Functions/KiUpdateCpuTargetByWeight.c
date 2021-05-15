// KiUpdateCpuTargetByWeight 
 
_DWORD **__fastcall KiUpdateCpuTargetByWeight(unsigned __int16 *a1, int a2)
{
  _DWORD **result; // r0
  int v4; // r4
  int v5; // r8
  int v6; // r0
  int v7; // r1
  int v8; // lr
  int v9; // r7
  int v10; // r6
  bool v11; // r2
  unsigned int v12; // r9
  void **v13; // r3
  int v14; // r4
  _DWORD *v15; // r8
  unsigned int *v16; // r1
  unsigned int v17; // r2
  char v18; // r3
  int v19; // r2
  unsigned int *v20; // r4
  unsigned int v21; // r2
  int v22; // r8
  unsigned __int64 v23; // r2
  __int64 v24; // r0
  int v25; // r1
  int v26; // [sp+0h] [bp-38h]
  int v28; // [sp+8h] [bp-30h]
  bool v29; // [sp+Ch] [bp-2Ch]
  int v30[10]; // [sp+10h] [bp-28h] BYREF

  if ( *a1 == a1[1] )
    return (_DWORD **)sub_525F00();
  if ( *((_DWORD *)a1 + 15) )
  {
    v20 = (unsigned int *)((char *)KiProcessorBlock + 24);
    while ( 1 )
    {
      do
        v21 = __ldrex(v20);
      while ( __strex(1u, v20) );
      __dmb(0xBu);
      if ( !v21 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v20 );
    }
    v22 = *((_DWORD *)a1 + 91);
    v23 = *(_QWORD *)(v22 + 8) * *a1;
    v24 = *(unsigned int *)(*((_DWORD *)a1 + 15) + 20);
    if ( !(_DWORD)v24 )
      __brkdiv0();
    v6 = _rt_udiv64((unsigned int)v24, v23);
    v8 = v25;
    v26 = v25;
    v28 = v6;
    v10 = *(_DWORD *)(v22 + 20);
    v9 = *(_DWORD *)(v22 + 16);
    __dmb(0xBu);
    *v20 = 0;
    v5 = MEMORY[0x68105C];
    v4 = KiCyclesPerGeneration;
  }
  else
  {
    v5 = MEMORY[0x68105C];
    v4 = KiCyclesPerGeneration;
    if ( !KiGroupSchedulingTotalWeight )
      __brkdiv0();
    v6 = _rt_udiv64(
           (unsigned int)KiGroupSchedulingTotalWeight,
           *(_QWORD *)&KiCyclesPerGeneration * (unsigned int)KiGroupSchedulingTotalWeight);
    v8 = v7;
    v26 = v7;
    v28 = v6;
    v9 = v4;
    v10 = v5;
  }
  v11 = v9 == v4 && v10 == v5;
  v12 = 0;
  if ( KeMaximumProcessors )
  {
    v29 = v11;
    v13 = &KiProcessorBlock;
    v14 = (int)(a1 + 64);
    do
    {
      v15 = *v13;
      v30[0] = (int)(v13 + 1);
      if ( v15 )
      {
        v16 = v15 + 6;
        while ( 1 )
        {
          do
            v17 = __ldrex(v16);
          while ( __strex(1u, v16) );
          __dmb(0xBu);
          if ( !v17 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v16 );
        }
        v8 = v26;
      }
      v18 = *(_BYTE *)(v14 + 92);
      *(_DWORD *)(v14 + 8) = v6;
      *(_DWORD *)(v14 + 12) = v8;
      *(_BYTE *)(v14 + 92) = v18 & 0xEF | (16 * v29);
      *(_DWORD *)(v14 + 16) = v9;
      *(_DWORD *)(v14 + 20) = v10;
      if ( v15 )
      {
        if ( a2 )
        {
          *(_DWORD *)(v14 + 32) = 0;
          *(_DWORD *)(v14 + 36) = 0;
          *(_DWORD *)(v14 + 48) = 0;
          *(_DWORD *)(v14 + 52) = 0;
          if ( (*((_DWORD *)a1 + 1) & 2) != 0 )
          {
            *(_BYTE *)(v14 + 92) &= 0xF1u;
            *(_DWORD *)v14 = 0;
            *(_DWORD *)(v14 + 4) = 0;
            *(_DWORD *)(v14 + 24) = 0;
            *(_DWORD *)(v14 + 28) = 0;
            *(_DWORD *)(v14 + 40) = 0;
            *(_DWORD *)(v14 + 44) = 0;
            *(_DWORD *)(v14 + 56) = 0;
            *(_DWORD *)(v14 + 60) = 0;
            *(_DWORD *)(v14 + 96) = 0;
            KiCheckForEffectivePriorityChange(v15, v14);
            v8 = v26;
            v6 = v28;
          }
        }
        __dmb(0xBu);
        v15[6] = 0;
      }
      ++v12;
      v14 += 248;
      v13 = (void **)v30[0];
    }
    while ( v12 < KeMaximumProcessors );
  }
  v19 = a2;
  if ( a2 )
  {
    KeQueryPerformanceCounter(v30, 0);
    v19 = a2;
    *((_DWORD *)a1 + 6) = v30[0];
    *((_DWORD *)a1 + 7) = v30[1];
  }
  result = (_DWORD **)(a1 + 26);
  if ( *((unsigned __int16 **)a1 + 13) != a1 + 26 )
    result = (_DWORD **)KiUpdateChildrenCpuTarget(result, v19);
  return result;
}
