// IopRegistryOpenDeepestPath 
 
int __fastcall IopRegistryOpenDeepestPath(int *a1, _DWORD *a2, bool *a3)
{
  int result; // r0
  unsigned int v7; // r2
  int v8; // [sp+8h] [bp-28h] BYREF
  int v9; // [sp+10h] [bp-20h] BYREF
  int v10; // [sp+14h] [bp-1Ch]

  v8 = 0;
  v9 = *a1;
  v10 = a1[1];
  while ( 1 )
  {
    result = IopOpenRegistryKey((int)&v8, 0, (int)&v9, 16, 0);
    if ( result >= 0 )
      break;
    v7 = (unsigned __int16)v9;
    if ( (_WORD)v9 )
    {
      while ( *(_WORD *)(v10 + 2 * (v7 >> 1) - 2) != 92 )
      {
        v7 = (unsigned __int16)(v7 - 2);
        LOWORD(v9) = v7;
        if ( !v7 )
          return result;
      }
      LOWORD(v9) = v7 - 2;
      if ( (_WORD)v7 != 2 )
        continue;
    }
    return result;
  }
  *a2 = v8;
  *a3 = (unsigned __int16)v9 == *(unsigned __int16 *)a1;
  return result;
}
