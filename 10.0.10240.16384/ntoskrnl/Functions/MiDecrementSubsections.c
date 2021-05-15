// MiDecrementSubsections 
 
int __fastcall MiDecrementSubsections(int a1, int a2)
{
  int v4; // r5
  int v5; // r3

  v4 = 0;
  do
  {
    v5 = *(_DWORD *)(a1 + 60) - 1;
    *(_DWORD *)(a1 + 60) = v5;
    if ( !v5 && (*(_WORD *)(a1 + 18) & 1) == 0 )
      v4 += MiInsertUnusedSubsection(a1, 1);
    if ( a1 == a2 )
      break;
    a1 = *(_DWORD *)(a1 + 8);
  }
  while ( a1 );
  return v4;
}
