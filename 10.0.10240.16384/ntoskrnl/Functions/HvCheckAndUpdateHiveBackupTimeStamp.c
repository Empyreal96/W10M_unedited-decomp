// HvCheckAndUpdateHiveBackupTimeStamp 
 
int __fastcall HvCheckAndUpdateHiveBackupTimeStamp(int a1)
{
  _DWORD *v2; // r0
  int v3; // r5
  unsigned int v4; // r6
  int v5; // r0
  __int64 v6; // kr00_8
  int v7; // r4
  int v9; // r2
  char v10[4]; // [sp+8h] [bp-18h] BYREF
  int v11[5]; // [sp+Ch] [bp-14h] BYREF

  v2 = (_DWORD *)HvpGetCellMap(a1, 0);
  v3 = (int)v2;
  if ( !v2 )
    sub_7D2BB0(0);
  v4 = HvpMapEntryGetBinAddress((int)v2, v2, v10, v11);
  v6 = *(_QWORD *)(*(_DWORD *)(a1 + 32) + 12);
  v5 = HIDWORD(v6);
  if ( *(_QWORD *)(v4 + 20) == v6 )
    goto LABEL_3;
  v5 = HvpMarkDirty(a1, 0, 32, 0);
  if ( v5 )
  {
    v9 = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(v4 + 20) = *(_DWORD *)(v9 + 12);
    *(_DWORD *)(v4 + 24) = *(_DWORD *)(v9 + 16);
LABEL_3:
    v7 = 0;
    goto LABEL_4;
  }
  v7 = -1073741443;
LABEL_4:
  if ( v10[0] )
    HvpMapEntryReleaseBinAddress(v5, v3);
  return v7;
}
