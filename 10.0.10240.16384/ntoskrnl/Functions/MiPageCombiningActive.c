// MiPageCombiningActive 
 
BOOL __fastcall MiPageCombiningActive(int a1)
{
  int v1; // r3

  if ( a1 )
    v1 = *(_DWORD *)(a1 + 3312);
  else
    v1 = dword_634304;
  return v1 != 0;
}
