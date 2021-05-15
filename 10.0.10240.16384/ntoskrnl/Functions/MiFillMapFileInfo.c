// MiFillMapFileInfo 
 
int __fastcall MiFillMapFileInfo(int result, _DWORD *a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r8
  int v7; // r9
  int v8; // r6
  __int64 v9; // r2
  int v10; // r7
  int v11; // r0
  int v12; // r3
  __int16 v13; // r1
  char v14; // r1
  unsigned int v15; // r2
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20[8]; // [sp+0h] [bp-20h] BYREF

  v20[0] = a3;
  v20[1] = a4;
  v4 = result;
  v5 = *(_DWORD *)(result + 12);
  v7 = *(_DWORD *)(result + 28) & 7;
  LODWORD(v9) = 0;
  v8 = **(_DWORD **)(result + 44);
  HIDWORD(v9) = *(_DWORD *)(result + 64);
  a2[2] = 0;
  a2[3] = 0;
  v10 = HIDWORD(v9) & 0xFFFFFFFE;
  if ( !*(_DWORD *)(v8 + 32) )
  {
    a2[1] = *(_DWORD *)(result + 48);
    HIDWORD(v9) = 12582912;
    goto LABEL_9;
  }
  v11 = MI_REFERENCE_CONTROL_AREA_FILE(v8);
  a2[1] = *(_DWORD *)(v11 + 12);
  MI_DEREFERENCE_CONTROL_AREA_FILE(v8, v11);
  MiGetProtoPteAddress((_DWORD *)v4, v5, 0, (unsigned int **)v20);
  MmGetSessionIdEx(v10);
  result = MiStartingOffset((_DWORD *)v20[0], *(_DWORD *)(v4 + 48));
  v12 = a2[3];
  a2[2] = result;
  a2[3] ^= (unsigned __int16)(v12 ^ v13);
  if ( v7 != 2 )
  {
    v9 = *((_QWORD *)a2 + 1);
    HIDWORD(v9) &= 0xFF3FFFFF;
LABEL_9:
    *((_QWORD *)a2 + 1) = v9;
    goto LABEL_10;
  }
  if ( (*(_DWORD *)(v4 + 28) & 0xF8) == 56 )
    v14 = 1;
  else
    v14 = 2;
  v15 = a2[3] & 0xFF3FFFFF | ((v14 & 3) << 22);
  a2[2] = a2[2];
  a2[3] = v15;
LABEL_10:
  v16 = a2[2];
  v17 = *(_BYTE *)(v4 + 43) & 1;
  v18 = a2[3];
  a2[2] = v16;
  a2[3] = v18 & 0xFFDFFFFF | (v17 << 21);
  a2[6] = *(_DWORD *)(v10 + 176);
  *a2 = v5 << 12;
  a2[4] = (*(_DWORD *)(v4 + 16) - *(_DWORD *)(v4 + 12) + 1) << 12;
  v19 = *(_DWORD *)(v4 + 28);
  a2[2] = v16;
  a2[3] = a2[3] & 0xFFE0FFFF | ((unsigned __int8)v19 >> 3 << 16);
  a2[5] = *(_DWORD *)(v4 + 32) << 12;
  return result;
}
