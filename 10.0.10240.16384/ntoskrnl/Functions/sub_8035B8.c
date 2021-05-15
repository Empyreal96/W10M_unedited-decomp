// sub_8035B8 
 
int sub_8035B8()
{
  int *v0; // r2
  int v1; // r3
  int v3; // r0
  int v4; // r2
  int v5; // r3
  int v6; // r5
  _DWORD *v7; // r10
  int v8; // r9
  unsigned int v9; // r5
  int v10; // r2
  int v11; // r4
  int v12; // r0
  int v14; // r4
  int v15; // r6
  int v16; // r7
  int v17; // r9
  _DWORD *v18; // r8
  int i; // r2
  char v20[8]; // [sp+20h] [bp-208h] BYREF
  int v21; // [sp+28h] [bp-200h] BYREF
  unsigned int v22; // [sp+2Ch] [bp-1FCh] BYREF
  unsigned int v23[2]; // [sp+30h] [bp-1F8h] BYREF
  _DWORD v24[4]; // [sp+38h] [bp-1F0h] BYREF
  char v25[8]; // [sp+48h] [bp-1E0h] BYREF
  int v26; // [sp+50h] [bp-1D8h] BYREF
  int v27; // [sp+54h] [bp-1D4h]
  int v28; // [sp+58h] [bp-1D0h]
  int v29; // [sp+5Ch] [bp-1CCh]
  int v30[5]; // [sp+60h] [bp-1C8h] BYREF
  char v31; // [sp+74h] [bp-1B4h] BYREF
  char v32; // [sp+78h] [bp-1B0h] BYREF
  char v33; // [sp+7Ch] [bp-1ACh] BYREF
  char v34; // [sp+80h] [bp-1A8h] BYREF
  char v35; // [sp+84h] [bp-1A4h] BYREF
  char v36; // [sp+88h] [bp-1A0h] BYREF
  char v37; // [sp+8Ch] [bp-19Ch] BYREF
  char v38; // [sp+90h] [bp-198h] BYREF
  unsigned int v39; // [sp+98h] [bp-190h]
  int v40; // [sp+9Ch] [bp-18Ch]
  int v41; // [sp+A0h] [bp-188h]
  int (*v42)(void); // [sp+224h] [bp-4h]

  v18 = *(_DWORD **)(v14 + 96);
  if ( !v18 || (v18[33] & 0x1F) != 19 )
  {
LABEL_28:
    v1 = -1073741823;
    goto LABEL_10;
  }
  v3 = KiGetVfpStatePointer(*(_DWORD *)(v14 + 96));
  v5 = *(unsigned __int8 *)(v16 + 49);
  v6 = v3;
  if ( (v5 & 2) != 0 )
  {
    if ( RtlpGetStackLimits((int)&v22, (int)v23, v4, v5) )
    {
      v7 = 0;
      v8 = 0;
      v21 = 0;
      v24[0] = 0;
      v24[1] = 0;
      v24[2] = 0;
      v24[3] = 0;
      RtlpCaptureContext((int)v30);
      *(_DWORD *)v15 = &v31;
      *(_DWORD *)(v15 + 4) = &v32;
      *(_DWORD *)(v15 + 8) = &v33;
      *(_DWORD *)(v15 + 12) = &v34;
      *(_DWORD *)(v15 + 16) = &v35;
      *(_DWORD *)(v15 + 20) = &v36;
      *(_DWORD *)(v15 + 24) = &v37;
      *(_DWORD *)(v15 + 28) = &v38;
      *(_DWORD *)(v15 + 36) = v6 + 80;
      *(_DWORD *)(v15 + 40) = v6 + 88;
      *(_DWORD *)(v15 + 44) = v6 + 96;
      *(_DWORD *)(v15 + 48) = v6 + 104;
      *(_DWORD *)(v15 + 52) = v6 + 112;
      *(_DWORD *)(v15 + 56) = v6 + 120;
      *(_DWORD *)(v15 + 60) = v6 + 128;
      *(_DWORD *)(v15 + 64) = v6 + 136;
      if ( !v6 )
      {
        *(_DWORD *)(v15 + 64) = v20;
        *(_DWORD *)(v15 + 60) = v20;
        *(_DWORD *)(v15 + 56) = v20;
        *(_DWORD *)(v15 + 52) = v20;
        *(_DWORD *)(v15 + 48) = v20;
        *(_DWORD *)(v15 + 44) = v20;
        *(_DWORD *)(v15 + 40) = v20;
        *(_DWORD *)(v15 + 36) = v20;
      }
      v26 = dword_616490[0];
      v27 = dword_616494;
      v28 = dword_616498;
      v29 = *(_DWORD *)algn_61649C;
      v9 = 0;
      while ( RtlpIsFrameInBoundsEx(&v22, v39, v23, v24) )
      {
        v11 = v41;
        if ( (v30[0] & 0x20000000) != 0 )
          v11 = v41 - 2;
        v12 = RtlpLookupFunctionEntryForStackWalks(v11, &v26, v10, v30[0]);
        if ( v12 )
        {
          v7 = (_DWORD *)v8;
          if ( RtlpVirtualUnwind(v12, v27, v11, v12, (int)v30, (int)v25, (int)&v21) < 0 )
            goto LABEL_28;
          v8 = v21;
        }
        else
        {
          if ( !v27 || v41 == v40 )
            goto LABEL_28;
          v41 = v40;
        }
        if ( v9++ >= 0x3C00 )
          goto LABEL_28;
        if ( v7 == v18 )
          goto LABEL_7;
      }
    }
    goto LABEL_28;
  }
  for ( i = *(_DWORD *)(v14 + 32); (*(_DWORD *)(i + 4) & v17) != 0; i = *(_DWORD *)(i + 20) )
    ;
  *(_DWORD *)v15 = i - 444;
  *(_DWORD *)(v15 + 4) = i - 440;
  *(_DWORD *)(v15 + 8) = i - 436;
  *(_DWORD *)(v15 + 12) = i - 432;
  *(_DWORD *)(v15 + 16) = i - 428;
  *(_DWORD *)(v15 + 20) = i - 424;
  *(_DWORD *)(v15 + 24) = i - 420;
  *(_DWORD *)(v15 + 28) = i - 416;
  *(_DWORD *)(v15 + 36) = v3 + 80;
  *(_DWORD *)(v15 + 40) = v3 + 88;
  *(_DWORD *)(v15 + 44) = v3 + 96;
  *(_DWORD *)(v15 + 48) = v3 + 104;
  *(_DWORD *)(v15 + 52) = v3 + 112;
  *(_DWORD *)(v15 + 56) = v3 + 120;
  *(_DWORD *)(v15 + 60) = v3 + 128;
  *(_DWORD *)(v15 + 64) = v3 + 136;
  if ( !v3 )
  {
    *(_DWORD *)(v15 + 64) = v20;
    *(_DWORD *)(v15 + 60) = v20;
    *(_DWORD *)(v15 + 56) = v20;
    *(_DWORD *)(v15 + 52) = v20;
    *(_DWORD *)(v15 + 48) = v20;
    *(_DWORD *)(v15 + 44) = v20;
    *(_DWORD *)(v15 + 40) = v20;
    *(_DWORD *)(v15 + 36) = v20;
  }
  *(_DWORD *)(v15 + 28) = v18 + 31;
LABEL_7:
  v0 = *(int **)(v16 + 72);
  if ( v23[1] )
    PspSetContext((int)v18, v15, v0, *(_BYTE *)(v16 + 48));
  else
    PspGetContext(v18, (int **)v15, v0);
  v1 = 0;
LABEL_10:
  *(_DWORD *)(v16 + 52) = v1;
  if ( (*(_BYTE *)(v16 + 49) & 1) != 0 )
    KeSignalGate(v16 + 56, 1);
  return v42();
}
