// PspGetPicoProcessContext 
 
int __fastcall PspGetPicoProcessContext(int a1)
{
  return *(_DWORD *)(a1 + 780);
}
