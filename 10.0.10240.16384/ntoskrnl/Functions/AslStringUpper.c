// AslStringUpper 
 
unsigned int __fastcall AslStringUpper(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r4
  unsigned int result; // r0
  unsigned int i; // r5

  v1 = a1;
  result = wcslen(a1);
  for ( i = result; i; --i )
  {
    result = RtlUpcaseUnicodeChar(*v1);
    *v1++ = result;
  }
  return result;
}
