// FsRtlInsertExtraCreateParameter 
 
int __fastcall FsRtlInsertExtraCreateParameter(int a1, int a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r4
  _DWORD *v5; // r1
  _DWORD *v6; // r2
  int result; // r0

  v2 = *(_DWORD **)(a1 + 8);
  v3 = (_DWORD *)(a1 + 8);
  if ( v2 == (_DWORD *)(a1 + 8) )
  {
LABEL_2:
    v5 = (_DWORD *)v3[1];
    v6 = (_DWORD *)(a2 - 44);
    *v6 = v3;
    v6[1] = v5;
    if ( (_DWORD *)*v5 != v3 )
      sub_7F4780();
    *v5 = v6;
    v3[1] = v6;
    result = 0;
  }
  else
  {
    while ( memcmp((unsigned int)(v2 + 2), a2 - 36, 16) )
    {
      v2 = (_DWORD *)*v2;
      if ( v2 == v3 )
        goto LABEL_2;
    }
    result = -1073741811;
    v2[7] |= 4u;
  }
  return result;
}
