// RtlpAddKnownObjectAce 
 
int __fastcall RtlpAddKnownObjectAce(unsigned __int8 *a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6, _BYTE *a7, char a8)
{
  int v11; // r8
  unsigned int v13; // r3
  int v14; // r3
  unsigned int v15; // lr
  int v16; // r1
  int v17; // r0
  int v18; // r3
  _DWORD *v19; // r1
  int v20; // [sp+0h] [bp-28h] BYREF
  int v21; // [sp+4h] [bp-24h]
  int v22; // [sp+8h] [bp-20h]

  v20 = a2;
  v22 = a4;
  v21 = a4;
  v11 = 0;
  if ( !RtlValidSid(a7) )
    return -1073741704;
  if ( *a1 > 4u || a2 != 4 )
    return -1073741735;
  v13 = a3 & 0xFFFFFFE0;
  if ( (a3 & 0xFFFFFFE0) != 0 )
  {
    if ( a8 == 2 || a8 == 7 )
      v13 = a3 & 0xFFFFFF20;
    if ( v13 )
      return -1073741811;
  }
  if ( !RtlValidAcl(a1) || !RtlFirstFreeAce((int)a1, &v20) )
    return -1073741705;
  v14 = (unsigned __int8)a7[1] + 2;
  v15 = 4 * v14;
  v16 = 4 * v14 + 12;
  if ( a5 )
  {
    v11 = 1;
    v16 = 4 * v14 + 28;
  }
  if ( a6 )
  {
    v11 |= 2u;
    v16 += 16;
  }
  v17 = v20;
  if ( !v20 || v16 + v20 > (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)] )
    return -1073741671;
  v18 = v21;
  *(_WORD *)(v20 + 2) = v16;
  *(_BYTE *)(v17 + 1) = a3;
  *(_DWORD *)(v17 + 4) = v18;
  *(_DWORD *)(v17 + 8) = v11;
  *(_BYTE *)v17 = a8;
  v19 = (_DWORD *)(v17 + 12);
  if ( a5 )
  {
    *v19 = *a5;
    *(_DWORD *)(v17 + 16) = a5[1];
    *(_DWORD *)(v17 + 20) = a5[2];
    *(_DWORD *)(v17 + 24) = a5[3];
    v19 = (_DWORD *)(v17 + 28);
  }
  if ( a6 )
  {
    *v19 = *a6;
    v19[1] = a6[1];
    v19[2] = a6[2];
    v19[3] = a6[3];
    v19 += 4;
  }
  RtlCopySid(v15, (int)v19, (int)a7);
  ++*((_WORD *)a1 + 2);
  *a1 = 4;
  return 0;
}
