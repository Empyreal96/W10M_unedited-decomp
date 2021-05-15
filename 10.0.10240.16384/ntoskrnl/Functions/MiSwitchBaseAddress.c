// MiSwitchBaseAddress 
 
int __fastcall MiSwitchBaseAddress(int *a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v6; // r8
  int v7; // r7
  _DWORD *v8; // r5
  _DWORD *i; // r4
  int result; // r0
  _DWORD *v12; // r4

  v4 = *a1;
  v6 = *(_DWORD *)a1[14];
  v7 = *(_DWORD *)(v6 + 20);
  *(_DWORD *)(v6 + 20) = a2 - *(_DWORD *)(*a1 + 24);
  v8 = *(_DWORD **)(v4 + 36);
  *(_DWORD *)(v4 + 24) = a2;
  *v8 += *(_DWORD *)(v6 + 20);
  for ( i = *(_DWORD **)(v6 + 8); i; i = (_DWORD *)*i )
    MiApplyBytestreamFixup((int)i, (int)(i + 4), v7);
  result = MiValidateImagePages(a1, a3, 2, a4);
  v12 = *(_DWORD **)(v6 + 8);
  *(_DWORD *)(v6 + 20) += v7;
  while ( v12 )
  {
    result = MiApplyBytestreamFixup((int)v12, (int)(v12 + 4), -v7);
    v12 = (_DWORD *)*v12;
  }
  if ( (*(_WORD *)(v4 + 8) & 0x2000) != 0 )
    result = sub_7E6DA4(result);
  return result;
}
