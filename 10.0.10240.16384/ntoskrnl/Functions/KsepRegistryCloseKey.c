// KsepRegistryCloseKey 
 
int __fastcall KsepRegistryCloseKey(int result)
{
  unsigned int v1; // r1

  if ( result )
  {
    result = ZwClose();
    __dmb(0xBu);
    do
      v1 = __ldrex(&dword_621724[6]);
    while ( __strex(v1 + 1, &dword_621724[6]) );
    __dmb(0xBu);
  }
  return result;
}
