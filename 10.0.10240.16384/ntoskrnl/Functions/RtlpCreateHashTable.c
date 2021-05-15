// RtlpCreateHashTable 
 
int __fastcall RtlpCreateHashTable(int *a1, unsigned int a2, int a3, int a4)
{
  unsigned int v5; // r7
  int v9; // r4
  int v10; // r5
  _BYTE *v11; // r0
  signed int v12; // r7
  int v13; // r0
  _BYTE *v15; // r0
  _DWORD *v16; // r5
  _BYTE *v17; // r0
  signed int v18; // r6

  v5 = a2 - 1;
  if ( ((a2 - 1) & a2) != 0 || a2 - 128 > 0xFF80 )
    return 0;
  v9 = *a1;
  v10 = 0;
  if ( !*a1 )
  {
    v9 = ExAllocatePoolWithTag(512, 36);
    if ( v9 )
    {
      v10 = 1;
      goto LABEL_4;
    }
    return 0;
  }
LABEL_4:
  v11 = memset((_BYTE *)v9, 0, 36);
  *(_DWORD *)v9 = v10 | a4;
  *(_DWORD *)(v9 + 4) = a3;
  *(_DWORD *)(v9 + 12) = 0;
  *(_DWORD *)(v9 + 16) = v5;
  v12 = v5 >> 7;
  *(_DWORD *)(v9 + 8) = a2;
  if ( a2 > 0x80 )
  {
    v15 = (_BYTE *)ExAllocatePoolWithTag(512, 2048);
    v16 = v15;
    if ( !v15 )
      return sub_50F1E4();
    v17 = memset(v15, 0, 2048);
    v18 = 0;
    for ( *(_DWORD *)(v9 + 32) = v16; v18 <= v12; ++v16 )
    {
      v17 = (_BYTE *)RtlpAllocateSecondLevelDir(v17);
      if ( !v17 )
        return sub_50F1E4();
      ++v18;
      *v16 = v17;
    }
  }
  else
  {
    v13 = RtlpAllocateSecondLevelDir(v11);
    if ( !v13 )
      return sub_50F1E4();
    *(_DWORD *)(v9 + 32) = v13;
  }
  *a1 = v9;
  return 1;
}
