// KiUpdateGlobalCpuSetConfiguration 
 
unsigned __int16 *__fastcall KiUpdateGlobalCpuSetConfiguration(unsigned __int16 *result)
{
  int v1; // r6
  void **v2; // r9
  int v3; // r5
  int v4; // t1
  unsigned int *v5; // r7
  unsigned int v6; // r2
  int v7; // r4
  unsigned int *v8; // r1
  unsigned int v9; // r2
  unsigned __int16 *v10; // lr
  unsigned __int16 *v11; // r8
  int v12; // r4
  int v13; // r3
  int v14; // r0
  char v15; // r2
  unsigned int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r2
  unsigned int v19; // r2
  int v20; // r2
  int v21; // r1
  unsigned __int16 *v22; // [sp+8h] [bp-30h]
  int v23; // [sp+10h] [bp-28h]

  v1 = 0;
  v22 = result;
  if ( KeNumberProcessors_0 )
  {
    v2 = &KiProcessorBlock;
    while ( 1 )
    {
      v4 = (int)*v2++;
      v3 = v4;
      v5 = (unsigned int *)(v4 + 24);
      *(_DWORD *)(*(_DWORD *)(v4 + 12) + 352) = KiCpuSetSequence;
      while ( 1 )
      {
        while ( 1 )
        {
          do
            v6 = __ldrex(v5);
          while ( __strex(1u, v5) );
          __dmb(0xBu);
          if ( !v6 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v5 );
        }
        v7 = *(_DWORD *)(v3 + 4);
        v8 = (unsigned int *)(v7 + 44);
        do
          v9 = __ldrex(v8);
        while ( __strex(1u, v8) );
        __dmb(0xBu);
        if ( !v9 )
          break;
        __dmb(0xBu);
        result = (unsigned __int16 *)(v7 + 808);
        do
          v16 = __ldrex(result);
        while ( __strex(v16 + 1, result) );
        __dmb(0xBu);
        *v5 = 0;
        while ( 1 )
        {
          do
            v17 = __ldrex(v8);
          while ( __strex(1u, v8) );
          __dmb(0xBu);
          if ( !v17 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v8 );
        }
        while ( 1 )
        {
          do
            v18 = __ldrex(v5);
          while ( __strex(1u, v5) );
          __dmb(0xBu);
          if ( !v18 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v5 );
        }
        __dmb(0xBu);
        do
          v19 = __ldrex(result);
        while ( __strex(v19 - 1, result) );
        __dmb(0xBu);
        if ( v7 == *(_DWORD *)(v3 + 4) )
          break;
        __dmb(0xBu);
        *v5 = 0;
        __dmb(0xBu);
        *v8 = 0;
      }
      v10 = v22;
      v11 = 0;
      if ( *(_DWORD *)(v7 + 352) != KiCpuSetSequence && (*(_DWORD *)(v7 + 76) & 8) == 0 )
      {
        result = (unsigned __int16 *)KiComputeThreadAffinity(v7);
        v13 = *(unsigned __int8 *)(v7 + 132);
        if ( v13 == 2 || v13 == 5 )
        {
          result = (unsigned __int16 *)KiRescheduleThreadAfterAffinityChange(v7, v7 + 356, 2, v3, 0, v22);
          v11 = result;
        }
        v10 = v22;
      }
      __dmb(0xBu);
      *(_DWORD *)(v7 + 44) = 0;
      v12 = *(_DWORD *)(v3 + 8);
      if ( v12 )
      {
        if ( *(_DWORD *)(v12 + 352) != KiCpuSetSequence && (*(_DWORD *)(v12 + 76) & 8) == 0 )
          break;
      }
LABEL_11:
      __dmb(0xBu);
      *v5 = 0;
      if ( v11 )
        return (unsigned __int16 *)sub_51BF74();
      if ( ++v1 >= (unsigned int)KeNumberProcessors_0 )
        return result;
    }
    v14 = *(_DWORD *)(v3 + 4);
    v23 = v14;
    if ( (*(_BYTE *)(v14 + 2) & 4) != 0 )
    {
      if ( *(char *)(v14 + 123) < 16 )
      {
        if ( *(_DWORD *)(v14 + 68) )
        {
          v20 = *(_DWORD *)(v14 + 68);
          if ( v20 )
          {
            v21 = v20 + *(_DWORD *)(v3 + 2352);
            if ( v21 )
            {
              if ( KiGetThreadEffectiveRankNonZero(v14, v21, 0) )
              {
                v10 = v22;
                v15 = 1;
                goto LABEL_23;
              }
              v14 = v23;
            }
          }
        }
      }
      v10 = v22;
      v15 = *(_BYTE *)(v14 + 123);
    }
    else
    {
      v15 = *(_BYTE *)(v14 + 123);
    }
LABEL_23:
    **(_BYTE **)(v3 + 28) = v15;
    result = (unsigned __int16 *)KiSelectNextThread(v3, v10);
    *(_BYTE *)(v12 + 132) = 7;
    *(_DWORD *)(v12 + 144) = *(_DWORD *)v22;
    *(_DWORD *)v22 = v12 + 144;
    goto LABEL_11;
  }
  return result;
}
