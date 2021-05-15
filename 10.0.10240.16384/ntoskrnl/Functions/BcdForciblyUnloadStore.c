// BcdForciblyUnloadStore 
 
int __fastcall BcdForciblyUnloadStore(int a1)
{
  int v2; // r6
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r4
  int v7; // r0

  v2 = BiIsOfflineHandle(a1);
  v6 = BiAcquireBcdSyncMutant(v2, v3, v4, v5);
  if ( v6 >= 0 )
  {
    v6 = 0;
    if ( BiIsSystemStore(a1) )
      v6 = BiExportStoreAlterationsToFirmware(a1);
    v7 = BiUnloadHiveByHandle(a1, 1);
    if ( v6 >= 0 )
      v6 = v7;
    BiReleaseBcdSyncMutant(v2);
  }
  return v6;
}
