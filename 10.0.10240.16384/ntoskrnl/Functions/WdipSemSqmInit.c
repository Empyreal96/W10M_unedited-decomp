// WdipSemSqmInit 
 
int WdipSemSqmInit()
{
  int v0; // r4
  int v1; // r0
  int v3[12]; // [sp+8h] [bp-30h] BYREF

  v3[0] = 1;
  v3[2] = (int)v3;
  v3[3] = 0;
  v3[4] = 4;
  v3[5] = 0;
  v0 = SeLocalSystemSid;
  v1 = RtlLengthSid(SeLocalSystemSid);
  v3[7] = 0;
  v3[8] = v1;
  v3[9] = 0;
  v3[6] = v0;
  return WdipSemWriteEvent(WdipSemRegHandle, SHIDWORD(WdipSemRegHandle), (int)WDI_SEM_EVENT_SQM_INIT, 0);
}
