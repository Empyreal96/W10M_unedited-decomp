// MiBackSystemImageWithPagefile 
 
int __fastcall MiBackSystemImageWithPagefile(_DWORD *a1, int a2)
{
  unsigned int v3; // r5
  int *v5; // r4
  int result; // r0
  unsigned int v7; // r5
  int *v8; // r7
  int v9; // r6
  int v10; // t1
  _DWORD *v11; // r2
  int v12; // lr
  int v13; // r1
  int v14; // t1
  int v15[2]; // [sp+0h] [bp-30h] BYREF
  int v16[10]; // [sp+8h] [bp-28h] BYREF

  v3 = a1[6];
  v16[0] = a2;
  if ( v3 >= dword_63389C
    && (*((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v3)) == 1
     || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v3)) == 11) )
  {
    return -1073741503;
  }
  if ( a1[15] && (*(_DWORD *)(((v3 >> 20) & 0xFFC) - 1070596096) & 0x402) != 1026 )
    MiBackSingleImageWithPagefile(a1);
  v5 = (int *)a1[19];
  result = 0;
  if ( v5 == (int *)1 || v5 == (int *)-2 )
    return 0;
  if ( ((unsigned __int8)v5 & 1) != 0 )
  {
    v15[0] = 1;
    v15[1] = (unsigned int)v5 & 0xFFFFFFFE;
    v5 = v15;
  }
  v16[2] = (int)v5;
  v7 = 0;
  if ( *v5 )
  {
    v8 = v5;
    do
    {
      v10 = v8[1];
      ++v8;
      v9 = v10;
      if ( !v10 )
        break;
      if ( *(_DWORD *)(v9 + 76) != 1 )
      {
        if ( a2 )
        {
          v11 = (_DWORD *)a2;
LABEL_20:
          v12 = v11[2];
          v13 = 0;
          while ( 1 )
          {
            v14 = *(_DWORD *)(v12 + 4);
            v12 += 4;
            if ( v14 == v9 )
              break;
            if ( (unsigned int)++v13 > v11[1] )
            {
              v11 = (_DWORD *)*v11;
              if ( !v11 )
                goto LABEL_16;
              goto LABEL_20;
            }
          }
        }
        else
        {
LABEL_16:
          v16[1] = v7;
          result = MiBackSystemImageWithPagefile(v9, v16);
          if ( result < 0 )
            return result;
        }
      }
      ++v7;
    }
    while ( v7 < *v5 );
  }
  return result;
}
