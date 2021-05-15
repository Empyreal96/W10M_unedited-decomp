// WheapCheckForAndReportErrorsFromPreviousSession 
 
int WheapCheckForAndReportErrorsFromPreviousSession()
{
  int result; // r0
  _DWORD *v1; // [sp+10h] [bp-20h]
  int v2; // [sp+14h] [bp-1Ch] BYREF
  char v3[4]; // [sp+18h] [bp-18h] BYREF
  int v4; // [sp+20h] [bp-10h]
  int v5; // [sp+24h] [bp-Ch]

  if ( PshedGetBootErrorPacket(v3, &v2) < 0 )
    v2 = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    if ( PshedReadErrorRecord(0) < 0 )
      break;
    if ( ((int (__fastcall *)())WheapReportPersistedErrorRecord)() == 1 )
      PshedClearErrorRecord((unsigned __int16)(v1[28] >> 8), v1[28] >> 8, v1[24], v1[25]);
    ExFreePoolWithTag(v1);
  }
  while ( (v4 & v5) != -1 );
  result = v2;
  if ( v2 )
  {
    WheapReportBootError();
    result = ExFreePoolWithTag(v2);
  }
  return result;
}
