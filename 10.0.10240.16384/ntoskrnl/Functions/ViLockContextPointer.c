// ViLockContextPointer 
 
int __fastcall ViLockContextPointer(int *a1)
{
  int v1; // r4
  unsigned int v2; // r1

  while ( 1 )
  {
    while ( 1 )
    {
      __pld(a1);
      v1 = *a1;
      if ( (*a1 & 1) == 0 )
        break;
      do
        v2 = __ldrex((unsigned int *)a1);
      while ( v2 == v1 && __strex(v1 - 1, (unsigned int *)a1) );
      __dmb(0xBu);
      if ( v2 == v1 )
        return 1;
    }
    if ( !v1 )
      break;
    __dmb(0xAu);
    __yield();
  }
  return 0;
}
