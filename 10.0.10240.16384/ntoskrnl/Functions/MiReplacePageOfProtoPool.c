// MiReplacePageOfProtoPool 
 
int __fastcall MiReplacePageOfProtoPool(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  unsigned int *v4; // r7
  int v5; // r6
  int v6; // r9
  unsigned int *v7; // r8
  unsigned int *v8; // r5
  int v9; // r10
  int v11; // r1
  unsigned int *v12; // r8
  unsigned int v13; // r3
  int v14; // r9
  int v15; // r4
  int v16; // r0
  unsigned int v17; // t1
  unsigned __int8 *v18; // r1
  unsigned int v19; // r2
  unsigned int v20; // r1
  unsigned __int8 *v21; // r4
  unsigned int v22; // r2
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r6
  unsigned int v26; // r0
  unsigned int v27; // r1
  char *v28; // r5
  int i; // r3
  unsigned int v30; // r5
  int v31; // r2
  unsigned int *v32; // r2
  unsigned int v33; // r0
  int v34; // r3
  int v35; // r1
  char *v36; // [sp+0h] [bp-C0h]
  unsigned int *v37; // [sp+4h] [bp-BCh]
  int v38; // [sp+8h] [bp-B8h]
  unsigned int *v40; // [sp+1Ch] [bp-A4h]
  char v41[160]; // [sp+20h] [bp-A0h] BYREF

  v40 = a4;
  v4 = a4;
  v5 = MmPfnDatabase + 24 * a2;
  v6 = MmPfnDatabase + 24 * a3;
  v7 = a1;
  v37 = a1;
  v38 = v6;
  v8 = a1;
  v9 = 0;
  memset(v41, 0, 128);
  if ( v8[1] != 1951624525 )
    return sub_5519DC(1734439494, 1816358221);
  if ( !MiIsPoolHeader(v7, 1816358221) )
    JUMPOUT(0x5519EC);
  if ( v8 != v7 + 1024 )
  {
    v12 = v8;
    while ( 1 )
    {
      v13 = v12[1];
      if ( v13 == 1734439494 || v13 == v11 || (*((_WORD *)v12 + 1) & 0x400) == 0 )
        JUMPOUT(0x551A72);
      v8 += 2;
      v14 = 8 * (*((_WORD *)v12 + 1) & 0x1FF) - 8;
      *v4 = *v12;
      v4[1] = v12[1];
      v4 += 2;
      v15 = (char *)v4 - (char *)v40;
      v36 = (char *)((char *)v4 - (char *)v40);
      do
      {
        v16 = MiLockLeafPage(v8, v9);
        if ( v16 )
        {
          ++v9;
          v41[(unsigned int)(v15 >> 2) >> 3] |= 1 << ((v15 >> 2) & 7);
          if ( (*(_BYTE *)(v16 + 18) & 8) != 0 || (*v8 & 2) == 0 && (*(_BYTE *)(v16 + 18) & 0x20) != 0 )
            JUMPOUT(0x551B08);
          v15 = (int)v36;
        }
        v17 = *v8++;
        v15 += 4;
        v36 = (char *)v15;
        *v4++ = v17;
        v14 -= 4;
      }
      while ( v14 );
      v12 += 2 * (*((_WORD *)v12 + 1) & 0x1FF);
      if ( ((unsigned __int16)v12 & 0xFFF) == 0 )
        break;
      v11 = 1816358221;
    }
    v6 = v38;
  }
  v18 = (unsigned __int8 *)(v5 + 15);
  if ( !v9 )
    JUMPOUT(0x551AB0);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 | 0x80, v18) );
  __dmb(0xBu);
  if ( v19 >> 7 )
    JUMPOUT(0x551A8C);
  if ( *(_WORD *)(v5 + 16) != 2 )
    JUMPOUT(0x551AF0);
  v20 = *(_DWORD *)(v5 + 12) & 0x3FFFFFFF;
  if ( *(unsigned __int16 *)(v5 + 12) != v9 + 1 || v20 >= 0x10000 )
  {
    __dmb(0xBu);
    JUMPOUT(0x551AF8);
  }
  v21 = (unsigned __int8 *)(v6 + 15);
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 | 0x80, v21) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v22 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v34 = *(_DWORD *)(v6 + 12);
      __dmb(0xBu);
    }
    while ( (v34 & 0x80000000) != 0 );
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 | 0x80, v21) );
  }
  *(_DWORD *)(v6 + 12) = *(_DWORD *)(v6 + 12) & 0xC0000000 | v20 & 0x3FFFFFFF;
  __dmb(0xBu);
  v23 = (unsigned int *)(v6 + 12);
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 & 0x7FFFFFFF, v23) );
  v25 = 0;
  while ( v9 )
  {
    if ( v25 >= 0x400 )
      v26 = 0;
    else
      v26 = v25;
    v27 = 1023;
    while ( 1 )
    {
      if ( v27 - v26 == -1 )
        goto LABEL_46;
      v28 = &v41[4 * (v26 >> 5)];
      for ( i = ~*(_DWORD *)v28 | ((1 << (v26 & 0x1F)) - 1); i == -1; i = ~*(_DWORD *)v28 )
      {
        v28 += 4;
        if ( v28 > &v41[4 * (v27 >> 5)] )
          goto LABEL_46;
      }
      v30 = __clz(__rbit(~i)) + 32 * ((v28 - v41) >> 2);
      if ( v30 > v27 )
      {
LABEL_46:
        v30 = -1;
      }
      else if ( v30 != -1 )
      {
        break;
      }
      if ( !v26 )
        break;
      v35 = v25 + 1;
      if ( v25 + 1 > 0x400 )
        v35 = 1024;
      v27 = v35 - 1;
      v26 = 0;
    }
    v31 = MmPfnDatabase + 24 * (v37[v30] >> 12);
    *(_DWORD *)(v31 + 20) = *(_DWORD *)(v31 + 20) & 0xFFF00000 | a3 & 0xFFFFF;
    --v9;
    __dmb(0xBu);
    v32 = (unsigned int *)(v31 + 12);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 & 0x7FFFFFFF, v32) );
    v25 = v30 + 1;
  }
  return 1;
}
