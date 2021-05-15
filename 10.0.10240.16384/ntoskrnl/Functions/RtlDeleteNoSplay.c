// RtlDeleteNoSplay 
 
_DWORD *__fastcall RtlDeleteNoSplay(_DWORD *result, _DWORD *a2)
{
  _DWORD *v3; // r2
  _DWORD *v4; // r2
  _DWORD *v5; // r1
  _DWORD *v6; // r3
  _DWORD *v7; // r3

  if ( !result[1] )
    goto LABEL_22;
  if ( result[2] )
    return (_DWORD *)sub_521928();
  v4 = (_DWORD *)result[1];
  if ( !v4 )
  {
LABEL_22:
    if ( !result[2] )
    {
      v3 = (_DWORD *)*result;
      if ( (_DWORD *)*result == result )
      {
        *a2 = 0;
      }
      else
      {
        if ( (_DWORD *)v3[1] == result )
          v6 = v3 + 1;
        else
          v6 = v3 + 2;
        *v6 = 0;
      }
      return result;
    }
    v4 = (_DWORD *)result[2];
  }
  v5 = (_DWORD *)*result;
  if ( (_DWORD *)*result == result )
  {
    *v4 = v4;
    *a2 = v4;
  }
  else
  {
    if ( (_DWORD *)v5[1] == result )
      v7 = v5 + 1;
    else
      v7 = v5 + 2;
    *v7 = v4;
    *v4 = *result;
  }
  return result;
}
