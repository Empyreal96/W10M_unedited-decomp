// IsRegistryKeyLocked 
 
int __fastcall IsRegistryKeyLocked(int a1, _BYTE *a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  *a2 = 0;
  v5 = ObReferenceObjectByHandle(a1, 131097, (int)CmKeyObjectType, 0, (int)v8, 0);
  if ( v5 >= 0 )
  {
    v6 = v8[0];
    *a2 = *(_BYTE *)(*(_DWORD *)(v8[0] + 4) + 4) & 0x80;
    ObfDereferenceObject(v6);
  }
  return v5;
}
