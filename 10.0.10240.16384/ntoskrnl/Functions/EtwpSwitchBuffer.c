// EtwpSwitchBuffer 
 
int __fastcall EtwpSwitchBuffer(int a1, int a2, _DWORD *a3, __int16 a4, __int16 a5)
{
  int v9; // r0
  int v10; // r3
  BOOL v11; // r8
  unsigned int *v12; // lr
  unsigned int v13; // r1
  unsigned int i; // r7
  unsigned int v15; // r1
  unsigned int v16; // r6
  unsigned int *v17; // r2
  unsigned int v18; // r4
  int result; // r0
  BOOL v20; // r0
  unsigned int v21; // r0
  BOOL v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r1
  unsigned int *v25; // r2
  unsigned int v26; // r1
  unsigned int v27; // r1
  unsigned int *v28; // r2
  unsigned int v29; // r1
  int v30; // r1
  int v31; // r2
  int v32; // r3
  unsigned __int8 *v33; // r3
  unsigned int v34; // r1

  v9 = ((int (*)(void))EtwpDequeueFreeBuffer)();
  if ( v9 )
  {
LABEL_2:
    v10 = *(_DWORD *)(a1 + 12);
    v11 = (v10 & 0x400) != 0;
    if ( (v10 & 0x10000000) == 0 )
      *(_WORD *)(v9 + 40) = a4;
    __dmb(0xBu);
    v12 = (unsigned int *)(v9 + 12);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 + 7, v12) );
    __dmb(0xBu);
    while ( 1 )
    {
      if ( (v10 & 0x400) == 0 )
        *(_DWORD *)(v9 + 32) = a2;
      __pld(a3);
      for ( i = *a3; (i ^ a2) <= 7; i = v15 )
      {
        __dmb(0xBu);
        do
          v15 = __ldrex(a3);
        while ( v15 == i && __strex(v9 | 7, a3) );
        if ( v15 == i )
          break;
      }
      v16 = i & 0xFFFFFFF8;
      if ( (i & 0xFFFFFFF8) == a2 )
      {
        if ( v16 )
        {
          EtwpPrepareDirtyBuffer(a1, i & 0xFFFFFFF8);
          __dmb(0xBu);
          v17 = (unsigned int *)(v16 + 12);
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 + -1 - (i & 7), v17) );
          __dmb(0xBu);
          if ( !v11 )
          {
            if ( !*(_DWORD *)(a1 + 136)
              || ((*(_DWORD *)(a1 + 12) & 0x10000000) == 0 ? (v30 = KeNumberProcessors_0) : (v30 = 1),
                  v31 = *(_DWORD *)(a1 + 160),
                  __dmb(0xBu),
                  v32 = *(_DWORD *)(a1 + 156),
                  __dmb(0xBu),
                  v31 - v32 - v30 >= *(_DWORD *)(a1 + 136)) )
            {
              if ( (a5 & 0x600) != 0
                || (!(v20 = KeAreInterruptsEnabled()) ? (v21 = 15) : (v21 = KeGetCurrentIrql(v20)), v21 > 2) )
              {
                __dmb(0xBu);
                v33 = (unsigned __int8 *)(a1 + 613);
                do
                  v34 = __ldrex(v33);
                while ( __strex(v34 | 1, v33) );
                __dmb(0xBu);
                if ( (v34 & 1) == 0 )
                {
                  *(_WORD *)(a1 + 442) = KiClockTimerOwner + 32;
                  KiInsertQueueDpc(a1 + 440, 0, 0, 0, 0);
                }
              }
              else
              {
                KeSetEvent(a1 + 372, 0, 0);
              }
            }
          }
        }
        else if ( *(_DWORD *)(a1 + 132) )
        {
          EtwpRequestFlushTimer(a1, (a5 & 0x600) != 0);
        }
        goto LABEL_20;
      }
      if ( v16 )
        break;
      if ( a2 )
      {
        __dmb(0xBu);
        v28 = (unsigned int *)(a2 + 12);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 - 1, v28) );
        __dmb(0xBu);
      }
      a2 = 0;
    }
    if ( a2 )
    {
      __dmb(0xBu);
      v25 = (unsigned int *)(a2 + 12);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 - 1, v25) );
      __dmb(0xBu);
    }
    __dmb(0xBu);
    do
      v27 = __ldrex(v12);
    while ( __strex(v27 - 7, v12) );
    __dmb(0xBu);
    if ( (v10 & 0x400) != 0 )
      EtwpEnqueueOverflowBuffer(a1, v9);
    else
      EtwpEnqueueFreeBuffer(a1, v9);
LABEL_20:
    result = 0;
  }
  else
  {
    while ( (a5 & 0x200) == 0 )
    {
      v22 = KeAreInterruptsEnabled();
      if ( !v22 )
        return sub_54C2D8();
      if ( (unsigned int)KeGetCurrentIrql(v22) > 2 || EtwpAllocateFreeBuffers((unsigned int *)a1, 1u) != 1 )
        break;
      v9 = EtwpDequeueFreeBuffer(a1);
      if ( v9 )
        goto LABEL_2;
    }
    if ( a2 )
    {
      __dmb(0xBu);
      v23 = (unsigned int *)(a2 + 12);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 - 1, v23) );
      __dmb(0xBu);
    }
    result = -1073741801;
  }
  return result;
}
