// RtlIsMultiSessionSku 
 
BOOL RtlIsMultiSessionSku()
{
  return (MEMORY[0xFFFF92F0] & 0x100) != 0;
}
