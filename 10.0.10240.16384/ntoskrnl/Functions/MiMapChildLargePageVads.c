// MiMapChildLargePageVads 
 
int *__fastcall MiMapChildLargePageVads(int *result, int a2)
{
  int v2; // r5
  int v3; // r6
  _DWORD *v4; // r3
  _DWORD *v5; // r4
  _DWORD *v6; // r3
  int v7; // r1
  _DWORD *v8; // r2
  int v9; // r1

  v2 = a2;
  v3 = (int)result;
  if ( a2 )
  {
    v4 = (_DWORD *)result[159];
    v5 = 0;
    while ( v4 )
    {
      v5 = v4;
      v4 = (_DWORD *)*v4;
    }
    while ( v5 )
    {
      v6 = (_DWORD *)v5[1];
      v7 = (int)v5;
      v8 = v5;
      if ( v6 )
      {
        do
        {
          v5 = v6;
          v6 = (_DWORD *)*v6;
        }
        while ( v6 );
      }
      else
      {
        while ( 1 )
        {
          v5 = (_DWORD *)(v5[2] & 0xFFFFFFFC);
          if ( !v5 || (_DWORD *)*v5 == v8 )
            break;
          v8 = v5;
        }
      }
      result = (int *)MiVadMapsLargeImage(v7);
      if ( result == (int *)1 || (*(_DWORD *)(v9 + 28) & 7) == 5 )
      {
        result = MiMapUserLargePages(v9, v9, v3);
        if ( !--v2 )
          break;
      }
    }
  }
  return result;
}
