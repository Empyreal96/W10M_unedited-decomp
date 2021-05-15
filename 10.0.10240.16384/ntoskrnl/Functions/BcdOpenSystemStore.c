// BcdOpenSystemStore 
 
int __fastcall BcdOpenSystemStore(int a1)
{
  int v2; // r4

  v2 = BiAcquireBcdSyncMutant(0);
  if ( v2 >= 0 )
  {
    v2 = BiOpenSystemStore(a1);
    BiReleaseBcdSyncMutant(0);
  }
  return v2;
}
