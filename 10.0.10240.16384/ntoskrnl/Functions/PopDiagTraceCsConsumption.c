// PopDiagTraceCsConsumption 
 
int __fastcall PopDiagTraceCsConsumption(int a1, int a2, int a3, int a4, int a5, __int16 a6)
{
  unsigned __int64 v7; // r6
  __int64 v8; // r8
  char v9; // r10
  unsigned int v10; // r5
  char v11; // r0
  __int64 v12; // kr68_8
  char v13; // r0
  __int64 v14; // kr70_8
  char v15; // r0
  __int64 v16; // kr78_8
  char v17; // r0
  __int64 v18; // kr80_8
  char v19; // r0
  unsigned __int64 v20; // r2
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int *v24; // r2
  char *v25; // r3
  int v26; // r1
  int v28; // [sp+8h] [bp-70h] BYREF
  __int16 v29; // [sp+Ch] [bp-6Ch]
  char v30; // [sp+Eh] [bp-6Ah]
  char v31; // [sp+Fh] [bp-69h]
  __int16 v32; // [sp+10h] [bp-68h]
  char v33; // [sp+12h] [bp-66h]
  char v34; // [sp+13h] [bp-65h]
  char v35; // [sp+14h] [bp-64h]
  char v36; // [sp+15h] [bp-63h]
  char v37; // [sp+16h] [bp-62h]
  char v38; // [sp+17h] [bp-61h]
  char v39; // [sp+18h] [bp-60h] BYREF

  v30 = 0;
  v31 = 0;
  v33 = 0;
  v34 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v7 = *(_QWORD *)(a1 + 16);
  v8 = *(_QWORD *)(a1 + 96);
  v9 = *(_BYTE *)(a1 + 92);
  v28 = *(_DWORD *)a1;
  v10 = *(_DWORD *)(a1 + 40);
  v29 = _rt_udiv64(60000000i64, v7);
  if ( v7 )
  {
    v11 = _rt_udiv64(v7, 100i64 * *(_QWORD *)(a1 + 24));
    v12 = *(_QWORD *)(a1 + 32);
    v30 = v11;
    v13 = _rt_udiv64(v7, 100 * v12);
    v14 = *(_QWORD *)(a1 + 48);
    v31 = v13;
    v15 = _rt_udiv64(v7, 100 * v14);
    v16 = *(_QWORD *)(a1 + 56);
    v33 = v15;
    v17 = _rt_udiv64(v7, 100 * v16);
    v18 = *(_QWORD *)(a1 + 64);
    v34 = v17;
    v19 = _rt_udiv64(v7, 100 * v18);
    v20 = 100i64 * *(_QWORD *)(a1 + 72);
    v36 = v19;
    v21 = _rt_udiv64(v7, v20);
    v37 = v21;
    if ( ((unsigned int)v8 & HIDWORD(v8)) == -1 )
      return sub_7BF2C0(v21, v22, v23, -1, a5, a6);
    v38 = _rt_udiv64(v7, 100 * v8);
  }
  if ( v10 > 0xFFFF )
    LOWORD(v10) = -1;
  v24 = &v28;
  v25 = &v39;
  v26 = 4;
  v32 = v10;
  v35 = v9;
  do
  {
    *(_DWORD *)v25 = v24;
    *((_DWORD *)v25 + 1) = 0;
    *((_DWORD *)v25 + 2) = 4;
    *((_DWORD *)v25 + 3) = 0;
    v25 += 16;
    ++v24;
    --v26;
  }
  while ( v26 );
  return EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_CS_CONSUMPTION_PERFTRACK, 0);
}
