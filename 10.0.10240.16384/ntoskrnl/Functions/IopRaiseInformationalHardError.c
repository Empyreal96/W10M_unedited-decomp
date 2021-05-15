// IopRaiseInformationalHardError 
 
unsigned int __fastcall IopRaiseInformationalHardError(unsigned int a1)
{
  unsigned int v2; // r0
  unsigned int result; // r0
  unsigned int v4; // r1

  if ( ExReadyForErrors )
    ExRaiseHardError(*(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 16) != 0);
  v2 = *(_DWORD *)(a1 + 16);
  if ( v2 )
    ExFreePoolWithTag(v2);
  result = ExFreePoolWithTag(a1);
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_631A54);
  while ( __strex(v4 - 1, (unsigned int *)&dword_631A54) );
  __dmb(0xBu);
  return result;
}
