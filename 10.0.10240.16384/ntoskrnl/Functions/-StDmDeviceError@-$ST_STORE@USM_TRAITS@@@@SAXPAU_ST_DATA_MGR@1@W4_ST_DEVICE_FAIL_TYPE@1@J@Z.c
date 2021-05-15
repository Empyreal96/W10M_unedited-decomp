// -StDmDeviceError@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@W4_ST_DEVICE_FAIL_TYPE@1@J@Z 
 
_DWORD *__fastcall ST_STORE<SM_TRAITS>::StDmDeviceError(_DWORD *result, int a2, int a3)
{
  int *v3; // r4
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  __int64 v9; // kr00_8
  unsigned int v10; // r8
  unsigned int v11; // r9
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r3

  v3 = (int *)result[170];
  if ( v3
    && a3 != -1073741691
    && a3 != -1073741058
    && a3 != -1073741670
    && a3 != -1073741801
    && a3 != -1073741548
    && a3 != -1073741549
    && ((result[18] & 0x2000) == 0 || a3 != -2147483626) )
  {
    if ( a2 )
    {
      do
      {
        v9 = MEMORY[0xFFFF93B0];
        while ( 1 )
        {
          v10 = MEMORY[0xFFFF900C];
          __dmb(0xBu);
          v11 = MEMORY[0xFFFF9008];
          __dmb(0xBu);
          if ( v10 == MEMORY[0xFFFF9010] )
            break;
          __dmb(0xAu);
          __yield();
        }
      }
      while ( v9 != MEMORY[0xFFFF93B0] );
      v12 = (__int64)(__PAIR64__(v10, v11) - v9) >> 23;
      v13 = *v3;
      v14 = v3[4];
      v3[4] = *v3;
      if ( v13 != v14 )
        v3[3] = 0;
      v15 = v3[3];
      if ( !v15 )
      {
        v3[3] = v12;
        return result;
      }
      if ( (unsigned int)(v12 - v15) <= 7 )
        return result;
      v8 = 4;
    }
    else
    {
      v5 = v3[1] + 1;
      v3[1] = v5;
      if ( (v5 & 0xF) != 0 )
        return result;
      v6 = *v3;
      v7 = v3[2];
      v3[2] = *v3;
      if ( ((v6 - v7) & 0xFFFFFFE0) > 0x200 )
        return result;
      v8 = 3;
    }
    result = (_DWORD *)SMKM_STORE_MGR<SM_TRAITS>::SmStoreActionNotify((int)result, result[23], v8);
    if ( (int)result < 0 && !a2 )
      --v3[1];
  }
  return result;
}
