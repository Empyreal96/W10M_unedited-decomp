// KeIsExecutingDpc 
 
int KeIsExecutingDpc()
{
  int v0; // r2
  int result; // r0

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v0 = 0;
  }
  else
  {
    __disable_irq();
    v0 = 1;
  }
  result = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10001;
  if ( v0 )
    __enable_irq();
  return result;
}
