// PpmEventTracePlatformIdleAccounting 
 
void PpmEventTracePlatformIdleAccounting()
{
  unsigned int v0; // r4
  _DWORD *v1; // r9
  int v2; // r6
  int v3; // r5
  _BYTE *v4; // r0
  _DWORD *v5; // r2
  _DWORD *v6; // r1
  int v7; // r0
  int v8; // r3
  _BYTE *v9; // r0
  _DWORD *v10; // r8
  char v11; // [sp+8h] [bp-78h] BYREF
  __int16 v12; // [sp+Ah] [bp-76h] BYREF
  int v13[29]; // [sp+Ch] [bp-74h] BYREF

  v12 = 1;
  v11 = 32;
  v0 = 0;
  if ( PpmEtwRegistered
    && EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PLATFORM_IDLE_ACCOUNTING_RUNDOWN)
    && PpmPlatformStates )
  {
    v1 = *(_DWORD **)(PpmPlatformStates + 32);
    v2 = 0;
    v3 = v1[1];
    if ( *(_DWORD *)(PpmPlatformStates + 4) == 1 )
    {
      v2 = 80 * v3;
      v4 = (_BYTE *)ExAllocatePoolWithTag(512, 80 * v3, 1699565648);
      v0 = (unsigned int)v4;
      if ( !v4 )
        return;
      memset(v4, 0, 80 * v3);
      if ( v3 )
      {
        v5 = (_DWORD *)v0;
        v6 = v1 + 18;
        v7 = v3;
        do
        {
          v5[2] = v6[8];
          v5[3] = v6[9];
          v5[4] = v6[10];
          v5[5] = v6[11];
          v5[6] = v6[14];
          v5[7] = v6[15];
          v5[8] = v6[12];
          v5[9] = v6[13];
          v5[14] = v6[4];
          v5[15] = v6[5];
          v5[16] = v6[2];
          v5[17] = v6[3];
          v5[18] = *v6;
          v5[19] = v6[1];
          *v5 = v6[20];
          v5[1] = v6[21];
          v5[10] = v6[24];
          v5[11] = v6[25];
          v5[12] = v6[22];
          v8 = v6[23];
          v6 += 248;
          v5[13] = v8;
          v5 += 20;
          --v7;
        }
        while ( v7 );
      }
    }
    v9 = (_BYTE *)ExAllocatePoolWithTag(512, 664 * v3 + 32, 1699565648);
    v10 = v9;
    if ( v9 )
    {
      memset(v9, 0, 664 * v3 + 32);
      PpmTranslatePlatformIdleAccounting(v1, v10);
      v13[1] = (int)v10;
      v13[2] = 0;
      v13[3] = 664 * v3 + 32;
      v13[4] = 0;
      v13[5] = (int)&v12;
      v13[6] = 0;
      v13[7] = 2;
      v13[8] = 0;
      v13[9] = (int)&v11;
      v13[10] = 0;
      v13[11] = 1;
      v13[12] = 0;
      if ( v0 )
      {
        v13[17] = v0;
        v13[18] = 0;
        v13[19] = v2;
        v13[20] = 0;
        v13[0] = v3;
      }
      else
      {
        v13[0] = 0;
      }
      v13[13] = (int)v13;
      v13[14] = 0;
      v13[15] = 4;
      v13[16] = 0;
      EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PLATFORM_IDLE_ACCOUNTING_RUNDOWN, 0);
      ExFreePoolWithTag((unsigned int)v10);
    }
    if ( v0 )
      ExFreePoolWithTag(v0);
  }
}
