// -StDmEtaPerformIo@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@KK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmEtaPerformIo(_DWORD *a1, int a2, __int16 a3)
{
  int v4; // r0
  _DWORD *v5; // r4
  int *v7; // [sp+0h] [bp-28h] BYREF
  int **v8; // [sp+4h] [bp-24h]
  int v9; // [sp+8h] [bp-20h] BYREF
  int v10; // [sp+Ch] [bp-1Ch]
  int v11; // [sp+10h] [bp-18h]
  int v12; // [sp+14h] [bp-14h]

  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v9 = a2 << a1[25];
  v10 = (unsigned __int16)(a3 - a1[28]);
  v4 = ST_STORE<SM_TRAITS>::StDeviceIoBuild(a1, &v9, 1, 57005);
  v5 = (_DWORD *)v4;
  if ( !v4 )
    return -1073741670;
  *(_DWORD *)(v4 + 16) |= 0xCu;
  v8 = &v7;
  v7 = 0;
  *(_DWORD *)v4 = *(_DWORD *)v4 & 7 | 8;
  *v8 = (int *)((unsigned int)*v8 & 7 | v4);
  v8 = (int **)v4;
  if ( ST_STORE<SM_TRAITS>::StDeviceIoIssue((int)a1, &v7) >= 0 )
    SmWaitForSyncIo(a1[23]);
  if ( (v5[4] & 1) == 0 )
    ST_STORE<SM_TRAITS>::StDeviceIoMarkFailed(v5 + 1, -1073741691);
  ST_STORE<SM_TRAITS>::StDmDeviceIoCompletion((int)a1, v5);
  return 0;
}
