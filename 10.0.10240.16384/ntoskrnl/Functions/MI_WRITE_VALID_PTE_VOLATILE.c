// MI_WRITE_VALID_PTE_VOLATILE 
 
int __fastcall MI_WRITE_VALID_PTE_VOLATILE(unsigned int *a1, int a2)
{
  unsigned int i; // r4
  int v4; // r2
  int result; // r0

  for ( i = *a1; ; i = result )
  {
    v4 = i;
    if ( a2 >= 0 )
    {
      if ( (a2 & 1) != 0 )
        v4 = i | 0x10;
      if ( (a2 & 2) != 0 )
        v4 &= 0xFFFFFDFF;
      if ( (a2 & 4) != 0 )
        break;
    }
    __dmb(0xBu);
    do
      result = __ldrex(a1);
    while ( result == i && __strex(v4, a1) );
    __dmb(0xBu);
    if ( result == i )
      return result;
  }
  return sub_51F0AC();
}
