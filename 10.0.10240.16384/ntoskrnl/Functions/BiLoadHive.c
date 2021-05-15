// BiLoadHive 
 
int __fastcall BiLoadHive(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v6; // r5
  int v7; // r4
  int v8; // r2
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v18; // [sp+4h] [bp-6Ch] BYREF
  _BYTE v19[8]; // [sp+8h] [bp-68h] BYREF
  _BYTE v20[8]; // [sp+10h] [bp-60h] BYREF
  _DWORD _18[28]; // [sp+18h] [bp-58h] BYREF

  _18[27] = a4;
  _18[26] = a3;
  _18[25] = a2;
  _18[24] = a1;
  v6 = 0;
  v18 = 0;
  if ( BiDoesHiveExist(a2) )
  {
    v7 = BiOpenKeyNonBcd(0, L"\\Registry\\Machine", 983103, &v18);
    if ( v7 < 0 )
    {
      v6 = v18;
    }
    else
    {
      RtlInitUnicodeString((unsigned int)v20, a1);
      _18[2] = 24;
      v6 = v18;
      _18[3] = v18;
      _18[5] = 576;
      _18[4] = v20;
      _18[6] = 0;
      _18[7] = 0;
      RtlInitUnicodeString((unsigned int)_18, (unsigned __int16 *)(a2 + 12));
      _18[8] = 24;
      _18[9] = 0;
      _18[11] = 576;
      _18[10] = _18;
      _18[12] = 0;
      _18[13] = 0;
      v7 = BiAcquirePrivilege(18, (int)v19, v8, 0);
      if ( v7 >= 0 )
      {
        v7 = ZwLoadKey2();
        if ( v7 < 0 )
        {
          v7 = ZwLoadKey2();
          if ( v7 < 0 )
            v7 = ZwLoadKey();
        }
        BiReleasePrivilege((int)v19, v9, v10, v11);
        if ( v7 >= 0 )
        {
          v7 = ZwOpenKey();
          if ( v7 < 0 )
          {
            BiAcquirePrivilege(17, (int)v19, v12, v13);
            ZwUnloadKey();
            BiReleasePrivilege((int)v19, v14, v15, v16);
          }
        }
      }
    }
  }
  else
  {
    v7 = -1073741809;
  }
  if ( v6 )
    ZwClose();
  if ( v7 == -1073741443 )
    __debugbreak();
  return v7;
}
