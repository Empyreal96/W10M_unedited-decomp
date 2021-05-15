// PopDisksRegisteredForIdle 
 
int PopDisksRegisteredForIdle()
{
  int v0; // r5
  int v1; // r7
  unsigned int v3; // r2
  int *i; // r2

  if ( (PopSimulate & 2) != 0 )
    return 1;
  v0 = 0;
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_528CD4();
  do
    v3 = __ldrex((unsigned int *)&PopDopeGlobalLock);
  while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
  __dmb(0xBu);
  if ( v3 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
  for ( i = (int *)PopIdleDetectList; i != &PopIdleDetectList; i = (int *)*i )
  {
    if ( i[2] == 1 )
    {
      v0 = 1;
      break;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopDopeGlobalLock);
  }
  else
  {
    __dmb(0xBu);
    PopDopeGlobalLock = 0;
  }
  KfLowerIrql(v1);
  return v0;
}
