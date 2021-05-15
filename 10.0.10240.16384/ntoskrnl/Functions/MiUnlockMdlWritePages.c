// MiUnlockMdlWritePages 
 
unsigned int __fastcall MiUnlockMdlWritePages(unsigned int result, unsigned int a2, int *a3)
{
  int *v3; // r7
  unsigned int v4; // r5
  unsigned int v5; // r8
  int v6; // t1
  int v7; // r4
  int v8; // r6
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned __int8 *v13; // r1
  int v14; // r3
  unsigned int v15; // r2

  v3 = (int *)result;
  if ( *a3 < 0 )
    return sub_544184();
  v4 = 0;
  if ( result > a2 )
    v5 = 0;
  else
    v5 = (a2 - result + 3) >> 2;
  if ( v5 )
  {
    do
    {
      v6 = *v3++;
      v7 = MmPfnDatabase + 24 * v6;
      v8 = KfRaiseIrql(2);
      v9 = (unsigned __int8 *)(v7 + 15);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 0x80, v9) );
      __dmb(0xBu);
      if ( v10 >> 7 )
      {
        v13 = (unsigned __int8 *)(v7 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v14 = *(_DWORD *)(v7 + 12);
            __dmb(0xBu);
          }
          while ( v14 < 0 );
          do
            v15 = __ldrex(v13);
          while ( __strex(v15 | 0x80, v13) );
          __dmb(0xBu);
        }
        while ( v15 >> 7 );
      }
      MiReleaseWriteInProgressCharges(MiSystemPartition, 1, 1);
      MiWriteCompletePfn(v7, 0);
      __dmb(0xBu);
      v11 = (unsigned int *)(v7 + 12);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 & 0x7FFFFFFF, v11) );
      result = KfLowerIrql(v8);
      ++v4;
    }
    while ( v4 < v5 );
  }
  return result;
}
