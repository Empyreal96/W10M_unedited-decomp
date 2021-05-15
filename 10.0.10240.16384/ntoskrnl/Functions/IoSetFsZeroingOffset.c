// IoSetFsZeroingOffset 
 
int __fastcall IoSetFsZeroingOffset(int a1, int a2)
{
  int v3; // r2
  int result; // r0

  v3 = *(_DWORD *)(a1 + 104);
  result = 0;
  if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 )
    return -1073741275;
  if ( !v3 || (*(_WORD *)(v3 + 2) & 0x10) == 0 )
    return -1073741275;
  *(_DWORD *)(*(_DWORD *)(a1 + 104) + 28) = a2;
  return result;
}
