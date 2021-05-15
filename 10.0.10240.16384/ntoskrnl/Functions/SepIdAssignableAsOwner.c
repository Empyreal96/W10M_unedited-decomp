// SepIdAssignableAsOwner 
 
BOOL __fastcall SepIdAssignableAsOwner(int a1, int a2)
{
  return !a2 || (*(_DWORD *)(*(_DWORD *)(a1 + 148) + 8 * a2 + 4) & 8) != 0;
}
