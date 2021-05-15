// KiUpdateCpuTargetByRate 
 
_DWORD **__fastcall KiUpdateCpuTargetByRate(unsigned __int16 *a1, int a2)
{
  __int64 v4; // r4
  int v5; // r1
  int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // lr
  _DWORD **result; // r0
  unsigned int v10; // r8
  void **v11; // r10
  unsigned __int16 *v12; // r4
  int v13; // r5
  int v14; // t1
  unsigned int *v15; // r1
  unsigned int v16; // r2
  char v17; // r2
  unsigned int *v18; // r8
  unsigned int v19; // r2
  int v20; // r4
  int v21; // r1
  unsigned int v22; // r1
  int v23; // [sp+0h] [bp-38h]
  int v24; // [sp+4h] [bp-34h]
  int v25; // [sp+8h] [bp-30h]
  unsigned int v26; // [sp+Ch] [bp-2Ch]
  int v27[10]; // [sp+10h] [bp-28h] BYREF

  if ( *((_DWORD *)a1 + 15) )
  {
    v18 = (unsigned int *)((char *)KiProcessorBlock + 24);
    while ( 1 )
    {
      do
        v19 = __ldrex(v18);
      while ( __strex(1u, v18) );
      __dmb(0xBu);
      if ( !v19 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v18 );
    }
    v20 = *((_DWORD *)a1 + 91);
    v24 = _rt_udiv64(10000i64, *(_QWORD *)(v20 + 8) * *a1);
    v25 = v21;
    v6 = _rt_udiv64(10000i64, *(_QWORD *)(v20 + 16) * a1[1]);
    v8 = v22;
    v26 = v22;
    v23 = v6;
    __dmb(0xBu);
    *v18 = 0;
    v4 = *(_QWORD *)&KiCyclesPerGeneration;
  }
  else
  {
    v4 = *(_QWORD *)&KiCyclesPerGeneration;
    v24 = _rt_udiv64(10000i64, *(_QWORD *)&KiCyclesPerGeneration * *a1);
    v25 = v5;
    v6 = _rt_udiv64(10000i64, v4 * a1[1]);
    v8 = v7;
    v26 = v7;
    v23 = v6;
  }
  if ( __PAIR64__(v8, v6) != v4 )
    return (_DWORD **)sub_5159AC();
  v10 = 0;
  if ( KeMaximumProcessors )
  {
    v27[0] = 1;
    v11 = &KiProcessorBlock;
    v12 = a1 + 64;
    do
    {
      v14 = (int)*v11++;
      v13 = v14;
      if ( v14 )
      {
        v15 = (unsigned int *)(v13 + 24);
        while ( 1 )
        {
          do
            v16 = __ldrex(v15);
          while ( __strex(1u, v15) );
          __dmb(0xBu);
          if ( !v16 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v15 );
        }
        v6 = v23;
      }
      v17 = v27[0];
      *((_DWORD *)v12 + 4) = v6;
      *((_DWORD *)v12 + 5) = v8;
      *((_DWORD *)v12 + 2) = v24;
      *((_DWORD *)v12 + 3) = v25;
      *((_BYTE *)v12 + 92) = v12[46] & 0xEF | (16 * v17);
      if ( v13 )
      {
        if ( a2 )
        {
          *((_DWORD *)v12 + 8) = 0;
          *((_DWORD *)v12 + 9) = 0;
          *((_DWORD *)v12 + 12) = 0;
          *((_DWORD *)v12 + 13) = 0;
          if ( (*((_DWORD *)a1 + 1) & 2) != 0 )
          {
            *((_BYTE *)v12 + 92) &= 0xF1u;
            *(_DWORD *)v12 = 0;
            *((_DWORD *)v12 + 1) = 0;
            *((_DWORD *)v12 + 6) = 0;
            *((_DWORD *)v12 + 7) = 0;
            *((_DWORD *)v12 + 10) = 0;
            *((_DWORD *)v12 + 11) = 0;
            *((_DWORD *)v12 + 14) = 0;
            *((_DWORD *)v12 + 15) = 0;
            *((_DWORD *)v12 + 24) = 0;
            KiCheckForEffectivePriorityChange(v13, v12);
            v8 = v26;
            v6 = v23;
          }
        }
        __dmb(0xBu);
        *(_DWORD *)(v13 + 24) = 0;
      }
      ++v10;
      v12 += 124;
    }
    while ( v10 < KeMaximumProcessors );
  }
  if ( a2 )
  {
    KeQueryPerformanceCounter(v27, 0);
    *((_DWORD *)a1 + 6) = v27[0];
    *((_DWORD *)a1 + 7) = v27[1];
  }
  result = (_DWORD **)(a1 + 26);
  if ( *((unsigned __int16 **)a1 + 13) != a1 + 26 )
    result = (_DWORD **)KiUpdateChildrenCpuTarget(result, a2);
  return result;
}
