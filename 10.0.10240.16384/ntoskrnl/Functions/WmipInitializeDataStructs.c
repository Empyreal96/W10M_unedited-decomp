// WmipInitializeDataStructs 
 
int WmipInitializeDataStructs()
{
  _DWORD *v0; // r4
  int result; // r0
  int v2; // r1
  _DWORD *i; // r2
  char v4[12]; // [sp+8h] [bp-88h] BYREF
  int v5; // [sp+14h] [bp-7Ch]
  int v6; // [sp+18h] [bp-78h]
  int v7; // [sp+1Ch] [bp-74h]
  int v8; // [sp+24h] [bp-6Ch]
  int v9; // [sp+28h] [bp-68h]
  int v10; // [sp+2Ch] [bp-64h]
  int v11[24]; // [sp+30h] [bp-60h] BYREF

  v5 = 298953435;
  v6 = -1610593601;
  v7 = 271124169;
  v8 = 298989845;
  v9 = -1073740911;
  v10 = -1567049393;
  WmipDSHead[0] = WmipDSHead;
  WmipDSHead[1] = WmipDSHead;
  WmipDSHeadPtr = (int)WmipDSHead;
  WmipGEHead[0] = WmipGEHead;
  WmipGEHead[1] = WmipGEHead;
  WmipGEHeadPtr = (int)WmipGEHead;
  WmipMRHead[0] = WmipMRHead;
  WmipMRHead[1] = WmipMRHead;
  WmipMRHeadPtr = (int)WmipMRHead;
  v0 = (_DWORD *)WmipAllocRegEntry(-1, 1342177280);
  if ( !v0 )
    return -1073741670;
  memset(v11, 0, 76);
  v11[0] = 76;
  v11[4] = 2;
  v11[5] = -943770160;
  v11[6] = v5;
  v11[12] = -471861315;
  v11[7] = v6;
  v11[8] = v7;
  v11[13] = v8;
  v11[14] = v9;
  v11[15] = v10;
  result = WmipAddDataSource(v0, (int)v11, 76, 0, 0);
  if ( result >= 0 )
  {
    v2 = WmipGEHeadPtr;
    for ( i = *(_DWORD **)WmipGEHeadPtr; i != (_DWORD *)v2; i = (_DWORD *)*i )
      i[2] |= 1u;
    result = WmipAddMofResource(v0[4], L"advapi32.dll", 1, L"MofResourceName", v4);
    if ( result >= 0 )
      result = 0;
  }
  return result;
}
