// ExpCovResetInfoCallBack 
 
int __fastcall ExpCovResetInfoCallBack(int a1, int a2)
{
  if ( ExpCovIsLoadedModulePresent(a1, *(_DWORD *)(a2 + 36), a2 + 12) == 1 )
    memset(
      (_BYTE *)(*(_DWORD *)(*(_DWORD *)(a1 + 72) + 32) + *(_DWORD *)(a1 + 72)),
      0,
      *(_DWORD *)(*(_DWORD *)(a1 + 72) + 28));
  return 0;
}
