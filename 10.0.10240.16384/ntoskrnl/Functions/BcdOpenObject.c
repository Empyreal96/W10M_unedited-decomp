// BcdOpenObject 
 
int __fastcall BcdOpenObject(int a1, _DWORD *a2, _DWORD *a3)
{
  BOOL v6; // r8
  int v7; // r4
  int v8; // r5
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r6
  int v14[2]; // [sp+0h] [bp-40h] BYREF
  int v15; // [sp+8h] [bp-38h] BYREF
  int v16; // [sp+Ch] [bp-34h]
  _DWORD v17[12]; // [sp+10h] [bp-30h] BYREF

  v6 = BiIsOfflineHandle(a1);
  v7 = BiAcquireBcdSyncMutant(v6);
  if ( v7 >= 0 )
  {
    *a3 = 0;
    v14[0] = 0;
    v16 = 0;
    v7 = BiOpenKey(a1, L"Objects", 131097, v14);
    v8 = v14[0];
    if ( v7 >= 0 )
    {
      if ( BiIsObjectAliased(a2, v14) )
        return sub_813BD0();
      v10 = a2[1];
      v11 = a2[2];
      v12 = a2[3];
      v17[0] = *a2;
      v17[1] = v10;
      v17[2] = v11;
      v17[3] = v12;
      v7 = RtlStringFromGUIDEx((int)v17, (int)&v15, 1);
      v13 = v16;
      if ( v7 >= 0 )
        v7 = BiOpenKey(v8, v16, 983103, a3);
      if ( v13 )
        RtlFreeAnsiString(&v15);
    }
    if ( v8 )
      BiCloseKey();
    BiReleaseBcdSyncMutant(v6);
  }
  return v7;
}
