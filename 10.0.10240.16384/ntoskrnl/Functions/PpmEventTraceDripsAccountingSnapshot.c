// PpmEventTraceDripsAccountingSnapshot 
 
void __fastcall PpmEventTraceDripsAccountingSnapshot(int a1, int a2)
{
  __int64 v3; // kr00_8
  int v4[18]; // [sp+8h] [bp-48h] BYREF

  v4[0] = 26;
  if ( PpmEtwRegistered )
  {
    v3 = *(_QWORD *)&PpmEtwHandle;
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_DRIPS_ACCOUNTING_SNAPSHOT) )
    {
      v4[2] = (int)&PopWdiCurrentScenarioInstanceId;
      v4[3] = 0;
      v4[4] = 1;
      v4[5] = 0;
      v4[6] = (int)v4;
      v4[7] = 0;
      v4[8] = 4;
      v4[9] = 0;
      v4[10] = a2;
      v4[11] = 0;
      v4[12] = 208;
      v4[13] = 0;
      EtwWrite(v3, SHIDWORD(v3), (int)PPM_ETW_DRIPS_ACCOUNTING_SNAPSHOT, 0);
    }
  }
}
