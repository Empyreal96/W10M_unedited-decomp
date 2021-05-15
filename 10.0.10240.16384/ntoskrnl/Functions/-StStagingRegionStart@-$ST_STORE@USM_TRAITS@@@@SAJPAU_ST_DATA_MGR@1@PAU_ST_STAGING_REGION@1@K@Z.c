// -StStagingRegionStart@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_STAGING_REGION@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StStagingRegionStart(int a1, _DWORD *a2, int a3)
{
  _BYTE *v6; // r0
  _BYTE *v7; // r5
  int v8; // r4
  int v9; // r8
  _BYTE *v10; // r0
  _DWORD *v11; // r4

  v6 = (_BYTE *)ExAllocatePoolWithTag(512, *(_DWORD *)(a1 + 80));
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, *(_DWORD *)(a1 + 80));
  v9 = SmCalcIoWorkItemSize(*(_DWORD *)(a1 + 92), v7, *(_DWORD *)(a1 + 80));
  v10 = (_BYTE *)ExAllocatePoolWithTag(512, v9);
  v11 = v10;
  if ( v10 )
  {
    memset(v10, 0, v9);
    *v11 |= 7u;
    a2[1] = v7;
    a2[2] = v11;
    v7 = 0;
    v8 = 0;
    *a2 = a3;
  }
  else
  {
    v8 = -1073741670;
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v8;
}
