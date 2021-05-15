// MiMarkMdlComplete 
 
_DWORD *__fastcall MiMarkMdlComplete(int a1, int a2)
{
  _DWORD *result; // r0
  _DWORD *v3; // r4
  int v4; // r2
  int *v5; // r8
  int i; // r7
  int v7; // t1
  int v8; // r5
  int v9; // lr
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned __int8 *v12; // r1
  int v13; // r3
  unsigned int v14; // r2
  char v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r0

  result = MiLocateVadEvent(a2, 8);
  v3 = (_DWORD *)result[2];
  v5 = (int *)(v4 + 28);
  for ( i = *(_DWORD *)(v4 + 20) >> 12; i; --i )
  {
    v7 = *v5++;
    v8 = MmPfnDatabase + 24 * v7;
    v9 = KfRaiseIrql(2);
    v10 = (unsigned __int8 *)(v8 + 15);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
    {
      v12 = (unsigned __int8 *)(v8 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v13 = *(_DWORD *)(v8 + 12);
          __dmb(0xBu);
        }
        while ( v13 < 0 );
        do
          v14 = __ldrex(v12);
        while ( __strex(v14 | 0x80, v12) );
        __dmb(0xBu);
      }
      while ( v14 >> 7 );
    }
    v15 = *(_BYTE *)(v8 + 18);
    *(_DWORD *)v8 = 0;
    *(_BYTE *)(v8 + 18) = v15 & 0xCF | 0x10;
    __dmb(0xBu);
    v16 = (unsigned int *)(v8 + 12);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 & 0x7FFFFFFF, v16) );
    result = (_DWORD *)KfLowerIrql(v9);
  }
  v3[12] = -1073741670;
  v3[13] = 0;
  if ( (int)v3[25] > 1 )
  {
    KeSetEvent((int)(v3 + 8), 0, 0);
    result = (_DWORD *)KeResetEvent((int)(v3 + 8));
  }
  return result;
}
