// CompareNamesCaseSensitive 
 
int __fastcall CompareNamesCaseSensitive(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned int v3; // r4
  unsigned int v4; // r6
  int result; // r0
  int v7; // r10
  int v8; // r8
  unsigned int v9; // r5
  unsigned int v10; // r0
  int v11; // r2
  int v12; // r8
  unsigned int v13; // r3
  unsigned int v14; // lr
  unsigned int v15; // r3
  unsigned int v16; // r1
  unsigned int i; // r2
  int v18; // r3
  unsigned int j; // r2
  int v20; // r3
  int v21; // [sp+0h] [bp-20h]

  v3 = *a1;
  v4 = *a2;
  if ( v3 == 1 && **((_BYTE **)a1 + 1) == 92 && v4 > 1 && **((_BYTE **)a2 + 1) == 92 )
    return 1;
  v7 = *((_DWORD *)a2 + 1);
  v8 = *((_DWORD *)a1 + 1);
  v9 = *a1;
  if ( v3 >= v4 )
    v9 = *a2;
  v21 = *((_DWORD *)a2 + 1);
  v10 = RtlCompareMemory(*((unsigned __int8 **)a1 + 1), v21, v9);
  if ( v10 < v9 )
  {
    v11 = *(char *)(v8 + v10);
    v12 = *(char *)(v7 + v10);
    v13 = (unsigned __int8)v11;
    if ( (unsigned __int8)v11 == 92 )
      v13 = 0;
    v14 = v13;
    v15 = (unsigned __int8)v12;
    if ( (unsigned __int8)v12 == 92 )
      v15 = 0;
    v16 = v15;
    if ( NlsMbCodePageTag )
    {
      if ( v11 == 92 )
      {
        for ( i = 0; i < v10; i += v18 )
        {
          if ( NlsLeadByteInfoTable[*(unsigned __int8 *)(*((_DWORD *)a1 + 1) + i)] )
            v18 = 2;
          else
            v18 = 1;
        }
        if ( i != v10 )
          v14 = 92;
      }
      if ( v12 == 92 )
      {
        for ( j = 0; j < v10; j += v20 )
        {
          if ( NlsLeadByteInfoTable[*(unsigned __int8 *)(*((_DWORD *)a2 + 1) + j)] )
            v20 = 2;
          else
            v20 = 1;
        }
        v7 = v21;
        if ( j != v10 )
          v16 = 92;
      }
      else
      {
        v7 = v21;
      }
    }
    if ( v14 < v16 )
      return 0;
    if ( v14 > v16 )
      goto LABEL_34;
  }
  if ( v3 < v4 )
    return *(_BYTE *)(v7 + v3) == 92;
  if ( v3 > v4 )
LABEL_34:
    result = 3;
  else
    result = 2;
  return result;
}
