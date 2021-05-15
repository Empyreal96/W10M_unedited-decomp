// BiAddStoreFromFile 
 
int __fastcall BiAddStoreFromFile(int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r4
  int v9; // r0
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r0
  int v14; // [sp+8h] [bp-38h] BYREF
  int v15; // [sp+Ch] [bp-34h] BYREF
  unsigned __int16 v16[24]; // [sp+10h] [bp-30h] BYREF

  v3 = 0;
  v14 = 0;
  v15 = 0;
  v6 = 0;
  while ( 1 )
  {
    swprintf_s((int)v16, 12, (int)L"BCD%08d", v6);
    v7 = BiLoadHive(v16, a1, &v14);
    v8 = v7;
    if ( v7 >= 0 )
      break;
    if ( v7 != -1073741790 )
      goto LABEL_17;
    if ( BiDoesHiveKeyExist(v16) )
      v3 = 0;
    else
      ++v3;
    if ( v3 >= 0xA )
      goto LABEL_10;
    if ( (unsigned int)++v6 > 0x5F5E0FF )
    {
      v8 = -1073741823;
LABEL_10:
      v9 = v14;
      goto LABEL_19;
    }
  }
  v10 = BiOpenKey(v14, L"Description", 131103, &v15);
  v8 = v10;
  v11 = v15;
  if ( v10 < 0 )
  {
    if ( v10 == -1073741772 )
      v8 = -1073741476;
    goto LABEL_14;
  }
  v8 = BiSetRegistryValue(v15, L"KeyName", 0, 1);
  if ( v8 < 0 )
  {
LABEL_14:
    v9 = v14;
    goto LABEL_15;
  }
  v9 = v14;
  *a3 = v14;
LABEL_15:
  if ( v11 )
  {
    BiCloseKey();
LABEL_17:
    v9 = v14;
  }
  if ( v8 >= 0 )
    return v8;
LABEL_19:
  if ( v9 )
  {
    BiCloseKey();
    v12 = wcslen(v16);
    BiUnloadHiveByName(v16, 2 * (v12 + 1), 0);
  }
  return v8;
}
