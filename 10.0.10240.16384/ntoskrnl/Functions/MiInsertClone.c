// MiInsertClone 
 
int __fastcall MiInsertClone(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  int v3; // r2
  _DWORD *v6; // r3

  v2 = *(_DWORD **)(a1 + 272);
  v3 = 0;
  if ( v2 )
  {
    while ( 1 )
    {
      if ( MiCloneCompare((int)a2, (int)v2) < 0 )
      {
        v6 = (_DWORD *)*v2;
        if ( !*v2 )
        {
          v3 = 0;
          return RtlAvlInsertNodeEx(a1 + 272, (int)v2, v3, a2);
        }
      }
      else
      {
        v6 = (_DWORD *)v2[1];
        if ( !v6 )
        {
          v3 = 1;
          return RtlAvlInsertNodeEx(a1 + 272, (int)v2, v3, a2);
        }
      }
      v2 = v6;
    }
  }
  return RtlAvlInsertNodeEx(a1 + 272, (int)v2, v3, a2);
}
