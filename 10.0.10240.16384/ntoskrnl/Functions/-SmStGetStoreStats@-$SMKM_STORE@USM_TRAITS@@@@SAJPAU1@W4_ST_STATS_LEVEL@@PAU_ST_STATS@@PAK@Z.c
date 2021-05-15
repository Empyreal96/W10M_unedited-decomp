// -SmStGetStoreStats@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@W4_ST_STATS_LEVEL@@PAU_ST_STATS@@PAK@Z 
 
int SMKM_STORE<SM_TRAITS>::SmStGetStoreStats()
{
  return ST_STORE<SM_TRAITS>::StGetStatsWorker();
}
