// MiReleaseInPageRefs 
 
int __fastcall MiReleaseInPageRefs(_DWORD *a1)
{
  int v2; // r5
  unsigned __int8 *v3; // r1
  unsigned int v4; // r2
  int result; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r0
  unsigned int **v8; // r1
  unsigned int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r0

  MiLockAndDecrementShareCount(MmPfnDatabase + 24 * (a1[5] & 0xFFFFF), 0);
  v2 = KfRaiseIrql(2);
  v3 = (unsigned __int8 *)a1 + 15;
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    return sub_528C54();
  a1[3] |= 0x40000000u;
  if ( (a1[5] & 0x8000000) != 0 && (a1[2] & 0x400) != 0 )
  {
    __dmb(0xBu);
    v6 = a1 + 3;
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 & 0x7FFFFFFF, v6) );
    KfLowerIrql(v2);
    v8 = (unsigned int **)(a1[2] & 0xFFFFF800 | (2 * (a1[2] & 0x3FC)));
    result = MiDereferenceControlAreaPfn(*v8, (int)v8, 3);
  }
  else
  {
    v9 = a1[2] & 0xFFFFFFEF;
    a1[2] = v9;
    a1[2] = v9 & 0xFFFFFFF7;
    __dmb(0xBu);
    v10 = a1 + 3;
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0x7FFFFFFF, v10) );
    result = KfLowerIrql(v2);
  }
  return result;
}
