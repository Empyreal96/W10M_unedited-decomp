// SeReleaseImageValidationContext 
 
unsigned int __fastcall SeReleaseImageValidationContext(unsigned int a1)
{
  unsigned int result; // r0

  if ( dword_61D8B4 )
    result = dword_61D8B4();
  else
    result = ExFreePoolWithTag(a1);
  return result;
}
