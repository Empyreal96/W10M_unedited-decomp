// -SmStoresContentsRundown@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@@Z 
 
unsigned __int8 *__fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoresContentsRundown(unsigned __int8 *result)
{
  unsigned int v1; // r5
  int v2; // r8
  unsigned __int8 *v3; // r7
  unsigned int v4; // r10
  unsigned int v5; // r9
  unsigned int *v6; // r6
  unsigned int v7; // r4
  unsigned int v8; // r1
  int v9; // r1
  unsigned int v10; // r4
  unsigned int v11; // r1

  v1 = 0;
  v2 = (int)result;
  v3 = result;
  do
  {
    v4 = v1 | (32 * (*((_WORD *)v3 + 6) & 0x7FF));
    v5 = v2 + 96 * (v4 & 0x1F);
    v6 = (unsigned int *)(v5 + 4);
    __pld((void *)(v5 + 4));
    v7 = *(_DWORD *)(v5 + 4) & 0xFFFFFFFE;
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 + 2, v6) );
    __dmb(0xBu);
    if ( v8 == v7 || (result = (unsigned __int8 *)ExfAcquireRundownProtection((_DWORD *)(v5 + 4))) != 0 )
    {
      if ( (*(_WORD *)(v5 + 12) & 0x7FF) == v4 >> 5 )
      {
        v9 = *(_DWORD *)v5;
        goto LABEL_15;
      }
      __pld(v6);
      v10 = *v6 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v11 = __ldrex(v6);
      while ( v11 == v10 && __strex(v10 - 2, v6) );
      if ( v11 != v10 )
        result = ExfReleaseRundownProtection((unsigned __int8 *)(v5 + 4));
    }
    v9 = 0;
LABEL_15:
    if ( v9 )
      result = (unsigned __int8 *)SMKM_STORE_MGR<SM_TRAITS>::SmStoreContentsRundown(v2, v9);
    ++v1;
    v3 += 96;
  }
  while ( v1 < 0x20 );
  return result;
}
