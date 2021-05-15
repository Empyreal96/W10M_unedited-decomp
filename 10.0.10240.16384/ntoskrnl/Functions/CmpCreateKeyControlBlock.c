// CmpCreateKeyControlBlock 
 
int __fastcall CmpCreateKeyControlBlock(__int64 a1, unsigned int *a2, char a3, unsigned __int16 *a4)
{
  int v4; // r4
  unsigned int v5; // r6
  __int64 v8; // r8
  _WORD *v11; // r5
  unsigned int v12; // r2
  unsigned int v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // t1
  _DWORD *v16; // r0
  unsigned int v17; // r4
  int v18; // r1
  int v19; // r0
  int v20; // r1
  int v21; // r9
  int v22; // r1
  int v23; // r0
  unsigned int v24; // r3
  int v25; // r2
  _DWORD *v26; // r7
  int v27; // r3
  unsigned __int8 *v28; // r7
  int v29; // r0
  int v30; // r5
  unsigned int v31; // r2
  int v32; // r1
  int v33; // r5
  unsigned int v34; // r7
  int v35; // r3
  unsigned int v36; // r3
  _DWORD *v37; // r0
  __int16 v38; // r3
  int v39; // r0
  unsigned int v40; // r0
  __int16 v41; // r3
  int v42; // r1
  int v43; // r2
  unsigned int v44; // r2
  int v45; // r3
  unsigned __int16 *v46; // r0
  char v47[4]; // [sp+8h] [bp-40h] BYREF
  __int64 v48; // [sp+Ch] [bp-3Ch]
  BOOL v49; // [sp+14h] [bp-34h]
  int v50[2]; // [sp+18h] [bp-30h] BYREF
  __int64 v51; // [sp+20h] [bp-28h] BYREF

  v4 = *(_DWORD *)(a1 + 92);
  v5 = 0;
  v50[0] = -1;
  v48 = a1;
  v8 = a1;
  if ( (v4 & 0x20) != 0 && *(_DWORD *)(a1 + 3268) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    return sub_805198();
  v49 = (a3 & 1) != 0;
  if ( a2 )
    v5 = a2[3];
  v11 = (_WORD *)*((_DWORD *)a4 + 1);
  v51 = *(_QWORD *)a4;
  v12 = (unsigned __int16)v51;
  v13 = (unsigned __int16)v51;
  if ( (_WORD)v51 )
  {
    do
    {
      if ( *v11 != 92 )
        break;
      v12 = (unsigned __int16)(v13 - 2);
      ++v11;
      LOWORD(v51) = v13 - 2;
      v13 = v12;
      HIDWORD(v51) = v11;
    }
    while ( v12 );
    if ( v12 )
    {
      v14 = ((v12 - 1) >> 1) + 1;
      do
      {
        v15 = (unsigned __int16)*v11++;
        v13 = v15;
        if ( v15 != 92 )
        {
          if ( v13 >= 0x61 )
          {
            if ( v13 > 0x7A )
              v13 = RtlUpcaseUnicodeChar(v13);
            else
              v13 -= 32;
          }
          v5 = 37 * v5 + v13;
        }
        --v14;
      }
      while ( v14 );
      HIDWORD(v8) = HIDWORD(v48);
    }
  }
  v16 = (_DWORD *)CmpAllocateKeyControlBlock(v13);
  v17 = (unsigned int)v16;
  if ( !v16 )
    return sub_805198();
  v16[16] = v16 + 16;
  v16[17] = v16 + 16;
  v16[18] = 0;
  v16[19] = 0;
  v16[20] = 0;
  v16[21] = 0;
  if ( a2 )
    v18 = (a2[1] >> 20) & 1;
  else
    LOBYTE(v18) = CmpLockTablePresent;
  v19 = v18 & 1;
  v20 = *(_DWORD *)(v17 + 4);
  *(_DWORD *)(v17 + 8) &= 0xFFFFFFF8;
  *(_DWORD *)(v17 + 12) = v5;
  *(_DWORD *)v17 = 1;
  *(_DWORD *)(v17 + 4) = v20 & 0xFFE1FFFF | (v19 << 20);
  *(_QWORD *)(v17 + 20) = v8;
  *(_DWORD *)(v17 + 32) = 0;
  *(_DWORD *)(v17 + 36) = 0;
  *(_DWORD *)(v17 + 28) = 0;
  *(_DWORD *)(v17 + 156) = 0;
  *(_DWORD *)(v17 + 108) = v17 + 108;
  *(_DWORD *)(v17 + 112) = v17 + 108;
  *(_DWORD *)(v17 + 116) = v17 + 116;
  *(_DWORD *)(v17 + 120) = v17 + 116;
  if ( a2 )
    *(_DWORD *)(v17 + 124) = a2[31];
  else
    *(_DWORD *)(v17 + 124) = 0;
  *(_DWORD *)(v17 + 128) = 0;
  *(_DWORD *)(v17 + 132) = 0;
  *(_DWORD *)(v17 + 136) = 0;
  *(_DWORD *)(v17 + 140) = 0;
  *(_DWORD *)(v17 + 144) = 0;
  *(_DWORD *)(v17 + 148) = -1;
  *(_DWORD *)(v17 + 152) = 0;
  v21 = a3 & 2;
  if ( (a3 & 2) == 0 )
  {
    CmpLockHashEntryExclusive(v8, v5);
    if ( a2 )
      CmpLockKcbExclusive(a2);
  }
  v22 = *(_DWORD *)(v17 + 20);
  v23 = *(_DWORD *)(v22 + 1844);
  v24 = 101027 * (*(_DWORD *)(v17 + 12) ^ (*(_DWORD *)(v17 + 12) >> 9));
  v25 = (v24 ^ (v24 >> 9)) & (*(_DWORD *)(v22 + 1848) - 1);
  if ( v49 )
    ++*(_DWORD *)(v17 + 24);
  v26 = CmpAddKeyHashToEntry((_DWORD *)(v17 + 12), v23 + 12 * v25, 0);
  v27 = *(_DWORD *)(v17 + 4);
  if ( v26 )
  {
    *(_DWORD *)(v17 + 4) = v27 | 0x80000;
    CmpFreeKeyControlBlock(v17);
    v17 = (unsigned int)v26;
    CmpLockKcbExclusive(v26);
    v33 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v48 + 4))(v48, HIDWORD(v48), v50);
    if ( v33 )
    {
      if ( CmpReferenceKeyControlBlock(v26) )
      {
        LODWORD(v8) = v48;
        if ( (v26[1] & 0x10) != 0 && !v49 )
        {
          *((_WORD *)v26 + 2) = 64;
          v45 = HIDWORD(v48);
          v26[5] = v8;
          v26[6] = v45;
        }
        v42 = v26[1];
        if ( (v42 & 7) == 0 )
        {
          v26[15] = *(_DWORD *)(v33 + 20) + *(_DWORD *)(v33 + 24);
          *((_WORD *)v26 + 2) = v42 & 0xFFBF;
        }
        v43 = v26[26];
        v26[22] = *(_DWORD *)(v33 + 4);
        v26[23] = *(_DWORD *)(v33 + 8);
        *((_WORD *)v26 + 48) = *(_DWORD *)(v33 + 52);
        *((_WORD *)v26 + 49) = *(_DWORD *)(v33 + 60);
        v26[25] = *(_DWORD *)(v33 + 64);
        v44 = v43 & 0xFFFFFFF0 | *(_WORD *)(v33 + 54) & 0xF;
        v26[26] = v44;
        v26[26] = ((unsigned __int8)*(_WORD *)(v33 + 54) ^ (unsigned __int8)v44) & 0xF0 ^ v44;
        *((_BYTE *)v26 + 105) = *(_BYTE *)(v33 + 55);
        goto LABEL_48;
      }
      CmpUnlockKcb(v26);
      goto LABEL_90;
    }
LABEL_89:
    CmpDereferenceKeyControlBlockWithLock((int)a2, 0);
    CmpRemoveKeyHash(*(_DWORD *)(v17 + 20), (_DWORD *)(v17 + 12));
    CmpUnlockKcb((_DWORD *)v17);
    *(_DWORD *)(v17 + 4) |= 0x80000u;
    CmpFreeKeyControlBlock(v17);
LABEL_90:
    LODWORD(v8) = v48;
    goto LABEL_91;
  }
  if ( (v27 & 0x100000) != 0 )
    *(_DWORD *)(v17 + 36) = CmpLockTableAdd(v17, 1);
  v28 = (unsigned __int8 *)(v17 + 28);
  v29 = KeAbPreAcquire(v17 + 28, 0, 0);
  v30 = v29;
  do
    v31 = __ldrex(v28);
  while ( __strex(v31 | 1, v28) );
  __dmb(0xBu);
  if ( (v31 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v17 + 28), v29, v17 + 28);
  if ( v30 )
    *(_BYTE *)(v30 + 14) |= 1u;
  v32 = HIDWORD(v48);
  *(_DWORD *)(v17 + 32) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v33 = (*(int (__fastcall **)(_DWORD, int, int *))(v8 + 4))(v8, v32, v50);
  if ( !v33 )
    goto LABEL_89;
  if ( !a2 )
  {
    v36 = *(_DWORD *)(v17 + 4) & 0x801FFFFF | 0x200000;
    *(_DWORD *)(v17 + 40) = 0;
    goto LABEL_39;
  }
  v34 = ((a2[1] >> 21) & 0x3FF) + 1;
  if ( v34 > 0x7F )
  {
    v46 = (unsigned __int16 *)CmpConstructName((int)a2);
    if ( !v46 )
      goto LABEL_87;
    if ( *a4 + (unsigned int)*v46 + 2 > 0xFFFF )
      v34 = 513;
    ExFreePoolWithTag((unsigned int)v46);
  }
  if ( v34 < 0x200 && CmpReferenceKeyControlBlock(a2) )
  {
    v35 = *(_DWORD *)(v17 + 4);
    *(_DWORD *)(v17 + 40) = a2;
    v36 = *(_DWORD *)(v17 + 4) ^ (v35 ^ (v34 << 21)) & 0x7FE00000;
LABEL_39:
    *(_DWORD *)(v17 + 4) = v36;
    if ( CmpAssignSecurityToKcb(v17, *(_DWORD *)(v33 + 44), 0, 0, 1) )
    {
      v37 = (_DWORD *)CmpGetNameControlBlock(&v51, v47);
      *(_DWORD *)(v17 + 44) = v37;
      if ( v37 )
      {
        *(_DWORD *)(v17 + 52) = *(_DWORD *)(v33 + 36);
        *(_DWORD *)(v17 + 56) = *(_DWORD *)(v33 + 40);
        if ( v49 )
        {
          *(_WORD *)(v17 + 4) = 16;
          if ( (*v37 & 1) != 0 )
            v41 = 32;
          else
            v41 = 0;
          *(_WORD *)(v17 + 106) = v41;
        }
        else
        {
          v38 = *(_WORD *)(v33 + 2);
          *(_WORD *)(v17 + 4) = 0;
          *(_WORD *)(v17 + 106) = v38;
        }
        if ( *(_DWORD *)(v17 + 124) )
          *(_WORD *)(v17 + 4) |= 0x20u;
        if ( CmpTraceRoutine )
          CmpEtwDumpKcb(v17, 22);
        v39 = *(_DWORD *)(v17 + 104);
        *(_DWORD *)(v17 + 60) = *(_DWORD *)(v33 + 24) + *(_DWORD *)(v33 + 20);
        *(_DWORD *)(v17 + 88) = *(_DWORD *)(v33 + 4);
        *(_DWORD *)(v17 + 92) = *(_DWORD *)(v33 + 8);
        *(_WORD *)(v17 + 96) = *(_DWORD *)(v33 + 52);
        *(_WORD *)(v17 + 98) = *(_DWORD *)(v33 + 60);
        *(_DWORD *)(v17 + 100) = *(_DWORD *)(v33 + 64);
        v40 = v39 & 0xFFFFFFF0 | *(_WORD *)(v33 + 54) & 0xF;
        *(_DWORD *)(v17 + 104) = v40;
        *(_DWORD *)(v17 + 104) = v40 ^ (*(unsigned __int16 *)(v33 + 54) ^ v40) & 0xF0;
        *(_BYTE *)(v17 + 105) = *(_BYTE *)(v33 + 55);
        goto LABEL_48;
      }
    }
    goto LABEL_89;
  }
LABEL_87:
  CmpRemoveKeyHash(*(_DWORD *)(v17 + 20), (_DWORD *)(v17 + 12));
  CmpUnlockKcb((_DWORD *)v17);
  *(_DWORD *)(v17 + 4) |= 0x80000u;
  CmpFreeKeyControlBlock(v17);
LABEL_91:
  v17 = 0;
LABEL_48:
  if ( v33 )
    (*(void (__fastcall **)(_DWORD, int *))(v8 + 8))(v8, v50);
  if ( v17 && *(_BYTE *)(v8 + 2532) == 1 && (*(_WORD *)(v17 + 106) & 0x10) == 0 )
    *(_WORD *)(v17 + 4) |= 0x20u;
  if ( !v21 )
  {
    if ( a2 )
      CmpUnlockKcb(a2);
    CmpUnlockHashEntry(v8, v5);
  }
  return v17;
}
