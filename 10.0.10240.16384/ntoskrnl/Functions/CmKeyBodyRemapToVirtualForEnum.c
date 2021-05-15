// CmKeyBodyRemapToVirtualForEnum 
 
int __fastcall CmKeyBodyRemapToVirtualForEnum(int a1, _DWORD *a2)
{
  int v4; // r1
  unsigned int *v5; // r2
  int v6; // r4
  unsigned int v7; // r3
  unsigned int v8; // r3
  int v10; // r1
  int v11; // r4
  int v12; // r0
  int v13; // r4
  int v14; // [sp+10h] [bp-78h] BYREF
  _DWORD v15[2]; // [sp+18h] [bp-70h] BYREF
  int v16; // [sp+20h] [bp-68h] BYREF
  int v17[25]; // [sp+24h] [bp-64h] BYREF

  memset(v17, 0, 76);
  v6 = (unsigned __int8)CmpVEEnabled;
  *a2 = 0;
  v16 = 8;
  if ( !v6 )
    return 0;
  if ( (*(_WORD *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + 106) & 0x200) != 0 || CmpIsMasterHive() )
  {
LABEL_4:
    if ( v6 )
    {
      v8 = *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + 106);
      if ( (v8 & 0x100) != 0 && !CmpIsSystemEntity(&v17[2], v4, v5, v8) )
      {
        v14 = 0;
        CmpLockRegistry(0, v10);
        CmpLockKcbShared(*(_DWORD *)(*(_DWORD *)a1 + 4));
        v11 = CmVirtualKCBToRealPath(*(_DWORD *)(*(_DWORD *)a1 + 4), v15);
        v12 = CmpUnlockKcb(*(_DWORD *)(*(_DWORD *)a1 + 4));
        CmpUnlockRegistry(v12);
        if ( v11 < 0 )
          JUMPOUT(0x7FE5A6);
        v17[12] = *(_DWORD *)(*(_DWORD *)a1 + 28);
        v13 = ObReferenceObjectByName((int)v15, 576, 0, 0, (int)CmKeyObjectType, 0, (int)&v16, &v14);
        RtlFreeAnsiString(v15);
        if ( v13 >= 0 )
        {
          *a2 = *(_DWORD *)a1;
          *(_DWORD *)a1 = v14;
        }
      }
    }
    return 0;
  }
  if ( CmpIsSystemEntity(&v17[2], v4, v5, v7) )
  {
    v6 = (unsigned __int8)CmpVEEnabled;
    goto LABEL_4;
  }
  return sub_7FE55C();
}
