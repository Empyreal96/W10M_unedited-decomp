// CmpPostNotify 
 
int __fastcall CmpPostNotify(int result, int a2, int a3, int a4, char a5, int *a6, int *a7)
{
  int v7; // r1
  int v8; // r4
  int *v9; // r7
  int *v10; // r6
  __int64 v11; // r4
  int v12; // r3
  __int64 v13; // r2
  int v14; // r3
  int **v15; // r2
  __int64 v16; // r0
  int **v17; // r1
  int v18; // r2
  int v20[2]; // [sp+8h] [bp-30h] BYREF
  int v21[10]; // [sp+10h] [bp-28h] BYREF

  v7 = a4;
  v8 = result;
  if ( a6 )
  {
    v9 = a6;
  }
  else
  {
    v20[1] = (int)v20;
    v9 = v20;
    v20[0] = (int)v20;
  }
  if ( a7 )
  {
    v10 = a7;
  }
  else
  {
    v21[1] = (int)v21;
    v10 = v21;
    v21[0] = (int)v21;
  }
  if ( !a5 )
  {
    result = LOCK_POST_LIST();
    v7 = a4;
  }
  HIDWORD(v11) = v8 + 8;
  v12 = *(_DWORD *)(v8 + 24);
  if ( *(_DWORD *)(v8 + 8) == v8 + 8 )
  {
    *(_DWORD *)(v8 + 24) = v12 | 0x80000000;
    if ( !a5 )
      result = UNLOCK_POST_LIST(result, v7);
  }
  else
  {
    *(_DWORD *)(v8 + 24) = v12 & 0x7FFFFFFF;
LABEL_9:
    result = 267;
    while ( *(_DWORD *)HIDWORD(v11) != HIDWORD(v11) )
    {
      LODWORD(v11) = *(_DWORD *)HIDWORD(v11);
      v13 = *(_QWORD *)*(_DWORD *)HIDWORD(v11);
      if ( __PAIR64__(HIDWORD(v13), *(_DWORD *)(v13 + 4)) != v11 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v11) = v13;
      *(_DWORD *)(v13 + 4) = HIDWORD(v11);
      if ( v7 == 267 && (*(_DWORD *)(v11 + 28) & 0x10000) == 0 )
        return sub_8069B0(267);
      if ( (*(_DWORD *)(v11 + 28) & 0x10000) == 0 )
      {
        v18 = v11;
        do
        {
          v18 = *(_DWORD *)(v18 + 16) - 16;
          *(_DWORD *)(v18 + 28) &= 0xFFFEFFFF;
        }
        while ( v18 != (_DWORD)v11 );
        *(_DWORD *)(v11 + 28) |= 0x10000u;
      }
      if ( *(_WORD *)(v11 + 28) != 1 )
      {
        CmpCancelSubordinatePost(v11, v9);
        CmpAddToDelayedDeref(v11);
        v7 = a4;
        result = 267;
      }
      v14 = *(unsigned __int16 *)(v11 + 28);
      if ( v14 == 2 )
      {
        KeInsertQueueApc(*(_DWORD *)(v11 + 32) + 8, v7, v11, 0);
LABEL_30:
        v7 = a4;
        goto LABEL_9;
      }
      if ( v14 == 1 )
        JUMPOUT(0x806A14);
      if ( (unsigned int)(v14 - 3) <= 1 )
      {
        CmpFreeSubordinatePost(v11);
        v15 = (int **)(v11 + 8);
        v16 = *(_QWORD *)(v11 + 8);
        if ( *(_DWORD *)(v16 + 4) != (_DWORD)v11 + 8 || *(int ***)HIDWORD(v16) != v15 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v16) = v16;
        *(_DWORD *)(v16 + 4) = HIDWORD(v16);
        v17 = (int **)v10[1];
        *v15 = v10;
        *(_DWORD *)(v11 + 12) = v17;
        if ( *v17 != v10 )
          __fastfail(3u);
        *v17 = (int *)v15;
        v10[1] = (int)v15;
        goto LABEL_30;
      }
    }
    if ( !a5 )
      result = UNLOCK_POST_LIST(267, v7);
    if ( !a6 )
      result = (int)CmpDelayedDerefKeys(v9);
    if ( !a7 )
      result = CmpSignalDeferredPosts((unsigned int)v10);
  }
  return result;
}
