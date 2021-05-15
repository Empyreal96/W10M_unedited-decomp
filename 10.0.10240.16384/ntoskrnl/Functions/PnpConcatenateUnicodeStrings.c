// PnpConcatenateUnicodeStrings 
 
int __fastcall PnpConcatenateUnicodeStrings(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int result; // r0

  result = IopAllocateUnicodeString((int)a1, *a2);
  if ( result >= 0 )
  {
    RtlCopyUnicodeString(a1, a2);
    result = 0;
  }
  return result;
}
