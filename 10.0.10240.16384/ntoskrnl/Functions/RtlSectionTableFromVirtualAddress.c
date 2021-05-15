// RtlSectionTableFromVirtualAddress 
 
int __fastcall RtlSectionTableFromVirtualAddress(unsigned int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v5; // r1
  unsigned int v7; // r2
  unsigned int v8; // r0

  v3 = *(unsigned __int16 *)(a1 + 6);
  v5 = a1 + *(unsigned __int16 *)(a1 + 20) + 24;
  __dmb(0xBu);
  if ( a1 <= MmHighestUserAddress )
    return sub_54DC8C();
  v7 = 0;
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    v8 = *(_DWORD *)(v5 + 12);
    if ( a3 >= v8 && a3 < *(_DWORD *)(v5 + 16) + v8 )
      break;
    ++v7;
    v5 += 40;
    if ( v7 >= v3 )
      return 0;
  }
  return v5;
}
