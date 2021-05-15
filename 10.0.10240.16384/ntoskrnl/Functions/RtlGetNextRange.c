// RtlGetNextRange 
 
int __fastcall RtlGetNextRange(_DWORD *a1, _DWORD *a2, int a3)
{
  int v3; // r7
  int v6; // r3
  int result; // r0
  int v8; // r3
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r3

  v3 = *a1;
  if ( *(_DWORD *)(*a1 + 16) != a1[3] )
    return -1073741811;
  v6 = a1[2];
  if ( !v6 )
    return sub_80FDDC();
  if ( a3 )
    v8 = *(_DWORD *)(v6 + 28);
  else
    v8 = *(_DWORD *)(v6 + 32);
  v9 = a1[1];
  v10 = v8 - 28;
  if ( v9 )
  {
    if ( v8 != v9 )
    {
      a1[2] = v10;
      *a2 = v10;
      return 0;
    }
    if ( a3 )
      v11 = *(_DWORD *)(v9 + 12);
    else
      v11 = *(_DWORD *)(v9 + 16);
    v10 = v11 - 28;
    a1[1] = 0;
  }
  if ( v10 + 28 == v3 )
  {
    a1[2] = 0;
    result = -2147483622;
    *a2 = 0;
  }
  else if ( (*(_WORD *)(v10 + 26) & 1) != 0 )
  {
    a1[1] = v10 + 16;
    if ( a3 )
      v12 = *(_DWORD *)(v10 + 16);
    else
      v12 = *(_DWORD *)(v10 + 20);
    v13 = v12 - 28;
    a1[2] = v13;
    *a2 = v13;
    result = 0;
  }
  else
  {
    a1[2] = v10;
    *a2 = v10;
    result = 0;
  }
  return result;
}
