// PoNotifyMediaBuffering 
 
int __fastcall PoNotifyMediaBuffering(int result)
{
  int v1; // r5
  char v2; // r7
  unsigned int v3; // r2
  int v4; // r0

  v1 = 0;
  v2 = result;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50F544();
  do
    v3 = __ldrex((unsigned int *)&PpmMediaBufferingWork);
  while ( __strex(1u, (unsigned int *)&PpmMediaBufferingWork) );
  __dmb(0xBu);
  if ( v3 )
    result = KxWaitForSpinLockAndAcquire(&PpmMediaBufferingWork);
  if ( !byte_61F484 )
  {
    v1 = 1;
    byte_61F484 = 1;
  }
  byte_61F485 = v2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseSpinLockInstrumented(&PpmMediaBufferingWork);
  }
  else
  {
    __dmb(0xBu);
    PpmMediaBufferingWork = 0;
  }
  if ( v1 )
  {
    v4 = KeQueryPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    if ( v4 < 31 )
      ++v4;
    result = ExQueueWorkItem(&dword_61F488, v4 + 32);
  }
  return result;
}
