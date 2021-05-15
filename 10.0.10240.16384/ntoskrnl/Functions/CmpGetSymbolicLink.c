// CmpGetSymbolicLink 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpGetSymbolicLink(int a1, unsigned int a2, _DWORD *a3, _DWORD *a4, unsigned __int16 *a5)
{
  _DWORD *v5; // r4
  _DWORD *v6; // r5
  unsigned __int16 *v7; // r7
  unsigned int v8; // r10
  unsigned int v9; // r8
  unsigned int *v10; // r9
  int v11; // r6
  unsigned __int16 *v12; // r0
  int v13; // r3
  int v14; // r2
  int v15; // r4
  int v16; // r6
  unsigned int *v17; // r5
  int v19; // r0
  int v20; // r0
  int v21; // r4 OVERLAPPED
  unsigned int v22; // r9
  unsigned int v23; // r0
  int v24; // r3
  int v25; // r0
  int v26; // r4
  int v27; // r10
  int v28; // r4
  int v29; // r0
  int v30; // r0
  unsigned __int16 *v31; // r4
  unsigned __int16 *v32; // r2
  int v33; // r1
  unsigned int v34; // r4
  unsigned int v35; // r5
  unsigned int v36; // r0
  unsigned int v37; // t1
  int v38; // r4
  int v39; // r0
  int v40; // r4
  unsigned int v41; // r0
  _DWORD *v42; // r4
  unsigned int v43; // r2
  unsigned __int16 *v44; // r0
  unsigned int v45; // r1
  unsigned __int16 *v46; // r2
  unsigned int v47; // r0
  int v48; // r3
  unsigned int v49; // r0
  int v50; // r0
  _DWORD *v51; // r4
  int v52; // r3
  int v53; // r0
  unsigned int v54; // r2
  unsigned int v55; // r0
  _WORD *v56; // r2
  int v57; // t1
  _DWORD *v58; // r6
  char v59[4]; // [sp+10h] [bp-90h] BYREF
  int v60; // [sp+14h] [bp-8Ch]
  int v61; // [sp+18h] [bp-88h]
  unsigned __int16 *v62; // [sp+1Ch] [bp-84h]
  _DWORD *v63; // [sp+20h] [bp-80h] BYREF
  unsigned int *v64; // [sp+24h] [bp-7Ch] BYREF
  unsigned int *v65; // [sp+28h] [bp-78h]
  int v66; // [sp+2Ch] [bp-74h] BYREF
  unsigned int v67; // [sp+30h] [bp-70h]
  unsigned int v68; // [sp+34h] [bp-6Ch]
  int v69; // [sp+38h] [bp-68h] BYREF
  int v70; // [sp+3Ch] [bp-64h]
  int v71; // [sp+40h] [bp-60h]
  _DWORD *v72; // [sp+44h] [bp-5Ch]
  unsigned int v73; // [sp+48h] [bp-58h]
  _DWORD *v74; // [sp+50h] [bp-50h] BYREF
  _WORD *v75; // [sp+54h] [bp-4Ch]
  int v76[2]; // [sp+58h] [bp-48h] BYREF
  unsigned __int16 *v77; // [sp+60h] [bp-40h]
  int v78; // [sp+64h] [bp-3Ch] BYREF
  char v79[4]; // [sp+68h] [bp-38h] BYREF
  int v80; // [sp+6Ch] [bp-34h]
  unsigned __int16 *v81; // [sp+70h] [bp-30h]
  int v82; // [sp+74h] [bp-2Ch] BYREF
  int v83; // [sp+78h] [bp-28h]
  int v84[9]; // [sp+7Ch] [bp-24h] BYREF

  v5 = a4;
  v6 = a3;
  v7 = (unsigned __int16 *)a2;
  v60 = a1;
  v61 = 0;
  v67 = 0;
  v68 = -1;
  v76[0] = -1;
  v80 = 0;
  v81 = 0;
  v78 = -1;
  v62 = 0;
  v63 = 0;
  v82 = -1;
  v83 = 0;
  v59[0] = 0;
  v8 = 0;
  v9 = 0;
  v65 = 0;
  v66 = 0;
  v10 = 0;
  v71 = 0;
  v72 = a4;
  v64 = 0;
  v74 = a3;
  v73 = a2;
  v11 = 0;
  CmpLockKcbShared(a3);
  v77 = (unsigned __int16 *)1;
  if ( (v6[1] & 0x20000) != 0 )
    JUMPOUT(0x80476A);
  while ( 1 )
  {
    if ( (v6[1] & 8) == 0 )
      goto LABEL_7;
    if ( v11 )
      break;
    v10 = (unsigned int *)v6[14];
    if ( CmpIsKcbLockAllowed(v6, v10, v79) == 1 )
    {
      v19 = CmpLockKcbShared(v10);
    }
    else
    {
      CmpUnlockKcb(v6);
      v19 = CmpLockTwoKcbsShared(v6, v10);
    }
    v11 = 1;
    if ( (v10[1] & 0x20000) != 0 )
      JUMPOUT(0x804696);
    if ( (v6[1] & 0x20000) != 0 )
      return sub_80468C(v19);
  }
  v12 = (unsigned __int16 *)CmpConstructName(v6[14]);
  v81 = v12;
  if ( v12 )
  {
    v9 = *v12;
    v71 = 1;
    v13 = *((_DWORD *)v12 + 1);
    v66 = v9;
    v8 = v9 + 2;
    v62 = (unsigned __int16 *)v13;
    v63 = (_DWORD *)v13;
  }
  v5 = v72;
LABEL_7:
  if ( v5 )
  {
    if ( !v5[11] )
    {
      v14 = v6[5];
      if ( (*(_DWORD *)(v14 + 3228) & 1) != 0 )
        v5[11] = v14;
    }
  }
  if ( v11 )
  {
    CmpUnlockKcb(v10);
    v11 = 0;
  }
  if ( v71 )
    goto LABEL_14;
  v84[0] = -1;
  v25 = v6[5];
  v69 = 0;
  CmpLockHiveFlusherShared(v25);
  v26 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v6[5] + 4))(v6[5], v6[6], v84);
  if ( !v26 )
    JUMPOUT(0x8046A4);
  CmpUpdateKeyNodeAccessBits(v6[5], v26, v6[6]);
  CmpUnlockHiveFlusher(v6[5]);
  if ( v6[38] )
    JUMPOUT(0x8046B0);
  CmpFindNameInListWithStatus(v60, (_DWORD *)(v26 + 36), (int)CmSymbolicLinkValueName, 0, 0, v76);
  v27 = v76[0];
  (*(void (__fastcall **)(_DWORD, int *))(v6[5] + 8))(v6[5], v84);
  if ( v27 == -1 )
    JUMPOUT(0x8046AA);
  v28 = v60;
  v29 = (*(int (__fastcall **)(int, int, int *))(v60 + 4))(v60, v27, &v78);
  v80 = v29;
  if ( !v29 )
    JUMPOUT(0x8046A8);
  if ( *(_DWORD *)(v29 + 12) != 6 )
    JUMPOUT(0x8046CC);
  v83 = 1;
  if ( !CmpGetValueData(v60, v27, v29, &v66, &v63, v59, &v82) )
    JUMPOUT(0x8046D0);
  (*(void (__fastcall **)(int, int *))(v28 + 8))(v28, &v78);
  v9 = v66;
  v80 = 0;
  v68 = (unsigned __int16)v66;
  v8 = (unsigned __int16)v66 + 2;
  v61 = (unsigned __int8)v59[0];
  if ( v59[0] )
    JUMPOUT(0x8046E8);
  v30 = ExAllocatePoolWithTag(1, v66, 1685474627);
  v31 = (unsigned __int16 *)v30;
  v62 = (unsigned __int16 *)v30;
  if ( !v30 )
    JUMPOUT(0x8046DE);
  memmove(v30, (int)v63, v9);
  (*(void (__fastcall **)(int, int *))(v60 + 8))(v60, &v82);
  v61 = 1;
  v32 = v31;
  if ( v9 < 2 || *v31 != 92 )
    JUMPOUT(0x804740);
  v33 = 0;
  v66 = 0;
  v34 = ((v9 - 1) >> 1) + 1;
  v35 = 0;
  do
  {
    v37 = *v32++;
    v36 = v37;
    v77 = v32;
    if ( v37 == 92 )
    {
      v66 = ++v33;
    }
    else
    {
      if ( v36 >= 0x61 )
      {
        if ( v36 > 0x7A )
        {
          v36 = RtlUpcaseUnicodeChar(v36);
          v32 = v77;
          v33 = v66;
        }
        else
        {
          v36 -= 32;
        }
      }
      v35 = 37 * v35 + v36;
    }
    --v34;
  }
  while ( v34 );
  v7 = (unsigned __int16 *)v73;
  v38 = (int)v62;
  v67 = v35;
  v6 = v74;
  CmpUnlockKcb(v74);
  v77 = 0;
  v73 = v38;
  v75 = (_WORD *)v38;
  HIWORD(v74) = v9;
  LOWORD(v74) = v9;
  v39 = CmpParseCacheLookup(-1, (unsigned __int16 *)&v74, (int)v76, (int)&v69, (int)&v64);
  v15 = v39;
  if ( v39 == -1073741772 )
  {
    if ( CmpLoadingSystemHivesActive )
    {
      v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( CmpMountThread != v54 )
      {
        v55 = v68;
        if ( v68 )
        {
          v56 = (_WORD *)v73;
          while ( *v56 == 92 )
          {
            v55 = (unsigned __int16)(v55 - 2);
            ++v56;
            LOWORD(v74) = v55;
            v75 = v56;
            if ( !v55 )
              goto LABEL_112;
          }
          for ( ; v55; v75 = v56 )
          {
            v57 = (unsigned __int16)*v56++;
            if ( v57 == 92 )
              break;
            v55 = (unsigned __int16)(v55 - 2);
            LOWORD(v74) = v55;
          }
        }
LABEL_112:
        v58 = v72;
        if ( CmpWaitForHiveMount(&v74, 1, 0, v72 + 19) )
        {
          v15 = 0;
          *v58 |= 0x100u;
        }
      }
    }
  }
  else if ( v39 >= 0 )
  {
    v40 = (int)v64;
    v41 = v64[5];
    v65 = v64;
    CmpLockHashEntryExclusive(v41, v67);
    v42 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v40 + 20) + 1844)
                     + 12
                     * (((101027 * (v67 ^ (v67 >> 9))) ^ ((101027 * (v67 ^ (v67 >> 9))) >> 9)) & (*(_DWORD *)(*(_DWORD *)(v40 + 20) + 1848)
                                                                                                - 1))
                     + 8);
    v63 = v42;
    if ( v42 )
    {
      while ( 1 )
      {
        v10 = v42 - 3;
        CmpLockTwoKcbsExclusive((unsigned int)v6, (unsigned int)(v42 - 3));
        v43 = *(v42 - 2);
        v11 = 1;
        if ( (v43 & 0x20000) == 0 && v67 == *v42 && v66 == ((v43 >> 21) & 0x3FF) && (v43 & 0x10) == 0 )
          break;
        v42 = (_DWORD *)v42[1];
        v63 = v42;
        CmpUnlockTwoKcbs(v6, v10);
        v11 = 0;
        if ( !v42 )
          goto LABEL_67;
      }
      v44 = (unsigned __int16 *)CmpConstructName(v42 - 3);
      v81 = v44;
      if ( v44 )
      {
        v45 = *v44;
        v71 = 1;
        v73 = v45;
        if ( v45 != v9 )
          goto LABEL_130;
        v68 = 0;
        v46 = v62;
        v76[0] = (int)v62;
        if ( v45 )
        {
          v69 = *((_DWORD *)v44 + 1) - (_DWORD)v62;
          while ( 1 )
          {
            v47 = *v46;
            if ( v47 >= 0x61 )
            {
              if ( v47 > 0x7A )
              {
                v53 = RtlUpcaseUnicodeChar(v47);
                v46 = (unsigned __int16 *)v76[0];
                v48 = v53;
              }
              else
              {
                v48 = v47 - 32;
              }
            }
            else
            {
              v48 = *v46;
            }
            v64 = (unsigned int *)v48;
            v49 = *(unsigned __int16 *)((char *)v46 + v69);
            if ( v49 >= 0x61 )
            {
              if ( v49 > 0x7A )
              {
                v49 = RtlUpcaseUnicodeChar(v49);
                v46 = (unsigned __int16 *)v76[0];
                v48 = (int)v64;
              }
              else
              {
                v49 -= 32;
              }
            }
            if ( v48 != v49 )
              break;
            ++v46;
            v68 += 2;
            v76[0] = (int)v46;
            if ( v68 >= v73 )
              goto LABEL_84;
          }
LABEL_130:
          JUMPOUT(0x8046F0);
        }
LABEL_84:
        if ( CmpReferenceKeyControlBlock(v10) )
        {
          v50 = v6[5];
          if ( (*(_DWORD *)(v50 + 3228) & 1) == 0 )
            v50 = 0;
          if ( !CmpOKToFollowLink(v50, v42[2]) || ((*(_DWORD *)(v42[2] + 3228) ^ *(_DWORD *)(v6[5] + 3228)) & 0x20) != 0 )
            JUMPOUT(0x80470E);
          CmpCleanUpKcbValueCache(v6);
          v51 = v72;
          if ( !v72[12] )
            v72[12] = v6;
          if ( (unsigned int *)v51[12] == v10 )
            JUMPOUT(0x804702);
          v52 = v6[1];
          v6[14] = v10;
          *((_WORD *)v6 + 2) = v52 | 8;
        }
      }
    }
LABEL_67:
    CmpUnlockHashEntry(v65[5], v67);
    if ( v11 )
    {
      if ( (v6[1] & 0x20000) != 0 || (v10[1] & 0x20000) != 0 )
        JUMPOUT(0x804730);
      CmpUnlockTwoKcbs(v10, v6);
    }
LABEL_14:
    if ( a5 )
      v8 += *a5 + 2;
    if ( v8 > 0xFFFF )
    {
      v15 = -1073741772;
    }
    else
    {
      if ( v8 > v7[1] )
      {
        v20 = ExAllocatePoolWithTag(1, v8, 538987843);
        v21 = v20;
        if ( !v20 )
          JUMPOUT(0x804748);
        v22 = (unsigned __int16)v9;
        v70 = v20;
        HIWORD(v69) = v8;
        LOWORD(v69) = v9;
        memmove(v20, (int)v62, v9);
        if ( a5 )
        {
          *(_WORD *)(v21 + 2 * (v9 >> 1)) = 92;
          LOWORD(v69) = v9 + 2;
          RtlAppendUnicodeStringToString((unsigned __int16 *)&v69, a5);
          v21 = v70;
          v22 = (unsigned __int16)v69;
        }
        *(_WORD *)(v21 + 2 * (v22 >> 1)) = 0;
        v23 = *((_DWORD *)v7 + 1);
        if ( v23 )
          ExFreePoolWithTag(v23);
        v24 = v69;
        *(_QWORD *)v7 = *(_QWORD *)(&v21 - 1);
      }
      else
      {
        *v7 = v9;
        if ( a5 )
        {
          memmove(*((_DWORD *)v7 + 1) + 2 * (v9 >> 1) + 2, *((_DWORD *)a5 + 1), *a5);
          *(_WORD *)(*((_DWORD *)v7 + 1) + 2 * (v9 >> 1)) = 92;
          *v7 += *a5 + 2;
        }
        memmove(*((_DWORD *)v7 + 1), (int)v62, v9);
        *(_WORD *)(*((_DWORD *)v7 + 1) + 2 * (*v7 >> 1)) = 0;
      }
      v15 = 0;
      *v72 |= 0x10u;
    }
    v16 = v61;
    if ( v77 )
    {
      CmpUnlockKcb(v6);
      if ( v80 )
        JUMPOUT(0x80474E);
    }
    v17 = v65;
    goto LABEL_25;
  }
  v17 = v64;
  v16 = v61;
LABEL_25:
  if ( v62 && v83 )
  {
    if ( !v16 )
      JUMPOUT(0x80475E);
    ExFreePoolWithTag((unsigned int)v62);
  }
  if ( v71 )
    ExFreePoolWithTag((unsigned int)v81);
  if ( v17 )
    CmpDereferenceKeyControlBlock(v17);
  return v15;
}
