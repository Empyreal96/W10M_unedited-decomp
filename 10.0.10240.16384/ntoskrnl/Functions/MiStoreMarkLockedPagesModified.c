// MiStoreMarkLockedPagesModified 
 
_DWORD *__fastcall MiStoreMarkLockedPagesModified(_DWORD *result)
{
  int *v1; // r6
  unsigned int v2; // r7
  int v3; // t1
  int v4; // r4
  int v5; // lr
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned __int8 *v8; // r1
  int v9; // r3
  unsigned int v10; // r2
  int v11; // r2
  unsigned int v12; // r5
  unsigned int *v13; // r2
  unsigned int v14; // r4
  int v15; // r3

  v1 = result + 7;
  v2 = (unsigned int)&result[((result[5] + (((unsigned __int16)result[6] + (unsigned __int16)result[4]) & 0xFFFu) + 4095) >> 12)
                           + 7];
  if ( (unsigned int)(result + 7) < v2 )
  {
    do
    {
      v3 = *v1++;
      v4 = MmPfnDatabase + 24 * v3;
      v5 = KfRaiseIrql(2);
      v6 = (unsigned __int8 *)(v4 + 15);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 0x80, v6) );
      __dmb(0xBu);
      if ( v7 >> 7 )
      {
        v8 = (unsigned __int8 *)(v4 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v9 = *(_DWORD *)(v4 + 12);
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
      v11 = *(_DWORD *)(v4 + 8);
      if ( (v11 & 0x10) != 0 )
      {
        *(_DWORD *)(v4 + 8) = v11 & 0xFFFFFFEF;
        v12 = v11 & 0xFFFFFFF7;
      }
      else
      {
        v12 = 0;
      }
      if ( (*(_BYTE *)(v4 + 18) & 0x10) == 0 )
        *(_BYTE *)(v4 + 18) |= 0x10u;
      __dmb(0xBu);
      v13 = (unsigned int *)(v4 + 12);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 & 0x7FFFFFFF, v13) );
      result = (_DWORD *)KfLowerIrql(v5);
      if ( v12 )
        result = (_DWORD *)MiReleasePageFileInfo((int)MiSystemPartition, v12, 0, v15);
    }
    while ( (unsigned int)v1 < v2 );
  }
  return result;
}
