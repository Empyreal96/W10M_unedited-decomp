// VerifierKeIsExecutingLegacyDpc 
 
int VerifierKeIsExecutingLegacyDpc()
{
  int v0; // r2
  __int16 v1; // r3

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v0 = 0;
  }
  else
  {
    __disable_irq();
    v0 = 1;
  }
  v1 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v0 )
    __enable_irq();
  return v1 & 1;
}
