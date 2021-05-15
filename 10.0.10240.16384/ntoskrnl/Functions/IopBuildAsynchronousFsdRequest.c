// IopBuildAsynchronousFsdRequest 
 
_DWORD *__fastcall IopBuildAsynchronousFsdRequest(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, int a6, int a7)
{
  unsigned int v7; // r8
  int v9; // r6
  int v10; // r0
  _DWORD *v11; // r4
  int v13; // r5
  int v14; // r3
  int v15; // r0
  int v16; // r3
  int v17; // r0
  _DWORD *v18; // r1
  int v19; // r2
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v7 = a4;
  v9 = a1;
  v10 = pIoAllocateIrp(a2, *(char *)(a2 + 48), 0, a7);
  v11 = (_DWORD *)v10;
  if ( !v10 )
    return 0;
  *(_DWORD *)(v10 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_DWORD *)(v10 + 96) - 40;
  *(_BYTE *)v13 = v9;
  if ( v9 != 9 && v9 != 16 && v9 != 27 && v9 != 22 )
  {
    v14 = *(_DWORD *)(a2 + 28);
    if ( (v14 & 4) != 0 )
    {
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v16 = 40;
        else
          v16 = 32;
        v15 = ExAllocatePoolWithTagPriority(516, v7, 538996553, v16);
      }
      else
      {
        v15 = ExAllocatePoolWithTag(516, v7, 538996553);
      }
      v11[3] = v15;
      if ( !v15 )
        goto LABEL_15;
      if ( v9 == 4 )
      {
        memmove(v15, a3, v7);
        v11[2] = 48;
        goto LABEL_23;
      }
      v11[2] = 112;
    }
    else if ( (v14 & 0x10) != 0 )
    {
      v17 = IoAllocateMdl(a3, v7, 0, 0, 0);
      v11[1] = v17;
      if ( !v17 )
      {
LABEL_15:
        pIoFreeIrp(v11);
        return 0;
      }
      sub_441640(v17);
      goto LABEL_23;
    }
    v11[15] = a3;
LABEL_23:
    *(_DWORD *)(v13 + 8) = v7;
    if ( a5 )
    {
      *(_DWORD *)(v13 + 16) = *a5;
      *(_DWORD *)(v13 + 20) = a5[1];
    }
  }
  v18 = (_DWORD *)v11[20];
  v19 = (v18[240] >> 9) & 7;
  if ( (*(_DWORD *)(v18[84] + 192) & 0x100000) != 0 )
    v19 = 0;
  if ( v19 < 2 && v18 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
  {
    if ( v18[250] )
      v19 = 2;
  }
  v11[2] = v11[2] & 0xFFF1FFFF | ((v19 + 1) << 17);
  v11[10] = a6;
  return v11;
}
