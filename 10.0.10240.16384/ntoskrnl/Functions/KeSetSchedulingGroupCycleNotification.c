// KeSetSchedulingGroupCycleNotification 
 
int __fastcall KeSetSchedulingGroupCycleNotification(int result, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r8
  int v5; // r5
  int v8; // r0
  int v9; // lr
  void **v10; // r6
  _DWORD *v11; // r4
  int v12; // t1
  unsigned int *v13; // r1
  unsigned int v14; // r2
  unsigned __int64 *v15; // r3
  unsigned __int64 v16; // kr00_8

  v4 = a4;
  v5 = result;
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 36) = 0;
  if ( a4 || a3 )
  {
    v8 = KfRaiseIrql(2);
    v9 = KeNumberProcessors_0;
    if ( KeNumberProcessors_0 )
    {
      v10 = &KiProcessorBlock;
      v11 = (_DWORD *)(v5 + 128);
      do
      {
        v12 = (int)*v10++;
        v13 = (unsigned int *)(v12 + 24);
        while ( 1 )
        {
          do
            v14 = __ldrex(v13);
          while ( __strex(1u, v13) );
          __dmb(0xBu);
          if ( !v14 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v13 );
        }
        v11[10] = *v11;
        v11[11] = v11[1];
        __dmb(0xBu);
        v11 += 62;
        --v9;
        *v13 = 0;
      }
      while ( v9 );
      v4 = a4;
    }
    *(_DWORD *)(v5 + 48) = a2;
    __dmb(0xBu);
    v15 = (unsigned __int64 *)(v5 + 32);
    do
      v16 = __ldrexd(v15);
    while ( __strexd(__PAIR64__(v4, a3), v15) );
    __dmb(0xBu);
    result = KfLowerIrql(v8);
  }
  return result;
}
