// VfInitSetVerifyDriverTargets 
 
int __fastcall VfInitSetVerifyDriverTargets(int a1, unsigned int a2)
{
  unsigned int v2; // r4
  int result; // r0

  v2 = a2;
  if ( a2 > 0x1800 )
  {
    v2 = 0x17FEu;
    word_9854EE = 0;
  }
  result = memmove((int)MmVerifyDriverBuffer, a1, v2);
  MmVerifyDriverBufferLength = v2;
  VfOptionFlags &= 0xFFFFFFFE;
  return result;
}
