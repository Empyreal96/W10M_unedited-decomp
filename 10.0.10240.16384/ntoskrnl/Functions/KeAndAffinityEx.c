// KeAndAffinityEx 
 
BOOL __fastcall KeAndAffinityEx(int a1, int a2, int a3)
{
  int v3; // r3

  v3 = *(_DWORD *)(a2 + 8) & *(_DWORD *)(a1 + 8);
  if ( a3 )
  {
    *(_WORD *)(a3 + 2) = 1;
    *(_WORD *)a3 = 1;
    *(_DWORD *)(a3 + 4) = 0;
    *(_DWORD *)(a3 + 8) = v3;
  }
  return v3 != 0;
}
