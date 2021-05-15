// CmpLockRegistryFreezeAware 
 
int __fastcall CmpLockRegistryFreezeAware(int a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r0
  int result; // r0
  char v6[40]; // [sp+10h] [bp-28h] BYREF

  v2 = KeInitializeEvent((int)v6, 1, 0);
  if ( a1 )
    v4 = CmpLockRegistryExclusive(v2);
  else
    v4 = CmpLockRegistry(v2, v3);
  if ( CmpFreezeThawState == 1 )
    result = sub_7D3D0C(v4);
  else
    result = 0;
  return result;
}
