// KiAbIoBoostOwners 
 
int __fastcall KiAbIoBoostOwners(int result, int a2, int a3, int a4)
{
  int v5; // r7
  _DWORD *v6; // r4
  _DWORD **v9; // r5
  _DWORD *v10; // r6
  _DWORD *v11; // r3
  _WORD v12[16]; // [sp+8h] [bp-20h] BYREF

  v12[1] = HIWORD(a4);
  v12[0] = 512;
  v5 = result;
  v6 = *(_DWORD **)(result + 28);
  while ( v6 )
  {
    result = KiAbSetMinimumThreadPriority(v6, v12, a2, a3, a4);
    v9 = (_DWORD **)v6[1];
    v10 = v6;
    if ( v9 )
    {
      v11 = *v9;
      v6 = (_DWORD *)v6[1];
      while ( v11 )
      {
        v6 = v11;
        v11 = (_DWORD *)*v11;
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = (_DWORD *)(v6[2] & 0xFFFFFFFC);
        if ( !v6 || (_DWORD *)*v6 == v10 )
          break;
        v10 = v6;
      }
    }
  }
  if ( (*(_BYTE *)(v5 + 13) & 1) == 0 )
    result = KiAbSetMinimumThreadPriority(v5, v12, a2, a3, a4);
  return result;
}
