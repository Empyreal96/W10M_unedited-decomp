// RtlpCreateServerAcl 
 
int __fastcall RtlpCreateServerAcl(int a1, int a2, int a3, int *a4, _BYTE *a5)
{
  unsigned int v7; // r4
  int v9; // r5
  int v10; // r1
  unsigned int v11; // r0
  __int16 v12; // r3
  int v13; // r2
  unsigned int v14; // r3
  int v15; // r2
  int v16; // r0
  int v18; // r7
  unsigned int v19; // r8
  _DWORD *v20; // r4
  int v21; // r5
  int v22; // r7
  int v23; // r9
  int v24; // r4
  int v25; // r4
  int v26; // r2
  _DWORD *v28; // [sp+0h] [bp-28h]
  int v29; // [sp+4h] [bp-24h]

  v7 = 8;
  if ( !a1 )
  {
    *a4 = 0;
    *a5 = 0;
    return 0;
  }
  v9 = *(unsigned __int16 *)(a1 + 4);
  v10 = a1 + 8;
  v11 = 4 * (*(unsigned __int8 *)(a3 + 1) + 2);
  if ( *(_WORD *)(a1 + 4) )
  {
    do
    {
      if ( *(_BYTE *)v10 )
      {
        if ( !a2 || *(_BYTE *)v10 != 4 )
          goto LABEL_12;
        v13 = *(unsigned __int8 *)(v10 + 13);
        v14 = 4 * (v13 + 2);
        if ( v14 <= v11 )
          v12 = v11 - 4 * v13 + v7 - 8;
        else
          v12 = v14 - v11 + v7;
      }
      else
      {
        v12 = v11 + v7 + 4;
      }
      LOWORD(v7) = v12;
LABEL_12:
      v15 = *(unsigned __int16 *)(v10 + 2);
      v10 += v15;
      v7 = (unsigned __int16)(v15 + v7);
      --v9;
    }
    while ( v9 );
  }
  v16 = ExAllocatePoolWithTag(1, v7, 1665230163);
  *a4 = v16;
  if ( !v16 )
    return -1073741670;
  *a5 = 1;
  RtlCreateAcl(v16, v7, 3);
  v18 = *a4;
  v19 = 0;
  v29 = v18;
  v20 = (_DWORD *)(v18 + 8);
  v21 = a1 + 8;
  if ( *(_WORD *)(a1 + 4) )
  {
    v22 = a3;
    do
    {
      if ( !*(_BYTE *)v21 || a2 && *(_BYTE *)v21 == 4 )
      {
        v28 = v20;
        if ( *(_BYTE *)v21 )
          v23 = RtlLengthSid(v21 + 12) + v21 + 12;
        else
          v23 = v21 + 8;
        *v20 = *(_DWORD *)v21;
        v20[1] = *(_DWORD *)(v21 + 4);
        v24 = (int)(v20 + 3);
        memmove(v24, v22, 4 * (*(unsigned __int8 *)(v22 + 1) + 2));
        v25 = v24 + (unsigned __int8)(4 * (*(_BYTE *)(v22 + 1) + 2));
        memmove(v25, v23, 4 * (*(unsigned __int8 *)(v23 + 1) + 2));
        v26 = *(unsigned __int8 *)(v23 + 1);
        v20 = (_DWORD *)(v25 + 4 * (v26 + 2));
        *((_WORD *)v28 + 1) = 4 * (*(unsigned __int8 *)(v22 + 1) + (_WORD)v26 + 7);
        *(_BYTE *)v28 = 4;
        *((_WORD *)v28 + 4) = 1;
      }
      else
      {
        memmove((int)v20, v21, *(unsigned __int16 *)(v21 + 2));
        v20 = (_DWORD *)((char *)v20 + *(unsigned __int16 *)(v21 + 2));
      }
      ++v19;
      v21 += *(unsigned __int16 *)(v21 + 2);
    }
    while ( v19 < *(unsigned __int16 *)(a1 + 4) );
    v18 = v29;
  }
  *(_WORD *)(v18 + 4) = *(_WORD *)(a1 + 4);
  return 0;
}
