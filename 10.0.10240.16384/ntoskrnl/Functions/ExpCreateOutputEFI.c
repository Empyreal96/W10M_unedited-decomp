// ExpCreateOutputEFI 
 
int __fastcall ExpCreateOutputEFI(int a1, unsigned int *a2, _DWORD *a3, int *a4, unsigned __int64 *a5, unsigned __int64 *a6, unsigned __int16 *a7, unsigned __int8 a8)
{
  int v9; // r7
  unsigned int v12; // r8
  unsigned int v13; // r7
  int v14; // r5
  int v16; // r3
  int v17; // r0
  int v18; // r4
  int *v19; // r3
  __int64 v20; // r0
  int v21; // r1
  int v22; // r1
  _BYTE *v23; // r3
  char v24; // r3
  int v26; // [sp+Ch] [bp-44h] BYREF
  int *v27; // [sp+10h] [bp-40h]
  int v28; // [sp+14h] [bp-3Ch] BYREF
  int v29[14]; // [sp+18h] [bp-38h] BYREF

  v27 = a4;
  v9 = 54;
  v12 = 0;
  if ( a7 )
  {
    v12 = 2 * (wcslen(a7) + 1);
    v9 = v12 + 58;
  }
  v13 = v9 + 4;
  if ( *a2 >= v13 )
  {
    memset(v29, 0, 24);
    v16 = *a4;
    v14 = 0;
    v26 = v16;
    v17 = ExpFindDiskSignature(a3, &v26, &v28, 0, 0, a8);
    if ( v17 < 0 )
      return v17;
    v17 = ExpGetDriveGeometry(v28, v29);
    if ( v17 < 0 )
      return v17;
    memset((_BYTE *)a1, 0, v13);
    *(_DWORD *)a1 = 1;
    *(_DWORD *)(a1 + 4) = v13;
    *(_DWORD *)(a1 + 8) = 4;
    *(_BYTE *)(a1 + 12) = 4;
    v18 = a1 + 12;
    *(_BYTE *)(a1 + 13) = 1;
    *(_BYTE *)(a1 + 14) = 42;
    v19 = v27;
    *(_BYTE *)(a1 + 15) = 0;
    v20 = (unsigned int)v29[5];
    *(_DWORD *)(a1 + 16) = *v19;
    if ( !(_DWORD)v20 )
      __brkdiv0();
    *(_DWORD *)(a1 + 20) = _rt_udiv64(v20, *a5);
    *(_DWORD *)(a1 + 24) = v21;
    if ( !v29[5] )
      __brkdiv0();
    *(_DWORD *)(a1 + 28) = _rt_udiv64((unsigned int)v29[5], *a6);
    *(_DWORD *)(a1 + 32) = v22;
    *(_DWORD *)(a1 + 36) = *a3;
    if ( a8 == 1 )
    {
      *(_DWORD *)(a1 + 40) = a3[1];
      *(_DWORD *)(a1 + 44) = a3[2];
      *(_DWORD *)(a1 + 48) = a3[3];
      v24 = 2;
    }
    else
    {
      v24 = 1;
    }
    *(_BYTE *)(a1 + 53) = v24;
    *(_BYTE *)(a1 + 52) = v24;
    if ( a7 )
    {
      v18 = a1 + 12 + (*(unsigned __int8 *)(a1 + 14) | (*(unsigned __int8 *)(a1 + 15) << 8));
      *(_BYTE *)v18 = 4;
      *(_BYTE *)(v18 + 1) = 4;
      *(_WORD *)(v18 + 2) = v12 + 4;
      memmove(v18 + 4, (int)a7, v12 - 2);
      *(_WORD *)(v18 + 2 * (v12 >> 1) + 2) = 0;
    }
    v23 = (_BYTE *)((*(unsigned __int8 *)(v18 + 2) | (*(unsigned __int8 *)(v18 + 3) << 8)) + v18);
    *v23 = 127;
    v23[1] = -1;
    v23[2] = 4;
    v23[3] = 0;
  }
  else
  {
    v14 = -1073741789;
  }
  *a2 = v13;
  return v14;
}
