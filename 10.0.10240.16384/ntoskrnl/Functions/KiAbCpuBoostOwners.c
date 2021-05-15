// KiAbCpuBoostOwners 
 
int __fastcall KiAbCpuBoostOwners(int result, unsigned __int8 a2, int a3, int a4, int a5)
{
  int v6; // r6
  unsigned int v7; // r5
  int v9; // r7
  _DWORD *v10; // r3
  unsigned int v11; // r2
  _DWORD v12[8]; // [sp+8h] [bp-20h] BYREF

  v12[0] = a4;
  v6 = result;
  v7 = *(_DWORD *)(result + 28);
  v9 = (char)a2;
  LOWORD(v12[0]) = a2;
  while ( v7 && *(char *)(v7 + 24) < v9 )
  {
    result = KiAbSetMinimumThreadPriority(v7, v12, a3, a4, a5);
    v10 = *(_DWORD **)(v7 + 4);
    *(_BYTE *)(v7 + 24) = v9;
    v11 = v7;
    if ( v10 )
    {
      do
      {
        v7 = (unsigned int)v10;
        v10 = (_DWORD *)*v10;
      }
      while ( v10 );
    }
    else
    {
      while ( 1 )
      {
        v7 = *(_DWORD *)(v7 + 8) & 0xFFFFFFFC;
        if ( !v7 || *(_DWORD *)v7 == v11 )
          break;
        v11 = v7;
      }
    }
  }
  if ( (*(_BYTE *)(v6 + 13) & 1) == 0 )
    result = KiAbSetMinimumThreadPriority(v6, v12, a3, a4, a5);
  return result;
}
