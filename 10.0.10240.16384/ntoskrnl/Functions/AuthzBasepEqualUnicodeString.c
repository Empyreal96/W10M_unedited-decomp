// AuthzBasepEqualUnicodeString 
 
int __fastcall AuthzBasepEqualUnicodeString(int a1, int a2)
{
  int result; // r0

  if ( (unsigned int)KeGetCurrentIrql() >= 2 )
    result = AuthzBasepEqualUnicodeStringCaseSensitive(a1, a2);
  else
    result = RtlEqualUnicodeString(a1, a2, 1);
  return result;
}
