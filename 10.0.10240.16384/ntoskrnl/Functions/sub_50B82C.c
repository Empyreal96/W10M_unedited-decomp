// sub_50B82C 
 
int __fastcall sub_50B82C(int a1, unsigned __int8 *a2)
{
  int v2; // r4
  int v3; // r5
  int v4; // r3
  unsigned int v5; // r2
  unsigned int *v6; // r2
  unsigned int v7; // r0
  int v8; // r0
  int (__fastcall *v10)(int); // [sp-4h] [bp-4h]

  do
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v4 = *(_DWORD *)(v2 + 12);
      __dmb(0xBu);
    }
    while ( v4 < 0 );
    do
      v5 = __ldrex(a2);
    while ( __strex(v5 | 0x80, a2) );
    __dmb(0xBu);
  }
  while ( v5 >> 7 );
  ++*(_WORD *)(v2 + 16);
  __dmb(0xBu);
  v6 = (unsigned int *)(v2 + 12);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 & 0x7FFFFFFF, v6) );
  v8 = KfLowerIrql(v3);
  return v10(v8);
}
