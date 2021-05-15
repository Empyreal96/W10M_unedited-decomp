// MiInitializePrivateFixupBitmap 
 
int __fastcall MiInitializePrivateFixupBitmap(_DWORD *a1, _DWORD **a2)
{
  int v3; // r8
  _DWORD **v4; // r4
  int v5; // r10
  unsigned int v6; // r6
  int v7; // r5
  _DWORD *v8; // r7
  unsigned int v9; // lr

  v3 = *a2[14];
  v4 = a2 + 20;
  v5 = v3 + 40;
  *a1 = (*a2)[1];
  a1[1] = a1 + 2;
  RtlClearAllBits((int)a1);
  v6 = 0;
  v7 = 0;
  do
  {
    if ( v4[1] >= &v4[1][(_DWORD)v4[7]] )
      goto LABEL_10;
    v8 = (_DWORD *)(v5 + 4 * v6);
    v9 = ((unsigned int)(4 * (_DWORD)v4[7] - 1) >> 2) + 1;
    do
    {
      if ( v6 < *(_DWORD *)(v3 + 24) && *v8 )
      {
        *(_BYTE *)((v6 >> 3) + a1[1]) |= 1 << (v6 & 7);
LABEL_7:
        ++v7;
        goto LABEL_8;
      }
      if ( ((_WORD)v4[4] & 0xA) == 10 )
        goto LABEL_7;
LABEL_8:
      ++v6;
      ++v8;
      --v9;
    }
    while ( v9 );
    v5 = v3 + 40;
LABEL_10:
    v4 = (_DWORD **)v4[2];
  }
  while ( v4 );
  return v7;
}
