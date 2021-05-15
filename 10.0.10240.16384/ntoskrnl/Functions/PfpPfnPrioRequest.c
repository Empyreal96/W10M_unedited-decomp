// PfpPfnPrioRequest 
 
int __fastcall PfpPfnPrioRequest(_DWORD *a1, int a2, unsigned int *a3, int a4)
{
  int v5; // r8
  int v7; // r4
  int v8; // r2
  int v9; // r5
  unsigned int v10; // r1
  _DWORD *v11; // r1
  unsigned int v12; // r0
  int v13; // r0
  unsigned int v14; // r1
  int v15; // r2
  unsigned int v16; // r8
  int v18; // [sp+8h] [bp-28h] BYREF
  unsigned int v19; // [sp+Ch] [bp-24h]
  _DWORD _10[14]; // [sp+10h] [bp-20h] BYREF

  _10[10] = a1;
  _10[11] = a2;
  _10[13] = a4;
  v19 = (unsigned int)a3;
  _10[0] = a4;
  _10[12] = a3;
  v5 = (char)a2;
  v7 = 0;
  v18 = 0;
  v8 = a1[2];
  if ( v8 != 6 )
  {
    if ( v8 != 7 && v8 != 22 )
    {
      v9 = -1073741821;
      goto LABEL_23;
    }
    v10 = a1[4];
    if ( v10 >= 0x78 )
    {
      v9 = PfpCopyUserPfnPrioRequest(a1[3], v10, v8, &v18, v5, 0);
      if ( v9 >= 0 )
      {
        v7 = v18;
        v11 = (_DWORD *)(v18 + 104);
        v12 = *(_DWORD *)(v18 + 8);
        if ( a1[2] == 7 )
          v13 = MmSetPfnListPriorities(v12, v11);
        else
          v13 = MmRelocatePfnList(v12, v11, *(unsigned __int16 *)(v18 + 4), *(unsigned __int16 *)(v18 + 6));
        v9 = v13;
        if ( v5 )
          ProbeForWrite(a1[3], a1[4], 8);
LABEL_21:
        v19 = 104;
        v16 = 16 * *(_DWORD *)(v7 + 8) + 104;
        v19 = v16;
        memmove(a1[3], v7, v16);
        *a3 = v16;
        goto LABEL_23;
      }
      goto LABEL_22;
    }
LABEL_14:
    v9 = -1073741306;
    goto LABEL_23;
  }
  v14 = a1[4];
  if ( v14 < 0x78 )
    goto LABEL_14;
  v9 = PfpCopyUserPfnPrioRequest(a1[3], v14, 6, &v18, v5, 1);
  if ( v9 >= 0 )
  {
    v7 = v18;
    v9 = MmQueryPfnList(*(_DWORD *)(v18 + 8), (int *)(v18 + 104));
    if ( v9 >= 0 && (*(_DWORD *)(v7 + 4) & 1) != 0 )
      MmQueryMemoryListInformation(v7 + 12, 0x58u, v15, _10);
    if ( v5 )
      ProbeForWrite(a1[3], a1[4], 8);
    goto LABEL_21;
  }
LABEL_22:
  v7 = v18;
LABEL_23:
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v9;
}
