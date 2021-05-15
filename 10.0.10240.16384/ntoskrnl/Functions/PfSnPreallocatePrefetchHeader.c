// PfSnPreallocatePrefetchHeader 
 
int __fastcall PfSnPreallocatePrefetchHeader(_DWORD *a1)
{
  int v2; // r3
  int v3; // r9
  int v4; // r0
  _BYTE *v5; // r8
  int v6; // r3
  unsigned int v7; // r7
  int v8; // r6
  int v9; // r4
  int v10; // r0
  _BYTE *v11; // r1
  int v12; // r4
  _BYTE *v13; // r0
  int v14; // r0
  int v15; // r0
  int result; // r0

  v2 = *(_DWORD *)(*a1 + 88);
  v3 = 5 * v2;
  v4 = ExAllocatePoolWithTag(1, 40 * v2, 1750098755);
  v5 = (_BYTE *)v4;
  if ( !v4 )
    goto LABEL_9;
  v6 = *a1;
  a1[26] = v4;
  v7 = 0;
  if ( *(_DWORD *)(v6 + 88) )
  {
    v8 = 0;
    do
    {
      v9 = v8 + a1[26];
      memset((_BYTE *)v9, 0, 20);
      ++v7;
      v8 += 32;
      *(_DWORD *)(v9 + 16) |= 2u;
    }
    while ( v7 < *(_DWORD *)(*a1 + 88) );
  }
  v10 = *a1;
  v11 = &v5[32 * *(_DWORD *)(*a1 + 88)];
  a1[27] = v11;
  a1[28] = &v11[4 * *(_DWORD *)(v10 + 88)];
  memset(v5, 0, 8 * v3);
  v12 = *(_DWORD *)(*a1 + 120) + *(_DWORD *)(*a1 + 88);
  v13 = (_BYTE *)ExAllocatePoolWithTag(1, 16 * v12, 1750098755);
  a1[34] = v13;
  if ( !v13 )
    goto LABEL_9;
  memset(v13, 0, 16 * v12);
  a1[36] = v12;
  v14 = ExAllocatePoolWithTag(1, 6160, 1297113923);
  a1[29] = v14;
  if ( v14 && (v15 = ExAllocatePoolWithTag(512, 896, 1464886083), (a1[30] = v15) != 0) )
    result = 0;
  else
LABEL_9:
    result = -1073741670;
  return result;
}
