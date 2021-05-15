// MiUpdateProcessSharedCommit 
 
int __fastcall MiUpdateProcessSharedCommit(int a1, int a2)
{
  int result; // r0
  int *v4; // r2
  int v5; // r5
  _DWORD *v6; // r4
  _DWORD *i; // r3
  int v8; // r3
  unsigned int *v9; // r2
  _DWORD *v10; // r3
  _DWORD *v11; // r2

  result = MiIncludeSharedCommit(a1);
  if ( result )
  {
    v5 = *v4;
    v6 = 0;
    for ( i = *(_DWORD **)(*v4 + 48); i; i = (_DWORD *)*i )
      v6 = i;
    if ( v6 )
    {
      while ( 1 )
      {
        v8 = v6[3];
        if ( (v8 & 1) != 0 )
          break;
        v9 = (unsigned int *)(v8 + 864);
        do
          result = __ldrex(v9);
        while ( __strex(result + a2, v9) );
        v10 = (_DWORD *)v6[1];
        v11 = v6;
        if ( v10 )
        {
          do
          {
            v6 = v10;
            v10 = (_DWORD *)*v10;
          }
          while ( v10 );
        }
        else
        {
          while ( 1 )
          {
            v6 = (_DWORD *)(v6[2] & 0xFFFFFFFC);
            if ( !v6 || (_DWORD *)*v6 == v11 )
              break;
            v11 = v6;
          }
        }
        if ( !v6 )
          goto LABEL_13;
      }
      result = sub_7E9894();
    }
    else
    {
LABEL_13:
      *(_DWORD *)(v5 + 12) += a2;
    }
  }
  return result;
}
