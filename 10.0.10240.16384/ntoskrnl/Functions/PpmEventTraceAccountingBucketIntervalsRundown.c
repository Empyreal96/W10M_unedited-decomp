// PpmEventTraceAccountingBucketIntervalsRundown 
 
void PpmEventTraceAccountingBucketIntervalsRundown()
{
  __int64 v0; // kr00_8
  _DWORD *v1; // r0
  char *v2; // r1
  int v3; // r4
  int v4; // r3
  int v5[10]; // [sp+8h] [bp-108h] BYREF
  char v6[224]; // [sp+30h] [bp-E0h] BYREF

  if ( PpmEtwRegistered )
  {
    v0 = *(_QWORD *)&PpmEtwHandle;
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_ACCOUNTING_BUCKET_INTERVALS_RUNDOWN) )
    {
      v1 = &PpmIdleIntervalLimits;
      v2 = v6;
      v5[0] = 26;
      v3 = 26;
      do
      {
        *(_DWORD *)v2 = v1[2];
        v4 = v1[3];
        v1 += 6;
        *((_DWORD *)v2 + 1) = v4;
        v2 += 8;
        --v3;
      }
      while ( v3 );
      v5[2] = (int)v5;
      v5[3] = 0;
      v5[4] = 4;
      v5[5] = 0;
      v5[6] = (int)v6;
      v5[7] = 0;
      v5[8] = 208;
      v5[9] = 0;
      EtwWrite(v0, SHIDWORD(v0), (int)PPM_ETW_ACCOUNTING_BUCKET_INTERVALS_RUNDOWN, 0);
    }
  }
}
