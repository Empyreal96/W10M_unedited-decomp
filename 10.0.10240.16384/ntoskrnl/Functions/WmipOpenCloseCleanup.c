// WmipOpenCloseCleanup 
 
int __fastcall WmipOpenCloseCleanup(int a1, int a2)
{
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  IofCompleteRequest(a2, 0);
  return 0;
}
