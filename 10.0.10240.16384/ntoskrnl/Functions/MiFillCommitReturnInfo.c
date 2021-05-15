// MiFillCommitReturnInfo 
 
int __fastcall MiFillCommitReturnInfo(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  result = a1 - *(_DWORD *)(a2 + 8);
  *a3 = result;
  a3[1] = result - *(_DWORD *)(a2 + 4);
  return result;
}
