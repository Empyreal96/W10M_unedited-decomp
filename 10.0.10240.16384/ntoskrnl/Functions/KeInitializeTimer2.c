// KeInitializeTimer2 
 
int __fastcall KeInitializeTimer2(int result, int a2, int a3, int a4)
{
  char v4; // r4
  char v5; // r3
  char v6; // r3

  *(_DWORD *)result = 0;
  v4 = a4;
  if ( a4 < 0 )
    v5 = 24;
  else
    v5 = 25;
  *(_DWORD *)(result + 4) = 0;
  *(_BYTE *)result = v5;
  *(_DWORD *)(result + 8) = result + 8;
  *(_DWORD *)(result + 12) = result + 8;
  *(_DWORD *)(result + 64) = __ROR4__(bswap32(KiWaitAlways ^ a2) ^ result, KiWaitNever) ^ KiWaitNever;
  *(_DWORD *)(result + 68) = __ROR4__(bswap32(KiWaitAlways ^ a3) ^ result, KiWaitNever) ^ KiWaitNever;
  *(_DWORD *)(result + 72) = __ROR4__(bswap32(KiWaitAlways) ^ result, KiWaitNever) ^ KiWaitNever;
  *(_DWORD *)(result + 76) = __ROR4__(bswap32(KiWaitAlways) ^ result, KiWaitNever) ^ KiWaitNever;
  v6 = v4 & 0xE;
  if ( (v4 & 0xE) == 0 )
    v6 = 1;
  *(_BYTE *)(result + 81) = v6;
  return result;
}
