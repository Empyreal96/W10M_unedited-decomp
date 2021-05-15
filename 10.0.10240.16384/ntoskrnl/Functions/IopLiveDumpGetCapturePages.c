// IopLiveDumpGetCapturePages 
 
int __fastcall IopLiveDumpGetCapturePages(int a1, int a2, int a3)
{
  unsigned int *v6; // r4
  unsigned int v7; // r2
  int result; // r0
  int vars4; // [sp+24h] [bp+4h]

  v6 = (unsigned int *)(a2 + 12);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a2 + 12);
  }
  else
  {
    do
      v7 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire(v6);
  }
  result = IopLiveDumpGetCapturePagesNoLock(a1, a2, a3);
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseSpinLockInstrumented(v6, vars4);
  __dmb(0xBu);
  *v6 = 0;
  return result;
}
