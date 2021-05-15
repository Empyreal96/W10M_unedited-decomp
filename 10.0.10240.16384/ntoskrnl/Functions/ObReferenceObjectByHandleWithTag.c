// ObReferenceObjectByHandleWithTag 
 
int __fastcall ObReferenceObjectByHandleWithTag(int a1, int a2, int a3, int a4, int a5, int *a6, int *a7)
{
  int v7; // r8
  int v10; // r5
  _DWORD *v11; // r9
  int v12; // r4
  int v13; // r0
  int *v14; // r2
  int v15; // r6
  int v16; // r3
  __int16 v17; // r3
  int v18; // r6
  int result; // r0
  _DWORD *v20; // r9
  int v21; // r0
  char v22; // lr
  unsigned int v23; // r4
  int v24; // r2
  int v25; // r0
  int v26; // r1
  unsigned int v27; // r3
  int v28; // r2
  int v29; // r3
  unsigned int v30; // r1
  int v31; // lr
  int v32; // r1
  unsigned int v33; // r1
  int v34; // r1
  int v35; // r0
  int v36; // r3
  unsigned int *v37; // r4
  unsigned int v38; // r1
  int v39; // r1
  int v40; // r4
  unsigned int *v41; // r5
  unsigned int v42; // r1
  int v43; // r1
  int v44; // r2
  unsigned int v45; // r0
  char v46; // r3
  unsigned int v47; // r4
  unsigned int v48; // r1
  unsigned int v49; // r4
  unsigned int v50; // r1
  int v51; // [sp+8h] [bp-38h]
  _DWORD *v52; // [sp+Ch] [bp-34h]
  unsigned __int64 v54[5]; // [sp+18h] [bp-28h] BYREF

  a4 = (char)a4;
  v7 = (char)a4;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_DWORD **)(v10 + 0x74);
  v12 = 0;
  v51 = 0;
  v52 = v11;
  v13 = 0x4000000;
  v14 = a6;
  *a6 = 0;
  if ( a1 >= 0 )
  {
    if ( (MmVerifierData & 0x100) != 0 && !(_BYTE)a4 )
    {
      VfCheckUserHandle(a1);
      v13 = 0x4000000;
    }
    --*(_WORD *)(v10 + 308);
    if ( v11 == *(_DWORD **)(v10 + 336) )
    {
      if ( (v11[48] & 0x4000000) == 0 )
        goto LABEL_134;
      v15 = v11[84];
    }
    else
    {
      v13 = ObReferenceProcessHandleTable((int)v11);
      v12 = 1;
      v51 = 1;
      v15 = v13;
    }
    if ( v15 )
    {
      if ( v15 == ObpKernelHandleTable )
        goto LABEL_63;
      goto LABEL_18;
    }
LABEL_134:
    v18 = -1073741816;
LABEL_38:
    v29 = (__int16)(*(_WORD *)(v10 + 308) + 1);
    *(_WORD *)(v10 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(v13);
    return v18;
  }
  if ( a1 == -1 )
  {
    if ( a3 != PsProcessType && a3 )
      return -1073741788;
    v40 = *(_DWORD *)(v10 + 116);
    if ( (a2 & 0xFFE00000) != 0 )
    {
      result = sub_7FFEB0();
    }
    else
    {
      v41 = (unsigned int *)(v40 - 24);
      if ( a7 )
      {
        *a7 = 0;
        a7[1] = 0x1FFFFF;
      }
      if ( ObpTraceFlags )
      {
        ObpPushStackInfo(v40 - 24, 1, 1u, a5);
        v14 = a6;
      }
      do
      {
        v42 = __ldrex(v41);
        v43 = v42 + 1;
      }
      while ( __strex(v43, v41) );
      __dmb(0xBu);
      if ( v43 <= 1 )
        KeBugCheckEx(24, 0, v40, 16, v43);
      result = 0;
      *v14 = v40;
    }
  }
  else
  {
    if ( a1 != -2 )
    {
      if ( a4 )
        return -1073741816;
      a1 ^= 0x80000000;
      v15 = ObpKernelHandleTable;
      --*(_WORD *)(v10 + 308);
LABEL_18:
      if ( (a1 & 0x7FC) != 0 )
      {
        v13 = ExpLookupHandleTableEntry(v15, a1);
        v20 = (_DWORD *)v13;
        if ( v13 )
        {
          v21 = ExFastReferenceHandleTableEntry(v15, (unsigned __int64 *)v13, v54);
          if ( v21 )
          {
            if ( v21 <= 0 )
            {
              do
              {
                while ( 1 )
                {
                  __pld(v20);
                  v13 = *v20;
                  if ( (*v20 & 1) != 0 )
                    break;
                  if ( !v13 )
                    goto LABEL_60;
                  ExpBlockOnLockedHandleEntry(v15, (unsigned __int64 *)v20, *v20);
                }
                do
                  v30 = __ldrex(v20);
                while ( v30 == v13 && __strex(v13 - 1, v20) );
                __dmb(0xBu);
              }
              while ( v30 != v13 );
              v54[0] = *(_QWORD *)v20;
              v23 = v54[0] & 0xFFFFFFF8;
              v31 = ExSlowReplenishHandleTableEntry((int)v20) + 1;
              do
                v32 = __ldrex((unsigned int *)v23);
              while ( __strex(v32 + v31, (unsigned int *)v23) );
              __dmb(0xBu);
              if ( v32 <= 0 )
                KeBugCheckEx(24, 0, v23 + 24, 16, v32 + v31);
              __dmb(0xBu);
              do
                v33 = __ldrex(v20);
              while ( __strex(v33 + 1, v20) );
              __dmb(0xBu);
              __dmb(0xFu);
              if ( *(_DWORD *)(v15 + 32) )
                ExfUnblockPushLock(v15 + 32, 0);
            }
            else
            {
              v23 = v54[0] & 0xFFFFFFF8;
              do
                v34 = __ldrex((unsigned int *)v23);
              while ( __strex(v34 + v21, (unsigned int *)v23) );
              __dmb(0xBu);
              if ( v34 <= 0 )
                KeBugCheckEx(24, 0, v23 + 24, 16, v34 + v21);
              v35 = ExFastReplenishHandleTableEntry((unsigned __int64 *)v20, (unsigned int *)v54, v21);
              if ( v35 )
              {
                __dmb(0xBu);
                v44 = -v35;
                do
                  v45 = __ldrex((unsigned int *)v23);
                while ( __strex(v45 + v44, (unsigned int *)v23) );
              }
            }
            v22 = v54[0];
          }
          else
          {
            v22 = v54[0];
            v23 = v54[0] & 0xFFFFFFF8;
          }
          if ( ObpTraceFlags )
          {
            ObpPushStackInfo(v23, 1, 1u, a5);
            v22 = v54[0];
          }
          v24 = BYTE1(v23) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v23 + 12);
          if ( !a3 || *(unsigned __int8 *)(a3 + 20) != v24 )
          {
            v28 = ObTypeIndexTable[v24];
            if ( !v28 || v28 == MmBadPointer )
              KeBugCheckEx(393, v23, v28, 0, 0);
            if ( a3 )
            {
              v18 = -1073741788;
LABEL_36:
              v13 = PspDereferenceSiloObject(v23 + 24);
              v12 = v51;
              v11 = v52;
LABEL_37:
              if ( v12 )
              {
                v13 = (int)(v11 + 43);
                __pld(v11 + 43);
                v49 = v11[43] & 0xFFFFFFFE;
                __dmb(0xBu);
                do
                  v50 = __ldrex((unsigned int *)v13);
                while ( v50 == v49 && __strex(v49 - 2, (unsigned int *)v13) );
                if ( v50 != v49 )
                  v13 = (int)ExfReleaseRundownProtection((unsigned __int8 *)v13);
              }
              goto LABEL_38;
            }
          }
          v25 = HIDWORD(v54[0]);
          v26 = HIDWORD(v54[0]) & 0x1FFFFFF;
          if ( v7 )
          {
            if ( (a2 & ~v26) != 0 )
            {
              v18 = -1073741790;
              goto LABEL_36;
            }
            if ( (*(_BYTE *)(v23 + 14) & 0x40) != 0 )
            {
              v27 = v23 - ObpInfoMaskToOffset[*(_BYTE *)(v23 + 14) & 0x7F];
              if ( v27 )
              {
                if ( *(_DWORD *)(v27 + 8) == 1 )
                {
                  v18 = -1073700858;
                  goto LABEL_36;
                }
                v22 = v54[0];
                v25 = HIDWORD(v54[0]);
              }
            }
          }
          v46 = v22 & 6;
          if ( a7 )
          {
            a7[1] = v26;
            if ( (v25 & 0x4000000) != 0 )
              v46 |= 8u;
            if ( (v25 & 0x2000000) != 0 )
              v46 |= 1u;
            v36 = v46 & 7;
            *a7 = v36;
            if ( (v36 & 4) != 0 )
            {
LABEL_69:
              v16 = 1;
LABEL_8:
              if ( !v16 || !a2 || (v25 = ObpAuditObjectAccess(v15, a1, v20, v23, a2)) != 0 )
              {
                *a6 = v23 + 24;
                if ( v51 )
                {
                  v25 = (int)(v52 + 43);
                  __pld(v52 + 43);
                  v47 = *(_DWORD *)v25 & 0xFFFFFFFE;
                  __dmb(0xBu);
                  do
                    v48 = __ldrex((unsigned int *)v25);
                  while ( v48 == v47 && __strex(v47 - 2, (unsigned int *)v25) );
                  if ( v48 != v47 )
                    v25 = (int)ExfReleaseRundownProtection((unsigned __int8 *)v25);
                }
                v17 = *(_WORD *)(v10 + 308) + 1;
                *(_WORD *)(v10 + 308) = v17;
                if ( !v17 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
                  KiCheckForKernelApcDelivery(v25);
                return 0;
              }
              v18 = -1073741816;
              goto LABEL_36;
            }
          }
          else
          {
            if ( (v25 & 0x4000000) != 0 )
              v46 |= 8u;
            if ( (v25 & 0x2000000) != 0 )
              v46 |= 1u;
            if ( (v46 & 4) != 0 )
              goto LABEL_69;
          }
          v16 = 0;
          goto LABEL_8;
        }
      }
LABEL_60:
      if ( a1 )
        v13 = ExHandleLogBadReference(v15, a1, *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
      v11 = v52;
LABEL_63:
      v18 = -1073741816;
      goto LABEL_37;
    }
    if ( a3 != PsThreadType && a3 )
      return -1073741788;
    if ( (a2 & 0xFFE00000) != 0 && (_BYTE)a4 )
      JUMPOUT(0x7FFEB8);
    v37 = (unsigned int *)(v10 - 24);
    if ( a7 )
    {
      *a7 = 0;
      a7[1] = 0x1FFFFF;
    }
    if ( ObpTraceFlags )
    {
      ObpPushStackInfo(v10 - 24, 1, 1u, a5);
      v14 = a6;
    }
    do
    {
      v38 = __ldrex(v37);
      v39 = v38 + 1;
    }
    while ( __strex(v39, v37) );
    __dmb(0xBu);
    if ( v39 <= 1 )
      KeBugCheckEx(24, 0, v10, 16, v39);
    result = 0;
    *v14 = v10;
  }
  return result;
}
