// KiCacheFlushTrial 
 
void __fastcall __noreturn KiCacheFlushTrial(int a1, _BYTE *a2, int a3, int a4)
{
  KeFlushIoBuffers(a1, 0, 1);
  memset(a2, 1, a4);
  __dmb(0xFu);
  __rdpmccntr64();
  JUMPOUT(0x569D0E);
}
