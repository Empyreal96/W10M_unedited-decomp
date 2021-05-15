// KeAreInterruptsEnabled 
 
BOOL KeAreInterruptsEnabled()
{
  return (__get_CPSR() & 0x80) == 0;
}
