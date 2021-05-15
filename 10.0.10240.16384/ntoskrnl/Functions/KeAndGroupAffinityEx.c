// KeAndGroupAffinityEx 
 
BOOL __fastcall KeAndGroupAffinityEx(int a1, _DWORD *a2, int *a3)
{
  int v3; // r3

  v3 = *a2 & *(_DWORD *)(a1 + 8);
  if ( a3 )
  {
    *a3 = 0;
    a3[1] = 0;
    a3[2] = 0;
    *a3 = v3;
  }
  return v3 != 0;
}
