// EtwpFindDebugId 
 
int __fastcall EtwpFindDebugId(unsigned int a1, unsigned int a2, int *a3, unsigned int *a4)
{
  unsigned int v6; // r5
  _DWORD *v7; // r6
  unsigned int v9; // r3
  int v10; // lr
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int *v15; // r6
  unsigned int v16; // r2
  int v17; // r3
  unsigned int v18; // r6
  unsigned int v19; // r4
  unsigned int *v20; // r5
  int v21; // r0
  int *v22; // r3
  unsigned int v24; // [sp+4h] [bp-54h] BYREF
  unsigned int *v25; // [sp+8h] [bp-50h]
  unsigned int v26; // [sp+Ch] [bp-4Ch]
  _DWORD *v27; // [sp+10h] [bp-48h]
  int v28; // [sp+18h] [bp-40h]
  int v29; // [sp+1Ch] [bp-3Ch]
  int v30; // [sp+20h] [bp-38h]
  int v31; // [sp+24h] [bp-34h]
  unsigned int v32; // [sp+28h] [bp-30h]
  unsigned int v33; // [sp+2Ch] [bp-2Ch]
  int v34; // [sp+30h] [bp-28h]

  v25 = a4;
  v6 = 0;
  v24 = 0;
  v7 = (_DWORD *)RtlImageDirectoryEntryToData(a1, 1, 6, (int)&v24);
  v27 = v7;
  if ( !v7 || v24 < 0x1C )
    return -1073741811;
  v9 = ((613566757 * (unsigned __int64)v24) >> 32)
     + ((unsigned int)(v24 - ((613566757 * (unsigned __int64)v24) >> 32)) >> 1);
  v24 = v9;
  v26 = 0;
  while ( 1 )
  {
    if ( v6 >= v9 >> 4 )
      return -1073741275;
    if ( (unsigned int)v7 < a1 )
      return -1073741811;
    v10 = (int)(v7 + 7);
    if ( (unsigned int)(v7 + 7) > a1 + a2 )
      return -1073741811;
    v11 = *v7;
    v12 = v7[1];
    v13 = v7[2];
    v14 = v7[3];
    v15 = v7 + 4;
    v28 = v11;
    v29 = v12;
    v30 = v13;
    v31 = v14;
    v16 = v15[1];
    v17 = v15[2];
    v32 = *v15;
    v33 = v16;
    v34 = v17;
    v18 = v16;
    if ( v16 > a2 )
      return -1073741811;
    v19 = v32;
    if ( v32 > a2 || v16 > a2 - v32 )
      return -1073741811;
    if ( v31 == 2 && *(_DWORD *)(a1 + v16) == 1396986706 )
      break;
    v7 = (_DWORD *)v10;
    v27 = (_DWORD *)v10;
    v26 = ++v6;
    v9 = v24;
  }
  v20 = v25;
  if ( *v25 >= v32 )
  {
    v22 = a3;
  }
  else
  {
    v21 = ExAllocatePoolWithTag(1, v32, 1651995717);
    v22 = a3;
    *a3 = v21;
    if ( !v21 )
      return -1073741801;
  }
  *v20 = v19;
  memmove(*v22, a1 + v18, v19);
  return 0;
}
