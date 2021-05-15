// IopSystemControlDispatch 
 
int __fastcall IopSystemControlDispatch(int a1, int a2)
{
  int v2; // r4

  v2 = *(_DWORD *)(a2 + 24);
  IofCompleteRequest(a2, 0);
  return v2;
}
