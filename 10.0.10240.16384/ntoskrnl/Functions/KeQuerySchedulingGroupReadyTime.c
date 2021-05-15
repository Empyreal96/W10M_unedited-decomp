// KeQuerySchedulingGroupReadyTime 
 
__int64 __fastcall KeQuerySchedulingGroupReadyTime(int a1)
{
  __int64 v2; // r0
  __int64 v3; // r6
  int v4; // r8
  int v5; // r10
  int v6; // r4
  void **v7; // r9
  int v8; // t1
  unsigned int *v9; // r5
  unsigned int v10; // r2
  int v12; // [sp+0h] [bp-20h]

  LODWORD(v2) = KfRaiseIrql(2);
  v3 = 0i64;
  v4 = KeNumberProcessors_0;
  v5 = v2;
  v12 = v2;
  if ( KeNumberProcessors_0 )
  {
    v6 = a1 + 128;
    v7 = &KiProcessorBlock;
    do
    {
      v8 = (int)*v7++;
      v9 = (unsigned int *)(v8 + 24);
      while ( 1 )
      {
        do
          v10 = __ldrex(v9);
        while ( __strex(1u, v9) );
        __dmb(0xBu);
        if ( !v10 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v9 );
      }
      v3 += *(_QWORD *)(v6 + 56);
      if ( (*(_BYTE *)(v6 + 92) & 1) != 0 )
      {
        v2 = KeQueryInterruptTime(v2);
        v3 += v2 - *(_QWORD *)(v6 + 64);
      }
      __dmb(0xBu);
      v6 += 248;
      --v4;
      *v9 = 0;
    }
    while ( v4 );
    v5 = v12;
  }
  KfLowerIrql(v5);
  return v3;
}
