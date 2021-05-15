// KeEnterKernelDebugger 
 
void __noreturn KeEnterKernelDebugger()
{
  unsigned int v0; // r1

  KiHardwareTrigger = 1;
  __disable_irq();
  KfRaiseIrql(15);
  if ( !KdDebuggerEnabled && !KdPitchDebugger )
  {
    __dmb(0xBu);
    do
      v0 = __ldrex(&dword_64B118);
    while ( __strex(1u, &dword_64B118) );
    __dmb(0xBu);
    if ( !v0 )
      KdInitSystem(0, 0);
  }
  KiBugCheckDebugBreak(5);
}
