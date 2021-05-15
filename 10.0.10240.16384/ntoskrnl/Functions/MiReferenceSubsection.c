// MiReferenceSubsection 
 
int __fastcall MiReferenceSubsection(int a1)
{
  int result; // r0

  if ( !*(_DWORD *)(a1 + 4) )
    return 0;
  ++*(_DWORD *)(a1 + 60);
  if ( (*(_WORD *)(a1 + 18) & 8) != 0 )
    MiRemoveUnusedSubsection(a1);
  result = 1;
  *(_WORD *)(a1 + 16) |= 1u;
  return result;
}
