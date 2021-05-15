// MiPrefetchVirtualMemory 
 
int __fastcall MiPrefetchVirtualMemory(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v5; // r2
  int v6; // r10
  unsigned int v7; // r8
  unsigned int v8; // r3
  unsigned int v9; // r4
  unsigned int v10; // r5
  _DWORD *v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v15; // r6
  int *v16; // r2
  unsigned int v17; // r3
  int v18; // r3
  bool v19; // zf
  unsigned int v20; // r6
  unsigned int v21; // r7
  int v22; // r9
  __int16 v23; // r2
  int v24; // r0
  __int16 v25; // r3
  int v26; // r0
  int v27; // r1
  int *v28; // r3
  int *i; // r2
  _DWORD v32[2]; // [sp+8h] [bp-48h] BYREF
  unsigned int v33; // [sp+10h] [bp-40h]
  unsigned int v34; // [sp+14h] [bp-3Ch]
  unsigned int v35; // [sp+18h] [bp-38h]
  int v36[2]; // [sp+1Ch] [bp-34h] BYREF
  int v37[2]; // [sp+24h] [bp-2Ch] BYREF
  unsigned int v38; // [sp+2Ch] [bp-24h] BYREF
  int v39; // [sp+30h] [bp-20h]
  int varg_r0; // [sp+58h] [bp+8h]
  int varg_r1; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v33 = a1;
  v36[1] = (int)v36;
  v4 = a3;
  v36[0] = (int)v36;
  v5 = a2;
  v37[1] = (int)v37;
  LOWORD(v32[0]) = 1;
  varg_r3 = a4;
  v37[0] = (int)v37;
  v32[1] = a2;
  v34 = 0;
  v35 = 0;
  v38 = 0;
  v39 = a4;
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(unsigned __int8 *)(v7 + 0x3CE);
  if ( v8 < 2 )
  {
    *(_BYTE *)(v7 + 974) = v8 + 1;
    --*(_WORD *)(v7 + 308);
    v10 = v34;
    v9 = v35;
    while ( 1 )
    {
      if ( v10 >= v33 )
      {
LABEL_42:
        v24 = MiPfCompletePrefetchIos(v36, (int)v37);
        if ( v24 < 0 )
          v6 = v24;
        v25 = *(_WORD *)(v7 + 308) + 1;
        *(_WORD *)(v7 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
          KiCheckForKernelApcDelivery(v24);
        --*(_BYTE *)(v7 + 974);
        return v6;
      }
      v11 = (_DWORD *)(v5 + 8 * v10);
      if ( v9 >= (v11[1] + (*v11 & 0xFFFu) + 4095) >> 12 )
        goto LABEL_79;
      if ( !v11[1] )
      {
        v34 = v33;
        v35 = 0;
        goto LABEL_42;
      }
      v12 = *v11 + (v9 << 12);
      v13 = v12;
      if ( v12 >= 0xC0400000 )
        return sub_52799C(v12);
      v15 = 0;
      v16 = MiState;
      do
      {
        v17 = v16[2295];
        if ( v12 >= v17 && v12 < ((*(_DWORD *)(v17 + 56) + 4095) & 0xFFFFF000) )
        {
          MiAdvanceFaultList(v32);
          goto LABEL_80;
        }
        ++v15;
        v16 += 32;
      }
      while ( v15 < 3 );
      if ( v12 >= dword_633790 && v12 < ((dword_633798 + 4095) & 0xFFFFF000) )
LABEL_79:
        JUMPOUT(0x5279A6);
      if ( v12 >= 0xC0000000 )
      {
        if ( v12 >= (((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000 )
          goto LABEL_79;
        do
        {
          if ( v13 > 0xC03FFFFF )
            break;
          v13 <<= 10;
        }
        while ( v13 >= 0xC0000000 );
      }
      if ( v13 < dword_63389C )
      {
        if ( v4 == 1 || (*(_BYTE *)(v4 + 112) & 7) != 0 )
          goto LABEL_79;
      }
      else
      {
        v18 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((v13 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
        if ( v18 == 1 || v18 == 11 )
        {
          if ( v4 == 1 )
            goto LABEL_79;
          v19 = (*(_BYTE *)(v4 + 112) & 7) == 1;
        }
        else
        {
          v19 = v4 == 1;
        }
        if ( !v19 )
          goto LABEL_79;
      }
      if ( (v39 & 0x80) == 0 )
      {
        if ( (unsigned int)dword_640580 < 0x100
          || MiCommitmentAvailable((int)MiSystemPartition) < 0x1000
          || dword_640600 < 256 )
        {
          goto LABEL_42;
        }
        v10 = v34;
        v9 = v35;
      }
      v20 = v10;
      v21 = v9;
      v22 = MmAccessFault(0, v12, 0, (int)v32 + 1);
      if ( BYTE1(v32[0]) == 2 )
        break;
      if ( BYTE1(v32[0]) == 1 )
      {
        BYTE1(v32[0]) = 0;
        goto LABEL_32;
      }
      if ( BYTE1(v32[0]) == 3 )
      {
        BYTE1(v32[0]) = 0;
        v34 = v10;
        v35 = v9;
      }
      else
      {
        v10 = v34;
        if ( v34 != v20 )
          goto LABEL_33;
        v9 = v35;
        if ( v35 == v21 )
        {
          MiAdvanceFaultList(v32);
LABEL_32:
          v10 = v34;
LABEL_33:
          v23 = v39;
LABEL_34:
          v9 = v35;
          goto LABEL_35;
        }
      }
      v23 = v39;
LABEL_35:
      if ( v22 < 0 )
      {
        if ( v22 != -1073741819 || v10 == v33 || !MiLeapPrefetch(v32, 0) )
          goto LABEL_42;
        v23 = v39;
        v10 = v34;
        v9 = v35;
      }
      if ( v38 >= 0x200000 )
      {
        MiPfCoalesceAndIssueIOs(v37, v36, &v38);
        v23 = v39;
        v10 = v34;
        v9 = v35;
      }
      v4 = a3;
      v19 = (v23 & 0x400) == 0;
      v5 = a2;
      if ( !v19 )
      {
        v26 = 0;
        v27 = 0;
        while ( 1 )
        {
          if ( v27 )
            v28 = v36;
          else
            v28 = v37;
          for ( i = (int *)*v28; i != v28; i = (int *)*i )
          {
            if ( ++v26 == 4 )
            {
              MiPfCompletePrefetchIos(v36, (int)v37);
              v38 = 0;
              goto LABEL_80;
            }
          }
          if ( (unsigned int)++v27 >= 2 )
LABEL_80:
            JUMPOUT(0x5279B0);
        }
      }
    }
    v23 = v39;
    if ( (v39 & 0x80) == 0 )
      goto LABEL_42;
    v10 = v34;
    BYTE1(v32[0]) = 0;
    goto LABEL_34;
  }
  return -1073741670;
}
