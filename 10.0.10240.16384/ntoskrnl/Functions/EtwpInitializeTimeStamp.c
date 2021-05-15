// EtwpInitializeTimeStamp 
 
int __fastcall EtwpInitializeTimeStamp(int a1)
{
  int v2; // r3
  void *v3; // r3
  int *v4; // r2
  int v5; // r3
  int *v6; // r5
  int *v7; // r4
  int result; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3

  v2 = *(_DWORD *)(a1 + 124);
  if ( v2 == 2 )
  {
    v3 = EtwpGetSystemTime;
  }
  else if ( v2 == 3 )
  {
    v3 = EtwpGetCycleCount;
  }
  else
  {
    *(_DWORD *)(a1 + 124) = 1;
    v3 = EtwpGetPerfCounter;
  }
  *(_DWORD *)(a1 + 32) = v3;
  if ( (*(_DWORD *)(a1 + 608) & 2) != 0 )
  {
    v4 = &EtwpRefTimeSystem;
    *(_DWORD *)(a1 + 232) = EtwpRefTimeSystem;
    *(_DWORD *)(a1 + 236) = dword_61A914;
    v5 = *(_DWORD *)(a1 + 124);
    if ( v5 == 3 )
    {
      v4 = &EtwpRefTimeCycle;
    }
    else if ( v5 != 2 )
    {
      v4 = &EtwpRefTimePerfCounter;
    }
    *(_DWORD *)(a1 + 240) = *v4;
    *(_DWORD *)(a1 + 244) = v4[1];
  }
  else
  {
    *(_QWORD *)(a1 + 240) = ((__int64 (*)(void))*(_DWORD *)(a1 + 32))();
    KeQuerySystemTimePrecise((__int64 *)(a1 + 232));
  }
  v6 = (int *)(a1 + 336);
  v7 = (int *)(a1 + 232);
  result = *v7;
  v9 = v7[1];
  v10 = v7[2];
  v11 = v7[3];
  *v6 = *v7;
  v6[1] = v9;
  v6[2] = v10;
  v6[3] = v11;
  return result;
}
