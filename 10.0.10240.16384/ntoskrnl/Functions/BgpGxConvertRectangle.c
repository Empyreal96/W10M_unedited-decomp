// BgpGxConvertRectangle 
 
int __fastcall BgpGxConvertRectangle(_DWORD *a1, unsigned int a2, int a3, char a4)
{
  _DWORD *v4; // r6
  unsigned int **v5; // r10
  int v7; // r9
  int v8; // r3
  int result; // r0
  unsigned int *v10; // r4
  unsigned int v11; // r1
  _BYTE *v12; // r5
  int v13; // r8
  unsigned int v14; // r3
  int j; // r2
  unsigned int v16; // r10
  unsigned int v17; // r6
  unsigned int i; // r7
  char v19[4]; // [sp+0h] [bp-40h] BYREF
  unsigned int *v20; // [sp+4h] [bp-3Ch] BYREF
  int v21; // [sp+8h] [bp-38h]
  unsigned int **v22; // [sp+Ch] [bp-34h]
  _DWORD *v23; // [sp+10h] [bp-30h]
  int v24[10]; // [sp+18h] [bp-28h] BYREF

  v4 = a1;
  v22 = (unsigned int **)a3;
  v23 = a1;
  v5 = (unsigned int **)a3;
  v7 = (a4 & 1) != 0;
  v8 = *a1;
  v21 = v7;
  if ( v7 )
    return sub_54D4E4(0);
  v24[1] = v8;
  v24[0] = a1[1];
  v20 = 0;
  result = BgpGxRectangleCreate(v24, a2, &v20);
  if ( result >= 0 )
  {
    v10 = v20;
    v11 = v4[2];
    v12 = (_BYTE *)v20[5];
    v13 = v4[5];
    v20 = (unsigned int *)v11;
    if ( v11 == a2 )
    {
      memmove((int)v12, v13, v4[3]);
    }
    else
    {
      v14 = *v10;
      if ( a2 == 4 )
      {
        v16 = 0;
        if ( v14 )
        {
          v17 = (unsigned int)v20;
          do
          {
            for ( i = 0; i < v10[1]; v13 += v17 >> 3 )
            {
              GxpMatchPaletteColor(*(_DWORD *)v13, v19);
              if ( (i & 1) != 0 )
                *v12++ |= v19[0];
              else
                *v12 = 16 * v19[0];
              ++i;
            }
            if ( (i & 1) != 0 )
              ++v12;
            ++v16;
          }
          while ( v16 < *v10 );
          v4 = v23;
          v7 = v21;
        }
        v5 = v22;
      }
      else
      {
        for ( j = v10[1] * v14; j; --j )
        {
          v12[2] = *(_BYTE *)(v13 + 2);
          v12[1] = *(_BYTE *)(v13 + 1);
          *v12 = *(_BYTE *)v13;
          if ( a2 == 32 )
            v12[3] = 0;
          v13 += v11 >> 3;
          v12 += a2 >> 3;
        }
      }
      if ( v7 )
        v4[4] |= 0x10u;
    }
    *v5 = v10;
    result = 0;
  }
  return result;
}
