// MiAllocateDummyPage 
 
int MiAllocateDummyPage()
{
  unsigned int v0; // r0
  int v1; // r0
  int v2; // r5
  int v3; // r0
  unsigned __int8 *v4; // r1
  unsigned int v5; // r2
  int v6; // r3
  unsigned int *v7; // r2
  unsigned int v8; // r4

  MiChargeResident(MiSystemPartition, 1u, 0);
  do
    v0 = __ldrex(&dword_634A2C[22]);
  while ( __strex(v0 + 1, &dword_634A2C[22]) );
  MiChargeCommit((int)MiSystemPartition, 1u, 1);
  v1 = MiGetPage((int)MiSystemPartition, 0, 8);
  if ( v1 == -1 )
    sub_96B768();
  v2 = MmPfnDatabase + 24 * v1;
  *(_DWORD *)v2 = 0;
  MiFinalizePageAttribute(v2, 1, 0);
  *(_DWORD *)(v2 + 4) = -1073741824;
  v3 = KfRaiseIrql(2);
  v4 = (unsigned __int8 *)(v2 + 15);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v5 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v6 = *(_DWORD *)(v2 + 12);
      __dmb(0xBu);
    }
    while ( v6 < 0 );
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
  }
  *(_DWORD *)(v2 + 8) = 128;
  *(_WORD *)(v2 + 16) = 2;
  *(_BYTE *)(v2 + 18) |= 0x2Fu;
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(v2 + 20) & 0xF7FFFFFF | 0xFFFFF;
  __dmb(0xBu);
  v7 = (unsigned int *)(v2 + 12);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 & 0x7FFFFFFF, v7) );
  KfLowerIrql(v3);
  return v2;
}
