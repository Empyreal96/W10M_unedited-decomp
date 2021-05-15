// SeQueryAuthenticationIdToken 
 
int __fastcall SeQueryAuthenticationIdToken(int a1, _DWORD *a2)
{
  int v2; // r3
  int result; // r0

  *a2 = *(_DWORD *)(a1 + 24);
  v2 = *(_DWORD *)(a1 + 28);
  result = 0;
  a2[1] = v2;
  return result;
}
