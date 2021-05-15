// tolower 
 
int __fastcall tolower(int a1)
{
  int v2; // r0
  int v3; // r3

  v2 = _pctype_func();
  v3 = -1;
  if ( a1 != -1 )
    v3 = (unsigned __int8)a1;
  if ( (*(_WORD *)(v2 + 2 * v3) & 1) != 0 )
    a1 += 32;
  return a1;
}
