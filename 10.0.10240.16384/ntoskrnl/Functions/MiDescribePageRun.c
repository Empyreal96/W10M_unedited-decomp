// MiDescribePageRun 
 
int __fastcall MiDescribePageRun(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r7
  int v6; // r8
  int v7; // r0
  _DWORD *v8; // r5
  _DWORD *v9; // r2

  v3 = a2;
  v4 = a2 + a3;
  if ( a2 == a2 + a3 )
    return 1;
  while ( 1 )
  {
    v6 = MiRestrictRangeToNode(v3, a3);
    v7 = ExAllocatePoolWithTag(512, 20);
    v8 = (_DWORD *)v7;
    if ( !v7 )
      break;
    *(_DWORD *)(v7 + 12) = v6;
    *(_BYTE *)(v7 + 17) = 0;
    *(_DWORD *)(v7 + 8) = v3;
    *(_BYTE *)(v7 + 16) = MiPageToNode();
    v9 = *(_DWORD **)(a1 + 4);
    *v8 = a1;
    v8[1] = v9;
    if ( *v9 != a1 )
      sub_50F120();
    *v9 = v8;
    *(_DWORD *)(a1 + 4) = v8;
    v3 += v6;
    a3 = v4 - v3;
    ++*(_DWORD *)(a1 + 8);
    if ( v3 == v4 )
      return 1;
  }
  return 0;
}
