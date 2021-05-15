// RtlCaptureContext 
 
int __fastcall RtlCaptureContext(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r12
  int v5; // lr
  __int64 v6; // d0
  __int64 v7; // d1
  __int64 v8; // d2
  __int64 v9; // d3
  __int64 v10; // d4
  __int64 v11; // d5
  __int64 v12; // d6
  __int64 v13; // d7
  __int64 v14; // d8
  __int64 v15; // d9
  __int64 v16; // d10
  __int64 v17; // d11
  __int64 v18; // d12
  __int64 v19; // d13
  __int64 v20; // d14
  __int64 v21; // d15
  __int64 v22; // d16
  __int64 v23; // d17
  __int64 v24; // d18
  __int64 v25; // d19
  __int64 v26; // d20
  __int64 v27; // d21
  __int64 v28; // d22
  __int64 v29; // d23
  __int64 v30; // d24
  __int64 v31; // d25
  __int64 v32; // d26
  __int64 v33; // d27
  __int64 v34; // d28
  __int64 v35; // d29
  __int64 v36; // d30
  __int64 v37; // d31
  _DWORD *v38; // r0
  _DWORD *v39; // r0
  _DWORD *v40; // r12
  unsigned int v46; // r1
  int v47; // r3
  int v48; // r1
  __int64 *v49; // r1
  __int64 v50; // t1

  a1[13] = v4;
  a1[16] = v5;
  a1[17] = __get_CPSR() | 0x20;
  v38 = a1 + 2;
  *v38 = a2;
  v38[1] = a3;
  v38[2] = a4;
  v39 = v38 - 2;
  v39[1] = 0;
  v39[15] = 0;
  v39[18] = 0;
  v40 = v39 + 20;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    __asm { VMRS            R3, FPSCR }
    v39[18] = _R3;
    *(_QWORD *)v40 = v6;
    *((_QWORD *)v39 + 11) = v7;
    *((_QWORD *)v39 + 12) = v8;
    *((_QWORD *)v39 + 13) = v9;
    *((_QWORD *)v39 + 14) = v10;
    *((_QWORD *)v39 + 15) = v11;
    *((_QWORD *)v39 + 16) = v12;
    *((_QWORD *)v39 + 17) = v13;
    *((_QWORD *)v39 + 18) = v14;
    *((_QWORD *)v39 + 19) = v15;
    *((_QWORD *)v39 + 20) = v16;
    *((_QWORD *)v39 + 21) = v17;
    *((_QWORD *)v39 + 22) = v18;
    *((_QWORD *)v39 + 23) = v19;
    *((_QWORD *)v39 + 24) = v20;
    *((_QWORD *)v39 + 25) = v21;
    *((_QWORD *)v39 + 26) = v22;
    *((_QWORD *)v39 + 27) = v23;
    *((_QWORD *)v39 + 28) = v24;
    *((_QWORD *)v39 + 29) = v25;
    *((_QWORD *)v39 + 30) = v26;
    *((_QWORD *)v39 + 31) = v27;
    *((_QWORD *)v39 + 32) = v28;
    *((_QWORD *)v39 + 33) = v29;
    *((_QWORD *)v39 + 34) = v30;
    *((_QWORD *)v39 + 35) = v31;
    *((_QWORD *)v39 + 36) = v32;
    *((_QWORD *)v39 + 37) = v33;
    *((_QWORD *)v39 + 38) = v34;
    *((_QWORD *)v39 + 39) = v35;
    *((_QWORD *)v39 + 40) = v36;
    *((_QWORD *)v39 + 41) = v37;
  }
  else
  {
    v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v47 = 32;
    if ( v46 && (v48 = *(_DWORD *)(v46 + 320)) != 0 )
    {
      v39[18] = 0;
      v49 = (__int64 *)(v48 + 16);
      do
      {
        --v47;
        v50 = *v49++;
        *(_QWORD *)v40 = v50;
        v40 += 2;
      }
      while ( v47 );
    }
    else
    {
      do
      {
        --v47;
        *v40 = 0;
        v40[1] = 0;
        v40 += 2;
      }
      while ( v47 );
    }
  }
  return CcSaveNVContext();
}
