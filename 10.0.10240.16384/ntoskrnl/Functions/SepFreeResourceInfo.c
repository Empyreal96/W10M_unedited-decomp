// SepFreeResourceInfo 
 
int __fastcall SepFreeResourceInfo(int result)
{
  int v1; // r4

  v1 = result;
  if ( result )
  {
    AuthzBasepFreeSecurityAttributesList(result);
    result = ExFreePoolWithTag(v1, 0);
  }
  return result;
}
