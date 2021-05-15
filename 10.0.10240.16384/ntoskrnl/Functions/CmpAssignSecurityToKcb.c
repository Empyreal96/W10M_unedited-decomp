// CmpAssignSecurityToKcb 
 
int __fastcall CmpAssignSecurityToKcb(int a1, int a2, int a3, int a4)
{
  _DWORD *v8; // r4
  int v9; // r5
  unsigned int *v10; // r0
  unsigned int v11; // r2
  int result; // r0
  int *v13; // r4
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17[8]; // [sp+8h] [bp-20h] BYREF

  v17[0] = a4;
  if ( a2 == -1 )
  {
    *(_DWORD *)(a1 + 48) = 0;
    result = 1;
  }
  else
  {
    v8 = *(_DWORD **)(a1 + 20);
    if ( !a4 )
    {
      v9 = KeAbPreAcquire((unsigned int)(v8 + 482), 0, 0);
      v10 = v8 + 482;
      do
        v11 = __ldrex(v10);
      while ( !v11 && __strex(0x11u, v10) );
      __dmb(0xBu);
      if ( v11 )
        ExfAcquirePushLockSharedEx(v10, v9, (unsigned int)(v8 + 482));
      if ( v9 )
        *(_BYTE *)(v9 + 14) |= 1u;
    }
    if ( CmpFindSecurityCellCacheIndex(v8, a2, v17) )
    {
      if ( !a3 )
        *(_DWORD *)(a1 + 48) = *(_DWORD *)(v8[501] + 8 * v17[0] + 4);
      if ( !a4 )
      {
        v13 = v8 + 482;
        __pld(v13);
        v14 = *v13;
        if ( (*v13 & 0xFFFFFFF0) > 0x10 )
          v15 = v14 - 16;
        else
          v15 = 0;
        if ( (v14 & 2) != 0 )
          goto LABEL_26;
        __dmb(0xBu);
        do
          v16 = __ldrex((unsigned int *)v13);
        while ( v16 == v14 && __strex(v15, (unsigned int *)v13) );
        if ( v16 != v14 )
LABEL_26:
          ExfReleasePushLock(v13, v14);
        KeAbPostRelease((unsigned int)v13);
      }
      result = 1;
    }
    else
    {
      result = sub_805380();
    }
  }
  return result;
}
