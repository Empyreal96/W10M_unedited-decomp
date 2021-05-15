// BcdCloseStore 
 
int __fastcall BcdCloseStore(int a1)
{
  BOOL v2; // r6
  int v3; // r4
  char v4; // r4

  v2 = BiIsOfflineHandle(a1);
  v3 = BiAcquireBcdSyncMutant(v2);
  if ( v3 >= 0 )
  {
    if ( BiIsSystemStore(a1) )
    {
      v4 = 4;
      if ( BiIsWinPEBoot() )
        v4 = 6;
    }
    else
    {
      v4 = 2;
    }
    v3 = BiCloseStore(a1, v4);
    BiReleaseBcdSyncMutant(v2);
  }
  return v3;
}
