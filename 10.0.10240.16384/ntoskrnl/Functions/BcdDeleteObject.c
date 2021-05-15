// BcdDeleteObject 
 
int __fastcall BcdDeleteObject(int a1)
{
  BOOL v2; // r6
  int v3; // r4

  v2 = BiIsOfflineHandle(a1);
  v3 = BiAcquireBcdSyncMutant(v2);
  if ( v3 >= 0 )
  {
    v3 = BiDeleteKey(a1);
    BiReleaseBcdSyncMutant(v2);
  }
  return v3;
}
