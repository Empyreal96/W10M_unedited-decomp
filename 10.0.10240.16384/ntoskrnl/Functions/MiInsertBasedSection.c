// MiInsertBasedSection 
 
int __fastcall MiInsertBasedSection(_DWORD *a1)
{
  unsigned int v2; // r7
  _DWORD *v3; // r4
  int v4; // r2
  _DWORD *v5; // r3

  v2 = a1[3];
  v3 = (_DWORD *)dword_632E0C;
  v4 = 0;
  if ( dword_632E0C )
  {
    while ( 1 )
    {
      if ( MiVadCompareVpn(v2, (int)v3) < 0 )
      {
        v5 = (_DWORD *)*v3;
        if ( !*v3 )
        {
          v4 = 0;
          return RtlAvlInsertNodeEx((int)&dword_632E0C, (int)v3, v4, a1);
        }
      }
      else
      {
        v5 = (_DWORD *)v3[1];
        if ( !v5 )
        {
          v4 = 1;
          return RtlAvlInsertNodeEx((int)&dword_632E0C, (int)v3, v4, a1);
        }
      }
      v3 = v5;
    }
  }
  return RtlAvlInsertNodeEx((int)&dword_632E0C, (int)v3, v4, a1);
}
