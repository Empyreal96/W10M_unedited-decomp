// PfTEntryInfoLookup 
 
int __fastcall PfTEntryInfoLookup(int a1, int a2, _WORD *a3, int a4)
{
  int v4; // r7
  int v5; // r4
  unsigned int v7; // r2
  unsigned int v8; // r9
  int result; // r0
  unsigned int v10; // r8
  int v11; // r1
  int v12; // r3
  unsigned int v13; // r6
  int *v14; // lr
  int v15; // r3
  int v16; // t1
  _WORD *varg_r2; // [sp+28h] [bp+10h]

  varg_r2 = a3;
  v4 = a2;
  v5 = (a2 & 3) + 2;
  v7 = *(_DWORD *)(a1 + 4 * v5);
  v8 = (a1 + 35) & 0xFFFFFFFC;
  if ( *(_DWORD *)(v8 + 20 * v7) == a2 )
    return (unsigned __int16)v7;
  v10 = *(_DWORD *)(a1 + 24);
  v11 = (v10 - 1) & (37 * (37 * (37 * ((unsigned __int8)a2 + 11623883) + BYTE1(a2)) + BYTE2(a2)) + HIBYTE(a2));
  v12 = *(_DWORD *)(v8 + 20 * v11);
  if ( v12 == v4 )
  {
    *(_DWORD *)(a1 + 4 * v5) = v11;
    result = (unsigned __int16)v11;
  }
  else
  {
    if ( v12 )
    {
      v7 = v11 + 1;
      v13 = 0;
      while ( v7 >= v10 )
      {
LABEL_14:
        ++v13;
        v7 = 0;
        v10 = v11;
        if ( v13 >= 2 )
        {
          result = 0xFFFF;
          *a3 = -1;
          return result;
        }
      }
      v14 = (int *)(v8 + 20 * v7);
      while ( 1 )
      {
        v16 = *v14;
        v14 += 5;
        v15 = v16;
        if ( v16 == v4 )
          break;
        if ( !v15 )
        {
          *(_DWORD *)(a1 + 4 * v5) = v7;
          *a3 = v7;
          goto LABEL_7;
        }
        if ( ++v7 >= v10 )
          goto LABEL_14;
      }
      *(_DWORD *)(a1 + 4 * v5) = v7;
      return (unsigned __int16)v7;
    }
    *(_DWORD *)(a1 + 4 * v5) = v11;
    *a3 = v11;
LABEL_7:
    result = 0xFFFF;
  }
  return result;
}
