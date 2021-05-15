// PoDestroyReasonContext 
 
int __fastcall PoDestroyReasonContext(_DWORD *a1)
{
  int result; // r0

  if ( *a1 )
    result = ExFreePoolWithTag(a1, 2017677904);
  else
    result = sub_523590();
  return result;
}
