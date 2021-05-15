// PpmEventTraceCoordinatedIdleStates 
 
unsigned __int64 __fastcall PpmEventTraceCoordinatedIdleStates(unsigned __int64 a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r2
  int v5; // r8
  int v6; // r7
  _BYTE *v7; // r0
  _DWORD *v8; // r6
  unsigned int v9; // r7
  _DWORD *v10; // r0
  _DWORD *v11; // r2
  int v12; // r1
  int v13; // r4
  int v14; // r3
  int v17[8]; // [sp+8h] [bp-20h] BYREF

  v17[0] = a2;
  v17[1] = a3;
  if ( PpmEtwRegistered && EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_COORDINATED_IDLE_RUNDOWN) )
  {
    v3 = PpmPlatformStates;
    v4 = PpmPlatformStates ? *(_DWORD *)PpmPlatformStates : 0;
    v5 = 2 * v4 + 1;
    v17[0] = v4;
    v6 = 12 * v4;
    v7 = (_BYTE *)ExAllocatePoolWithTag(1, 12 * v4 + 16 * v5, 1699565648);
    v8 = v7;
    if ( v7 )
    {
      memset(v7, 0, v6 + 16 * v5);
      *v8 = v17;
      v8[1] = 0;
      v8[2] = 4;
      v8[3] = 0;
      v9 = 0;
      v10 = &v8[4 * v5];
      if ( v17[0] )
      {
        v11 = v8 + 4;
        v12 = v3 + 128;
        do
        {
          *v10 = *(_DWORD *)v12;
          v10[1] = *(_DWORD *)(v12 + 4);
          v10[2] = *(unsigned __int8 *)(v12 + 29);
          v11[1] = 0;
          v11[2] = 12;
          *v11 = v10;
          v11[3] = 0;
          v13 = *(_DWORD *)(v12 + 52);
          if ( v13 )
          {
            v14 = *(unsigned __int16 *)(v12 + 50);
            v11[4] = v13;
          }
          else
          {
            v11[4] = L"<unspecified>";
            v14 = 28;
          }
          v11[6] = v14;
          v11[7] = 0;
          v11[5] = 0;
          ++v9;
          v10 += 3;
          v11 += 8;
          v12 += 256;
        }
        while ( v9 < v17[0] );
      }
      a1 = __PAIR64__((unsigned int)v8, v5);
      EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_COORDINATED_IDLE_RUNDOWN, 0);
      ExFreePoolWithTag((unsigned int)v8);
    }
  }
  return a1;
}
