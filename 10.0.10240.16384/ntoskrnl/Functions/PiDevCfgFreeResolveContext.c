// PiDevCfgFreeResolveContext 
 
int __fastcall PiDevCfgFreeResolveContext(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 12) )
    return sub_7E43C4();
  result = *(_DWORD *)(a1 + 8);
  if ( result )
    result = ZwClose();
  return result;
}
