// PopPepTriggerComponentActivatingActivity 
 
int __fastcall PopPepTriggerComponentActivatingActivity(int result, int a2)
{
  int v3; // r5
  int v4; // r1
  int v5; // r3
  unsigned __int64 v6; // kr00_8
  int v7; // r2

  v3 = result;
  if ( a2 )
  {
    v6 = KeQueryInterruptTime(result) - *(_QWORD *)(a2 + 104);
    v4 = HIDWORD(v6);
    v5 = v6;
    v7 = *(_DWORD *)(a2 + 96);
    if ( *(_QWORD *)(a2 + 96) < v6 )
    {
      v5 = *(_DWORD *)(a2 + 96);
      v4 = *(_DWORD *)(a2 + 100);
    }
    *(_DWORD *)(a2 + 88) = v5;
    *(_DWORD *)(a2 + 92) = v4;
    *(_DWORD *)(a2 + 120) = 0;
    PopPepTryPowerUpComponent(v3, a2, v7);
    result = PopPepGetComponentPreferedIdleState(a2);
    if ( result != *(_DWORD *)(a2 + 144) )
      result = PopPepTriggerActivity(v3, a2, 1, result | 0x80000000);
  }
  return result;
}
