// CmpBlockHiveWrites 
 
int __fastcall CmpBlockHiveWrites(int *a1, int a2, int **a3)
{
  int *v6; // r4
  int v7; // r2
  int v8; // r3

  v6 = (int *)CmpGetNextHive(0);
  if ( v6 )
  {
    while ( 1 )
    {
      if ( a1 == v6 || !a1 )
      {
        if ( !a2 || (v6[807] & a2) == a2 || v6 == CmpMasterHive )
        {
          CmpReferenceHive((int)v6);
          if ( a3 )
            *a3 = v6;
          ExAcquireResourceExclusiveLite(v6[468], 1, v7, v8);
        }
        if ( a1 == v6 )
          break;
      }
      v6 = (int *)CmpGetNextHive((int)v6);
      if ( !v6 )
        goto LABEL_12;
    }
    CmpDereferenceHive(v6);
  }
  else
  {
LABEL_12:
    if ( a1 )
      return -1073741772;
  }
  return 0;
}
