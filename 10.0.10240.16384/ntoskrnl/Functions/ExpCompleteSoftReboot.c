// ExpCompleteSoftReboot 
 
int ExpCompleteSoftReboot()
{
  unsigned int v0; // r1
  int v1; // r4
  int result; // r0
  unsigned int v3; // r1
  unsigned int v4; // r2

  do
  {
    v1 = ExSoftRebootFlags;
    if ( (ExSoftRebootFlags & 2) == 0 )
      return 0;
    __dmb(0xBu);
    do
      v0 = __ldrex((unsigned int *)&ExSoftRebootFlags);
    while ( v0 == v1 && __strex(v1 & 0xFFFFFFF8 | 1, (unsigned int *)&ExSoftRebootFlags) );
    __dmb(0xBu);
  }
  while ( v0 != v1 );
  result = KsrCleanupPageDatabase_0();
  if ( result < 0 )
  {
    v3 = ExSoftRebootFlags & 0xFFFFFFF8 | 6;
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&ExSoftRebootFlags);
    while ( __strex(v3, (unsigned int *)&ExSoftRebootFlags) );
    __dmb(0xBu);
  }
  return result;
}
