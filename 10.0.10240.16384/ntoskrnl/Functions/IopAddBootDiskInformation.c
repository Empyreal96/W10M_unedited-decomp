// IopAddBootDiskInformation 
 
_DWORD *__fastcall IopAddBootDiskInformation(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r5
  unsigned int v3; // r7
  unsigned int v4; // r4
  unsigned int v6; // r6
  _DWORD *v7; // r1
  _DWORD *v8; // r4
  int v9; // r1
  int v10; // r2
  int v11; // r3
  _DWORD *v12; // r8
  int v13; // r2
  int v14; // r3

  v2 = result;
  v3 = *result;
  v4 = 0;
  if ( *result )
  {
    v6 = (unsigned int)(result + 1);
    do
    {
      result = (_DWORD *)memcmp(v6, (unsigned int)a2, 24);
      if ( !result )
        break;
      ++v4;
      v6 += 28;
    }
    while ( v4 < v3 );
  }
  v7 = &v2[7 * v4];
  v7[7] |= a2[6];
  if ( v4 == *v2 )
  {
    ++*v2;
    v8 = v7 + 1;
    result = (_DWORD *)*a2;
    v9 = a2[1];
    v10 = a2[2];
    v11 = a2[3];
    v12 = a2 + 4;
    *v8 = result;
    v8[1] = v9;
    v8[2] = v10;
    v8[3] = v11;
    v8 += 4;
    v13 = v12[1];
    v14 = v12[2];
    *v8 = *v12;
    v8[1] = v13;
    v8[2] = v14;
  }
  return result;
}
