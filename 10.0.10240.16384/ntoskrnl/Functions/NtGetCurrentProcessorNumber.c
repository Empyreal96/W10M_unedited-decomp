// NtGetCurrentProcessorNumber 
 
int NtGetCurrentProcessorNumber()
{
  int result; // r0

  result = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x99D);
  __mrc(15, 0, 13, 0, 3);
  return result;
}
