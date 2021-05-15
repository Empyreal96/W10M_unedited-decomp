// PdcPoCsEnterExitReason 
 
int __fastcall PdcPoCsEnterExitReason(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v4[2]; // [sp+0h] [bp-8h] BYREF

  v4[0] = a2;
  v4[1] = a3;
  if ( (_DWORD)a1 )
  {
    PopPdcLastCsEnterReason = HIDWORD(a1);
  }
  else
  {
    PopPdcLastCsExitReason = HIDWORD(a1);
    LODWORD(a1) = KeQueryInterruptTimePrecise(v4);
    PopPdcLastCsExitTime = a1;
  }
  return a1;
}
