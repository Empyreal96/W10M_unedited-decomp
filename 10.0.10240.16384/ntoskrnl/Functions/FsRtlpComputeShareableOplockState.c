// FsRtlpComputeShareableOplockState 
 
_DWORD *__fastcall FsRtlpComputeShareableOplockState(_DWORD *result)
{
  int v1; // r4
  _DWORD *v2; // r1
  int v3; // r3
  _DWORD *v4; // r5
  int v5; // r6
  int v6; // r7
  _DWORD *v7; // r1
  int v8; // r2

  v1 = result[18];
  v2 = result + 5;
  if ( (_DWORD *)result[5] == result + 5 && (_DWORD *)result[7] == result + 7 && (_DWORD *)result[9] == result + 9 )
  {
    v3 = result[18] & 0x20 | 1;
    goto LABEL_5;
  }
  if ( (_DWORD *)*v2 != v2 )
    return (_DWORD *)sub_529EB8();
  if ( (_DWORD *)result[7] != result + 7 )
  {
    v3 = result[18] & 0x20 | 0x3000;
    goto LABEL_5;
  }
  if ( (_DWORD *)*v2 != v2 )
  {
    v4 = (_DWORD *)result[5];
    v5 = 0;
    v6 = 0;
    if ( v4 == v2 )
      goto LABEL_22;
    while ( *(_DWORD *)(v4[2] + 16) != 590400 )
    {
      v6 = 1;
      if ( v5 )
        goto LABEL_16;
LABEL_17:
      v4 = (_DWORD *)*v4;
      if ( v4 == v2 )
      {
LABEL_18:
        if ( v5 )
        {
          if ( v6 )
            v3 = result[18] & 0x20 | 0x1010;
          else
            v3 = result[18] & 0x20 | 0x1000;
LABEL_5:
          result[18] = v3;
          goto LABEL_6;
        }
LABEL_22:
        v3 = result[18] & 0x20 | 0x10;
        goto LABEL_5;
      }
    }
    v5 = 1;
LABEL_16:
    if ( v6 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v7 = (_DWORD *)result[9];
  v8 = 0;
  for ( result[18] = result[18] & 0x20 | 0x3000; v7 != result + 9; v7 = (_DWORD *)*v7 )
  {
    if ( v8 && (v7[6] & 0xF00000) != v8 )
    {
      v3 = result[18] & 0x20 | 0x3000;
      goto LABEL_5;
    }
    v8 = v7[6] & 0xF00000;
    result[18] |= v8;
  }
LABEL_6:
  result[18] |= v1 & 0x1010000;
  return result;
}
