// PspUpdateCreateInfo 
 
int __fastcall PspUpdateCreateInfo(int a1, int a2, int a3, int a4)
{
  int v4; // lr
  int v7; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r0
  int v11; // r0
  int v12; // r4
  int v13; // r1
  char v14; // r3
  char v15; // r3
  int v16; // r0
  int v17; // r3
  int v18; // r0
  int v19; // r3
  int *v20; // r6
  int v21; // r5
  int v22; // r0
  int v23; // t1
  int v26; // [sp+20h] [bp-28h] BYREF
  _DWORD _24[15]; // [sp+24h] [bp-24h] BYREF

  _24[12] = a2;
  _24[13] = a3;
  _24[14] = a4;
  v4 = a3;
  _24[11] = a1;
  v7 = 0;
  v8 = *(_DWORD *)(a2 + 24);
  v26 = 0;
  _24[0] = 0;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( (*(_BYTE *)(a2 + 8) & 2) == 0 )
    goto LABEL_34;
  switch ( a1 )
  {
    case 2:
      v18 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      if ( v9 )
      {
        v7 = ObDuplicateObject(v18, *(_DWORD *)(a2 + 100), v18, &v26, 0, 0, 2, 0);
        v19 = v26;
      }
      else
      {
        v19 = *(_DWORD *)(a2 + 100);
        v26 = v19;
        *(_DWORD *)(a2 + 100) = 0;
        v7 = 0;
      }
      if ( v7 >= 0 )
      {
        *(_DWORD *)(v8 + 8) = v19;
        break;
      }
      goto LABEL_33;
    case 3:
      *(_WORD *)(v8 + 8) = *(_WORD *)(a2 + 58);
      break;
    case 5:
      v16 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      if ( v9 )
      {
        v7 = ObDuplicateObject(v16, *(_DWORD *)(a2 + 112), v16, &v26, 0, 0, 2, 0);
        v17 = v26;
      }
      else
      {
        v17 = *(_DWORD *)(a2 + 112);
        v26 = v17;
        *(_DWORD *)(a2 + 112) = 0;
        v7 = 0;
      }
      if ( v7 >= 0 )
      {
        *(_DWORD *)(v8 + 8) = v17;
        break;
      }
LABEL_33:
      v26 = 0;
      break;
    case 6:
      if ( (*(_DWORD *)(a2 + 4) & 0x20) != 0 )
      {
        v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        if ( v9 )
        {
          v7 = ObDuplicateObject(v10, *(_DWORD *)(a2 + 100), v10, &v26, 0, 0, 2, 0);
          v11 = v26;
        }
        else
        {
          v11 = *(_DWORD *)(a2 + 100);
          v26 = v11;
          *(_DWORD *)(a2 + 100) = 0;
          v7 = 0;
        }
        if ( v7 < 0 )
        {
          v26 = 0;
          goto LABEL_36;
        }
        v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v13 = *(_DWORD *)(a2 + 108);
        if ( v9 )
        {
          v7 = ObDuplicateObject(v12, v13, v12, _24, 0, 0, 2, 0);
          v13 = _24[0];
          v11 = v26;
        }
        else
        {
          _24[0] = *(_DWORD *)(a2 + 108);
          *(_DWORD *)(a2 + 108) = 0;
          v7 = 0;
        }
        if ( v7 < 0 )
        {
          _24[0] = 0;
          goto LABEL_36;
        }
        v4 = a3;
      }
      else
      {
        v13 = _24[0];
        v11 = v26;
      }
      *(_DWORD *)(v8 + 8) = 0;
      *(_BYTE *)(v8 + 8) ^= (*(_BYTE *)(v8 + 8) ^ ((*(_BYTE *)(v4 + 734) & 7) != 0)) & 1;
      *(_BYTE *)(v8 + 8) ^= (*(_BYTE *)(v8 + 8) ^ (16 * ((*(_BYTE *)(v4 + 734) & 7) == 1))) & 0x10;
      *(_BYTE *)(v8 + 8) ^= (*(_BYTE *)(v8 + 8) ^ (2 * ((*(_DWORD *)(v4 + 192) & 0x20000) != 0))) & 2;
      v14 = *(_BYTE *)(v8 + 8) ^ (*(_BYTE *)(v8 + 8) ^ (4 * ((PspGlobalFlags & 1) != 0))) & 4;
      *(_BYTE *)(v8 + 8) = v14;
      v15 = *(_BYTE *)(v8 + 8) ^ (v14 ^ (*(_BYTE *)(a2 + 8) >> 2)) & 8;
      *(_BYTE *)(v8 + 8) = v15;
      if ( (v15 & 8) != 0 )
      {
        *(_QWORD *)(v8 + 56) = *(int *)(a2 + 180);
        *(_DWORD *)(v8 + 64) = *(_DWORD *)(a2 + 184);
      }
      *(_DWORD *)(v8 + 12) = v11;
      *(_DWORD *)(v8 + 16) = v13;
      *(_DWORD *)(v8 + 24) = *(_DWORD *)(a2 + 124);
      *(_DWORD *)(v8 + 28) = 0;
      *(_DWORD *)(v8 + 32) = *(_DWORD *)(a2 + 128);
      *(_DWORD *)(v8 + 36) = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 8);
      *(_DWORD *)(v8 + 40) = *(_DWORD *)(v4 + 320);
      *(_DWORD *)(v8 + 44) = 0;
      *(_DWORD *)(v8 + 48) = *(_DWORD *)(a2 + 132);
      break;
  }
LABEL_34:
  if ( v7 >= 0 )
  {
    *(_DWORD *)(v8 + 4) = a1;
    return 0;
  }
LABEL_36:
  v20 = &v26;
  v21 = 2;
  do
  {
    v23 = *v20++;
    v22 = v23;
    if ( v23 )
      ObCloseHandle(v22);
    --v21;
  }
  while ( v21 );
  return v7;
}
