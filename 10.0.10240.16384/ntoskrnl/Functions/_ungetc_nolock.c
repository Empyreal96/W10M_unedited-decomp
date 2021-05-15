// _ungetc_nolock 
 
int __fastcall ungetc_nolock(int a1, int *a2)
{
  int v2; // r4
  int v3; // r2
  int v4; // r3
  int v5; // r3
  _BYTE *v6; // r3

  if ( a2 )
  {
    v2 = -1;
    if ( a1 != -1 )
    {
      v3 = a2[3];
      if ( (v3 & 1) != 0 || (v3 & 0x80) != 0 && (v3 & 2) == 0 )
      {
        v4 = a2[2];
        if ( v4 )
        {
          if ( *a2 == v4 )
          {
            if ( a2[1] )
              return v2;
            ++*a2;
          }
          v5 = *a2;
          if ( (v3 & 0x40) != 0 )
          {
            *a2 = v5 - 1;
            if ( *(char *)(v5 - 1) != (char)a1 )
            {
              *a2 = v5;
              return v2;
            }
          }
          else
          {
            v6 = (_BYTE *)(v5 - 1);
            *a2 = (int)v6;
            *v6 = a1;
          }
          v2 = (unsigned __int8)a1;
          ++a2[1];
          a2[3] = a2[3] & 0xFFFFFFEF | 1;
          return v2;
        }
        PopPoCoalescinCallback();
      }
    }
  }
  else
  {
    PopPoCoalescinCallback();
    v2 = -1;
  }
  return v2;
}
