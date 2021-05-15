// KiUpdateProcessorCount 
 
int *KiUpdateProcessorCount()
{
  int *result; // r0
  char v1; // r2
  int v2; // r1

  KiActiveGroups = KiGetCurrentGroupCount();
  result = &KeNumberProcessors_0;
  __disable_irq();
  ++KeNumberProcessors_0;
  dword_681D78[0] |= 1 << v1;
  __enable_irq();
  if ( !v2 )
    ++KeNumberProcessorsGroup0;
  ++MEMORY[0xFFFF93C0];
  ++MEMORY[0xFFFF936A];
  MEMORY[0xFFFF93C4] = KiActiveGroups;
  return result;
}
