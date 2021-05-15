// KiRundownMutants 
 
int __fastcall KiRundownMutants(int result)
{
  if ( *(_DWORD *)(result + 476) != result + 476 )
    result = sub_50AFCC();
  return result;
}
