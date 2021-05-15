// MmGetPageBadStatus 
 
int __fastcall MmGetPageBadStatus(__int64 *a1)
{
  unsigned int v1; // r4
  int v2; // r5
  int v3; // r4
  int v4; // r0
  unsigned __int8 *v5; // r6
  unsigned int v6; // r2
  int v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r4

  v1 = *a1 >> 12;
  if ( !MI_IS_PFN(v1) )
    return -1073741585;
  v2 = 0;
  v3 = MmPfnDatabase + 24 * v1;
  v4 = KfRaiseIrql(2);
  v5 = (unsigned __int8 *)(v3 + 15);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v6 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v7 = *(_DWORD *)(v3 + 12);
      __dmb(0xBu);
    }
    while ( (v7 & 0x80000000) != 0 );
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
  }
  if ( (*(_BYTE *)(v3 + 19) & 0x40) != 0 )
  {
    if ( (*(_DWORD *)(v3 + 4) | 0x80000000) == -4 && (*(_BYTE *)(v3 + 18) & 7) == 5 )
      v2 = -1073740023;
    else
      v2 = 259;
  }
  __dmb(0xBu);
  v8 = (unsigned int *)(v3 + 12);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 & 0x7FFFFFFF, v8) );
  KfLowerIrql(v4);
  return v2;
}
