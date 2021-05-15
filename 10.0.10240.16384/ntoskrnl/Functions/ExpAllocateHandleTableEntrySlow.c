// ExpAllocateHandleTableEntrySlow 
 
int __fastcall ExpAllocateHandleTableEntrySlow(int *a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r8
  int v5; // r3
  unsigned int v7; // r4
  unsigned int v8; // r7
  int v10; // r0
  int v11; // r3
  int v12; // r2
  unsigned int v13; // r1
  int v14; // r0
  int v16; // r3
  unsigned int v17; // r6
  int v18; // r0
  unsigned int v19; // r6
  int v20; // r8
  int v21; // r0
  int v22[8]; // [sp+0h] [bp-20h] BYREF

  v22[0] = a3;
  v22[1] = a4;
  v4 = (unsigned int *)(a1 + 2);
  v5 = a1[2];
  v7 = *a1;
  v8 = v5 & 0xFFFFFFFC;
  if ( (v5 & 3) == 0 )
  {
    v10 = ExpAllocateMidLevelTable((int)a1, v22, *a1, v5);
    if ( v10 )
    {
      v11 = *(_DWORD *)v10;
      *(_DWORD *)v10 = v8;
      *(_DWORD *)(v10 + 4) = v11;
      __dmb(0xBu);
      v12 = v10 | 1;
      do
LABEL_4:
        v13 = __ldrex(v4);
      while ( __strex(v12, v4) );
      __dmb(0xBu);
      goto LABEL_6;
    }
LABEL_22:
    JUMPOUT(0x7DDA96);
  }
  if ( (a1[2] & 3) != 1 )
  {
    v19 = v7 >> 21;
    if ( v7 >> 21 < 0x20 )
    {
      v20 = *(_DWORD *)(v8 + 4 * v19);
      if ( v20 )
      {
        v14 = ExpAllocateLowLevelTable(a1, v7);
        if ( v14 )
        {
          __dmb(0xBu);
          *(_DWORD *)(v20 + 4 * ((v7 >> 11) & 0x3FF)) = v14;
          goto LABEL_7;
        }
      }
      else
      {
        v21 = ExpAllocateMidLevelTable((int)a1, v22, v7, v5);
        if ( v21 )
        {
          __dmb(0xBu);
          *(_DWORD *)(v8 + 4 * v19) = v21;
LABEL_6:
          v14 = v22[0];
LABEL_7:
          ExpInsertLowLevelTableIntoFreeList(a1, v14, a2, a2 != 0);
          return 1;
        }
      }
    }
    goto LABEL_22;
  }
  if ( v7 >> 11 < 0x400 )
  {
    v14 = ExpAllocateLowLevelTable(a1, *a1);
    if ( v14 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v8 + 4 * (v7 >> 11)) = v14;
      goto LABEL_7;
    }
    goto LABEL_22;
  }
  v17 = (unsigned int)ExpAllocateTablePagedPool(a1[3], 128);
  if ( !v17 )
    goto LABEL_22;
  v18 = ExpAllocateMidLevelTable((int)a1, v22, v7, v16);
  if ( v18 )
  {
    *(_DWORD *)v17 = v8;
    *(_DWORD *)(v17 + 4) = v18;
    __dmb(0xBu);
    v12 = v17 | 2;
    goto LABEL_4;
  }
  return sub_7DDA8C();
}
