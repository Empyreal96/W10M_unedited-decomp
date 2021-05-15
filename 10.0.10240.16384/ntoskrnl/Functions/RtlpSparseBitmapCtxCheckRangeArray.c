// RtlpSparseBitmapCtxCheckRangeArray 
 
int __fastcall RtlpSparseBitmapCtxCheckRangeArray(int a1, int *a2)
{
  int v4; // r5
  int v5; // r8
  int v6; // r6
  _BYTE *v7; // r5
  _BYTE *v8; // r0
  int v9; // r0

  v4 = 0;
  while ( 1 )
  {
    v9 = RtlpSparseBitmapCtxLockShared(a1, a1);
    if ( *(_DWORD *)(a1 + 4) || v4 < 0 )
      break;
    RtlpSparseBitmapCtxUnlockShared(a1, a1, v9);
    v5 = RtlpSparseBitmapCtxLockExclusive(a1, a1);
    if ( *(_DWORD *)(a1 + 4) )
      goto LABEL_9;
    v6 = *(_DWORD *)(a1 + 28);
    v7 = 0;
    if ( (*(_DWORD *)(a1 + 48) & 2) == 0 )
    {
      v8 = (_BYTE *)(*(int (__fastcall **)(int))(a1 + 16))(4 * v6);
      v7 = v8;
      if ( !v8 )
      {
        v4 = -1073741670;
        goto LABEL_9;
      }
      memset(v8, 0, 4 * v6);
    }
    *(_DWORD *)(a1 + 4) = v7;
    v4 = 0;
LABEL_9:
    RtlpSparseBitmapCtxUnlockExclusive(a1, a1, v5);
  }
  *a2 = v9;
  return v4;
}
