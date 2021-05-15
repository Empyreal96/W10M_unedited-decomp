// NtUnsubscribeWnfStateChange 
 
int __fastcall NtUnsubscribeWnfStateChange(int a1)
{
  int v1; // r3
  int v2; // r0
  int v3; // r4
  int v4; // r5
  int v5; // r2
  unsigned int v6; // r1
  __int16 v7; // r3
  int v9; // [sp+4h] [bp-1Ch] BYREF
  _DWORD v10[6]; // [sp+8h] [bp-18h] BYREF

  v1 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v1 & 0xFFFFFFC0) + 0x134);
  v2 = ExpCaptureWnfStateName(a1, v10, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
  v3 = v2;
  if ( v2 >= 0 )
  {
    v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v5 = *(_DWORD *)(v4 + 724);
    __dmb(0xBu);
    if ( v5 )
    {
      v2 = ExpWnfAcquireSubscriptionByName(v10[0], v10[1], v5, &v9, v2);
      v3 = v2;
      if ( v2 >= 0 )
      {
        v2 = ExpWnfDeleteSubscription(v9, v4);
        v3 = 0;
      }
    }
    else
    {
      v3 = -1073741772;
    }
  }
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v2);
  return v3;
}
