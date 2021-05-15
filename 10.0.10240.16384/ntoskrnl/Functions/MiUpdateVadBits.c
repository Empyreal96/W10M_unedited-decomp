// MiUpdateVadBits 
 
_DWORD *__fastcall MiUpdateVadBits(unsigned int a1, unsigned int a2)
{
  int v4; // r3
  int v5; // r0
  _DWORD *result; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r1
  _DWORD *v9; // r2
  _DWORD *i; // r3
  int v11; // r3
  _DWORD *v12; // r3
  _DWORD *v13; // r2
  _DWORD *v14; // r3
  _DWORD *v15; // r2

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(v4 + 116);
  if ( a2 < a1 )
    return (_DWORD *)sub_7F5534(v5);
  result = MiCheckForConflictingVad(v5, a1, a2 - 1, v4);
  v7 = result;
  if ( result )
  {
    v8 = (_DWORD *)*result;
    v9 = result;
    if ( *result )
    {
      for ( i = (_DWORD *)v8[1]; i; i = (_DWORD *)i[1] )
        v8 = i;
    }
    else
    {
      v11 = result[2];
      while ( 1 )
      {
        v8 = (_DWORD *)(v11 & 0xFFFFFFFC);
        if ( (v11 & 0xFFFFFFFC) == 0 || (_DWORD *)v8[1] == v9 )
          break;
        v11 = v8[2];
        v9 = v8;
      }
    }
    while ( v8 && ((v8[4] << 12) | 0xFFFu) >= a1 )
    {
      v12 = (_DWORD *)*v8;
      v7 = v8;
      v13 = v8;
      if ( *v8 )
      {
        do
        {
          v8 = v12;
          v12 = (_DWORD *)v12[1];
        }
        while ( v12 );
      }
      else
      {
        while ( 1 )
        {
          v8 = (_DWORD *)(v8[2] & 0xFFFFFFFC);
          if ( !v8 || (_DWORD *)v8[1] == v13 )
            break;
          v13 = v8;
        }
      }
    }
    do
    {
      result = (_DWORD *)MiSetVadBits(v7);
      v14 = (_DWORD *)v7[1];
      v15 = v7;
      if ( v14 )
      {
        do
        {
          v7 = v14;
          v14 = (_DWORD *)*v14;
        }
        while ( v14 );
      }
      else
      {
        while ( 1 )
        {
          v7 = (_DWORD *)(v7[2] & 0xFFFFFFFC);
          if ( !v7 || (_DWORD *)*v7 == v15 )
            break;
          v15 = v7;
        }
      }
    }
    while ( v7 && v7[3] << 12 < a2 );
  }
  return result;
}
