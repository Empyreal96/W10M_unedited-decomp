// LogVfpState 
 
int __fastcall LogVfpState(int a1)
{
  __int64 v1; // d0
  __int64 v2; // d1
  __int64 v3; // d2
  __int64 v4; // d3
  __int64 v5; // d4
  __int64 v6; // d5
  __int64 v7; // d6
  __int64 v8; // d7
  __int64 v9; // d8
  __int64 v10; // d9
  __int64 v11; // d10
  __int64 v12; // d11
  __int64 v13; // d12
  __int64 v14; // d13
  __int64 v15; // d14
  __int64 v16; // d15
  __int64 v17; // d16
  __int64 v18; // d17
  __int64 v19; // d18
  __int64 v20; // d19
  __int64 v21; // d20
  __int64 v22; // d21
  __int64 v23; // d22
  __int64 v24; // d23
  __int64 v25; // d24
  __int64 v26; // d25
  __int64 v27; // d26
  __int64 v28; // d27
  __int64 v29; // d28
  __int64 v30; // d29
  __int64 v31; // d30
  __int64 v32; // d31
  _QWORD *v38; // r0
  int result; // r0
  unsigned int v40; // r2
  int v41; // r2
  _QWORD *v42; // r0
  __int64 *v43; // r2
  int v44; // r3
  __int64 v45; // t1

  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    __asm { VMRS            R2, FPSCR }
    *(_DWORD *)(a1 + 4) = _R2;
    v38 = (_QWORD *)(a1 + 16);
    *v38 = v1;
    v38[1] = v2;
    v38[2] = v3;
    v38[3] = v4;
    v38[4] = v5;
    v38[5] = v6;
    v38[6] = v7;
    v38[7] = v8;
    v38[8] = v9;
    v38[9] = v10;
    v38[10] = v11;
    v38[11] = v12;
    v38[12] = v13;
    v38[13] = v14;
    v38[14] = v15;
    v38[15] = v16;
    v38 += 16;
    *v38 = v17;
    v38[1] = v18;
    v38[2] = v19;
    v38[3] = v20;
    v38[4] = v21;
    v38[5] = v22;
    v38[6] = v23;
    v38[7] = v24;
    v38[8] = v25;
    v38[9] = v26;
    v38[10] = v27;
    v38[11] = v28;
    v38[12] = v29;
    v38[13] = v30;
    v38[14] = v31;
    v38[15] = v32;
    result = 0;
  }
  else
  {
    v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v40 && (v41 = *(_DWORD *)(v40 + 320)) != 0 )
    {
      *(_DWORD *)(a1 + 4) = *(_DWORD *)(v41 + 4);
      v42 = (_QWORD *)(a1 + 16);
      v43 = (__int64 *)(v41 + 16);
      v44 = 32;
      do
      {
        --v44;
        v45 = *v43++;
        *v42++ = v45;
      }
      while ( v44 );
      result = 0;
    }
    else
    {
      result = -1;
    }
  }
  return result;
}
