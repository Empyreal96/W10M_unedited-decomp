// sub_8AA5DC 
 
int __fastcall sub_8AA5DC(int a1, int a2)
{
  char v4; // r6
  int v5; // r4
  BOOL v6; // r7
  BOOL v7; // r3
  int v8; // r0
  char v9; // r3
  char v11[4]; // [sp+8h] [bp-28h] BYREF
  int v12; // [sp+Ch] [bp-24h] BYREF
  int v13[8]; // [sp+10h] [bp-20h] BYREF

  v4 = 0;
  v5 = 0;
  if ( sub_8AACAC(a1, 0, DEVPKEY_Device_IsPresent, 17, 1, v11) >= 0 )
  {
    v6 = v11[0] == -1;
    if ( v11[0] == -1 )
      v4 = 2;
  }
  else
  {
    v5 = 4;
    v6 = 0;
  }
  if ( sub_8AAB70(a1, 0, DEVPKEY_Device_EnumeratorName, 18, a2 + 36) < 0 )
  {
    v5 |= 8u;
    v7 = 1;
LABEL_11:
    v4 |= 4u;
    goto LABEL_12;
  }
  if ( *(_WORD *)(a2 + 36) == 8 )
    v7 = memcmp(*(_DWORD *)(a2 + 44), (unsigned int)L"SWD", 8) == 0;
  else
    v7 = 0;
  if ( v7 )
    goto LABEL_11;
LABEL_12:
  if ( !v5 && v6 && !v7 && *(_DWORD *)(a2 + 32) >= 2u )
  {
    v8 = sub_8AAB70(a1, 0, DEVPKEY_Device_CompatibleIds, 8210, a2 + 60);
    if ( v8 == -1073741772 )
      v8 = 0;
    if ( v8 < 0 )
      LOBYTE(v5) = 2;
    if ( sub_8AACAC(a1, 0, DEVPKEY_Device_ReportedDeviceIdsHash, 7, 4, v13) >= 0 )
    {
      v12 = 0;
      if ( sub_8AB570(&v12, a2 + 48) >= 0 && sub_8AB570(&v12, a2 + 60) >= 0 && v12 == v13[0] )
        v4 |= 1u;
    }
    else
    {
      LOBYTE(v5) = v5 | 1;
    }
  }
  v9 = *(_BYTE *)(a2 + 29);
  *(_BYTE *)(a2 + 28) = v4;
  *(_BYTE *)(a2 + 29) = v9 | v5;
  return 0;
}
