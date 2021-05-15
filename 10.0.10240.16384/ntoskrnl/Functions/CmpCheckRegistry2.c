// CmpCheckRegistry2 
 
int __fastcall CmpCheckRegistry2(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, int *a7)
{
  int v8; // r6
  int v11; // r8
  int v12; // r0
  int v14; // r6
  int v15; // r4
  int v16; // r3
  int v17; // r1
  int v18; // t1
  _DWORD *v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  __int64 v22; // r2
  int v23; // r10
  unsigned int v24; // r4
  int v25; // r1
  int v26; // r3
  int v27; // [sp+0h] [bp-38h]
  int v28; // [sp+8h] [bp-30h]
  int v29; // [sp+Ch] [bp-2Ch]
  int v30; // [sp+10h] [bp-28h] BYREF
  int v31[9]; // [sp+14h] [bp-24h] BYREF

  v8 = *(_DWORD *)(a1 + 28);
  v28 = v8;
  v30 = -1;
  v11 = 0;
  v12 = ExAllocatePoolWithTag(1, 10240, 1935887683);
  v29 = v12;
  if ( !v12 )
    return sub_7FC1E4();
  *(_DWORD *)(v8 + 216) = v12;
  *(_DWORD *)v12 = a3;
  *(_DWORD *)(v12 + 4) = -1;
  *a7 = 0;
  *(_QWORD *)(v12 + 8) = 0xFFFFFFFFi64;
  *(_BYTE *)(v12 + 16) = 0;
  v14 = 0;
  v15 = v12;
  while ( 1 )
  {
    if ( *(_BYTE *)(v15 + 16) )
      goto LABEL_12;
    v16 = *a7;
    *(_BYTE *)(v15 + 16) = 1;
    if ( v16 != -1 )
      *a7 = v16 + 1;
    v11 = CmpCheckKey(a1, a2, *(_DWORD *)v15, *(_DWORD *)(v15 + 4), a5, a6);
    if ( v11 )
      break;
    if ( v14 > 0 )
    {
      v17 = *(_DWORD *)(v15 - 12);
      if ( v17 != -1 && !CmpCheckLexicographicalOrder(a1, v17, *(_DWORD *)v15) )
      {
        v23 = v28;
        v11 = 4091;
        SetFailureLocation(v28, 0, 13, 4091, 48);
        goto LABEL_34;
      }
      *(_DWORD *)(v15 - 12) = *(_DWORD *)v15;
    }
LABEL_12:
    v18 = *(_DWORD *)v15;
    v15 += 20;
    v19 = (_DWORD *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v18, &v30);
    if ( !v19 )
    {
      v23 = v28;
      v11 = 4098;
      SetFailureLocation(v28, 0, 13, 4098, 64);
      goto LABEL_22;
    }
    v20 = *(_DWORD *)(v15 - 8);
    if ( v20 < v19[5] )
    {
      v21 = CmpFindSubKeyByNumber(a1, v19, v20, v31);
      if ( v21 < 0 || (LODWORD(v22) = v31[0], v31[0] == -1) )
      {
        v27 = 80;
        v26 = v21;
        v11 = 4097;
      }
      else
      {
        ++v14;
        ++*(_DWORD *)(v15 - 8);
        if ( v14 != 512 )
        {
          HIDWORD(v22) = *(_DWORD *)(v15 - 20);
          *(_QWORD *)v15 = v22;
          *(_DWORD *)(v15 + 8) = -1;
          *(_DWORD *)(v15 + 12) = 0;
          *(_BYTE *)(v15 + 16) = 0;
          goto LABEL_15;
        }
        v11 = 4096;
        v27 = 96;
        v26 = 4096;
      }
      v23 = v28;
      SetFailureLocation(v28, 0, 13, v26, v27);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v30);
      goto LABEL_22;
    }
    --v14;
    v15 -= 40;
LABEL_15:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v30);
    if ( v14 < 0 )
    {
      v23 = v28;
      goto LABEL_22;
    }
  }
  v25 = CmpSelfHeal || (CmpBootType & 6) != 0;
  v23 = v28;
  SetFailureLocation(v28, v25, 13, v11, 16);
LABEL_34:
  if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
  {
LABEL_22:
    v24 = v29;
    goto LABEL_23;
  }
  v24 = v29;
  if ( v14 )
  {
    if ( CmpRemoveSubKeyCellNoCellRef(a1, *(_DWORD *)(v29 + 20 * v14 + 4), *(_DWORD *)(v29 + 20 * v14)) )
    {
      v11 = -1;
      *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
    }
    else
    {
      SetFailureLocation(v23, 0, 13, v11, 32);
    }
  }
LABEL_23:
  ExFreePoolWithTag(v24);
  if ( !v11 && (a2 & 0x20000) == 0 && !CmpCheckAndFixSecurityCellsRefcount(a1) )
  {
    v11 = 4099;
    SetFailureLocation(v23, 0, 13, 4099, 112);
  }
  return v11;
}
