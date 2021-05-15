// ExpCovIsUnLoadedModulePresent 
 
int __fastcall ExpCovIsUnLoadedModulePresent(int a1, int a2, unsigned __int16 *a3, unsigned __int8 *a4)
{
  int v5; // r1
  int result; // r0

  v5 = *(_DWORD *)(a1 + 28);
  if ( v5 )
    result = ExpCovIsModulePresent(a1 + 8, v5, a2, a3, a4);
  else
    result = 0;
  return result;
}
