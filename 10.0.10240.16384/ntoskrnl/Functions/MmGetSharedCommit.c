// MmGetSharedCommit 
 
int MmGetSharedCommit()
{
  int result; // r0

  result = dword_634DAC;
  __dmb(0xBu);
  return result;
}
