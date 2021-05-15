// -StCleanup@-$ST_STORE@USM_TRAITS@@@@SAXPAU1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StCleanup(_DWORD *a1)
{
  int v2; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0

  a1[450] |= 1u;
  ST_STORE<SM_TRAITS>::StDmCleanup(a1 + 14, 0);
  ST_STORE<SM_TRAITS>::StDmCleanup(a1 + 206, 0);
  v2 = a1[11];
  if ( v2 )
    ExFreePoolWithTag(v2, 0);
  if ( a1[12] )
    return sub_51140C();
  v4 = a1[13];
  if ( v4 )
    ExFreePoolWithTag(v4, 0);
  v5 = a1[412];
  if ( v5 )
    ExFreePoolWithTag(v5, 0);
  v6 = a1[442];
  if ( v6 )
    ExFreePoolWithTag(v6, 0);
  StEtaCleanup(a1 + 400);
  SmCrEncCleanup(a1 + 418);
  return ST_STORE<SM_TRAITS>::StDrainReadContextList(a1);
}
