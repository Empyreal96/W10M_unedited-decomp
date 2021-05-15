// ExCovReadjustUnloadedModuleEntry 
 
int __fastcall ExCovReadjustUnloadedModuleEntry(int result)
{
  if ( *(_DWORD *)(result + 72) )
    result = sub_7CEA20();
  return result;
}
