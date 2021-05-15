// RaspAntiAlias 
 
unsigned int __fastcall RaspAntiAlias(int a1, unsigned int *a2, int a3, unsigned int a4, int *a5)
{
  unsigned int *v6; // r6
  int v7; // r8
  unsigned int v8; // r7
  unsigned int result; // r0
  int v11; // r4
  int v12; // r3
  int v13; // r6
  unsigned int v14; // r1
  int v15; // r9
  unsigned int v16; // r0
  int v17; // lr
  int v18; // r0
  unsigned int v19; // [sp+4h] [bp-34h]
  int v20; // [sp+8h] [bp-30h]
  unsigned int v21; // [sp+Ch] [bp-2Ch]
  int v22; // [sp+10h] [bp-28h]

  v6 = a2;
  v7 = a1;
  v22 = *(_DWORD *)(a1 + 20);
  v8 = 0;
  v21 = 0;
  result = (unsigned int)BgpGxFillRectangle(a2, *a5);
  if ( *v6 )
  {
    if ( !a4 )
      __brkdiv0();
    result = *(_DWORD *)(v7 + 4) / a4;
    v11 = 0;
    do
    {
      v19 = 0;
      v12 = v6[5] + 4 * v6[1] * v8;
      v20 = v12;
      if ( result )
      {
        v13 = 0;
        do
        {
          v14 = 0;
          v15 = 0;
          do
          {
            if ( a3 )
            {
              v16 = v13 + (v11 + v14) * *(_DWORD *)(v7 + 4);
              v17 = a3;
              do
              {
                v12 = *(unsigned __int8 *)((v16 >> 3) + v22);
                if ( ((128 >> (v16 & 7)) & v12) != 0 )
                  ++v15;
                ++v16;
                --v17;
              }
              while ( v17 );
              v7 = a1;
            }
            ++v14;
          }
          while ( v14 < a4 );
          if ( !(a3 * a4) )
            __brkdiv0();
          v18 = BgpGxBlendColor(*a5, a5[1], (unsigned __int8)(255 * v15 / (a3 * a4)), v12);
          *(_BYTE *)(v20 + 2) = BYTE2(v18);
          ++v19;
          v13 += a3;
          *(_WORD *)v20 = v18;
          v12 = 255;
          *(_BYTE *)(v20 + 3) = -1;
          v20 += 4;
          result = *(_DWORD *)(v7 + 4) / a4;
        }
        while ( v19 < result );
        v6 = a2;
        v8 = v21;
      }
      ++v8;
      v11 += a4;
      v21 = v8;
    }
    while ( v8 < *v6 );
  }
  return result;
}
