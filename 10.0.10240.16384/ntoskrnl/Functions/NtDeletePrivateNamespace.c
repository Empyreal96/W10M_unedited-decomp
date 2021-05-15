// NtDeletePrivateNamespace 
 
int __fastcall NtDeletePrivateNamespace(int a1)
{
  char v1; // r3
  int v2; // r4
  int v3; // r5
  int v5; // [sp+8h] [bp-18h] BYREF
  char v6[16]; // [sp+10h] [bp-10h] BYREF

  v1 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v2 = ObReferenceObjectByHandle(a1, 0x10000, ObpDirectoryObjectType, v1, (int)&v5, (int)v6);
  if ( v2 >= 0 )
  {
    v3 = v5;
    if ( *(_DWORD *)(v5 + 164) )
    {
      v2 = ObpVerifyCreatorAccessCheck(v5 + 196);
      if ( v2 >= 0 )
        v2 = ObpRemoveNamespaceFromTable(v3);
    }
    else
    {
      v2 = -1073741816;
    }
    ObfDereferenceObject(v3);
  }
  return v2;
}
