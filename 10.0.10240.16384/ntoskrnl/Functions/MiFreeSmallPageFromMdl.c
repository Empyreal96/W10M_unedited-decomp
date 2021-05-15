// MiFreeSmallPageFromMdl 
 
int __fastcall MiFreeSmallPageFromMdl(unsigned int a1, char a2)
{
  int v2; // r8
  int v3; // r5
  int v7; // r6
  unsigned __int8 *v8; // r1
  unsigned int v9; // r2
  __int16 v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r4
  int v13; // r3

  v2 = 1;
  v3 = MmPfnDatabase + 24 * a1;
  if ( ((*(char *)((a1 >> 13) + dword_634C94) >> ((a1 >> 10) & 7)) & 1) != 0 )
    return sub_514B68();
  v7 = KfRaiseIrql(2);
  v8 = (unsigned __int8 *)(v3 + 15);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v9 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v13 = *(_DWORD *)(v3 + 12);
      __dmb(0xBu);
    }
    while ( v13 < 0 );
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
  }
  if ( (a2 & 1) != 0 )
    *(_DWORD *)(v3 + 12) |= 0x40000000u;
  v10 = *(_WORD *)(v3 + 16);
  *(_DWORD *)(v3 + 12) &= 0xC0000000;
  *(_WORD *)(v3 + 16) = v10 - 2;
  if ( v10 == 2 )
  {
    MiPfnReferenceCountIsZero(v3, a1);
  }
  else
  {
    v2 = 0;
    *(_BYTE *)(v3 + 18) |= 7u;
  }
  __dmb(0xBu);
  v11 = (unsigned int *)(v3 + 12);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0x7FFFFFFF, v11) );
  KfLowerIrql(v7);
  return v2;
}
