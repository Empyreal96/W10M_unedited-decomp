// PfSnLogVolumeCreate 
 
int __fastcall PfSnLogVolumeCreate(unsigned int *a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r7
  unsigned int *v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // r4
  int v11; // r3
  int v12; // r2
  int v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r3
  unsigned int *v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  unsigned int *v19; // [sp+0h] [bp-20h] BYREF
  int v20; // [sp+4h] [bp-1Ch]
  int v21; // [sp+8h] [bp-18h] BYREF
  int v22; // [sp+Ch] [bp-14h]

  v19 = a1;
  v20 = a2;
  v21 = a3;
  v22 = a4;
  v5 = 2 * *((unsigned __int16 *)a1 + 11);
  v6 = PfSnLogHelper(*a1, (unsigned int)(v5 + 69) >> 3, &v19);
  if ( !v6 )
    return sub_7E8BC0();
  v8 = v19;
  *v19 = 0;
  *v8 = (8 * (((unsigned int)(v5 + 69) >> 3) - 1)) | 5;
  v9 = a1[1];
  LOWORD(v19) = v5;
  HIWORD(v19) = v5;
  v8[1] = v9;
  v10 = ((unsigned int)v8 + 15) & 0xFFFFFFF8;
  *(_DWORD *)v10 = 0;
  v22 = v10 + 44;
  LOWORD(v21) = 0;
  v11 = a1[7];
  HIWORD(v21) = v5;
  v12 = *(_DWORD *)v10;
  v20 = v11;
  *(_DWORD *)v10 = v12 & 0x80000002 | (8 * ((v5 + 54) & 0xFFFFFFF)) | 2;
  v13 = *(_DWORD *)(v10 + 32);
  *(_DWORD *)(v10 + 4) = a1[9];
  *(_DWORD *)(v10 + 8) = a1[10];
  *(_DWORD *)(v10 + 24) = a1[1];
  v14 = v13 & 0xFFFFFFF0 | a1[8] & 0xF;
  *(_DWORD *)(v10 + 32) = v14;
  *(_DWORD *)(v10 + 32) = ((unsigned __int8)a1[8] ^ (unsigned __int8)v14) & 0xF0 ^ v14;
  *(_DWORD *)(v10 + 16) = a1[2];
  *(_DWORD *)(v10 + 20) = a1[3];
  v15 = a1[4];
  *(_WORD *)(v10 + 36) = v5;
  *(_WORD *)(v10 + 38) = v5;
  *(_DWORD *)(v10 + 28) = v15;
  RtlUpcaseUnicodeString(&v21, &v19, 0);
  *(_WORD *)(v10 + 2 * *((unsigned __int16 *)a1 + 11) + 44) = 0;
  v16 = (unsigned int *)(v6 + 268);
  __pld((void *)(v6 + 268));
  v17 = *(_DWORD *)(v6 + 268) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v18 = __ldrex(v16);
  while ( v18 == v17 && __strex(v17 - 2, v16) );
  if ( v18 != v17 )
    ExfReleaseRundownProtection((unsigned __int8 *)v16);
  return 0;
}
