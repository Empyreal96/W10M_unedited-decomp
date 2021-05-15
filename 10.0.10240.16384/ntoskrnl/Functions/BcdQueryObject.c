// BcdQueryObject 
 
int __fastcall BcdQueryObject(int a1, int a2, _DWORD *a3, int a4)
{
  int v7; // r4
  int v8; // r8
  int v9; // r1
  int v10; // r2
  int v11; // r3

  if ( a3 )
  {
    if ( a2 != 1 )
      return -1073741811;
  }
  else if ( !a4 )
  {
    return -1073741811;
  }
  v8 = BiIsOfflineHandle(a1);
  v7 = BiAcquireBcdSyncMutant(v8, v9, v10, v11);
  if ( v7 >= 0 )
  {
    v7 = 0;
    if ( !a3 || (v7 = BiGetObjectDescription(a1, a3), v7 >= 0) )
    {
      if ( a4 )
        v7 = BiGetObjectIdentifier(a1, a4);
    }
    BiReleaseBcdSyncMutant(v8);
  }
  return v7;
}
