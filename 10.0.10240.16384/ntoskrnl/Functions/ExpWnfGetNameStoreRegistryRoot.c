// ExpWnfGetNameStoreRegistryRoot 
 
int __fastcall ExpWnfGetNameStoreRegistryRoot(int a1, _DWORD *a2)
{
  int *v3; // r4
  int v4; // r3
  int result; // r0
  int v6; // r2
  unsigned int *v7; // r1
  int v8; // r0
  int v9; // r3
  unsigned int v10; // [sp+10h] [bp-28h]

  v3 = &ExpWnfNameStoreDescriptors[6 * a1];
  v4 = *(_DWORD *)v3[3];
  __dmb(0xBu);
  *a2 = v4;
  if ( v4 )
    return 0;
  result = ZwCreateKey();
  if ( result >= 0 )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)v3[3];
    do
    {
      v8 = __ldrex(v7);
      if ( v8 )
        break;
      v6 = __strex(v10, v7);
    }
    while ( v6 );
    __dmb(0xBu);
    if ( v8 )
      return sub_7C49A0(v8, (int)v7, v6, v10);
    v9 = *(_DWORD *)v3[3];
    __dmb(0xBu);
    *a2 = v9;
    return 0;
  }
  return result;
}
