// KiDpcWatchdog 
 
void KiDpcWatchdog()
{
  __disable_irq();
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xCC0) = 0;
  __enable_irq();
}
