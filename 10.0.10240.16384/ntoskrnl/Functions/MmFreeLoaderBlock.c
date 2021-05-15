// MmFreeLoaderBlock 
 
int __fastcall MmFreeLoaderBlock(int a1)
{
  _DWORD *v1; // r3
  int v2; // r2
  _DWORD *v3; // r7
  int v4; // r4
  int v6; // r1
  int v7; // r2
  int result; // r0
  unsigned int v9; // r6
  _DWORD *v10; // r2
  _DWORD *v11; // r5
  int v12; // r3
  int v13; // r1
  unsigned int v14; // r2
  int v15; // r7
  int v16; // r0
  int v17; // r4
  int v18; // r3
  unsigned int v19; // r0
  int v20; // r4
  int v21; // [sp+4h] [bp-D0h]

  v1 = *(_DWORD **)(a1 + 24);
  v2 = 0;
  v3 = (_DWORD *)(a1 + 24);
  v4 = 0;
  v21 = 0;
  if ( v1 != (_DWORD *)(a1 + 24) )
  {
    do
    {
      v6 = v1[4];
      if ( v6 )
      {
        v7 = v1[2];
        if ( v7 == 19 )
          v4 += v6;
        if ( v7 == 7 || v7 == 21 || v7 == 14 )
          ++v21;
      }
      v1 = (_DWORD *)*v1;
    }
    while ( v1 != v3 );
    if ( v4 && ExAllocatePoolWithTag(512, 4 * (v4 + 1), 1817013581) )
      return sub_9650D0();
    v2 = v21;
  }
  result = ExAllocatePoolWithTag(512, 8 * v2, 1817013581);
  v9 = result;
  if ( result )
  {
    v10 = *(_DWORD **)(a1 + 24);
    v11 = (_DWORD *)result;
    if ( v10 == v3 )
      return ExFreePoolWithTag(v9);
    do
    {
      v12 = v10[2];
      if ( v12 == 7 || v12 == 21 || v12 == 14 )
      {
        if ( v10[4] )
        {
          *v11 = v10[3];
          v11[1] = v10[4];
          v11 += 2;
        }
      }
      v10 = (_DWORD *)*v10;
    }
    while ( v10 != v3 );
    if ( v11 == (_DWORD *)result )
      return ExFreePoolWithTag(v9);
    while ( 1 )
    {
      while ( 1 )
      {
        v11 -= 2;
        if ( (unsigned int)v11 < v9 )
          return ExFreePoolWithTag(v9);
        v16 = MmPfnDatabase;
        v17 = MmPfnDatabase + 24 * *v11;
        v13 = v17;
        v14 = *(_DWORD *)(v17 + 4) | 0x80000000;
        v18 = v11[1];
        v15 = v18 - 1;
        if ( v18 != 1 )
          break;
LABEL_27:
        MiDeleteBootRange(*(_DWORD *)(v16 + 24 * *v11 + 4) | 0x80000000, v11[1]);
      }
      while ( 1 )
      {
        v13 += 24;
        v14 += 4;
        if ( (*(_DWORD *)(v13 + 4) | 0x80000000) != v14 )
          break;
        if ( !--v15 )
          goto LABEL_27;
      }
      v19 = *(_DWORD *)(v17 + 4) | 0x80000000;
      v20 = (int)(v14 - v19) >> 2;
      MiDeleteBootRange(v19, v20);
      v11[1] -= v20;
      *v11 += v20;
      v11 += 2;
      if ( !v20 )
      {
        v16 = MmPfnDatabase;
        goto LABEL_27;
      }
    }
  }
  return result;
}
