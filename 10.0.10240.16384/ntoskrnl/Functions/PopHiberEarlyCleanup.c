// PopHiberEarlyCleanup 
 
unsigned int __fastcall PopHiberEarlyCleanup(int a1)
{
  unsigned int result; // r0

  MmInvalidateDumpAddresses(dword_61EEBC, 13);
  result = *(_DWORD *)(a1 + 188);
  if ( result )
    result = MmInvalidateDumpAddresses(result, 16 * *(_DWORD *)(a1 + 160));
  return result;
}
