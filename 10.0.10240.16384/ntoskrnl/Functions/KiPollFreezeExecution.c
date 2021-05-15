// KiPollFreezeExecution 
 
int KiPollFreezeExecution()
{
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC08) & 0xF) == 5 )
    return sub_5197D4();
  __dmb(0xAu);
  __yield();
  return 0;
}
