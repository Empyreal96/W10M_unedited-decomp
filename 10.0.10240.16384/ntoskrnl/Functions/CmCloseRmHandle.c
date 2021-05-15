// CmCloseRmHandle 
 
int __fastcall CmCloseRmHandle(int a1, int a2)
{
  int v2; // r2

  v2 = 0;
  if ( a1 && (*(_DWORD *)(a1 + 32) == 1 || a2 == 1) )
  {
    v2 = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(a1 + 24) = 0;
  }
  return v2;
}
