// MiCrcStillIntact 
 
int __fastcall MiCrcStillIntact(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r5
  unsigned int *v7; // r7
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r4
  int v11; // r6
  unsigned __int8 *v12; // r1
  unsigned int v13; // r2
  int v15; // r8
  int v16; // r3
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r2
  unsigned int v20; // r9
  _DWORD *v21; // r0
  int v22; // r3
  int v23; // r5
  int v24; // r4
  unsigned int v25; // r0
  int v27; // [sp+10h] [bp-B8h] BYREF
  char v28; // [sp+14h] [bp-B4h]
  char v29; // [sp+15h] [bp-B3h]
  int v30; // [sp+18h] [bp-B0h]
  int v31; // [sp+1Ch] [bp-ACh]
  int v32; // [sp+20h] [bp-A8h]
  int v33; // [sp+24h] [bp-A4h]

  v4 = *(_DWORD *)(a3 + 8);
  v7 = (unsigned int *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( !MiRecheckVaVm(a2, v4) )
    return 0;
  if ( !MiIsAddressValid((unsigned int)v7, 0, v8, v9) )
    return 0;
  v10 = *v7;
  if ( (*v7 & 2) == 0 )
    return 0;
  v11 = MmPfnDatabase + 24 * (v10 >> 12);
  v12 = (unsigned __int8 *)(v11 + 15);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 | 0x80, v12) );
  __dmb(0xBu);
  if ( v13 >> 7 )
    return sub_54EAF4();
  v15 = MiCombineCandidate(a1, v11);
  if ( !v15 )
  {
    __dmb(0xBu);
    v17 = (unsigned int *)(v11 + 12);
    do
LABEL_28:
      v25 = __ldrex(v17);
    while ( __strex(v25 & 0x7FFFFFFF, v17) );
    return 0;
  }
  v16 = *(_BYTE *)(v11 + 18) & 7;
  __dmb(0xBu);
  v17 = (unsigned int *)(v11 + 12);
  if ( v16 != 6 )
    goto LABEL_28;
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 & 0x7FFFFFFF, v17) );
  if ( v7 == (unsigned int *)(*(_DWORD *)(v11 + 4) | 0x80000000) )
  {
    v19 = *(_DWORD *)(v11 + 20);
    if ( (v19 & 0x8000000) == 0 && (*(_BYTE *)(v11 + 19) & 8) == 0 && (v19 & 0xFFFFF) != 1048573 )
    {
      v20 = MiLocateWsle(v4, a2, *(_DWORD *)v11);
      if ( v20 >= *(_DWORD *)(*(_DWORD *)(a2 + 92) + 4) && *(_WORD *)(v11 + 16) == 1 )
      {
        v21 = 0;
        if ( v15 != 1 || (v21 = MiLocateAddress(v4)) != 0 && ((1 << (v21[7] & 7)) & 0x55) != 0 )
        {
          if ( a4 == 2 )
          {
            if ( (v10 & 0x200) == 0 )
            {
              MiMakeCombineCandidateClean(v7, v21);
              return 1;
            }
          }
          else
          {
            if ( a4 != 3 )
              return 1;
            v22 = *(_DWORD *)(a2 + 92);
            v23 = *(_DWORD *)(v22 + 36);
            v24 = *(_DWORD *)(v22 + 252);
            v31 = 0;
            v32 = 0;
            v28 = 0;
            v29 = 0;
            v30 = 33;
            v33 = 0;
            v27 = MiTbFlushType(a2);
            if ( MiClearPteAccessed(a2, v11, v7, v24 + v23 * v20, &v27, dword_634484) )
              return 1;
          }
        }
      }
    }
  }
  return 0;
}
