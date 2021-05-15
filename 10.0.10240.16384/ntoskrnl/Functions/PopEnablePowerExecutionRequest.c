// PopEnablePowerExecutionRequest 
 
int __fastcall PopEnablePowerExecutionRequest(int a1)
{
  int v2; // r2
  int v3; // r5
  int v4; // r3

  if ( !*(_DWORD *)(a1 + 64) && PopExecutionRequiredTimeout && !PopLastCsEnterTime )
  {
    v2 = *(_DWORD *)(a1 + 68);
    v3 = *(_DWORD *)(v2 + 288);
    __dmb(0xBu);
    if ( v3 && (*(_DWORD *)(v3 + 744) & 0x1000) != 0 )
    {
      __mrc(15, 0, 13, 0, 3);
      PspChargeJobWakeCounter((_DWORD *)v3, 0, 1, 0, 1u, 0, 1, v2, a1);
      ObfReferenceObjectWithTag(v3);
      v4 = v3 | 1;
    }
    else
    {
      v4 = 0;
    }
    *(_DWORD *)(a1 + 64) = v4;
  }
  return 0;
}
