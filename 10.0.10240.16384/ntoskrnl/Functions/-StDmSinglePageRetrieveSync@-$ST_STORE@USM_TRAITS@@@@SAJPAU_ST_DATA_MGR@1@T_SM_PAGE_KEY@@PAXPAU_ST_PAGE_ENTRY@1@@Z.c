// -StDmSinglePageRetrieveSync@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@T_SM_PAGE_KEY@@PAXPAU_ST_PAGE_ENTRY@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmSinglePageRetrieveSync(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // r3
  int result; // r0
  int v9; // r0
  _DWORD *v10; // r4
  int v11; // r2
  int *v12; // [sp+8h] [bp-38h] BYREF
  int **v13; // [sp+Ch] [bp-34h]
  _DWORD v14[4]; // [sp+10h] [bp-30h] BYREF
  _DWORD var20[14]; // [sp+20h] [bp-20h] BYREF

  var20[10] = a1;
  var20[12] = a3;
  var20[13] = a4;
  v14[0] = 0;
  v14[1] = a3;
  v14[2] = a2;
  v6 = a4 | 1;
  var20[11] = a2;
  if ( !a4 )
    v6 = 0;
  result = ST_STORE<SM_TRAITS>::StDmpSinglePageRetrieve(a1, a1 + 61, v14, v6, var20);
  if ( result > 0 )
  {
    v9 = ST_STORE<SM_TRAITS>::StDeviceIoBuild(a1, var20, 1, a3);
    v10 = (_DWORD *)v9;
    if ( v9 )
    {
      v11 = *(_DWORD *)(v9 + 16) | 0xC;
      *(_DWORD *)(v9 + 16) = v11;
      *(_DWORD *)(v9 + 16) = ((unsigned __int8)v11 ^ (unsigned __int8)(16 * (a4 != 0))) & 0x10 ^ v11;
      v13 = &v12;
      v12 = 0;
      *(_DWORD *)v9 = *(_DWORD *)v9 & 7 | 8;
      *v13 = (int *)((unsigned int)*v13 & 7 | v9);
      v13 = (int **)v9;
      if ( ST_STORE<SM_TRAITS>::StDeviceIoIssue((int)a1, &v12) >= 0 )
        SmWaitForSyncIo(a1[23]);
      result = ST_STORE<SM_TRAITS>::StDmDeviceIoCompletion((int)a1, v10);
      if ( result >= 0 )
        result = 0;
    }
    else
    {
      result = -1073741670;
    }
  }
  return result;
}
