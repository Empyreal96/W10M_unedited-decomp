// VfSetVerifierRunningMode 
 
int __fastcall VfSetVerifierRunningMode(int a1)
{
  int result; // r0

  if ( (unsigned int)(a1 - 1) > 3 )
    return -1073741811;
  result = 0;
  VfVerifyMode = a1;
  __dmb(0xBu);
  dword_620DEC = a1;
  return result;
}
