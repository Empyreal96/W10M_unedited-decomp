// ObReleaseObjectSecurity 
 
int __fastcall ObReleaseObjectSecurity(int result, int a2)
{
  if ( result )
  {
    if ( a2 )
      result = ExFreePoolWithTag(result);
    else
      result = ObDereferenceSecurityDescriptor(result, 1);
  }
  return result;
}
