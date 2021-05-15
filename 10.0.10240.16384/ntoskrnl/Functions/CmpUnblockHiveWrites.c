// CmpUnblockHiveWrites 
 
_DWORD *__fastcall CmpUnblockHiveWrites(int *a1, int a2, int *a3)
{
  int *v3; // r4
  int *i; // r0

  v3 = a1;
  if ( a1 )
  {
    ExReleaseResourceLite(a1[468]);
  }
  else
  {
    for ( i = (int *)CmpGetNextHive(0); ; i = (int *)CmpGetNextHive((int)v3) )
    {
      v3 = i;
      if ( !a2 || (i[807] & a2) == a2 || i == CmpMasterHive )
      {
        ExReleaseResourceLite(i[468]);
        CmpDereferenceHive(v3);
      }
      if ( v3 == a3 )
        break;
    }
  }
  return CmpDereferenceHive(v3);
}
