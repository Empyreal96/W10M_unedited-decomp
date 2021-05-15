// CmpMarkCurrentProfileDirty 
 
int CmpMarkCurrentProfileDirty()
{
  int result; // r0
  int v1; // r4
  int v2; // r5
  int v3; // r1
  int v4; // r4
  int v5; // [sp+8h] [bp-38h]
  int v6; // [sp+Ch] [bp-34h] BYREF
  int v7[12]; // [sp+10h] [bp-30h] BYREF

  v7[2] = 24;
  v7[3] = 0;
  v7[5] = 576;
  v7[6] = 0;
  v7[7] = 0;
  v6 = -1;
  v7[4] = (int)&CmpStrDatabaseString;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    v1 = ObReferenceObjectByHandle(v5, 131097, (int)CmKeyObjectType, 0, (int)v7, 0);
    result = ZwClose();
    if ( v1 >= 0 )
    {
      CmpLockRegistryExclusive();
      v2 = v7[0];
      v3 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v7[0] + 4) + 20) + 4))(
             *(_DWORD *)(*(_DWORD *)(v7[0] + 4) + 20),
             *(_DWORD *)(*(_DWORD *)(v7[0] + 4) + 24),
             &v6);
      if ( v3 )
      {
        v4 = CmpFindValueByName(
               *(_DWORD *)(*(_DWORD *)(v2 + 4) + 20),
               v3,
               (int)&CmpCurrentConfigString,
               *(_DWORD *)(v2 + 4));
        (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v2 + 4) + 20) + 8))(
          *(_DWORD *)(*(_DWORD *)(v2 + 4) + 20),
          &v6);
        if ( v4 != -1 )
          HvpMarkCellDirty(*(_DWORD *)(*(_DWORD *)(v2 + 4) + 20), v4, 1, 0);
      }
      CmpUnlockRegistry();
      result = ObfDereferenceObject(v2);
    }
  }
  return result;
}
