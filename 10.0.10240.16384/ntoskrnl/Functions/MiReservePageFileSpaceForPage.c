// MiReservePageFileSpaceForPage 
 
int __fastcall MiReservePageFileSpaceForPage(__int16 *a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v5; // r6
  char v6; // r5
  int v7; // r10
  unsigned int v9; // r8
  int v10; // r4
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r3
  unsigned __int8 *v14; // r0
  unsigned int v15; // r2
  int v16; // r3
  __int16 v17; // r2
  int v18; // r2
  unsigned int v19; // r3
  int *v20; // r5
  int v21; // r6
  int v22; // r2
  int v23; // r3
  int v24; // r7
  int v25; // r0
  int v26; // r5
  unsigned int v27; // r3
  int v28; // r6
  int v29; // r0
  int v30; // r3
  unsigned int *v31; // r2
  unsigned int v32; // r5
  unsigned int v34; // [sp+8h] [bp-38h] BYREF
  int v35; // [sp+Ch] [bp-34h]
  __int16 *v36; // [sp+10h] [bp-30h]
  unsigned int v37; // [sp+14h] [bp-2Ch]
  int v38; // [sp+18h] [bp-28h] BYREF
  int v39; // [sp+1Ch] [bp-24h]
  __int16 *varg_r0; // [sp+48h] [bp+8h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  unsigned int *varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v5 = 0;
  v6 = a3;
  v39 = 0;
  v7 = 0;
  varg_r2 = a3;
  v36 = a1;
  v37 = 0;
  v9 = 0;
  while ( 1 )
  {
    v35 = 0;
    if ( (v6 & 0x80) != 0 )
    {
      v10 = 0;
    }
    else
    {
      v10 = MiLockLeafPage((unsigned int *)a2, 0);
      v6 = varg_r2;
      if ( v10 )
        v35 = 1;
    }
    v11 = *(_DWORD *)a2;
    v34 = v11;
    if ( (v11 & 2) != 0 )
      break;
    if ( (v11 & 0x400) != 0 )
      goto LABEL_98;
    if ( (v11 & 0x800) == 0 )
    {
      if ( v11 )
      {
        v13 = (v11 >> 5) & 0x1F;
        if ( v13 == 16 || !v13 )
          goto LABEL_98;
      }
      else
      {
        if ( (v6 & 2) == 0 )
          goto LABEL_98;
        v11 = 8 * (v6 & 0x7C);
        v39 = 1;
        v34 = v11;
      }
      goto LABEL_50;
    }
    if ( (v6 & 0x80) == 0 )
      goto LABEL_15;
    v12 = MiLockTransitionLeafPage((unsigned int *)a2, 0);
    v10 = v12;
    if ( v12 )
    {
      v35 = 1;
      if ( (*(_DWORD *)(v12 + 20) & 0x8000000) != 0 )
        goto LABEL_99;
      v6 = varg_r2;
LABEL_15:
      if ( MiSystemPartition != v36 )
        goto LABEL_98;
      v11 = *(_DWORD *)(v10 + 8);
      v34 = v11;
      if ( (v11 & 2) == 0
        && (v11 & 0xC00) == 0
        && (v11 & 0x10) == 0
        && (v11 & 8) == 0
        && (v11 & 0xFFFFE000) == 0x2000
        && (*(_BYTE *)(v10 + 18) & 0x10) == 0 )
      {
        goto LABEL_98;
      }
      goto LABEL_50;
    }
    v6 = varg_r2;
  }
  if ( (v6 & 0x80) != 0 )
  {
    v10 = MmPfnDatabase + 24 * (v11 >> 12);
    if ( (v6 & 1) == 0 )
    {
      v35 = 1;
      v14 = (unsigned __int8 *)(v10 + 15);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v15 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v16 = *(_DWORD *)(v10 + 12);
          __dmb(0xBu);
        }
        while ( v16 < 0 );
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 | 0x80, v14) );
      }
      v6 = varg_r2;
    }
    if ( (*(_DWORD *)(v10 + 20) & 0x8000000) != 0 )
      goto LABEL_98;
  }
  if ( !*(_DWORD *)v10 )
    goto LABEL_98;
  if ( MiSystemPartition != v36 )
    goto LABEL_98;
  if ( (*(_BYTE *)(v10 + 19) & 8) != 0 )
    goto LABEL_98;
  v17 = v11;
  v11 = *(_DWORD *)(v10 + 8);
  v34 = v11;
  if ( (v11 & 2) == 0
    && (v11 & 0xC00) == 0
    && (v11 & 0x10) == 0
    && (v11 & 8) == 0
    && (v11 & 0xFFFFE000) == 0x2000
    && (*(_BYTE *)(v10 + 18) & 0x10) == 0
    && ((v6 & 0x80) == 0 || (v17 & 0x200) != 0) )
  {
    goto LABEL_98;
  }
LABEL_50:
  if ( (v11 & 8) != 0 )
  {
    if ( (v6 & 1) != 0 )
      *a4 = v11;
  }
  else if ( !v10 || (*(_BYTE *)(v10 + 18) & 8) == 0 && (*(_BYTE *)(v10 + 18) & 0x20) == 0 )
  {
    if ( (v11 & 0x10) != 0 )
    {
      if ( !v10 )
        goto LABEL_98;
      if ( (v6 & 1) == 0 )
      {
        if ( !*(_WORD *)(v10 + 16) )
        {
          if ( !MiUnlinkPageFromList(v10, 0) )
          {
            MiDiscardTransitionPte(v10);
            goto LABEL_98;
          }
          v7 = 1;
        }
        v18 = *(_DWORD *)(v10 + 8);
        if ( (v18 & 0x10) != 0 )
        {
          *(_DWORD *)(v10 + 8) = v18 & 0xFFFFFFEF;
          v19 = v18 & 0xFFFFFFF7;
        }
        else
        {
          v19 = 0;
        }
        v37 = v19;
        *(_BYTE *)(v10 + 18) |= 0x10u;
        v6 = varg_r2;
      }
    }
    if ( (v6 & 1) == 0 )
    {
      MI_SET_PAGING_FILE_INFO(&v38, &v34, *(_DWORD *)&v36[2 * ((*a4 >> 2) & 1) + 1800], *a4 >> 13, 2);
      if ( v10 )
      {
        if ( !*(_WORD *)(v10 + 16) && (*(_BYTE *)(v10 + 18) & 0x10) != 0 && !v7 )
        {
          MiUnlinkPageFromList(v10, 0);
          v7 = 1;
        }
        v20 = (int *)(v10 + 8);
        v21 = v38;
        v22 = v10 + 1073741832;
        if ( (unsigned int)(v10 + 1073741832) > 0x3FFFFF )
        {
          *v20 = v38;
        }
        else
        {
          v23 = *v20;
          v24 = 0;
          __dmb(0xBu);
          v22 = 2;
          *v20 = v21;
          if ( (v23 & 2) == 0 && (v21 & 2) != 0 )
            v24 = 1;
          if ( (unsigned int)(v10 + 1070596104) <= 0xFFF )
          {
            v25 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v25, (_DWORD *)(v25 + 4 * ((unsigned __int16)v20 & 0xFFF)), v21);
          }
          if ( v24 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        if ( v7 )
          MiInsertPageInList(v10, 8, v22);
      }
      else
      {
        v26 = v38;
        if ( a2 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)a2 = v38;
        }
        else
        {
          v27 = *(_DWORD *)a2;
          v28 = 0;
          __dmb(0xBu);
          *(_DWORD *)a2 = v26;
          if ( (v27 & 2) == 0 && (v26 & 2) != 0 )
            v28 = 1;
          if ( a2 + 1070596096 <= 0xFFF )
          {
            v29 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v29, (_DWORD *)(v29 + 4 * (a2 & 0xFFF)), v26);
          }
          if ( v28 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
      }
      if ( v39 && a2 <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 && a2 >= 0xC0000000 )
        MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * (((a2 >> 12) & 0x3FF) - 534769440)), 1u);
    }
    v9 = v37;
    v5 = 1;
  }
LABEL_98:
  v30 = v35;
  if ( v35 != 1 )
    goto LABEL_101;
LABEL_99:
  __dmb(0xBu);
  v31 = (unsigned int *)(v10 + 12);
  do
  {
    v32 = __ldrex(v31);
    v30 = __strex(v32 & 0x7FFFFFFF, v31);
  }
  while ( v30 );
LABEL_101:
  if ( v9 )
    MiReleasePageFileInfo((int)v36, v9, 1, v30);
  return v5;
}
