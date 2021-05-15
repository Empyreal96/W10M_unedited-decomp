// HvpGetCellMap 
 
int __fastcall HvpGetCellMap(int a1, unsigned int a2)
{
  unsigned int v3; // r2
  int v4; // r1
  int result; // r0

  v3 = a2 >> 31;
  v4 = a1 + 412 * (a2 >> 31);
  if ( a2 + (v3 << 31) >= *(_DWORD *)(v4 + 952) )
    result = 0;
  else
    result = *(_DWORD *)(*(_DWORD *)(v4 + 956) + 4 * ((a2 >> 21) & 0x3FF)) + 20 * ((a2 >> 12) & 0x1FF);
  return result;
}
