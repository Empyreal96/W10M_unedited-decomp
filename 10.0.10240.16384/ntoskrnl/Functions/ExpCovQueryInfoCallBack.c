// ExpCovQueryInfoCallBack 
 
int __fastcall ExpCovQueryInfoCallBack(int a1, int a2)
{
  int v4; // r5
  int v5; // r0

  v4 = 0;
  if ( ExpCovIsLoadedModulePresent(a1, *(_DWORD *)(a2 + 36), a2 + 12) == 1 )
  {
    v5 = ExpCovQueryLoadedModule(a1, *(unsigned __int8 *)(a2 + 8), *(_DWORD *)(a2 + 4), *(_DWORD *)a2);
    v4 = v5;
    if ( !v5 || v5 == -1073741820 )
    {
      ++*(_DWORD *)(a2 + 40);
      if ( !v5 )
        *(_DWORD *)a2 = *(_DWORD *)a2;
      v4 = 0;
    }
  }
  return v4;
}
