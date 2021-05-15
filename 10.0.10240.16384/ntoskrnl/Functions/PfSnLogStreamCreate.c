// PfSnLogStreamCreate 
 
int __fastcall PfSnLogStreamCreate(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r9
  unsigned int *v10; // r2
  unsigned int v11; // r5
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r2
  unsigned int v16; // r2
  int v17; // r5
  unsigned int *v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r1
  unsigned int *v22; // [sp+0h] [bp-28h] BYREF
  int v23; // [sp+4h] [bp-24h]
  int v24; // [sp+8h] [bp-20h] BYREF
  int v25; // [sp+Ch] [bp-1Ch]

  v22 = (unsigned int *)a1;
  v23 = a2;
  v24 = a3;
  v25 = a4;
  v5 = *(unsigned __int16 *)(a1 + 16);
  v6 = *(unsigned __int16 *)(a1 + 18);
  if ( v6 <= v5 )
    return -1073741637;
  v7 = v6 - v5;
  v8 = 2 * (v6 - v5 + 25);
  v9 = PfSnLogHelper(*(_DWORD *)a1, (unsigned int)(v8 + 7) >> 3, &v22);
  if ( !v9 )
    return -1073741446;
  v10 = v22;
  *v22 = 0;
  *v10 = (8 * (((unsigned int)(v8 + 7) >> 3) - 1)) | 5;
  v10[1] = *(_DWORD *)(a1 + 8);
  v11 = ((unsigned int)v10 + 15) & 0xFFFFFFF8;
  *(_DWORD *)v11 = 0;
  v25 = v11 + 32;
  v12 = *(unsigned __int16 *)(a1 + 16);
  LOWORD(v24) = 0;
  v13 = *(_DWORD *)(a1 + 12);
  HIWORD(v24) = 2 * v7;
  LOWORD(v22) = 2 * v7;
  v23 = v13 + 2 * v12;
  v14 = *(_DWORD *)v11;
  HIWORD(v22) = 2 * v7;
  *(_DWORD *)v11 = v14 & 0x80000000 | (8 * ((v8 - 8) & 0xFFFFFFF));
  v15 = *(_DWORD *)(v11 + 28);
  *(_DWORD *)(v11 + 4) = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(v11 + 8) = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(v11 + 20) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v11 + 24) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(v11 + 16) = *(_DWORD *)(a1 + 8);
  v16 = v15 & 0xFFFFFFFE | *(_DWORD *)(a1 + 20) & 1;
  *(_DWORD *)(v11 + 28) = v16;
  *(_DWORD *)(v11 + 28) = ((unsigned __int8)v16 ^ (unsigned __int8)(2 * *(_BYTE *)(a1 + 20))) & 4 ^ v16;
  *(_WORD *)(v11 + 30) = v7;
  RtlUpcaseUnicodeString(&v24, &v22, 0);
  *(_WORD *)(2 * v7 + v11 + 32) = 0;
  v17 = 0;
  v18 = (unsigned int *)(v9 + 268);
  __pld((void *)(v9 + 268));
  v19 = *(_DWORD *)(v9 + 268) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v20 = __ldrex(v18);
  while ( v20 == v19 && __strex(v19 - 2, v18) );
  if ( v20 != v19 )
    ExfReleaseRundownProtection((unsigned __int8 *)v18);
  return v17;
}
