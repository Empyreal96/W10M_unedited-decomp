// sub_96AEB0 
 
int sub_96AEB0()
{
  int v0; // r4
  int v1; // r5
  unsigned __int8 *v2; // r1
  unsigned int v3; // r2
  int v4; // r3
  unsigned int *v5; // r2
  unsigned int v6; // r0
  int v7; // r0
  int v8; // r1
  int (__fastcall *v10)(int, int); // [sp-4h] [bp-4h]

  v1 = KfRaiseIrql(2);
  v2 = (unsigned __int8 *)(v0 + 15);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v3 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v4 = *(_DWORD *)(v0 + 12);
      __dmb(0xBu);
    }
    while ( v4 < 0 );
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 | 0x80, v2) );
  }
  *(_WORD *)(v0 + 16) = 0;
  *(_DWORD *)(v0 + 12) &= 0xC0000000;
  *(_BYTE *)(v0 + 18) = *(_BYTE *)(v0 + 18) & 0xF8 | 5;
  __dmb(0xBu);
  v5 = (unsigned int *)(v0 + 12);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 & 0x7FFFFFFF, v5) );
  KfLowerIrql(v1);
  v7 = MiLockAndInsertPageInFreeList(v0);
  return v10(v7, v8);
}
