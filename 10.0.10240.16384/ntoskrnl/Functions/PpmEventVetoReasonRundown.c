// PpmEventVetoReasonRundown 
 
void PpmEventVetoReasonRundown()
{
  int v0; // r6
  int v1; // r7
  int v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r4
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8[16]; // [sp+8h] [bp-40h] BYREF

  if ( PpmEtwRegistered )
  {
    v0 = dword_61DEC4;
    v1 = PpmEtwHandle;
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_VETO_NAME_RUNDOWN) )
    {
      v2 = PpmIdleVetoList;
      if ( PpmIdleVetoList )
      {
        v8[2] = (int)v8;
        v8[3] = 0;
        v8[4] = 4;
        v8[5] = 0;
        v3 = 0;
        if ( *(_DWORD *)PpmIdleVetoList )
        {
          while ( 1 )
          {
            v4 = v3 + 1;
            v5 = v2 + 8 * v3;
            v8[0] = v3 + 1;
            v6 = *(unsigned __int16 *)(v5 + 6);
            v7 = *(_DWORD *)(v5 + 8);
            v8[8] = v6;
            v8[6] = v7;
            v8[7] = 0;
            v8[9] = 0;
            EtwWrite(v1, v0, (int)PPM_ETW_VETO_NAME_RUNDOWN, 0);
            v2 = PpmIdleVetoList;
            v3 = v4;
            if ( v4 >= *(_DWORD *)PpmIdleVetoList )
              break;
            v0 = dword_61DEC4;
            v1 = PpmEtwHandle;
          }
        }
      }
    }
  }
}
