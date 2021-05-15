// KiFinalizeTimer2Disablement 
 
int __fastcall KiFinalizeTimer2Disablement(int a1)
{
  int result; // r0
  void (__fastcall *v3)(unsigned int); // r9
  unsigned int v4; // r8
  int v5; // r10

  if ( (dword_682608 & 0x20000) != 0 )
    return sub_525408();
  result = KiWaitAlways;
  v3 = (void (__fastcall *)(unsigned int))(bswap32(__ROR4__(*(_DWORD *)(a1 + 72) ^ KiWaitNever, -(char)KiWaitNever) ^ a1) ^ KiWaitAlways);
  if ( v3 )
  {
    v4 = bswap32(__ROR4__(*(_DWORD *)(a1 + 76) ^ KiWaitNever, -(char)KiWaitNever) ^ a1) ^ KiWaitAlways;
    v5 = KfRaiseIrql(2);
    v3(v4);
    KfLowerIrql(v5);
    result = KiWaitAlways;
  }
  return result;
}
