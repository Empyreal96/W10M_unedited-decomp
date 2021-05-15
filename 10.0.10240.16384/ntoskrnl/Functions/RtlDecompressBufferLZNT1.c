// RtlDecompressBufferLZNT1 
 
int __fastcall RtlDecompressBufferLZNT1(int a1, int a2, unsigned __int8 *a3, int a4, char *a5, unsigned int *a6)
{
  unsigned __int8 *v6; // r6
  _BYTE *v7; // r8
  unsigned int v8; // r10
  unsigned int v9; // r9
  int v10; // r5
  int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r7
  unsigned int v14; // r4
  bool v15; // cc
  unsigned int v16; // r9
  int v17; // r9
  unsigned int v18; // r1
  unsigned int v19; // r1
  int v21; // [sp+4h] [bp-54h]
  int v22; // [sp+8h] [bp-50h]
  char *v23; // [sp+Ch] [bp-4Ch] BYREF
  unsigned int v24; // [sp+10h] [bp-48h]
  unsigned int v25; // [sp+14h] [bp-44h]
  int v26; // [sp+18h] [bp-40h]
  char v27[16]; // [sp+20h] [bp-38h] BYREF
  unsigned int v28; // [sp+30h] [bp-28h] BYREF
  int v29; // [sp+34h] [bp-24h]

  v6 = a3;
  v26 = a1;
  v7 = (_BYTE *)a1;
  v8 = a1 + a2;
  v9 = (unsigned int)&a3[a4];
  v24 = (unsigned int)&a3[a4];
  v25 = a1 + a2;
  v10 = 0;
  KeInitializeEvent((int)v27, 1, 0);
  v28 = 1;
  v29 = 0;
  if ( ((unsigned __int8)v6 & 1) != 0 )
  {
    LOWORD(v22) = *(_WORD *)v6;
    v11 = *(unsigned __int16 *)v6;
  }
  else
  {
    v11 = *(unsigned __int16 *)v6;
    LOWORD(v22) = *(_WORD *)v6;
  }
  v12 = (v11 & 0xFFF) + 3;
  v13 = (unsigned int)&v6[v12];
  v14 = 0;
  v15 = (unsigned int)&v6[v12] > v9;
  v23 = 0;
  while ( 1 )
  {
    if ( v15 )
    {
LABEL_33:
      *a6 = (unsigned int)v6;
      goto LABEL_34;
    }
    if ( (v11 & 0xFFFF8000) != 0 )
    {
      if ( a5 )
      {
        v10 = LZNT1DecompressChunkNewThread((int)v27, (unsigned int)v7, v8, (unsigned int)(v6 + 2), v13, (signed int)a5);
        if ( v10 < 0 )
        {
          *a6 = v14;
          goto LABEL_35;
        }
        v14 = (unsigned int)a5;
        v23 = a5;
      }
      else
      {
        v10 = LZNT1DecompressChunk((unsigned int)v7, v8, v6 + 2, v13, &v23, v21, v22);
        if ( v10 < 0 )
        {
          *a6 = (unsigned int)v23;
          goto LABEL_35;
        }
        v14 = (unsigned int)v23;
      }
      v16 = v24;
    }
    else
    {
      if ( v12 < 2 )
        goto LABEL_33;
      v14 = v12 - 2;
      v23 = (char *)(v12 - 2);
      if ( (unsigned int)&v7[v12 - 2] > v8 )
      {
        v14 = v8 - (_DWORD)v7;
        v23 = (char *)(v8 - (_DWORD)v7);
      }
      v16 = v24;
      if ( (unsigned int)&v6[v14 + 2] > v24 )
        goto LABEL_33;
      memmove((int)v7, (int)(v6 + 2), v14);
    }
    v7 += v14;
    v6 = (unsigned __int8 *)v13;
    if ( v7 == (_BYTE *)v8 || v13 > v16 - 2 )
      break;
    if ( (v13 & 1) != 0 )
    {
      LOWORD(v22) = *(_WORD *)v13;
      v17 = *(unsigned __int16 *)v13;
    }
    else
    {
      v17 = *(unsigned __int16 *)v13;
      LOWORD(v22) = *(_WORD *)v13;
    }
    if ( !v17 )
      break;
    if ( v14 < 0x1000 )
    {
      if ( (unsigned int)&v7[4096 - v14] >= v25 )
        break;
      memset(v7, 0, 4096 - v14);
      v7 += 4096 - v14;
      v8 = v25;
    }
    v12 = (v17 & 0xFFF) + 3;
    v13 += v12;
    v15 = v13 > v24;
    v11 = v17;
  }
  if ( v13 <= v24 )
  {
    *a6 = (unsigned int)&v7[-v26];
    goto LABEL_35;
  }
  *a6 = v13;
LABEL_34:
  v10 = -1073741246;
LABEL_35:
  __dmb(0xBu);
  do
  {
    v18 = __ldrex(&v28);
    v19 = v18 - 1;
  }
  while ( __strex(v19, &v28) );
  __dmb(0xBu);
  if ( !v19 )
    KeSetEvent((int)v27, 0, 0);
  KeWaitForSingleObject((unsigned int)v27, 0, 0, 0, 0);
  if ( v10 >= 0 && v29 < 0 )
    v10 = v29;
  return v10;
}
