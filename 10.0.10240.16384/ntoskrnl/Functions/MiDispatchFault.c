// MiDispatchFault 
 
int __fastcall MiDispatchFault(int a1, unsigned int a2, unsigned int a3, int a4, int a5, unsigned __int8 a6, int a7, int a8, int *a9)
{
  char v11; // lr
  int v12; // r0
  int v13; // r4
  _DWORD *v14; // r6
  unsigned int v15; // r4
  unsigned int v16; // r6
  int v17; // r4
  unsigned __int8 *v18; // lr
  unsigned int v19; // r0
  unsigned int v20; // r3
  int v21; // r2
  int v22; // r3
  int result; // r0
  unsigned int *v24; // r6
  unsigned int v25; // r1
  unsigned int v26; // r5
  unsigned int v27; // r0
  unsigned int *v28; // r5
  unsigned int *v29; // r0
  unsigned int v30; // r5
  int v31; // r3
  bool v32; // zf
  unsigned int *v33; // r6
  unsigned int v34; // r1
  __int16 v35; // r3
  __int16 v36; // r3
  unsigned __int8 *v37; // lr
  unsigned int v38; // r2
  int v39; // r3
  unsigned int v40; // r2
  unsigned int v41; // r3
  unsigned int v42; // r2
  unsigned int *v43; // r2
  unsigned int v44; // r0
  __int16 v45; // [sp+10h] [bp-40h]
  int v46; // [sp+14h] [bp-3Ch] BYREF
  int v47; // [sp+18h] [bp-38h]
  int v48; // [sp+1Ch] [bp-34h]
  _DWORD *v49; // [sp+20h] [bp-30h]
  unsigned int v50; // [sp+24h] [bp-2Ch]
  int v51; // [sp+28h] [bp-28h]
  int *v52; // [sp+2Ch] [bp-24h]

  v50 = a2;
  v47 = a1;
  v11 = a1;
  v12 = a5;
  v51 = a7;
  v52 = a9;
  *a9 = 0;
  v13 = MmBadPointer;
  v14 = (_DWORD *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000);
  v48 = a5;
  v49 = v14;
  v46 = MmBadPointer;
  if ( a3 )
  {
    v15 = *(_DWORD *)(((a3 >> 10) & 0x3FFFFC) - 0x40000000);
    do
    {
      if ( (v15 & 2) == 0 || (v15 & 0x100) != 0 )
        return -1073741802;
      v16 = v15 >> 12;
    }
    while ( !MI_IS_PFN(v15 >> 12) );
    v17 = MmPfnDatabase + 24 * v16;
    v18 = (unsigned __int8 *)(v17 + 15);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
    __dmb(0xBu);
    if ( v19 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v39 = *(_DWORD *)(v17 + 12);
          __dmb(0xBu);
        }
        while ( (v39 & 0x80000000) != 0 );
        do
          v40 = __ldrex(v18);
        while ( __strex(v40 | 0x80, v18) );
        __dmb(0xBu);
      }
      while ( v40 >> 7 );
    }
    v20 = *(_DWORD *)(((a3 >> 10) & 0x3FFFFC) - 0x40000000);
    if ( (v20 & 2) == 0 || (v20 & 0x100) != 0 || v16 != v20 >> 12 )
    {
      __dmb(0xBu);
      v43 = (unsigned int *)(v17 + 12);
      do
        v44 = __ldrex(v43);
      while ( __strex(v44 & 0x7FFFFFFF, v43) );
      return -1073741802;
    }
    v21 = *(unsigned __int16 *)(v17 + 16);
    v22 = *(_DWORD *)(v17 + 12) & 0x3FFFFFFF;
    if ( *(_WORD *)(v17 + 16) )
    {
      if ( v21 == 1 )
      {
        if ( !v22 && (*(_BYTE *)(v17 + 18) & 8) == 0 )
          goto LABEL_24;
      }
      else if ( v21 != 2 || !v22 || (*(_BYTE *)(v17 + 18) & 8) == 0 )
      {
        goto LABEL_24;
      }
    }
    if ( (*(_DWORD *)(v17 + 20) & 0x8000000) != 0 )
      return sub_534C90();
    if ( (*(_DWORD *)(v17 + 4) | 0x80000000) <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 )
      JUMPOUT(0x534CA0);
    v24 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4992);
    v25 = *v24;
    if ( *v24 )
    {
      while ( v25 != -1 )
      {
        do
          v26 = __ldrex(v24);
        while ( v26 == v25 && __strex(v25 - 1, v24) );
        if ( v26 == v25 )
          goto LABEL_23;
        v25 = v26;
        if ( !v26 )
          break;
      }
    }
    if ( !MiChargePartitionResidentAvailable((int)MiSystemPartition, 1u, -1) )
      goto LABEL_25;
    do
LABEL_23:
      v27 = __ldrex(&dword_634A2C[85]);
    while ( __strex(v27 + 1, &dword_634A2C[85]) );
LABEL_24:
    ++*(_WORD *)(v17 + 16);
LABEL_25:
    v28 = (unsigned int *)(*(_DWORD *)(v17 + 4) | 0x80000000);
    if ( (*(_BYTE *)(v17 + 18) & 0x20) != 0 )
    {
      v33 = (unsigned int *)(v17 + 12);
      do
      {
        __dmb(0xBu);
        do
          v34 = __ldrex(v33);
        while ( __strex(v34 & 0x7FFFFFFF, v33) );
        v35 = *(_WORD *)(v17 + 18);
        __dmb(0xBu);
        v45 = v35;
        if ( (v35 & 0x20) != 0 )
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v36 = *(_WORD *)(v17 + 18);
            __dmb(0xBu);
            v45 = v36;
          }
          while ( (v36 & 0x20) != 0 );
        }
        KfRaiseIrql(2);
        v37 = (unsigned __int8 *)(v17 + 15);
        do
          v38 = __ldrex(v37);
        while ( __strex(v38 | 0x80, v37) );
        __dmb(0xBu);
        if ( v38 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v41 = *v33;
              __dmb(0xBu);
            }
            while ( (v41 & 0x80000000) != 0 );
            do
              v42 = __ldrex(v37);
            while ( __strex(v42 | 0x80, v37) );
            __dmb(0xBu);
          }
          while ( v42 >> 7 );
        }
      }
      while ( (*(_BYTE *)(v17 + 18) & 0x20) != 0 );
    }
    *(_BYTE *)(v17 + 18) |= 0x20u;
    if ( (*(_DWORD *)(v17 + 12) & 0x40000000) == 0 && (*v28 & 0x10) == 0 )
      MI_WRITE_VALID_PTE_VOLATILE(v28, 1);
    __dmb(0xBu);
    v29 = (unsigned int *)(v17 + 12);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 & 0x7FFFFFFF, v29) );
    result = MiResolveProtoPteFault(v47 & 1, v50, v49, v48, a6, a3, v51, &v46, v45);
    goto LABEL_32;
  }
  v31 = *v14;
  if ( (*v14 & 2) != 0 || !v31 )
    return 0;
  if ( (v31 & 0x800) != 0 )
  {
    result = MiResolveTransitionFault(v11 & 1, a2, ((a2 >> 10) & 0x3FFFFC) - 0x40000000, a5, a6, 0, a7, &v46);
LABEL_32:
    v13 = v46;
    goto LABEL_33;
  }
  if ( (v31 & 0x10) != 0 )
  {
    result = MiResolvePageFileFault(a2, ((a2 >> 10) & 0x3FFFFC) - 0x40000000, a5, 0, 0, a7, &v46);
    goto LABEL_32;
  }
  if ( (a7 & 1) != 0 && *(_BYTE *)(a7 & 0xFFFFFFFE) == 1 && (*(_DWORD *)((a7 & 0xFFFFFFFE) + 40) & 0x4000) == 0 )
    return 0;
  if ( (a7 & 1) != 0 )
  {
    if ( *(_BYTE *)(a7 & 0xFFFFFFFE) != 1 && *(_BYTE *)(a7 & 0xFFFFFFFE) != 3 )
      goto LABEL_44;
LABEL_85:
    if ( a2 >= dword_63389C )
      return -1073741819;
    goto LABEL_44;
  }
  v11 = v47;
  v32 = KeInvalidAccessAllowed(a7) == 1;
  v12 = v48;
  if ( v32 )
    goto LABEL_85;
LABEL_44:
  result = MiResolveDemandZeroFault(v11 & 1, a2, a7, ((a2 >> 10) & 0x3FFFFC) - 0x40000000, v12, a6, 0);
LABEL_33:
  if ( result == -1073532109 )
    *v52 = v13;
  return result;
}
