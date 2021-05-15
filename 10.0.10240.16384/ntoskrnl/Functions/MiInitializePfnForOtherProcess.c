// MiInitializePfnForOtherProcess 
 
int __fastcall MiInitializePfnForOtherProcess(int a1, int a2, int a3, char a4)
{
  int v6; // r5
  int result; // r0
  int v8; // r7
  unsigned __int8 *v9; // r1
  unsigned int v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r4
  int v14; // r5
  unsigned __int8 *v15; // r1
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r3
  int v20; // r3

  v6 = MmPfnDatabase + 24 * a1;
  if ( (a4 & 0x10) != 0 )
    return sub_509C28();
  v8 = KfRaiseIrql(2);
  v9 = (unsigned __int8 *)(v6 + 15);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v10 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v19 = *(_DWORD *)(v6 + 12);
      __dmb(0xBu);
    }
    while ( (v19 & 0x80000000) != 0 );
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
  }
  *(_DWORD *)(v6 + 4) = a2;
  MiSetPfnTbFlushStamp(v6, 0, 1);
  *(_DWORD *)(v6 + 8) = 128;
  *(_WORD *)(v6 + 16) = 1;
  if ( (a4 & 0x80) != 0 )
    *(_DWORD *)(v6 + 12) = *(_DWORD *)(v6 + 12) & 0xC0000000 | (*(_DWORD *)(v6 + 12) + 1) & 0x3FFFFFFF;
  else
    *(_DWORD *)(v6 + 12) = *(_DWORD *)(v6 + 12) & 0xC0000000 | 1;
  *(_BYTE *)(v6 + 18) |= 0x10u;
  __dmb(0xBu);
  v11 = (unsigned int *)(v6 + 12);
  if ( v8 == 17 )
  {
    do
      result = __ldrex(v11);
    while ( __strex(result & 0x7FFFFFFF, v11) );
  }
  else
  {
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 & 0x7FFFFFFF, v11) );
    result = KfLowerIrql(v8);
  }
  if ( a3 != -1 )
  {
    *(_DWORD *)(v6 + 20) = *(_DWORD *)(v6 + 20) & 0xFFF00000 | a3 & 0xFFFFF;
    v13 = MmPfnDatabase + 24 * a3;
    v14 = KfRaiseIrql(2);
    v15 = (unsigned __int8 *)(v13 + 15);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 0x80, v15) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v16 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v20 = *(_DWORD *)(v13 + 12);
        __dmb(0xBu);
      }
      while ( (v20 & 0x80000000) != 0 );
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
    }
    *(_DWORD *)(v13 + 12) = *(_DWORD *)(v13 + 12) & 0xC0000000 | (*(_DWORD *)(v13 + 12) + 1) & 0x3FFFFFFF;
    __dmb(0xBu);
    v17 = (unsigned int *)(v13 + 12);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 & 0x7FFFFFFF, v17) );
    result = KfLowerIrql(v14);
  }
  return result;
}
