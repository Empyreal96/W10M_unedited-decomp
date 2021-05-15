// -StDmCheckForCompaction@-$ST_STORE@USM_TRAITS@@@@SA-AW4_ST_COMPACTION_CHECK_RESULT@@PAU_ST_DATA_MGR@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmCheckForCompaction(int a1, char a2)
{
  unsigned int v3; // r8
  unsigned int i; // r6

  if ( (a2 & 3) != 0 || (*(_BYTE *)(a1 + 756) & 3) != 2 )
  {
    if ( *(_BYTE *)(a1 + 72) )
      v3 = 1;
    else
      v3 = 8;
    for ( i = 0; i < v3; ++i )
      a1 = ST_STORE<SM_TRAITS>::StDmComputeSpaceUsageForPriority(a1);
    if ( (a2 & 2) == 0 )
      __dmb(0xBu);
  }
  return 0;
}
