// BcdCreateObject 
 
int __fastcall BcdCreateObject(int a1, int a2, int a3, int a4)
{
  BOOL v8; // r6
  int v9; // r4

  v8 = BiIsOfflineHandle(a1);
  v9 = BiAcquireBcdSyncMutant(v8);
  if ( v9 >= 0 )
  {
    v9 = BiCreateObject(a1, a2, a3, 0, a4);
    BiReleaseBcdSyncMutant(v8);
  }
  return v9;
}
