// RtlCaptureContext 
 
int __fastcall RtlCaptureContext(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // r12
  int v6; // lr
  __int64 v7; // d0
  __int64 v8; // d1
  __int64 v9; // d2
  __int64 v10; // d3
  __int64 v11; // d4
  __int64 v12; // d5
  __int64 v13; // d6
  __int64 v14; // d7
  __int64 v15; // d8
  __int64 v16; // d9
  __int64 v17; // d10
  __int64 v18; // d11
  __int64 v19; // d12
  __int64 v20; // d13
  __int64 v21; // d14
  __int64 v22; // d15
  __int64 v23; // d16
  __int64 v24; // d17
  __int64 v25; // d18
  __int64 v26; // d19
  __int64 v27; // d20
  __int64 v28; // d21
  __int64 v29; // d22
  __int64 v30; // d23
  __int64 v31; // d24
  __int64 v32; // d25
  __int64 v33; // d26
  __int64 v34; // d27
  __int64 v35; // d28
  __int64 v36; // d29
  __int64 v37; // d30
  __int64 v38; // d31
  int *v39; // r0
  int v40; // r0
  int v41; // r2
  int v42; // r12
  int v43; // r1
  __int64 v49; // t1

  a1[13] = v5;
  a1[16] = v6;
  a1[17] = __get_CPSR() | 0x20;
  v39 = a1 + 2;
  *v39 = a2;
  v39[1] = a3;
  v39[2] = a4;
  v40 = (int)(v39 - 2);
  v41 = 0;
  *(_DWORD *)(v40 + 4) = 0;
  *(_DWORD *)(v40 + 60) = 0;
  *(_DWORD *)(v40 + 72) = 0;
  v42 = v40 + 80;
  v43 = __mrc(15, 0, 1, 0, 2);
  if ( (v43 & 0xF00000) != 0 )
  {
    __asm { VMRS            R3, FPSCR }
    *(_DWORD *)(v40 + 72) = _R3;
    *(_QWORD *)v42 = v7;
    *(_QWORD *)(v40 + 88) = v8;
    *(_QWORD *)(v40 + 96) = v9;
    *(_QWORD *)(v40 + 104) = v10;
    *(_QWORD *)(v40 + 112) = v11;
    *(_QWORD *)(v40 + 120) = v12;
    *(_QWORD *)(v40 + 128) = v13;
    *(_QWORD *)(v40 + 136) = v14;
    *(_QWORD *)(v40 + 144) = v15;
    *(_QWORD *)(v40 + 152) = v16;
    *(_QWORD *)(v40 + 160) = v17;
    *(_QWORD *)(v40 + 168) = v18;
    *(_QWORD *)(v40 + 176) = v19;
    *(_QWORD *)(v40 + 184) = v20;
    *(_QWORD *)(v40 + 192) = v21;
    *(_QWORD *)(v40 + 200) = v22;
    *(_QWORD *)(v40 + 208) = v23;
    *(_QWORD *)(v40 + 216) = v24;
    *(_QWORD *)(v40 + 224) = v25;
    *(_QWORD *)(v40 + 232) = v26;
    *(_QWORD *)(v40 + 240) = v27;
    *(_QWORD *)(v40 + 248) = v28;
    *(_QWORD *)(v40 + 256) = v29;
    *(_QWORD *)(v40 + 264) = v30;
    *(_QWORD *)(v40 + 272) = v31;
    *(_QWORD *)(v40 + 280) = v32;
    *(_QWORD *)(v40 + 288) = v33;
    *(_QWORD *)(v40 + 296) = v34;
    *(_QWORD *)(v40 + 304) = v35;
    *(_QWORD *)(v40 + 312) = v36;
    *(_QWORD *)(v40 + 320) = v37;
    *(_QWORD *)(v40 + 328) = v38;
  }
  else
  {
    v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    _R3 = 32;
    if ( v43 && (v43 = *(_DWORD *)(v43 + 320)) != 0 )
    {
      *(_DWORD *)(v40 + 72) = 0;
      v43 += 16;
      do
      {
        --_R3;
        v49 = *(_QWORD *)v43;
        v43 += 8;
        v41 = v49;
        *(_QWORD *)v42 = v49;
        v42 += 8;
      }
      while ( _R3 );
    }
    else
    {
      do
      {
        --_R3;
        *(_DWORD *)v42 = 0;
        *(_DWORD *)(v42 + 4) = 0;
        v42 += 8;
      }
      while ( _R3 );
    }
  }
  return CcSaveNVContext(v40, v43, v41, _R3, a5);
}
