// sub_7B5F04 
 
int __fastcall sub_7B5F04(int a1, _DWORD *a2)
{
  int v3; // r0
  int v4; // r4
  int v6; // [sp+8h] [bp-30h]
  int v7[11]; // [sp+Ch] [bp-2Ch] BYREF

  v7[1] = 24;
  v7[2] = 0;
  v7[4] = 576;
  v7[5] = 0;
  v7[6] = 0;
  v7[3] = a1;
  v3 = ZwOpenKey();
  v4 = v3;
  if ( v3 == -1073741772 )
    return sub_7BF0A0();
  if ( v3 >= 0 )
  {
    v4 = ObReferenceObjectByHandle(v6, 131078, (int)CmKeyObjectType, 0, (int)v7, 0);
    if ( v4 >= 0 )
    {
      v4 = ZwLockRegistryKey();
      if ( v4 < 0 )
        ObfDereferenceObject(v7[0]);
      else
        *a2 = v7[0];
    }
    ZwClose();
  }
  return v4;
}
