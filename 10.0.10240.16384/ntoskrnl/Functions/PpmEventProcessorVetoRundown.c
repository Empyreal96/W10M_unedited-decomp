// PpmEventProcessorVetoRundown 
 
int __fastcall PpmEventProcessorVetoRundown(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r7
  unsigned int v4; // r2
  unsigned int v5; // r2
  int v6; // r3
  _DWORD *v7; // r7
  _DWORD *v8; // r8
  unsigned int v9; // [sp+8h] [bp-80h] BYREF
  __int16 v10; // [sp+Ch] [bp-7Ch] BYREF
  int v11; // [sp+10h] [bp-78h]
  __int16 *v12; // [sp+18h] [bp-70h]
  int v13; // [sp+1Ch] [bp-6Ch]
  int v14; // [sp+20h] [bp-68h]
  int v15; // [sp+24h] [bp-64h]
  int v16; // [sp+28h] [bp-60h]
  int v17; // [sp+2Ch] [bp-5Ch]
  int v18; // [sp+30h] [bp-58h]
  int v19; // [sp+34h] [bp-54h]
  int *v20; // [sp+38h] [bp-50h]
  int v21; // [sp+3Ch] [bp-4Ch]
  int v22; // [sp+40h] [bp-48h]
  int v23; // [sp+44h] [bp-44h]
  _DWORD *v24; // [sp+48h] [bp-40h]
  int v25; // [sp+4Ch] [bp-3Ch]
  int v26; // [sp+50h] [bp-38h]
  int v27; // [sp+54h] [bp-34h]
  _DWORD *v28; // [sp+58h] [bp-30h]
  int v29; // [sp+5Ch] [bp-2Ch]
  int v30; // [sp+60h] [bp-28h]
  int v31; // [sp+64h] [bp-24h]
  int vars4; // [sp+8Ch] [bp+4h]

  v1 = result;
  if ( PpmEtwRegistered )
  {
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PROCESSOR_IDLE_VETO_RUNDOWN);
    if ( result )
    {
      v2 = *(_DWORD *)(v1 + 2944);
      if ( v2 )
      {
        v10 = *(unsigned __int8 *)(v1 + 1052);
        v12 = &v10;
        v13 = 0;
        v14 = 2;
        v15 = 0;
        v16 = v1 + 1053;
        v17 = 0;
        v18 = 1;
        v19 = 0;
        v3 = KfRaiseIrql(2);
        v11 = v3;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)&PpmIdleVetoLock);
        }
        else
        {
          do
            v4 = __ldrex((unsigned int *)&PpmIdleVetoLock);
          while ( __strex(1u, (unsigned int *)&PpmIdleVetoLock) );
          __dmb(0xBu);
          if ( v4 )
            KxWaitForSpinLockAndAcquire((unsigned int *)&PpmIdleVetoLock);
        }
        v5 = 0;
        v9 = 0;
        if ( *(_DWORD *)(v2 + 28) )
        {
          do
          {
            v21 = 0;
            v22 = 4;
            v6 = v2 + (v5 << 6);
            v23 = 0;
            v20 = (int *)&v9;
            v7 = *(_DWORD **)(v6 + 292);
            v8 = (_DWORD *)(v6 + 292);
            if ( v7 != (_DWORD *)(v6 + 292) )
            {
              do
              {
                v24 = v7 + 2;
                v25 = 0;
                v26 = 4;
                v27 = 0;
                v28 = v7 + 3;
                v29 = 0;
                v30 = 4;
                v31 = 0;
                EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_PROCESSOR_IDLE_VETO_RUNDOWN, 0);
                v7 = (_DWORD *)*v7;
              }
              while ( v7 != v8 );
              v5 = v9;
            }
            v9 = ++v5;
          }
          while ( v5 < *(_DWORD *)(v2 + 28) );
          v3 = v11;
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
        result = KfLowerIrql(v3);
      }
    }
  }
  return result;
}
