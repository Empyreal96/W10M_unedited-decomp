// SeIsSecureBootDebugPolicyPresent 
 
BOOL SeIsSecureBootDebugPolicyPresent()
{
  BOOL v0; // r3

  if ( dword_641874 )
    v0 = memcmp(dword_641874 + 4, (unsigned int)dword_41CE4C, 16) == 0;
  else
    v0 = 0;
  return v0;
}
