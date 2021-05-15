// MiDetermineModifiedPageListHead 
 
int __fastcall MiDetermineModifiedPageListHead(int a1, int a2)
{
  unsigned int v2; // r3
  int result; // r0

  v2 = *(_DWORD *)(a1 + 8);
  if ( (v2 & 8) != 0 || ((v2 >> 2) & 1) == *(_DWORD *)(a2 + 668) )
    result = sub_513E58();
  else
    result = a2 + 1792;
  return result;
}
