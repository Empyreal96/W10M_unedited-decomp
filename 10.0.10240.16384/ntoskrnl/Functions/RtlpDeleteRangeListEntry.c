// RtlpDeleteRangeListEntry 
 
int __fastcall RtlpDeleteRangeListEntry(int a1)
{
  int v3; // r5
  int v4; // r0
  int v5; // r3
  int v6; // r6

  if ( (*(_WORD *)(a1 + 26) & 1) != 0 )
  {
    v3 = a1 + 16;
    v4 = *(_DWORD *)(a1 + 16) - 28;
    v5 = **(_DWORD **)(a1 + 16);
    while ( 1 )
    {
      v6 = v5 - 28;
      if ( v3 == v4 + 28 )
        break;
      RtlpFreeRangeListEntry(v4);
      v5 = *(_DWORD *)(v6 + 28);
      v4 = v6;
    }
  }
  return RtlpFreeRangeListEntry(a1);
}
