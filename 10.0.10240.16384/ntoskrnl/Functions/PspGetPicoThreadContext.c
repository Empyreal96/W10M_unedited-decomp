// PspGetPicoThreadContext 
 
int __fastcall PspGetPicoThreadContext(int a1)
{
  return *(_DWORD *)(a1 + 1072);
}
