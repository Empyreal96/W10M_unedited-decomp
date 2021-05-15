// PsGetProcessProtection 
 
int __fastcall PsGetProcessProtection(int a1)
{
  return *(_DWORD *)(a1 + 734);
}
