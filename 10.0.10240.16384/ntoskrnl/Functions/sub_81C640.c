// sub_81C640 
 
void sub_81C640()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  __mrc(15, 0, 13, 0, 3);
  v1 = KeAbPreAcquire((unsigned int)&SepRmNotifyMutex, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&SepRmNotifyMutex);
  while ( __strex(v2 & 0xFE, (unsigned __int8 *)&SepRmNotifyMutex) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&SepRmNotifyMutex, v1);
  JUMPOUT(0x7BCBA6);
}
