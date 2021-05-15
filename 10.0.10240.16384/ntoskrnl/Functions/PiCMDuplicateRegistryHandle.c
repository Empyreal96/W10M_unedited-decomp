// PiCMDuplicateRegistryHandle 
 
int __fastcall PiCMDuplicateRegistryHandle(int a1, int a2, int a3, char a4, int a5)
{
  int v6; // r7
  int v7; // r5
  int v8; // r4
  int v10[6]; // [sp+10h] [bp-18h] BYREF

  v6 = a4;
  v7 = ObReferenceObjectByHandle(a1, 0, CmKeyObjectType, 0, v10);
  v8 = v10[0];
  if ( v7 >= 0 )
    v7 = ObOpenObjectByPointer(v10[0], 1088, 0, a3, CmKeyObjectType, v6, a5);
  if ( v8 )
    ObfDereferenceObject(v8);
  return v7;
}
