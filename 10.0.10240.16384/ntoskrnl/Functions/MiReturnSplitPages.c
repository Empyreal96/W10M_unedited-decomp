// MiReturnSplitPages 
 
unsigned int __fastcall MiReturnSplitPages(int *a1)
{
  int *v1; // r4
  int v2; // r6
  int *v3; // r7
  unsigned int v4; // r8
  int v5; // r9
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned __int8 *v8; // r1
  int v9; // r3
  unsigned int v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned int v13; // r0
  unsigned int result; // r0

  v1 = a1;
  v2 = 0;
  if ( a1 )
  {
    do
    {
      v3 = (int *)*v1;
      v4 = (int)((unsigned __int64)(715827883i64 * ((int)v1 - MmPfnDatabase)) >> 32) >> 2;
      v5 = KfRaiseIrql(2);
      v6 = (unsigned __int8 *)v1 + 15;
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 0x80, v6) );
      __dmb(0xBu);
      if ( v7 >> 7 )
      {
        v8 = (unsigned __int8 *)v1 + 15;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v9 = v1[3];
            __dmb(0xBu);
          }
          while ( v9 < 0 );
          do
            v10 = __ldrex(v8);
          while ( __strex(v10 | 0x80, v8) );
          __dmb(0xBu);
        }
        while ( v10 >> 7 );
      }
      v1[3] &= 0xC0000000;
      *((_WORD *)v1 + 8) = 0;
      MiInsertPageInFreeOrZeroedList(v4 + (v4 >> 31), 2);
      __dmb(0xBu);
      v11 = (unsigned int *)(v1 + 3);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 & 0x7FFFFFFF, v11) );
      KfLowerIrql(v5);
      ++v2;
      v1 = v3;
    }
    while ( v3 );
  }
  MiReturnResidentAvailable(v2);
  do
    v13 = __ldrex(&dword_634A2C[11]);
  while ( __strex(v13 + v2, &dword_634A2C[11]) );
  MiReturnCommit((int)MiSystemPartition, v2);
  do
    result = __ldrex(&dword_634D98);
  while ( __strex(result - v2, &dword_634D98) );
  return result;
}
