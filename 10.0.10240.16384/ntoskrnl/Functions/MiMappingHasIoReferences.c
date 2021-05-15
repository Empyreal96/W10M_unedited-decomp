// MiMappingHasIoReferences 
 
unsigned int __fastcall MiMappingHasIoReferences(unsigned int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)(((a1 >> 20) & 0xFFC) - 1070596096);
  v2 = *v1;
  if ( (*v1 & 0x400) == 0 )
  {
    v1 = (unsigned int *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
    v2 = *v1;
  }
  while ( 1 )
  {
    __dmb(0xBu);
    do
      result = __ldrex(v1);
    while ( result == v2 && __strex(v2 | 0x100, v1) );
    __dmb(0xBu);
    if ( result == v2 )
      break;
    v2 = result;
  }
  return result;
}
