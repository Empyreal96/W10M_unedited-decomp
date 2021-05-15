// BootApplicationPersistentDataInitialize 
 
int __fastcall BootApplicationPersistentDataInitialize(int result)
{
  _DWORD *v1; // r7
  _DWORD *v2; // r5
  int v3; // r3

  dword_6475C0 = (int)&dword_6475C0;
  *(_DWORD *)algn_6475C4 = &dword_6475C0;
  v1 = (_DWORD *)(*(_DWORD *)(result + 132) + 76);
  v2 = (_DWORD *)*v1;
  while ( v2 != v1 )
  {
    v3 = v2[4];
    v2 = (_DWORD *)*v2;
    if ( v3 )
    {
      result = ExAllocatePoolWithTag(512, 20, 1682989378);
      if ( result )
        result = sub_96E534();
      return result;
    }
  }
  return result;
}
