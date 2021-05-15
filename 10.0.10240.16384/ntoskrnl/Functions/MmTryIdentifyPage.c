// MmTryIdentifyPage 
 
int __fastcall MmTryIdentifyPage(int a1, int *a2)
{
  int v3; // r5
  int v4; // r6
  int v5; // r8
  unsigned __int8 *v6; // r3
  unsigned int v7; // r4
  unsigned int *v8; // r2
  unsigned int v9; // r0

  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  v3 = 1;
  v4 = MmPfnDatabase + 24 * a1;
  v5 = KfRaiseIrql(2);
  v6 = (unsigned __int8 *)(v4 + 15);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 0x80, v6) );
  __dmb(0xBu);
  if ( v7 >> 7 )
  {
    v3 = 0;
  }
  else
  {
    if ( (*(_BYTE *)(v4 + 19) & 0x40) != 0 )
      v3 = 0;
    else
      MiIdentifyPfn((int *)v4, a2);
    __dmb(0xBu);
    v8 = (unsigned int *)(v4 + 12);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 & 0x7FFFFFFF, v8) );
  }
  KfLowerIrql(v5);
  return v3;
}
