// PopFxIdleWorker 
 
int __fastcall PopFxIdleWorker(_DWORD *a1, int a2, int a3)
{
  unsigned int *v4; // r4
  unsigned int *v7; // r6
  unsigned int *v8; // r7
  int result; // r0
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int *v12; // r6
  void (__fastcall *v13)(_DWORD, int); // r3
  int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r2
  unsigned int v17; // r2
  int v18; // [sp+0h] [bp-20h]

  v4 = *(unsigned int **)(a1[98] + 4 * a2);
  v7 = v4 + 13;
  v8 = v4 + 20;
  v18 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_540348();
  do
    v10 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire(v4 + 20);
  __dmb(0xBu);
  do
    v11 = __ldrex(v7);
  while ( v11 == 0x80000000 && __strex(0x40000000u, v7) );
  __dmb(0xBu);
  if ( v11 == 0x80000000 )
  {
    KeResetEvent((int)(v4 + 16));
    __dmb(0xBu);
    v12 = v4 + 21;
    v4[21] = 2;
    v13 = (void (__fastcall *)(_DWORD, int))a1[16];
    v14 = 0;
    if ( v13 )
    {
      v13(a1[22], a2);
      __dmb(0xBu);
      do
      {
        v15 = __ldrex(v12);
        v16 = v15 - 1;
      }
      while ( __strex(v16, v12) );
      if ( v16 )
      {
LABEL_15:
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v8);
        }
        else
        {
          __dmb(0xBu);
          *v8 = 0;
        }
        result = KfLowerIrql(v18);
        if ( v14 )
          result = PopFxIdleWorkerTail(a1, a2, a3);
        return result;
      }
    }
    else
    {
      __dmb(0xBu);
      do
        v17 = __ldrex(v12);
      while ( __strex(v17 - 2, v12) );
    }
    v14 = 1;
    goto LABEL_15;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4 + 20);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  return KfLowerIrql(v18);
}
