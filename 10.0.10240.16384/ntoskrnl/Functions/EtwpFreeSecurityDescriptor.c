// EtwpFreeSecurityDescriptor 
 
unsigned int __fastcall EtwpFreeSecurityDescriptor(unsigned int *a1)
{
  unsigned int result; // r0

  result = *a1;
  if ( result )
  {
    if ( result != WmipDefaultAccessSd && result != EtwpDefaultTraceSecurityDescriptor )
      result = ExFreePoolWithTag(result);
    *a1 = 0;
  }
  return result;
}
