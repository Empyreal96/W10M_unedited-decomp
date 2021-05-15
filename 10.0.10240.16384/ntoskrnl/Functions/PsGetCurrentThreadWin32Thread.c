// PsGetCurrentThreadWin32Thread 
 
int PsGetCurrentThreadWin32Thread()
{
  int result; // r0

  result = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x11C);
  __dmb(0xBu);
  return result;
}
