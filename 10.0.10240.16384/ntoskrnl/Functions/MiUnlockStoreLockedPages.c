// MiUnlockStoreLockedPages 
 
_DWORD *__fastcall MiUnlockStoreLockedPages(_DWORD *result)
{
  int *v1; // r8
  unsigned int v2; // r10
  int v3; // r5
  int v4; // r3
  int v5; // t1
  int v6; // r4
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned __int8 *v9; // r1
  int v10; // r3
  unsigned int v11; // r2
  int v12; // r9
  __int16 *v13; // r7
  unsigned int *v14; // r2
  unsigned int v15; // r4
  int v16; // r3
  int v17; // [sp+0h] [bp-28h]
  _DWORD *v18; // [sp+4h] [bp-24h]

  v1 = result + 7;
  v18 = result;
  v2 = (unsigned int)&result[((result[5] + (((unsigned __int16)result[6] + (unsigned __int16)result[4]) & 0xFFFu) + 4095) >> 12)
                           + 7];
  v3 = 0;
  do
  {
    v5 = *v1++;
    v4 = v5;
    if ( v5 == -1 )
      break;
    v6 = MmPfnDatabase + 24 * v4;
    v17 = KfRaiseIrql(2);
    v7 = (unsigned __int8 *)(v6 + 15);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
    {
      v9 = (unsigned __int8 *)(v6 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v10 = *(_DWORD *)(v6 + 12);
          __dmb(0xBu);
        }
        while ( v10 < 0 );
        do
          v11 = __ldrex(v9);
        while ( __strex(v11 | 0x80, v9) );
        __dmb(0xBu);
      }
      while ( v11 >> 7 );
    }
    v3 = (*(_BYTE *)(v6 + 18) & 0x10) != 0 ? v3 | 2 : v3 & 0xFFFFFFFD;
    v12 = MiWriteCompletePfn(v6, v3);
    v13 = v12 ? MiSystemPartition : 0;
    __dmb(0xBu);
    v14 = (unsigned int *)(v6 + 12);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 & 0x7FFFFFFF, v14) );
    result = (_DWORD *)KfLowerIrql(v17);
    if ( v12 )
      result = (_DWORD *)MiReleasePageFileInfo((int)v13, v12, 0, v16);
  }
  while ( (unsigned int)v1 < v2 );
  *((_WORD *)v18 + 3) &= 0xFFFDu;
  return result;
}
