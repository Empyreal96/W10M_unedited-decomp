// sub_7F79F8 
 
void __fastcall sub_7F79F8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8, int a9, int a10, unsigned int a11, int a12, char a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, char a26)
{
  int v26; // r0
  int v27; // r1
  unsigned int v28; // r2
  unsigned int v29; // r4
  unsigned int v30; // r0
  int v31; // r10
  unsigned int v32; // r0
  unsigned int v33; // r0
  unsigned int v34; // r1
  int v35; // r3
  int v36; // r2
  _DWORD *v37; // r0
  unsigned int v38; // r2
  int v39; // r2
  int v40; // r1
  bool v41; // cf
  char v42; // r5
  int v43; // r7
  int v44; // r9
  unsigned __int8 *v45; // r10
  int v46; // lr
  unsigned __int8 *v47; // r0
  int v48; // r7
  int v49; // r2
  int v50; // r3
  unsigned int v51; // r1
  signed __int64 v52; // r2
  int v53; // r7
  int v54; // r0
  unsigned int v55; // r7
  int v56; // r0
  unsigned int v57; // r1
  int v58; // r3
  int v59; // [sp+0h] [bp+0h]
  int v60; // [sp+4h] [bp+4h]

  if ( (*(_DWORD *)(*(_DWORD *)(v43 + 336) + 192) & 0x100000) != 0 )
    MmGetMinWsPagePriority();
  v26 = MmGetDefaultPagePriority();
  v29 = v26;
  if ( v28 > v26 - 1 )
    v28 = v26;
  if ( v28 <= v26 - 1 )
LABEL_36:
    JUMPOUT(0x71CAEA);
  if ( (dword_637410 & 0x10) != 0 && !v27 )
    v42 = 1;
  v46 = 314159;
  v47 = v45;
  v48 = 8;
  do
  {
    v49 = 37 * (37 * (37 * (37 * (37 * (37 * v47[1] + v47[2]) + v47[3]) + v47[4]) + v47[5]) + v47[6])
        + 442596621 * *v47
        - 803794207 * v46;
    v50 = v47[7];
    v47 += 8;
    --v48;
    v46 = v49 + v50;
  }
  while ( v48 );
  a11 = v49 + v50;
  v51 = MEMORY[0xFFFF9004];
  if ( MEMORY[0xFFFF9004] < 0x1000000u )
  {
    while ( 1 )
    {
      v54 = MEMORY[0xFFFF9324];
      __dmb(0xBu);
      v55 = MEMORY[0xFFFF9320];
      __dmb(0xBu);
      if ( v54 == MEMORY[0xFFFF9328] )
        break;
      __dmb(0xAu);
      __yield();
    }
    LODWORD(v52) = (__int64)(v55 * (unsigned __int64)v51) >> 24;
    v53 = v52 + (v54 << 8) * v51;
  }
  else
  {
    v52 = MEMORY[0xFFFF9320] * (unsigned __int64)MEMORY[0xFFFF9004];
    v53 = v52 >> 24;
  }
  MmQueryMemoryListInformation((int)&a13, 0x58u, v52, &a7);
  v30 = PfpGetPageListCount((int)&a26, 0, 7u);
  v31 = (v30 >> 6) & 0x3FFF | (v30 >> 20 << 14);
  v32 = PfpGetPageListCount((int)&a26, v29, 7u);
  v60 = (v32 >> 6) & 0x3FFF | (v32 >> 20 << 14);
  v33 = PfpGetPageListCount((int)&a26, v29 - 1, 7u);
  v59 = (v33 >> 6) & 0x3FFF | (v33 >> 20 << 14);
  v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v35 = *(__int16 *)(v34 + 0x134) - 1;
  *(_WORD *)(v34 + 308) = v35;
  ExAcquireResourceExclusiveLite((int)&unk_6373CC, 1, v36, v35);
  v37 = (_DWORD *)PfSnPrefetchCacheEntryGet(&dword_6373B0[1], a8, a11, &a7);
  if ( !v37 )
  {
LABEL_14:
    v56 = ExReleaseResourceLite((int)&unk_6373CC);
    v57 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v58 = (__int16)(*(_WORD *)(v57 + 0x134) + 1);
    *(_WORD *)(v57 + 308) = v58;
    if ( !v58 && *(_DWORD *)(v57 + 100) != v57 + 100 && !*(_WORD *)(v57 + 310) )
      KiCheckForKernelApcDelivery(v56);
    goto LABEL_36;
  }
  if ( a7 )
    goto LABEL_31;
  v38 = v53 - v37[23];
  if ( v38 < v37[24] )
    v42 &= 0xFEu;
  if ( (v42 & 2) == 0 || v38 < v37[25] || (*(_DWORD *)(v44 + 464) & 2) != 0 )
  {
LABEL_31:
    v40 = v59;
    v39 = v60;
  }
  else
  {
    if ( v38 >= 0x1B7740 )
    {
      v41 = v38 >= 0x36EE80;
      v39 = v60;
      if ( !v41 )
      {
        v40 = v59;
        goto LABEL_32;
      }
    }
    else
    {
      v39 = v60;
    }
    v40 = v59;
  }
LABEL_32:
  v37[22] = v31;
  v37[23] = v53;
  v37[20] = v39;
  v37[21] = v40;
  goto LABEL_14;
}
