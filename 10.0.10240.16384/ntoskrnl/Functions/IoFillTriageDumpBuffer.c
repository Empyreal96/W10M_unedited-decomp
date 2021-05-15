// IoFillTriageDumpBuffer 
 
int __fastcall IoFillTriageDumpBuffer(unsigned int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, _DWORD *a13)
{
  __int16 v13; // r9
  int v15; // r7
  int v18; // r1
  unsigned int v19; // r6
  int v20; // r8
  unsigned int v21; // r5
  unsigned int v22; // r1
  unsigned int v23; // r9
  unsigned int v24; // r10
  unsigned int v25; // r3
  int v26; // r1
  int v27; // r0
  int v28; // r2
  __int16 v29; // r3
  int v30; // r7
  unsigned int v31; // r3
  unsigned int v32; // r7
  int v33; // r2
  unsigned int v34; // r7
  int v35; // r9
  unsigned int v36; // r2
  int v37; // r3
  unsigned int v38; // r3
  int v39; // r0
  int v40; // r0
  int v41; // r2
  unsigned int v42; // r2
  int v43; // r0
  __int16 v44; // r3
  int v45; // r3
  int v46; // r1
  int v47; // r0
  int v48; // r0
  int v49; // r7
  unsigned int v50; // r2
  int v51; // r7
  int v52; // r2
  int v53; // r2
  unsigned int v55; // [sp+8h] [bp-38h]
  int v56; // [sp+Ch] [bp-34h] BYREF
  int v57; // [sp+10h] [bp-30h]
  int v58; // [sp+14h] [bp-2Ch] BYREF
  int v59; // [sp+18h] [bp-28h]
  int v60; // [sp+1Ch] [bp-24h]
  unsigned int v61; // [sp+20h] [bp-20h]

  v13 = a4;
  v57 = a4;
  v15 = 0;
  v59 = a3;
  v60 = 0;
  v56 = 0;
  if ( a13 )
    *a13 = 0;
  if ( a5 )
    *a5 = 0;
  if ( a1 < 0x6C )
    return -1073741801;
  memset((_BYTE *)a2, 0, 104);
  v18 = 4096;
  *(_DWORD *)(a2 + 4) = a1 + 4096;
  *(_DWORD *)(a2 + 8) = a1 + 4092;
  v19 = a1 - 4;
  *(_DWORD *)(v19 + a2) = 0;
  *(_DWORD *)(a2 + 12) = 800;
  *(_DWORD *)(a2 + 16) = 2000;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = a9;
  *(_DWORD *)a2 = a8;
  v20 = 130;
  if ( a6 )
    v20 = 131;
  v21 = 4200;
  if ( (v13 & 0x100) != 0 )
  {
    if ( v19 <= 0x10A0 )
    {
      *(_DWORD *)(a2 + 68) = a9 | 0x100;
    }
    else
    {
      *(_DWORD *)(a2 + 20) = 4200;
      v21 = 4256;
      v20 |= 0x100u;
    }
  }
  if ( (v13 & 4) != 0 )
  {
    if ( v21 + 18560 >= v19 )
    {
      *(_DWORD *)(a2 + 68) |= 0x100u;
    }
    else
    {
      *(_DWORD *)(a2 + 28) = v21;
      v21 += 18560;
      v20 |= 4u;
    }
  }
  if ( (v13 & 8) != 0 )
  {
    if ( v21 + 888 >= v19 )
    {
      *(_DWORD *)(a2 + 68) |= 0x100u;
    }
    else
    {
      *(_DWORD *)(a2 + 32) = v21;
      v21 += 888;
      v20 |= 8u;
    }
  }
  if ( (v13 & 0x10) != 0 )
  {
    if ( v21 + 1104 >= v19 )
    {
      *(_DWORD *)(a2 + 68) |= 0x100u;
    }
    else
    {
      *(_DWORD *)(a2 + 36) = v21;
      v21 += 1104;
      v20 |= 0x10u;
    }
  }
  if ( (v13 & 0x20) != 0 && (*(_WORD *)(a7 + 82) & 1) != 0 )
  {
    v22 = *(_DWORD *)(a7 + 40);
    v23 = *(_DWORD *)(a6 + 56);
    v55 = v22;
    v61 = *(_DWORD *)(a7 + 36);
    __dmb(0xBu);
    if ( v61 > v23 || v23 >= v22 )
    {
      v24 = *(_DWORD *)(a7 + 36);
      __dmb(0xBu);
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v28 = 0;
      }
      else
      {
        __disable_irq();
        v28 = 1;
      }
      v29 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
      if ( v28 )
        __enable_irq();
      if ( (v29 & 1) != 0 && a7 != *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x58C) )
      {
        v30 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC40);
        if ( IopIsAddressRangeValid(v30, 16, v28) )
        {
          v31 = *(_DWORD *)(v30 + 8);
          v28 = v61;
          if ( v61 <= v31 )
          {
            v28 = v55;
            if ( v31 < v55 )
              v24 = *(_DWORD *)(v30 + 8);
          }
        }
      }
      if ( *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xE99) > 2u )
      {
        v32 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574);
        if ( v32 - KeKernelStackSize <= v23 && v23 < v32 )
        {
          if ( IopIsAddressRangeValid(v32 - 4, 4, v28) )
          {
            v34 = *(_DWORD *)(v32 - 4);
            if ( IopIsAddressRangeValid(v34, 4, v33) )
            {
              v25 = v55;
              if ( v61 <= v34 && v34 < v55 )
                v24 = v34;
              goto LABEL_31;
            }
          }
        }
      }
    }
    else
    {
      v24 = v23;
    }
    v25 = v55;
LABEL_31:
    v26 = v25 - v24;
    if ( v25 - v24 >= 0x3FFF )
      v26 = 0x3FFF;
    v27 = IopGetMaxValidMemorySize(v24, v26);
    v15 = v56;
    v13 = v57;
    v18 = 4096;
    if ( v27 )
    {
      if ( v27 + v21 >= v19 )
      {
        *(_DWORD *)(a2 + 68) |= 0x100u;
      }
      else
      {
        *(_DWORD *)(a2 + 40) = v21;
        *(_DWORD *)(a2 + 44) = v27;
        v21 = (v27 + v21 + 7) & 0xFFFFFFF8;
        *(_DWORD *)(a2 + 72) = v24;
        v20 |= 0x20u;
      }
    }
  }
  if ( (v13 & 0x400) != 0 )
  {
    if ( v21 + 864 >= v19 )
    {
      *(_DWORD *)(a2 + 68) |= 0x100u;
    }
    else
    {
      *(_DWORD *)(a2 + 88) = v21;
      *(_DWORD *)(a2 + 92) = 864;
      v21 = (v21 + 871) & 0xFFFFFFF8;
      v20 |= 0x400u;
    }
  }
  v35 = a2 - 4096;
  if ( !v59 )
  {
    v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v36 + 308);
    ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  }
  v37 = 2004;
  if ( !dword_634F88 )
    v37 = 4;
  v38 = ((v37 + 7) & 0xFFFFFFF8) + v21;
  if ( v38 >= v19 )
  {
    *(_DWORD *)(a2 + 68) |= 0x100u;
  }
  else
  {
    *(_DWORD *)(a2 + 24) = v21;
    v39 = v35 + v21;
    v21 = v38;
    v20 |= 0x40u;
    MmWriteUnloadedDriverInformation(v39, v18);
  }
  if ( (v57 & 0x40) != 0 )
  {
    v40 = IoGetLoadedDriverInfo(v59, &v56, &v58);
    v15 = v56;
    v60 = v40;
    if ( v40 >= 0 && ((76 * v56 + 7) & 0xFFFFFFF8) != 0 )
    {
      v41 = v58;
      if ( ((76 * v56 + 7) & 0xFFFFFFF8) + v21 >= v19 )
      {
        *(_DWORD *)(a2 + 68) |= 0x100u;
      }
      else
      {
        *(_DWORD *)(a2 + 48) = v21;
        *(_DWORD *)(a2 + 52) = v15;
        v21 += (76 * v15 + 7) & 0xFFFFFFF8;
        v20 |= 0x40u;
      }
    }
    else
    {
      v41 = v58;
    }
  }
  else
  {
    v41 = 0;
  }
  v42 = (v41 + 6 * v15 + 7) & 0xFFFFFFF8;
  if ( v42 )
  {
    if ( v42 + v21 >= v19 )
    {
      *(_DWORD *)(a2 + 68) |= 0x100u;
    }
    else
    {
      *(_DWORD *)(a2 + 56) = v21;
      *(_DWORD *)(a2 + 60) = v42;
      v21 = (v42 + v21 + 7) & 0xFFFFFFF8;
    }
  }
  if ( *(_DWORD *)(a2 + 48) )
  {
    if ( *(_DWORD *)(a2 + 56) )
    {
      v60 = IopWriteDriverList(v35, v59);
      if ( v60 < 0 )
        *(_DWORD *)(a2 + 48) = 0;
    }
  }
  if ( !v59 )
  {
    ExpReleaseResourceForThreadLite((int)&PsLoadedModuleResource, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v44 = *(_WORD *)(v43 + 0x134) + 1;
    *(_WORD *)(v43 + 308) = v44;
    if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
      KiCheckForKernelApcDelivery(v43);
  }
  if ( (v57 & 0x800) != 0 )
  {
    IopAddRunTimeTriageDataBlocks(a10, a11, a12, a6, *(_DWORD *)(a2 + 72), *(_DWORD *)(a2 + 44) + *(_DWORD *)(a2 + 72));
    v21 = (IopSizeTriageDumpDataBlocks(a2, a10, a11, v21, v19) + 7) & 0xFFFFFFF8;
    if ( *(_DWORD *)(a2 + 100) )
      v20 |= 0x800u;
  }
  v45 = *(_DWORD *)(a2 + 20);
  if ( v45 )
    MmWriteTriageInformation(v45 + v35);
  v46 = *(_DWORD *)(a2 + 28);
  if ( v46 && v46 + 18560 <= v19 )
    memmove(v46 + v35, ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 0x4880u);
  v47 = *(_DWORD *)(a2 + 32);
  if ( v47 && v47 + 888 <= v19 )
    memmove(v47 + v35, *(_DWORD *)(a7 + 116), 0x378u);
  v48 = *(_DWORD *)(a2 + 36);
  if ( v48 && v48 + 1104 <= v19 )
    memmove(v48 + v35, a7, 0x450u);
  v49 = *(_DWORD *)(a2 + 40);
  if ( v49 )
  {
    v50 = *(_DWORD *)(a2 + 44);
    if ( v49 + v50 <= v19 )
      memmove(v49 + v35, *(_DWORD *)(a2 + 72), v50);
  }
  v51 = *(_DWORD *)(a2 + 88);
  if ( v51 && v51 + 864 <= v19 )
    KdCopyDataBlock(v51 + v35);
  if ( a10 )
    IopFillTriageDumpDataBlocks(a2, a10, a11, v35);
  if ( v19 != 126972 || a13 )
  {
    v52 = v21 + 4;
    if ( a13 )
      *a13 = v21 - 4092;
  }
  else
  {
    v52 = 0x20000;
  }
  if ( a5 )
    *a5 = v20;
  *(_DWORD *)(a2 + 4) = v52;
  v53 = v52 - 4;
  *(_DWORD *)(a2 + 8) = v53;
  if ( v53 - 4096 > v19 )
    return -1073741670;
  *(_DWORD *)(v53 + a2 - 4096) = 1145524820;
  return v60;
}
