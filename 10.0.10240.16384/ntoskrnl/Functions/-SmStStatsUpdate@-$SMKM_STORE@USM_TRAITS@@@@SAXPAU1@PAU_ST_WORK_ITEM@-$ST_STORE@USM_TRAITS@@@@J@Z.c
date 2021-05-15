// -SmStStatsUpdate@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@PAU_ST_WORK_ITEM@-$ST_STORE@USM_TRAITS@@@@J@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStStatsUpdate(unsigned __int64 a1, int a2)
{
  int v2; // r4
  int v3; // r5
  int v4; // r7
  int v5; // r6

  if ( a2 < 0 )
  {
    if ( (*(_DWORD *)(HIDWORD(a1) + 4) & 0x2000000) != 0 )
    {
      v2 = 2;
    }
    else if ( a2 == -1073741643 )
    {
      v2 = 3;
    }
    else
    {
      v2 = 4;
    }
  }
  else
  {
    v2 = 1;
  }
  v3 = *(_DWORD *)(a1 + 736);
  if ( v3 )
  {
    v4 = *(unsigned __int8 *)(HIDWORD(a1) + 4);
    v5 = *(_DWORD *)(v3 + 24);
    LODWORD(a1) = KeQueryInterruptTime();
    if ( a1 >= *(_QWORD *)(v3 + 32) )
    {
      LODWORD(a1) = StIoCountsMovePeriod(v3 + 24, a1);
      v5 = a1;
    }
    *(_DWORD *)(v5 + 4 * v2) += v4;
  }
  return a1;
}
