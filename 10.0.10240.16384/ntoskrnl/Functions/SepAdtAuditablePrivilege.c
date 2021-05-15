// SepAdtAuditablePrivilege 
 
int __fastcall SepAdtAuditablePrivilege(_DWORD *a1, unsigned int a2)
{
  int v2; // r4
  unsigned int v3; // r5
  int **v4; // r7
  unsigned int i; // r6
  _DWORD *v6; // lr
  _DWORD *v7; // t1

  v2 = 0;
  v3 = 0;
  if ( a2 )
  {
    while ( 2 )
    {
      v4 = off_41CE14;
      for ( i = 0; i < 0xE; ++i )
      {
        v7 = *v4++;
        v6 = v7;
        if ( *a1 == *v7 && a1[1] == v6[1] )
          return 1;
      }
      ++v3;
      a1 += 3;
      if ( v3 < a2 )
        continue;
      break;
    }
  }
  return v2;
}
