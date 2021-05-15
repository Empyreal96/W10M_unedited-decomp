// BcdFlushStore 
 
int __fastcall BcdFlushStore(char a1)
{
  int v1; // r6
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r4

  v1 = BiIsOfflineHandle(a1);
  v5 = BiAcquireBcdSyncMutant(v1, v2, v3, v4);
  if ( v5 >= 0 )
  {
    v5 = ZwFlushKey();
    BiReleaseBcdSyncMutant(v1);
  }
  return v5;
}
