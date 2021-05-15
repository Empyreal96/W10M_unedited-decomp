// sub_802F18 
 
void sub_802F18()
{
  int v0; // r5
  int v1; // r1
  __int16 *v2; // r0
  int v3; // r3
  int v4; // r4
  unsigned int v5; // r0
  unsigned int *v6; // r6
  int v7; // r1
  unsigned int v8; // r4
  unsigned int v9; // r0
  unsigned int v10; // r2

  MiChargeWsles(v0 + 492, 4 - *(_DWORD *)(v0 + 540), 0);
  PsReturnProcessQuota(v0, v1, *(_DWORD *)(v0 + 540) - 4);
  v2 = MiGetThreadPartition();
  v3 = *(_DWORD *)(v0 + 540);
  if ( v2 == MiSystemPartition )
  {
    MiReturnResidentAvailable(v3 - 4);
    v4 = *(_DWORD *)(v0 + 540) - 4;
    do
      v5 = __ldrex(&dword_634A04[8]);
    while ( __strex(v5 + v4, &dword_634A04[8]) );
  }
  else
  {
    MiReturnPartitionResidentAvailable((int)v2, v3 - 4);
  }
  v6 = (unsigned int *)(v0 + 192);
  v7 = *(_DWORD *)(v0 + 192);
  __dmb(0xBu);
  do
    v8 = __ldrex(v6);
  while ( v8 == v7 && __strex(v7 & 0xFFFFF3FF | 0x400, v6) );
  __dmb(0xBu);
  if ( v8 != v7 )
  {
    do
    {
      v9 = v8;
      __dmb(0xBu);
      do
        v10 = __ldrex(v6);
      while ( v10 == v8 && __strex(v8 & 0xFFFFF3FF | 0x400, v6) );
      v8 = v10;
      __dmb(0xBu);
    }
    while ( v10 != v9 );
  }
  if ( (*(_DWORD *)(v0 + 192) & 0x10000) != 0 )
    MiDereferenceSession();
  JUMPOUT(0x742E26);
}
