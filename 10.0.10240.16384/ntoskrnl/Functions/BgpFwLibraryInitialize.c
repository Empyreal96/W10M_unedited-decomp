// BgpFwLibraryInitialize 
 
int __fastcall BgpFwLibraryInitialize(unsigned int a1, int a2)
{
  int v5; // r3
  int v6; // r1
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r4
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r0
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r4
  int v22; // r2
  unsigned int v23; // r9
  int v24; // lr
  int v25; // r0
  unsigned int v26; // r8
  int v27; // r2
  int v28; // r0
  unsigned int *v29; // r10
  int v30; // r1
  int v31; // r2
  int v32; // r3
  int v33; // r5
  int v34; // r4
  unsigned int v35; // r3
  int v36; // r0
  _DWORD *v37; // r5
  int v38; // r3
  int v39; // r0
  int v40; // r0
  int v41; // r5
  int *v42; // r0
  int v43; // r4
  int v44; // r3
  int v45; // r0
  int v46; // r4
  int v47; // r1
  int v48; // r1
  int v49; // r0
  unsigned int v50; // r0
  int v51; // r1
  int v52; // [sp+0h] [bp-40h]
  int v53; // [sp+4h] [bp-3Ch]
  unsigned int v54; // [sp+8h] [bp-38h]
  unsigned int v55; // [sp+Ch] [bp-34h]
  int v56[2]; // [sp+10h] [bp-30h] BYREF
  int v57; // [sp+18h] [bp-28h]
  int v58; // [sp+1Ch] [bp-24h]

  v57 = a2;
  if ( !a1 )
    return sub_8DFBD8();
  if ( *(_DWORD *)(a1 + 80) != 2 )
    return -1073741735;
  v5 = *(_DWORD *)(a1 + 84) & 0x3FF0000;
  v58 = v5;
  if ( (dword_619018 & 1) != 0 && (dword_619018 & 4) == 0 && (v5 & 0x100000) == 0 )
    return sub_8DFBD8();
  if ( (v5 & 0x100000) != 0 )
  {
    v50 = BgpFwAcquireLock(a1);
    if ( a2 == -1 )
    {
      dword_619018 &= 0xFFFFFFFD;
      memset(&BgInternal, 0, 28);
      dword_619018 |= 0x101800u;
      v10 = BgpFwLibraryEnable((unsigned __int8 *)(a1 + 16), v51, 1054720);
      if ( v10 < 0 )
        return v10;
      dword_619018 &= 0xFFFFDFFF;
      if ( *(_DWORD *)(a1 + 8) )
      {
        BgpFwReservePoolSwap(0, *(_DWORD *)(a1 + 144), *(_DWORD *)(a1 + 148));
        dword_619098 = (int)ResFwConfigureDisplayStringResources(*(_DWORD *)(a1 + 152));
        dword_619094 = (int)AnFwConfigureProgressResources(*(int **)(a1 + 156));
      }
      else
      {
        dword_619094 = 0;
        dword_619098 = 0;
      }
      LogFwInitialize();
    }
    else
    {
      dword_619018 &= 0xFFFFEFFF;
      AnFwProgressIndicatorTransition(v50);
    }
    BgpFwReleaseLock();
    goto LABEL_14;
  }
  if ( a2 == -1 )
  {
    BgpFwInitializeLock();
    dword_619018 = v6 | 0xC04;
    dword_6190A0 = (int)&dword_61909C;
    dword_61909C = (int)&dword_61909C;
    v7 = *(_DWORD *)(a1 + 144);
    if ( !v7 || !*(_DWORD *)(a1 + 148) )
      return -1073741670;
    BgpFwInitializeReservePool(v7, 0x4000, (int)&unk_6495C8);
    v10 = BgpFwLibraryEnable((unsigned __int8 *)(a1 + 16), v8, v9);
    if ( v10 < 0 )
      goto LABEL_60;
    v11 = *(_DWORD *)(a1 + 68);
    v12 = *(_DWORD *)(a1 + 72);
    v13 = *(_DWORD *)(a1 + 76);
    unk_61904C = *(_DWORD *)(a1 + 64);
    unk_619050 = v11;
    unk_619054 = v12;
    unk_619058 = v13;
    if ( !*(_DWORD *)(a1 + 56) )
    {
LABEL_13:
      v10 = BgpBcInitializeCriticalMode(a1, -1);
      if ( v10 >= 0 )
      {
LABEL_14:
        v10 = 0;
        dword_619018 |= 1u;
        goto LABEL_15;
      }
LABEL_60:
      BgpFwLibraryDestroy();
      return v10;
    }
    v14 = (_DWORD *)BgpFwAllocateMemory(0x10u);
    if ( v14 )
    {
      *v14 = *(_DWORD *)(a1 + 56);
      v14[1] = *(_DWORD *)(a1 + 60);
      v15 = *(_DWORD *)(a1 + 56);
      v14[2] = 1;
      v14[3] = v15;
      dword_619088 = (int)v14;
      v10 = BgpFoInitialize(v14, 0);
      if ( v10 < 0 )
        goto LABEL_60;
      goto LABEL_13;
    }
LABEL_59:
    v10 = -1073741801;
    goto LABEL_60;
  }
  BgpFwAcquireLock(a1);
  v10 = BgpFwLibraryEnable((unsigned __int8 *)(a1 + 16), v16, v17);
  if ( v10 >= 0 )
  {
    MmGetPhysicalAddress((int)v56, (int)off_618FD8, v18, v19);
    dword_618FF8 = v56[0];
    dword_618FFC = v56[1];
    dword_619000 = dword_618FC8;
    dword_619004 = dword_618FC4;
    dword_619008 = dword_618FCC;
    if ( dword_618FD0 == 5 )
    {
      v20 = 4;
    }
    else if ( dword_618FD0 == 4 )
    {
      v20 = 3;
    }
    else
    {
      v20 = 0;
    }
    dword_619010 = v20;
    memmove((int)&unk_6190A4, a1 + 160, 0x80u);
    v21 = 0;
    v22 = 288;
    v23 = 0;
    v53 = 0;
    v24 = 0;
    if ( *(_DWORD *)(a1 + 44) )
    {
      v24 = *(_DWORD *)(a1 + 52);
      v21 = 4;
      v53 = 4;
      v23 = (*(_DWORD *)(a1 + 48) + 15) & 0xFFFFFFF0;
      v22 = v23 + 304;
    }
    v25 = 0;
    v26 = 0;
    v52 = 0;
    if ( *(_DWORD *)(a1 + 92) )
    {
      v25 = 16;
      v52 = 4;
      v26 = (*(_DWORD *)(a1 + 96) + 15) & 0xFFFFFFF0;
      v22 += v26 + 16;
    }
    v27 = v22 + v24 + 16464;
    v56[0] = v27 - v25 - v26 - v21 * 4 - v23 - 288;
    v55 = (((unsigned int)v56[0] >> 3) + 15) & 0xFFFFFFF0;
    v54 = v55 + v27;
    v28 = BgpFwAllocateMemory(v55 + v27);
    v29 = (unsigned int *)v28;
    dword_619048 = v28;
    if ( !v28 )
    {
      BgpFwReleaseLock();
      goto LABEL_59;
    }
    memmove(v28, a1, 0x120u);
    v30 = v56[0];
    *v29 = v54;
    v29[21] |= 0x100000u;
    v29[36] = 0;
    v29[37] = 0;
    v29[38] = 0;
    v29[39] = 0;
    v31 = (int)&v29[v52 + 72] + v26 + v21 * 4 + v23;
    BgpFwInitializeReservePool(v31 + v55, v30, v31);
    v32 = 0;
    dword_61908C = 0;
    if ( !v23 )
      goto LABEL_67;
    v33 = (int)(v29 + 72);
    v34 = (int)&v29[v21 + 72];
    memmove(v34, *(_DWORD *)(a1 + 44), *(_DWORD *)(a1 + 48));
    v29[74] = 1;
    v29[72] = v34;
    v35 = *(_DWORD *)(a1 + 48);
    v29[75] = v34;
    v29[73] = v35;
    dword_619018 |= 0x800u;
    v36 = BgpFoInitialize(v29 + 72, 1);
    v32 = dword_619018 & 0xFFFFF7FF;
    dword_619018 &= 0xFFFFF7FF;
    if ( v36 < 0 )
    {
      v32 = dword_61908C;
      v33 = dword_61908C;
    }
    else
    {
      dword_61908C = (int)(v29 + 72);
    }
    if ( !v33 )
LABEL_67:
      DbgPrintEx(101, 0, (int)"BGFX system font initialization failure!\n", v32);
    dword_619090 = 0;
    if ( v26 )
    {
      v37 = (unsigned int *)((char *)&v29[v53 + 72] + v23);
      memmove((int)&v37[v52], *(_DWORD *)(a1 + 92), *(_DWORD *)(a1 + 96));
      v37[2] = 1;
      *v37 = &v37[v52];
      v38 = *(_DWORD *)(a1 + 96);
      v37[3] = &v37[v52];
      v37[1] = v38;
      dword_619090 = (int)v37;
    }
    memset(&dword_61905C, 0, 32);
    if ( *(_DWORD *)(a1 + 100) )
    {
      v39 = BgpFwAllocateMemory(*(_DWORD *)(a1 + 108));
      dword_61905C = v39;
      if ( v39 )
      {
        memmove(v39, *(_DWORD *)(a1 + 100), *(_DWORD *)(a1 + 108));
        dword_619064 = *(_DWORD *)(a1 + 108);
        dword_619068 = *(_DWORD *)(a1 + 112);
        dword_61906C = *(_DWORD *)(a1 + 116);
      }
    }
    dword_619088 = 0;
    if ( *(_DWORD *)(a1 + 56) )
    {
      v40 = BgpFwAllocateMemory(*(_DWORD *)(a1 + 60));
      v41 = v40;
      if ( v40 )
      {
        memmove(v40, *(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 60));
        v42 = (int *)BgpFwAllocateMemory(0x10u);
        v43 = (int)v42;
        if ( v42 )
        {
          v42[2] = 0;
          *v42 = v41;
          v44 = *(_DWORD *)(a1 + 60);
          v42[3] = v41;
          v42[1] = v44;
          if ( BgpFoInitialize(v42, 0) >= 0 )
          {
            dword_619088 = v43;
            goto LABEL_39;
          }
          BgpFwFreeMemory(v41);
          v49 = v43;
        }
        else
        {
          v49 = v41;
        }
        BgpFwFreeMemory(v49);
        goto LABEL_39;
      }
    }
LABEL_39:
    dword_619018 |= 0x8000u;
    BgpBcInitializeCriticalMode(a1, v57);
    dword_619018 = dword_619018 & 0xFFFF7FFF | 0x800;
    v45 = BgpFwAllocateMemory(0x38u);
    v46 = v45;
    dword_619018 &= 0xFFFFF7FF;
    if ( v45 )
    {
      v47 = *(_DWORD *)(a1 + 152);
      if ( v47 )
      {
        memmove(v45, v47, 0x1Cu);
        v29[38] = v46;
        v46 += 28;
      }
      v48 = *(_DWORD *)(a1 + 156);
      if ( v48 )
      {
        memmove(v46, v48, 0x1Cu);
        v29[39] = v46;
      }
    }
    dword_619098 = (int)ResFwConfigureDisplayStringResources(*(_DWORD *)(a1 + 152));
    dword_619094 = (int)AnFwConfigureProgressResources(*(int **)(a1 + 156));
    dword_61901C = *(_DWORD *)(a1 + 88);
    dword_619018 |= v58 | 0x80;
    BgpFwReleaseLock();
    qword_619080 = *(_QWORD *)(a1 + 136);
    goto LABEL_14;
  }
  BgpFwReleaseLock();
LABEL_15:
  if ( v10 < 0 )
    goto LABEL_60;
  return v10;
}
