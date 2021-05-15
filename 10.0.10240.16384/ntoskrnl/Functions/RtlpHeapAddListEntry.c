// RtlpHeapAddListEntry 
 
int __fastcall RtlpHeapAddListEntry(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  unsigned int v5; // r6
  int v6; // r5
  int v7; // r7
  int result; // r0

  v5 = a5 - a2[5];
  if ( a2[2] )
    v6 = 2 * v5;
  else
    v6 = a5 - a2[5];
  ++a2[3];
  v7 = *(_DWORD *)(a2[8] + 4 * v6);
  if ( a5 == a2[1] - 1 )
    ++a2[4];
  if ( v7 )
    return sub_528A40();
  *(_DWORD *)(a2[8] + 4 * v6) = a4;
  result = v5 >> 5;
  *(_DWORD *)(a2[7] + 4 * (v5 >> 5)) |= 1 << (v5 & 0x1F);
  return result;
}
