// VfDevObjAdjustFdoForVerifierFilters 
 
int __fastcall VfDevObjAdjustFdoForVerifierFilters(int result)
{
  if ( *(int (**)())(*(_DWORD *)(*(_DWORD *)result + 8) + 164) == ViFilterDispatchPnp )
    *(_DWORD *)result = *(_DWORD *)(*(_DWORD *)result + 16);
  return result;
}
