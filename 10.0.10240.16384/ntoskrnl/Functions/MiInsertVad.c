// MiInsertVad 
 
int __fastcall MiInsertVad(int a1, _DWORD *a2)
{
  __int64 v3; // kr00_8
  int v4; // r2
  unsigned int v5; // r3
  unsigned int v7; // r2
  unsigned int v8; // r3
  _DWORD *v9; // r4
  unsigned int v10; // r5
  int v11; // r2
  _DWORD *v12; // r3
  int result; // r0
  int v14; // r3

  v3 = *(_QWORD *)(a1 + 12);
  v4 = a2[161] + 1;
  v5 = a2[98];
  a2[160] = a1;
  a2[161] = v4;
  if ( HIDWORD(v3) <= v5 >> 12 )
  {
    v7 = a2[57] + ((HIDWORD(v3) - (_DWORD)v3 + 1) << 12);
    v8 = a2[56];
    a2[57] = v7;
    if ( v8 < v7 )
      a2[56] = v7;
  }
  v9 = (_DWORD *)a2[159];
  v10 = *(_DWORD *)(a1 + 12);
  v11 = 0;
  if ( v9 )
  {
    while ( 1 )
    {
      if ( MiVadCompareVpn(v10, (int)v9) < 0 )
      {
        v12 = (_DWORD *)*v9;
        if ( !*v9 )
        {
          v11 = 0;
          break;
        }
      }
      else
      {
        v12 = (_DWORD *)v9[1];
        if ( !v12 )
        {
          v11 = 1;
          break;
        }
      }
      v9 = v12;
    }
  }
  result = RtlAvlInsertNodeEx(a2 + 159, v9, v11, a1);
  v14 = *(_DWORD *)(a1 + 28) & 7;
  if ( v14 == 5 || v14 == 2 && (*(_BYTE *)(a1 + 43) & 1) != 0 )
    result = sub_545A44(result);
  return result;
}
