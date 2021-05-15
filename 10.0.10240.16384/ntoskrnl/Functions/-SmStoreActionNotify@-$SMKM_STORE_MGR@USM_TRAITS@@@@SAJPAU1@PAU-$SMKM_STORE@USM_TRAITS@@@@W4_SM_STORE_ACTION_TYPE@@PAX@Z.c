// -SmStoreActionNotify@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@W4_SM_STORE_ACTION_TYPE@@PAX@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoreActionNotify(int a1, int a2, int a3)
{
  int result; // r0
  _DWORD *v4; // r0
  unsigned int v5; // r4
  unsigned int v6; // r1
  unsigned int v7; // r6
  _DWORD *v8; // r4
  unsigned int *v9; // r5
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r4
  unsigned int v14; // r1

  switch ( a3 )
  {
    case 0:
      SMKM_STORE_MGR<SM_TRAITS>::SmEmptyStore(SmGlobals, *(_DWORD *)(a2 + 3512) & 0x1F, 1);
      return 0;
    case 1:
      v7 = *(_DWORD *)(a2 + 3512);
      v8 = &SmGlobals[24 * (v7 & 0x1F)];
      v9 = v8 + 1;
      __pld(v8 + 1);
      v10 = v8[1] & 0xFFFFFFFE;
      do
        v11 = __ldrex(v9);
      while ( v11 == v10 && __strex(v10 + 2, v9) );
      __dmb(0xBu);
      if ( v11 == v10 || ExfAcquireRundownProtection(v8 + 1) )
      {
        if ( (v8[3] & 0x7FF) == v7 >> 5 )
        {
          v12 = *v8;
          goto LABEL_25;
        }
        __pld(v9);
        v13 = *v9 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v14 = __ldrex(v9);
        while ( v14 == v13 && __strex(v13 - 2, v9) );
        if ( v14 != v13 )
          ExfReleaseRundownProtection((unsigned __int8 *)v9);
      }
      v12 = 0;
LABEL_25:
      if ( !v12 )
        return -1073741431;
      return 0;
    case 2:
      v4 = &SmGlobals[24 * (*(_DWORD *)(a2 + 3512) & 0x1F) + 1];
      __pld(v4);
      v5 = *v4 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v6 = __ldrex(v4);
      while ( v6 == v5 && __strex(v5 - 2, v4) );
      if ( v6 != v5 )
        ExfReleaseRundownProtection((unsigned __int8 *)v4);
      return 0;
  }
  if ( (unsigned int)(a3 - 3) > 1 )
    result = -1073741811;
  else
    result = SMKM_STORE_MGR<SM_TRAITS>::SmStoreTerminate(SmGlobals, a2, a3 != 3);
  return result;
}
