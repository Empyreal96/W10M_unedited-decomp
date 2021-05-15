// AdtpCleanupParameterAllocations 
 
int __fastcall AdtpCleanupParameterAllocations(int result, _DWORD *a2, unsigned int a3)
{
  unsigned int v4; // r4
  int i; // r7

  v4 = 0;
  for ( i = result; v4 < a3; a2 += 4 )
  {
    if ( *(_BYTE *)(v4 + i) )
      result = ExFreePoolWithTag(*a2, 0);
    ++v4;
  }
  return result;
}
