// BcdCloseObject 
 
int __fastcall BcdCloseObject(char a1)
{
  BOOL v1; // r5
  int result; // r0

  v1 = BiIsOfflineHandle(a1);
  result = BiAcquireBcdSyncMutant(v1);
  if ( result >= 0 )
  {
    BiCloseKey();
    result = BiReleaseBcdSyncMutant(v1);
  }
  return result;
}
