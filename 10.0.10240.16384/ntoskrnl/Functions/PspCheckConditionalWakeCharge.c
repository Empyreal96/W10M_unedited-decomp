// PspCheckConditionalWakeCharge 
 
int __fastcall PspCheckConditionalWakeCharge(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r3
  int v6; // r4
  int v7; // r3

  v3 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  if ( !v3 )
    return 1;
  v5 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  v6 = *(_DWORD *)(v5 + 576);
  __dmb(0xBu);
  v7 = *(_DWORD *)(a2 + 576);
  __dmb(0xBu);
  if ( v6 != v7 )
    return 1;
  if ( PspIsProcessInJob(a1, a2, a3, 1) == 292 )
    return 0;
  return sub_7C0BC0();
}
