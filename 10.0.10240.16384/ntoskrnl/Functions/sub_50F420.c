// sub_50F420 
 
void __fastcall sub_50F420(char a1, int a2, int a3)
{
  *(_BYTE *)(*(_DWORD *)(a3 + 4 * KiClockTimerOwner) + 18) ^= (*(_BYTE *)(*(_DWORD *)(a3 + 4 * KiClockTimerOwner) + 18) ^ a1) & 1;
  JUMPOUT(0x4F269A);
}
