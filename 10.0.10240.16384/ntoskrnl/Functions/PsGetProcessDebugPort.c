// PsGetProcessDebugPort 
 
int __fastcall PsGetProcessDebugPort(int a1)
{
  return *(_DWORD *)(a1 + 340);
}
