// PpmIdleInstallDefaultStates 
 
int __fastcall PpmIdleInstallDefaultStates(int a1, int a2)
{
  *(_DWORD *)(a2 + 8) = a1 + 2944;
  return PpmInstallNewIdleStates();
}
