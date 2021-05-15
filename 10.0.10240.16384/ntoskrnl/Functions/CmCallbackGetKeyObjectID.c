// CmCallbackGetKeyObjectID 
 
int __fastcall CmCallbackGetKeyObjectID(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v6; // r0
  _DWORD *v8; // r4
  int v9; // r3
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1

  if ( !a2 || *a2 != 1803104306 || !a1 )
    return -1073741811;
  v6 = a2[1];
  if ( a3 )
    *a3 = v6;
  if ( !a4 )
    return 0;
  if ( (v6 & 1) != 0 )
    return -1073741811;
  CmpLockRegistry();
  v8 = (_DWORD *)a2[1];
  CmpLockKcbShared(v8);
  v9 = v8[39];
  if ( v9 )
    goto LABEL_18;
  if ( v8[11] )
  {
    v10 = CmpConstructName((int)v8);
    if ( v10 )
    {
      __dmb(0xBu);
      v11 = v8 + 39;
      do
        v12 = __ldrex(v11);
      while ( !v12 && __strex(v10, v11) );
      __dmb(0xBu);
      if ( v12 )
        ExFreePoolWithTag(v10);
    }
  }
  v9 = v8[39];
  if ( v9 )
  {
LABEL_18:
    *a4 = v9;
    CmpUnlockKcb(v8);
    CmpUnlockRegistry();
    return 0;
  }
  CmpUnlockKcb(v8);
  CmpUnlockRegistry();
  return -1073741670;
}
