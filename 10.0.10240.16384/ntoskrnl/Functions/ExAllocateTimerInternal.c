// ExAllocateTimerInternal 
 
int __fastcall ExAllocateTimerInternal(int a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r5

  if ( (a3 & 0x8000000E) != a3 || (a3 & 8) != 0 && (a3 & 6) != 0 )
    sub_5545F0();
  v6 = ExAllocatePoolWithTag(512, 104);
  v7 = v6;
  if ( v6 )
  {
    KeInitializeTimer2(v6, a1, a2, a3);
    *(_DWORD *)(v7 + 88) = __ROR4__(bswap32(KiWaitAlways) ^ v7, KiWaitNever) ^ KiWaitNever;
    *(_DWORD *)(v7 + 92) = __ROR4__(bswap32(KiWaitAlways) ^ v7, KiWaitNever) ^ KiWaitNever;
    *(_BYTE *)(v7 + 96) = ExpTimerFreedCookie;
  }
  return v7;
}
