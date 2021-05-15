// ExpCovIsLoadedModulePresent 
 
int __fastcall ExpCovIsLoadedModulePresent(int a1, int a2, int a3)
{
  int v4; // r1
  int result; // r0

  v4 = *(_DWORD *)(a1 + 72);
  if ( v4 )
    result = ExpCovIsModulePresent(a1 + 44, v4, a2, a3);
  else
    result = 0;
  return result;
}
