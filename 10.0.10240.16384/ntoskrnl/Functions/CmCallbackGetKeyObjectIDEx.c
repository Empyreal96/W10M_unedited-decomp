// CmCallbackGetKeyObjectIDEx 
 
int __fastcall CmCallbackGetKeyObjectIDEx(int a1, _DWORD *a2, _DWORD *a3, int *a4, int a5)
{
  int v6; // r6
  int v8; // r0
  _DWORD *v10; // r4

  v6 = 0;
  if ( !a2 || *a2 != 1803104306 || !a1 || a5 )
    return -1073741811;
  v8 = a2[1];
  if ( a3 )
    *a3 = v8;
  if ( !a4 )
    return 0;
  if ( (v8 & 1) != 0 )
    return -1073741811;
  CmpLockRegistry();
  v10 = (_DWORD *)a2[1];
  CmpLockKcbShared(v10);
  if ( v10[11] )
    v6 = CmpConstructName((int)v10);
  CmpUnlockKcb(v10);
  CmpUnlockRegistry();
  if ( v6 )
  {
    *a4 = v6;
    return 0;
  }
  return -1073741670;
}
