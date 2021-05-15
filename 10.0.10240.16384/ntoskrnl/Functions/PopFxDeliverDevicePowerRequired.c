// PopFxDeliverDevicePowerRequired 
 
int __fastcall PopFxDeliverDevicePowerRequired(_DWORD *a1, int a2)
{
  int v4; // r0
  void (__fastcall *v5)(_DWORD); // r3
  unsigned int *v7; // r2
  unsigned int v8; // r0

  if ( a1[5] == 2 )
  {
    v4 = PopDiagTraceFxDevicePowerRequirement(a1[7], 0, 1);
    v5 = (void (__fastcall *)(_DWORD))a1[18];
    if ( !v5 )
      return sub_53EF84(v4);
    v5(a1[22]);
    __dmb(0xBu);
    v7 = a1 + 4;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 & 0xFFFFFFBF, v7) );
    __dmb(0xBu);
  }
  return PopFxCompleteDevicePowerRequired(a1, a2);
}
