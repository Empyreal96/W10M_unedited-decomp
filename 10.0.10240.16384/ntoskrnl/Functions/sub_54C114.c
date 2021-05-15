// sub_54C114 
 
void __fastcall sub_54C114(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int v7; // r6
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned __int8 *v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r0

  v7 = KfRaiseIrql(2);
  v8 = (unsigned __int8 *)(v6 + 15);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
  {
    v10 = (unsigned __int8 *)(v6 + 15);
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v11 = *(_DWORD *)(v6 + 12);
        __dmb(0xBu);
      }
      while ( (v11 & 0x80000000) != 0 );
      do
        v12 = __ldrex(v10);
      while ( __strex(v12 | 0x80, v10) );
      __dmb(0xBu);
    }
    while ( v12 >> 7 );
  }
  *(_BYTE *)(v6 + 18) = *(_BYTE *)(v6 + 18) & 0xF8 | 6;
  *(_DWORD *)(v6 + 4) = -4;
  __dmb(0xBu);
  v13 = (unsigned int *)(v6 + 12);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 & 0x7FFFFFFF, v13) );
  KfLowerIrql(v7);
  *(_DWORD *)v6 = a6;
  JUMPOUT(0x4D5AA0);
}
