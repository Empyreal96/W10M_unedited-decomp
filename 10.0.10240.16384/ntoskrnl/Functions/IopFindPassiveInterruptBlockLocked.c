// IopFindPassiveInterruptBlockLocked 
 
int *__fastcall IopFindPassiveInterruptBlockLocked(int a1)
{
  int *result; // r0
  int *i; // r2
  unsigned int *v4; // r2
  unsigned int v5; // r1

  result = 0;
  for ( i = (int *)PassiveInterruptList; i != &PassiveInterruptList; i = (int *)*i )
  {
    if ( i[2] == a1 )
    {
      result = i;
      __dmb(0xBu);
      v4 = (unsigned int *)(i + 27);
      do
        v5 = __ldrex(v4);
      while ( __strex(v5 + 1, v4) );
      __dmb(0xBu);
      return result;
    }
  }
  return result;
}
