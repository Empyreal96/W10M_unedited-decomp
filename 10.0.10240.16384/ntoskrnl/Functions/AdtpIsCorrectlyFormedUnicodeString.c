// AdtpIsCorrectlyFormedUnicodeString 
 
BOOL __fastcall AdtpIsCorrectlyFormedUnicodeString(unsigned __int16 *a1)
{
  return !a1 || a1[1] >= (unsigned int)*a1;
}
