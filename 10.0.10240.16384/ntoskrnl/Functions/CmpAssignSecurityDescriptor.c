// CmpAssignSecurityDescriptor 
 
int __fastcall CmpAssignSecurityDescriptor(int a1, unsigned int a2, int a3, _WORD *a4, unsigned __int8 a5)
{
  _WORD *v9; // r5
  int v10; // r0
  unsigned int v12; // r0
  unsigned int v13; // r0
  _WORD *v14; // r2
  unsigned int v15; // [sp+4h] [bp-24h]
  int v16; // [sp+8h] [bp-20h] BYREF
  int v17[7]; // [sp+Ch] [bp-1Ch] BYREF

  v15 = a2;
  v17[0] = (int)a4;
  v16 = -1;
  if ( !HvpMarkCellDirty(a1, a2, 0, 0) )
    return -1073741443;
  CmpUpdateKeyNodeAccessBits(a1, a3, a2);
  if ( !CmpFindMatchingDescriptorCell(a1, a4, a2 >> 31, v17, 0, v15, v16) )
  {
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)
      && (*(_DWORD *)(a1 + 3228) & 0x20) != 0
      && *(_DWORD *)(a1 + 1992) > 1u )
    {
      return -1073741790;
    }
    v12 = RtlLengthSecurityDescriptor((int)a4);
    v9 = (_WORD *)HvAllocateCell(a1, v12 + 20);
    if ( v9 != (_WORD *)-1 )
    {
      v13 = RtlLengthSecurityDescriptor((int)a4);
      v14 = (_WORD *)v17[0];
      *(_WORD *)v17[0] = 27507;
      *((_DWORD *)v14 + 3) = 1;
      *((_DWORD *)v14 + 4) = v13;
      memmove((int)(v14 + 10), (int)a4, v13);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
      if ( !CmpInsertSecurityCellList(a1, a2, (int)v9, a5) )
        return sub_8057D0();
      goto LABEL_6;
    }
    return -1073741670;
  }
  v9 = (_WORD *)v17[0];
  if ( !HvpMarkCellDirty(a1, v17[0], 0, 0) )
    return -1073741443;
  v10 = (*(int (__fastcall **)(int, _WORD *, int *))(a1 + 4))(a1, v9, &v16);
  if ( !v10 )
    return -1073741670;
  ++*(_DWORD *)(v10 + 12);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
LABEL_6:
  *(_DWORD *)(a3 + 44) = v9;
  return 0;
}
