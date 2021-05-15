// PpmApplyProfile 
 
void __fastcall PpmApplyProfile(int *a1)
{
  int v2; // r10
  int v3; // r9
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r2
  int *v7; // r6
  __int64 v8; // r4
  int v9; // r1
  unsigned int v10; // r1
  int v11; // r0
  int *v12; // r2
  int *v13; // r2
  __int64 v14; // kr00_8
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // [sp+0h] [bp-50h]
  int *v20; // [sp+4h] [bp-4Ch]
  int v21[2]; // [sp+8h] [bp-48h] BYREF
  int v22[16]; // [sp+10h] [bp-40h] BYREF

  v2 = 0;
  v21[0] = dword_61EC0C;
  v3 = 0;
  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  do
    v6 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
  {
    sub_7F3648(v5);
  }
  else
  {
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = PpmCurrentProfile;
    if ( !a1 )
      a1 = &PpmDefaultProfile;
    LODWORD(v8) = KeQueryInterruptTime();
    HIDWORD(v8) = v9;
    PpmEndProfileAccumulation(v7, v9, v8, v9);
    v10 = 0;
    a1[6] |= 2u;
    v7[6] &= 0xFFFFFFFD;
    PpmCurrentProfile = a1;
    *((_QWORD *)a1 + 48) = v8;
    do
    {
      v11 = v21[0];
      if ( a1 != &PpmDefaultProfile )
      {
        v12 = &a1[44 * v21[0] + 2 * v10];
        v2 |= v12[8];
        v3 |= v12[9];
      }
      if ( v7 != &PpmDefaultProfile )
      {
        v13 = &v7[44 * v21[0] + 2 * v10];
        v2 |= v13[8];
        v3 |= v13[9];
      }
      ++v10;
    }
    while ( v10 < 2 );
    v21[0] = v2 & 0xD8030FC0;
    v21[1] = v3 & 0x3FF;
    PpmCompareAndApplyPolicySettings(v21, &v7[44 * v11 + 8], &a1[44 * v11 + 8]);
    if ( PpmEtwRegistered )
    {
      v14 = *(_QWORD *)&PpmEtwHandle;
      if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PROCESSOR_PROFILE_CHANGE) )
      {
        v22[0] = (int)(v7 + 1);
        v22[1] = 0;
        v22[2] = 1;
        v22[3] = 0;
        v22[4] = (int)(a1 + 1);
        v22[5] = 0;
        v22[6] = 1;
        v22[7] = 0;
        v20 = v22;
        v19 = 2;
        EtwWrite(v14, SHIDWORD(v14), (int)PPM_ETW_PROCESSOR_PROFILE_CHANGE, 0);
      }
    }
    if ( v7 == (int *)PpmLowPowerProfile )
    {
      if ( PpmLowPowerProfile )
      {
        v15 = PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
        PpmPostProcessMediaBuffering(v15, v16, v17, v18, v19, (int)v20, v21[0]);
      }
    }
  }
}
