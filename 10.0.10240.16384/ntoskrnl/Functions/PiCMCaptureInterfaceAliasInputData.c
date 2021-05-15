// PiCMCaptureInterfaceAliasInputData 
 
int __fastcall PiCMCaptureInterfaceAliasInputData(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r8
  int v6; // r9
  int v7; // r5
  int v8; // r1
  unsigned int v9; // lr
  unsigned int v10; // r0

  v4 = a4;
  v5 = 0;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = 0;
  if ( !a1 || !a2 )
  {
    v7 = -1073741811;
    goto LABEL_23;
  }
  if ( (a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  if ( a1 + a2 > MmUserProbeAddress || a1 + a2 < a1 )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( a2 < 0x24 || (memmove(a4, a1, 0x24u), *(_DWORD *)v4 != 36) )
    v7 = -1073741811;
  if ( v7 >= 0 )
  {
    v8 = *(_DWORD *)(v4 + 24);
    *(_DWORD *)(v4 + 24) = 0;
    if ( v8 )
    {
      v9 = *(_DWORD *)(v4 + 28);
      if ( v9 >= 2 )
      {
        v7 = PiControlMakeUserModeCallersCopy((int *)(v4 + 24), v8, v9, 2, v6, 1);
        if ( v7 < 0 )
        {
          *(_DWORD *)(v4 + 24) = 0;
          *(_DWORD *)(v4 + 28) = 0;
        }
        else
        {
          v5 = 1;
          *(_WORD *)(*(_DWORD *)(v4 + 24) + 2 * (*(_DWORD *)(v4 + 28) >> 1) - 2) = 0;
        }
LABEL_23:
        if ( v7 >= 0 )
          return v7;
        goto LABEL_24;
      }
      if ( *(_DWORD *)(v4 + 28) >= 2u )
        goto LABEL_23;
    }
    else if ( !*(_DWORD *)(v4 + 28) )
    {
      goto LABEL_23;
    }
    v7 = -1073741811;
  }
LABEL_24:
  if ( v5 )
  {
    v10 = *(_DWORD *)(v4 + 24);
    if ( v6 )
    {
      if ( v10 )
        ExFreePoolWithTag(v10);
    }
  }
  memset((_BYTE *)v4, 0, 36);
  return v7;
}
