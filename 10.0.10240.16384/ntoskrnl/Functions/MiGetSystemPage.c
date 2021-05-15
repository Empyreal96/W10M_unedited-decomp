// MiGetSystemPage 
 
int __fastcall MiGetSystemPage(int a1)
{
  int v1; // r5
  int v2; // r2
  int v3; // r3
  int v4; // r0
  int v6; // r5
  int v7; // r0
  unsigned __int8 *v8; // r1
  unsigned int v9; // r2
  unsigned int *v10; // r2
  unsigned int v11; // r4
  int v12; // r3

  v1 = *(unsigned __int16 *)(a1 + 6);
  v2 = (unsigned __int16)(**(_WORD **)a1 + 1);
  v3 = *(unsigned __int16 *)(a1 + 4);
  **(_WORD **)a1 = v2;
  v4 = MiGetPage((int)MiSystemPartition, v3 & v2 | v1, 194);
  if ( v4 == -1 )
    return sub_53AA20();
  v6 = MmPfnDatabase + 24 * v4;
  MiFinalizePageAttribute(v6, 1, 0);
  v7 = KfRaiseIrql(2);
  v8 = (unsigned __int8 *)(v6 + 15);
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
      v12 = *(_DWORD *)(v6 + 12);
      __dmb(0xBu);
    }
    while ( v12 < 0 );
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
  }
  *(_DWORD *)(v6 + 12) &= 0xC0000000;
  __dmb(0xBu);
  v10 = (unsigned int *)(v6 + 12);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & 0x7FFFFFFF, v10) );
  KfLowerIrql(v7);
  return v6;
}
