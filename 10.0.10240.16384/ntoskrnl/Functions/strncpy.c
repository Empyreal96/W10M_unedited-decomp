// strncpy 
 
_BYTE *__fastcall strncpy(_BYTE *a1, int a2, int a3)
{
  _BYTE *v3; // r4
  int v4; // r1
  int v5; // r3
  int v6; // r2
  _BYTE *v7; // r3

  v3 = a1;
  if ( a3 )
  {
    v4 = a2 - (_DWORD)a1;
    do
    {
      v5 = (char)a1[v4];
      *a1++ = v5;
      if ( !v5 )
        break;
      --a3;
    }
    while ( a3 );
    if ( a3 )
    {
      v6 = a3 - 1;
      if ( v6 )
      {
        v7 = &a1[v6];
        do
          *a1++ = 0;
        while ( a1 != v7 );
      }
    }
  }
  return v3;
}
