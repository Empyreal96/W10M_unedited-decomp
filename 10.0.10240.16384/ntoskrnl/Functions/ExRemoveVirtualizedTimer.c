// ExRemoveVirtualizedTimer 
 
int __fastcall ExRemoveVirtualizedTimer(int result, int a2, int a3, int a4)
{
  int v6; // r5
  unsigned int *v7; // r4
  int v8; // r1
  unsigned int v9; // r2
  char v10; // r3
  int vars4; // [sp+1Ch] [bp+4h]

  v6 = result;
  v7 = (unsigned int *)(result - 116);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = KiAcquireSpinLockInstrumented(result - 116);
  }
  else
  {
    v8 = 1;
    do
      v9 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v9 )
      result = KxWaitForSpinLockAndAcquire((unsigned int *)(result - 116));
  }
  v10 = *(_BYTE *)(v6 - 20);
  *(_DWORD *)(v6 - 4) = 0;
  if ( (v10 & 2) != 0 )
    result = ExpTimerResume(v6 - 164, v8, a3, a4);
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseSpinLockInstrumented(v7, vars4);
  __dmb(0xBu);
  *v7 = 0;
  return result;
}
