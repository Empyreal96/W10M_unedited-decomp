// PpmEventPlatformVetoRundown 
 
void PpmEventPlatformVetoRundown()
{
  int v0; // r10
  unsigned int v1; // r2
  unsigned int *v2; // r1
  unsigned int v3; // r2
  unsigned int *v4; // r3
  unsigned int *v5; // r7
  unsigned int *v6; // r8
  unsigned int v7; // [sp+8h] [bp-58h] BYREF
  int v8; // [sp+Ch] [bp-54h]
  int *v9; // [sp+10h] [bp-50h]
  int v10; // [sp+14h] [bp-4Ch]
  int v11; // [sp+18h] [bp-48h]
  int v12; // [sp+1Ch] [bp-44h]
  _DWORD *v13; // [sp+20h] [bp-40h]
  int v14; // [sp+24h] [bp-3Ch]
  int v15; // [sp+28h] [bp-38h]
  int v16; // [sp+2Ch] [bp-34h]
  _DWORD *v17; // [sp+30h] [bp-30h]
  int v18; // [sp+34h] [bp-2Ch]
  int v19; // [sp+38h] [bp-28h]
  int v20; // [sp+3Ch] [bp-24h]
  int vars4; // [sp+64h] [bp+4h]

  if ( PpmEtwRegistered
    && EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PLATFORM_IDLE_VETO_RUNDOWN)
    && PpmPlatformStates )
  {
    v0 = KfRaiseIrql(2);
    v8 = v0;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&PpmIdleVetoLock);
    }
    else
    {
      do
        v1 = __ldrex((unsigned int *)&PpmIdleVetoLock);
      while ( __strex(1u, (unsigned int *)&PpmIdleVetoLock) );
      __dmb(0xBu);
      if ( v1 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&PpmIdleVetoLock);
    }
    v2 = (unsigned int *)PpmPlatformStates;
    v3 = 0;
    v7 = 0;
    if ( *(_DWORD *)PpmPlatformStates )
    {
      do
      {
        v10 = 0;
        v11 = 4;
        v4 = &v2[64 * v3];
        v12 = 0;
        v9 = (int *)&v7;
        v5 = (unsigned int *)v4[35];
        v6 = v4 + 35;
        if ( v5 != v4 + 35 )
        {
          do
          {
            v13 = v5 + 2;
            v14 = 0;
            v15 = 4;
            v16 = 0;
            v17 = v5 + 3;
            v18 = 0;
            v19 = 4;
            v20 = 0;
            EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PLATFORM_IDLE_VETO_RUNDOWN, 0);
            v5 = (unsigned int *)*v5;
          }
          while ( v5 != v6 );
          v3 = v7;
          v2 = (unsigned int *)PpmPlatformStates;
        }
        v7 = ++v3;
      }
      while ( v3 < *v2 );
      v0 = v8;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PpmIdleVetoLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      PpmIdleVetoLock = 0;
    }
    KfLowerIrql(v0);
  }
}
