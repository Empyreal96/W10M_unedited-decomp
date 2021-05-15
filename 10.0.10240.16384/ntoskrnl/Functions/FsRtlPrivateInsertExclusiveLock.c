// FsRtlPrivateInsertExclusiveLock 
 
int *__fastcall FsRtlPrivateInsertExclusiveLock(int a1, int *a2, int a3, int a4)
{
  int v6; // r0
  int v8; // r2
  int v9; // [sp+8h] [bp-10h] BYREF
  int v10; // [sp+Ch] [bp-Ch]

  v9 = a3;
  v10 = a4;
  v6 = FsRtlFindFirstOverlappingExclusiveNode(*(_DWORD *)(a1 + 8), a2 + 4, a2 + 12);
  a2[1] = 0;
  a2[2] = 0;
  *a2 = (int)a2;
  if ( v6 )
    return (int *)sub_51E388();
  v8 = v10;
  if ( v10 )
  {
    if ( (_BYTE)v9 )
      *(_DWORD *)(v10 + 4) = a2;
    else
      *(_DWORD *)(v10 + 8) = a2;
    *a2 = v8;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = a2;
  }
  return &v9;
}
