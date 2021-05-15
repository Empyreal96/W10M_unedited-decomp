// PdcPoCurrentPdcPhase 
 
int __fastcall PdcPoCurrentPdcPhase(__int64 a1, __int64 a2)
{
  int v2; // r4
  __int64 v3; // kr00_8
  int v4; // r1
  char v5; // r3
  char v6; // r3

  v2 = HIDWORD(a1);
  if ( (_DWORD)a1 == 1 )
  {
    LODWORD(a1) = PopCsStateChanged(HIDWORD(a1) != 0);
  }
  else if ( (_DWORD)a1 == 7 )
  {
    a1 = PpmQueryTime(7, a2);
    if ( v2 )
    {
      qword_6353C8 = a1;
      v6 = PopFxDeviceAccountingLevel;
      __dmb(0xBu);
      if ( (v6 & 2) != 0 )
        LODWORD(a1) = PopFxResumeDeviceAccounting();
    }
    else
    {
      v3 = qword_6353D0 + (unsigned int)PpmConvertTimeTo(a1 - qword_6353C8, (unsigned __int64)(a1 - qword_6353C8) >> 32);
      LODWORD(qword_6353D0) = v3;
      HIDWORD(qword_6353D0) = v4 + HIDWORD(v3);
      v5 = PopFxDeviceAccountingLevel;
      __dmb(0xBu);
      if ( (v5 & 2) != 0 )
        PopFxPauseDeviceAccounting();
      LODWORD(a1) = PopBatteryRefreshStatus();
    }
  }
  return a1;
}
