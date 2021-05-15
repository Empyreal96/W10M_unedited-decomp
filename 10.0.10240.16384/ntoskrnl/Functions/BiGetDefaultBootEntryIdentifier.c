// BiGetDefaultBootEntryIdentifier 
 
int __fastcall BiGetDefaultBootEntryIdentifier(int a1, _DWORD *a2)
{
  int v3; // r2
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v9; // [sp+8h] [bp-28h] BYREF
  int v10; // [sp+Ch] [bp-24h] BYREF
  _DWORD v11[8]; // [sp+10h] [bp-20h] BYREF

  v9 = 0;
  v4 = BcdOpenObject(a1, &GUID_WINDOWS_BOOTMGR, &v9);
  if ( v4 >= 0 )
  {
    v10 = 16;
    v4 = BcdGetElementDataWithFlags(v9, 0x23000003u, v3, (int)v11, &v10);
    if ( v4 >= 0 )
    {
      v5 = v11[1];
      v6 = v11[2];
      v7 = v11[3];
      *a2 = v11[0];
      a2[1] = v5;
      a2[2] = v6;
      a2[3] = v7;
    }
  }
  if ( v9 )
    BcdCloseObject(v9);
  return v4;
}
