// ObpAllocateObject 
 
int __fastcall ObpAllocateObject(_DWORD *a1, char a2, int a3, _DWORD *a4, int a5, int *a6, _BYTE *a7)
{
  char v8; // r7
  _WORD *v9; // r8
  int v12; // r2
  int v13; // r2
  int v14; // r10
  int v15; // r2
  int v16; // lr
  int v17; // r0
  int v18; // r9
  int v19; // r2
  int v20; // r8
  unsigned int v21; // r1
  int v22; // r0
  int v23; // r3
  char v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r1
  unsigned int v27; // r2
  int v28; // r3
  int v29; // r2
  int v30; // r3
  int v31; // r3
  int v32; // [sp+0h] [bp-40h]
  int v33; // [sp+Ch] [bp-34h]
  int v34; // [sp+10h] [bp-30h]
  int v35; // [sp+14h] [bp-2Ch]
  int v37; // [sp+1Ch] [bp-24h]

  v8 = 0;
  v9 = a4;
  v37 = a2;
  if ( (*a1 & 0x20) != 0 )
  {
    v32 = 8;
    v8 = 16;
  }
  else
  {
    v32 = 0;
  }
  if ( SeAuditHeaderRequired((void *)a3) )
    return sub_7FF408();
  v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v12 == PsInitialSystemProcess
    || (v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v13 == PsIdleProcess)
    || !PsInitialSystemProcess )
  {
    v14 = 0;
  }
  else
  {
    v14 = 16;
    v8 |= 8u;
  }
  v15 = *(unsigned __int8 *)(a3 + 42);
  if ( (v15 & 0x10) != 0 )
  {
    v16 = 8;
    v8 |= 4u;
  }
  else
  {
    v16 = 0;
  }
  if ( *v9 )
  {
    if ( (v15 & 2) != 0 )
      return -1073741773;
    v17 = 16;
    v8 |= 2u;
  }
  else
  {
    v17 = 0;
  }
  v33 = v17;
  v18 = 0;
  if ( (v15 & 0xFFFFFF80) != 0 )
    v18 = 120;
  if ( (v15 & 0x20) != 0 )
  {
    v19 = 16;
    v8 |= 1u;
  }
  else
  {
    v19 = 0;
  }
  v34 = v19;
  if ( a7 && *a7 )
  {
    v20 = 16;
    v8 |= 0x40u;
  }
  else
  {
    v20 = 0;
  }
  v35 = v20 + v19 + v17 + v16 + v14 + v32 + 24;
  v21 = v18 + v35 + a5;
  if ( v21 < v18 + v35 )
    return -1073741811;
  v22 = ExAllocatePoolWithTag(*(_DWORD *)(a3 + 76), v21, *(_DWORD *)(a3 + 132));
  if ( !v22 )
    return -1073741670;
  if ( v18 )
  {
    v29 = (unsigned __int8)-(char)(v35 + v22);
    v30 = (unsigned __int8)(v29 - ((unsigned __int8)(v29 >> 7) << 7));
    if ( (_BYTE)v29 != (unsigned __int8)(v29 >> 7) << 7 )
    {
      v22 += v30;
      *(_DWORD *)(v22 - 4) = v30;
      v8 |= 0x80u;
    }
  }
  if ( v20 )
  {
    *(_DWORD *)v22 = 0;
    *(_DWORD *)(v22 + 4) = 0;
    *(_DWORD *)(v22 + 8) = 0;
    *(_DWORD *)(v22 + 12) = 0;
    v22 += 16;
  }
  if ( v32 )
  {
    *(_DWORD *)v22 = 0;
    v22 += 8;
  }
  if ( v14 )
  {
    *(_DWORD *)v22 = a1[3];
    *(_DWORD *)(v22 + 4) = a1[4];
    *(_DWORD *)(v22 + 8) = a1[5];
    *(_DWORD *)(v22 + 12) = 0;
    v22 += 16;
  }
  if ( v16 )
  {
    v23 = *(_DWORD *)(v22 + 4);
    *(_DWORD *)v22 = 0;
    *(_DWORD *)(v22 + 4) = v23 & 0xFF000000;
    *(_BYTE *)(v22 + 7) = 0;
    v22 += 8;
  }
  if ( v33 )
  {
    *(_DWORD *)(v22 + 4) = *a4;
    v28 = a4[1];
    *(_DWORD *)v22 = 0;
    *(_DWORD *)(v22 + 8) = v28;
    *(_DWORD *)(v22 + 12) = 0;
    v22 += 16;
  }
  if ( v34 )
  {
    *(_WORD *)(v22 + 12) = 0;
    v31 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
    *(_DWORD *)(v22 + 4) = v22;
    *(_DWORD *)(v22 + 8) = v31;
    *(_DWORD *)v22 = v22;
    v22 += 16;
  }
  *(_BYTE *)(v22 + 15) = 1;
  *(_BYTE *)(v22 + 14) = v8;
  *(_BYTE *)(v22 + 13) = 0;
  if ( v16 )
    *(_BYTE *)(v22 + 15) = 65;
  *(_DWORD *)v22 = 1;
  *(_DWORD *)(v22 + 4) = 0;
  *(_DWORD *)(v22 + 8) = 0;
  *(_BYTE *)(v22 + 12) = ObHeaderCookie ^ *(_BYTE *)(a3 + 20) ^ BYTE1(v22);
  if ( !v37 )
  {
    v24 = *(_BYTE *)(v22 + 15) | 2;
    *(_BYTE *)(v22 + 15) = v24;
    if ( (*a1 & 0x10000) != 0 )
      *(_BYTE *)(v22 + 15) = v24 | 4;
  }
  if ( (*a1 & 0x10) != 0 )
    *(_BYTE *)(v22 + 15) |= 0x10u;
  if ( (*a1 & 0x20) != 0 )
    *(_BYTE *)(v22 + 15) |= 8u;
  *(_DWORD *)(v22 + 16) = a1;
  *(_DWORD *)(v22 + 20) = 0;
  __dmb(0xBu);
  v25 = (unsigned int *)(a3 + 24);
  do
    v26 = __ldrex(v25);
  while ( __strex(v26 + 1, v25) );
  __dmb(0xBu);
  v27 = *(_DWORD *)(a3 + 24);
  if ( v27 > *(_DWORD *)(a3 + 32) )
    *(_DWORD *)(a3 + 32) = v27;
  *a6 = v22;
  return 0;
}
