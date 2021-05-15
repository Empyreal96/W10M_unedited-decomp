// CmCloseTmHandle 
 
int __fastcall CmCloseTmHandle(int a1, int a2)
{
  int v2; // r2

  v2 = 0;
  if ( a1 && (*(_DWORD *)(a1 + 32) == 1 || a2 == 1) )
  {
    v2 = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 16) = 0;
  }
  return v2;
}
