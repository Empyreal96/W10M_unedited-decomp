// PopDiagTracePowerTransitionTime 
 
void PopDiagTracePowerTransitionTime()
{
  int v0; // [sp+8h] [bp-90h] BYREF
  int v1; // [sp+Ch] [bp-8Ch] BYREF
  int v2; // [sp+10h] [bp-88h] BYREF
  int v3; // [sp+14h] [bp-84h] BYREF
  int v4[32]; // [sp+18h] [bp-80h] BYREF

  if ( PopDiagHandleRegistered )
  {
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_TRANSITIONTIMES) )
    {
      PopPowerTransitionTimesInMs(v4, &v2, &v0, &v1, &v3);
      v4[2] = (int)v4;
      v4[3] = 0;
      v4[4] = 4;
      v4[5] = 0;
      v4[6] = (int)&v2;
      v4[7] = 0;
      v4[8] = 4;
      v4[9] = 0;
      v4[10] = (int)&dword_61F118;
      v4[11] = 0;
      v4[12] = 4;
      v4[13] = 0;
      v4[14] = (int)&v0;
      v4[15] = 0;
      v4[16] = 4;
      v4[17] = 0;
      v4[18] = (int)&v1;
      v4[19] = 0;
      v4[20] = 4;
      v4[21] = 0;
      v4[22] = (int)&dword_61F160;
      v4[23] = 0;
      v4[24] = 4;
      v4[25] = 0;
      v4[26] = (int)&v3;
      v4[27] = 0;
      v4[28] = 4;
      v4[29] = 0;
      EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_TRANSITIONTIMES, 0);
    }
  }
}
