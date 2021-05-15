// PopPepCompleteComponentActiveActivity 
 
int __fastcall PopPepCompleteComponentActiveActivity(int result, int a2)
{
  int v3; // r5
  __int64 v4; // r0
  int v5; // r3
  int v6; // r0

  v3 = result;
  if ( a2 )
  {
    v4 = KeQueryInterruptTime(result);
    v5 = *(_DWORD *)(a2 + 156);
    *(_QWORD *)(a2 + 104) = v4;
    *(_DWORD *)(a2 + 120) = v5 - 1;
    *(_DWORD *)(a2 + 128) = PopPepComponentGetResidencyIdleState(
                              a2,
                              HIDWORD(v4),
                              *(_DWORD *)(a2 + 88),
                              *(_DWORD *)(a2 + 92));
    *(_DWORD *)(a2 + 4) &= 0xFFFFFFFE;
    v6 = PopPepGetComponentPreferedIdleState(a2);
    if ( v6 != *(_DWORD *)(a2 + 144) )
      PopPepTriggerActivity(v3, a2, 1, v6);
    result = PopPepTryPowerDownComponent(v3, a2);
  }
  return result;
}
