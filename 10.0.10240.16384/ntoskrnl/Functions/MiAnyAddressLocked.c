// MiAnyAddressLocked 
 
int __fastcall MiAnyAddressLocked(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // r2
  unsigned int *v3; // r3

  v2 = 1;
  if ( MEMORY[0xC0402004] <= 1u )
    return 0;
  v3 = (unsigned int *)(MEMORY[0xC04020FC] + MEMORY[0xC0402024]);
  while ( *v3 < a1 || *v3 > a2 )
  {
    ++v2;
    v3 = (unsigned int *)((char *)v3 + MEMORY[0xC0402024]);
    if ( v2 >= MEMORY[0xC0402004] )
      return 0;
  }
  return 1;
}
