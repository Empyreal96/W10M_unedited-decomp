// -SmReadPickStore@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAT_SM_PAGE_KEY@@PAKPAPAU-$SMKM_STORE@USM_TRAITS@@@@2@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmReadPickStore(_DWORD *a1, unsigned int *a2, unsigned int *a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v8; // r7
  int v9; // r3
  unsigned __int64 v10; // kr00_8
  int result; // r0
  unsigned int v12; // r6
  _DWORD *v13; // r4
  unsigned int *v14; // r5
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // r2
  unsigned int v18; // r4
  unsigned int v19; // r1
  unsigned int v20; // r3
  unsigned int v21; // [sp+8h] [bp-28h] BYREF
  int v22; // [sp+Ch] [bp-24h] BYREF
  __int64 v23[4]; // [sp+10h] [bp-20h] BYREF

  v21 = *a3;
  v8 = SMKM_STORE_MGR<SM_TRAITS>::SmFeReadInitiate((int)a1, a2, &v21, v23, &v22);
  if ( v8 == 32 )
    return -1073741275;
  v9 = a1[1475] + 1;
  a1[1475] = v9;
  if ( (v9 & 0xFFF) == 0 && a1[796] )
    SMKM_STORE_MGR<SM_TRAITS>::SmStoresEtaCheck(a1);
  v10 = v23[0];
  if ( v23[0] )
  {
    KeQueryPerformanceCounter(v23, 0);
    if ( v10 > v23[0] + (unsigned __int64)(unsigned int)a1[1474] )
      return -1073741763;
  }
  if ( v8 >= 0x20 )
    return -1073741275;
  v12 = v8 | (32 * (a1[24 * v8 + 3] & 0x7FF));
  v13 = &a1[24 * (v12 & 0x1F)];
  v14 = v13 + 1;
  __pld(v13 + 1);
  v15 = v13[1] & 0xFFFFFFFE;
  do
    v16 = __ldrex(v14);
  while ( v16 == v15 && __strex(v15 + 2, v14) );
  __dmb(0xBu);
  if ( v16 == v15 || ExfAcquireRundownProtection(v13 + 1) )
  {
    if ( (v13[3] & 0x7FF) == v12 >> 5 )
    {
      v17 = *v13;
      goto LABEL_22;
    }
    __pld(v14);
    v18 = *v14 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v19 = __ldrex(v14);
    while ( v19 == v18 && __strex(v18 - 2, v14) );
    if ( v19 != v18 )
      ExfReleaseRundownProtection((unsigned __int8 *)v14);
  }
  v17 = 0;
LABEL_22:
  if ( !v17 )
    return -1073741275;
  *a5 = 0;
  if ( v22 )
    *a5 = 1;
  v20 = v21;
  *a4 = v17;
  result = 0;
  *a3 = v20;
  return result;
}
