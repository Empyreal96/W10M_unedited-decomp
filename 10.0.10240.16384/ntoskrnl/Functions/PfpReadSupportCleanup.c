// PfpReadSupportCleanup 
 
unsigned int __fastcall PfpReadSupportCleanup(int a1, _DWORD *a2)
{
  unsigned int result; // r0

  if ( a2[6] )
    NtClose();
  result = *a2;
  if ( *a2 )
    result = ExFreePoolWithTag(result);
  if ( (a2[5] & 4) != 0 )
    result = (unsigned int)PfpOpenHandleClose(a2 + 1, a1);
  return result;
}
