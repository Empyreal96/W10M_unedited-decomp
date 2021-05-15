// IopFreeIrp 
 
int __fastcall IopFreeIrp(int a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r2
  int v4; // r3
  unsigned int v5; // r1
  int v6; // r5
  unsigned int v7; // r2
  unsigned int v9; // r2
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // r2

  if ( *(_WORD *)a1 != 6 )
    sub_52C9AC();
  *(_WORD *)a1 = 0;
  if ( (*(_BYTE *)(a1 + 39) & 0x40) != 0 )
    IopFreeIrpExtension(a1, -1, 1);
  if ( (*(_BYTE *)(a1 + 39) & 0x21) == 33 )
    return IopFreeReserveIrp(a1);
  v2 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( (*(_BYTE *)(a1 + 39) & 8) != 0 )
  {
    *(_BYTE *)(a1 + 39) ^= 8u;
    __dmb(0xBu);
    v10 = (unsigned int *)(v2 + 1616);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
    __dmb(0xBu);
  }
  if ( (*(_BYTE *)(a1 + 39) & 4) == 0 )
    return ExFreePoolWithTag(a1, 0);
  if ( (IopIrpStackProfilerFlags & 3) != 0 )
  {
    v12 = *(unsigned __int16 *)(a1 + 2);
    if ( v12 != (unsigned __int16)(40 * (char)IopLargeIrpStackLocations + 112)
      && v12 != (unsigned __int16)(40 * (char)IopMediumIrpStackLocations + 112)
      && v12 != 152 )
    {
      return ExFreePoolWithTag(a1, 0);
    }
  }
  v3 = *(unsigned __int16 *)(a1 + 2);
  if ( v3 >= (unsigned __int16)(40 * (char)IopLargeIrpStackLocations + 112) )
    v4 = 2;
  else
    v4 = v3 >= (unsigned __int16)(40 * (char)IopMediumIrpStackLocations + 112);
  v5 = v2 + 8 * v4;
  *(_DWORD *)(a1 + 28) = v3;
  v6 = *(_DWORD *)(v5 + 1408);
  v7 = *(unsigned __int16 *)(v6 + 8);
  ++*(_DWORD *)(v6 + 20);
  if ( *(unsigned __int16 *)(v6 + 4) >= v7 )
  {
    ++*(_DWORD *)(v6 + 24);
    v6 = *(_DWORD *)(v5 + 1412);
    v9 = *(unsigned __int16 *)(v6 + 8);
    ++*(_DWORD *)(v6 + 20);
    if ( *(unsigned __int16 *)(v6 + 4) >= v9 )
    {
      ++*(_DWORD *)(v6 + 24);
      return ExFreePoolWithTag(a1, 0);
    }
  }
  if ( (*(_BYTE *)(a1 + 39) & 1) != 0 )
  {
    *(_BYTE *)(a1 + 39) ^= 1u;
    ExReturnPoolQuota(a1);
  }
  return RtlpInterlockedPushEntrySList((unsigned __int64 *)v6, (_DWORD *)a1);
}
