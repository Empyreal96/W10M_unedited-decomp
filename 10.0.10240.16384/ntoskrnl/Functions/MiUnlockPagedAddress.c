// MiUnlockPagedAddress 
 
int __fastcall MiUnlockPagedAddress(unsigned int a1)
{
  int v1; // r4
  int v2; // r5
  unsigned __int8 *v3; // r1
  unsigned int v4; // r2
  int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r0

  v1 = MmPfnDatabase + 24 * (*(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v2 = KfRaiseIrql(2);
  v3 = (unsigned __int8 *)(v1 + 15);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v5 = *(_DWORD *)(v1 + 12);
      __dmb(0xBu);
    }
    while ( v5 < 0 );
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x80, v3) );
  }
  MiRemoveLockedPageChargeAndDecRef(v1);
  __dmb(0xBu);
  v6 = (unsigned int *)(v1 + 12);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 & 0x7FFFFFFF, v6) );
  return KfLowerIrql(v2);
}
