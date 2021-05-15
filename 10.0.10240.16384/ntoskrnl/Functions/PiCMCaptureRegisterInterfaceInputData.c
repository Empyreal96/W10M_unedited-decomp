// PiCMCaptureRegisterInterfaceInputData 
 
int __fastcall PiCMCaptureRegisterInterfaceInputData(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // lr
  int v6; // r10
  int v7; // r6
  int v8; // r1
  unsigned int v9; // r2
  int v10; // r1
  unsigned int v11; // r2
  unsigned int v12; // r0
  unsigned int v13; // r0
  int v15; // [sp+Ch] [bp-34h]
  int v16; // [sp+10h] [bp-30h]

  v4 = a4;
  v5 = 0;
  v15 = 0;
  v16 = 0;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = 0;
  if ( !a1 || !a2 )
  {
    v7 = -1073741811;
    goto LABEL_33;
  }
  if ( (a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  if ( a1 + a2 > MmUserProbeAddress || a1 + a2 < a1 )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( a2 < 0x2C || (memmove(a4, a1, 0x2Cu), v5 = 0, *(_DWORD *)v4 != 44) )
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
          v5 = 0;
        }
        else
        {
          v5 = 1;
          v15 = 1;
          *(_WORD *)(*(_DWORD *)(v4 + 24) + 2 * (*(_DWORD *)(v4 + 28) >> 1) - 2) = 0;
        }
LABEL_22:
        v10 = *(_DWORD *)(v4 + 32);
        *(_DWORD *)(v4 + 32) = 0;
        if ( v10 )
        {
          v11 = *(_DWORD *)(v4 + 36);
          if ( v11 >= 2 )
          {
            v7 = PiControlMakeUserModeCallersCopy((int *)(v4 + 32), v10, v11, 2, v6, 1);
            v5 = v15;
            if ( v7 < 0 )
            {
              *(_DWORD *)(v4 + 32) = 0;
              *(_DWORD *)(v4 + 36) = 0;
            }
            else
            {
              v16 = 1;
              *(_WORD *)(*(_DWORD *)(v4 + 32) + 2 * (*(_DWORD *)(v4 + 36) >> 1) - 2) = 0;
            }
LABEL_33:
            if ( v7 >= 0 )
              return v7;
            goto LABEL_34;
          }
          if ( *(_DWORD *)(v4 + 36) >= 2u )
            goto LABEL_33;
        }
        else if ( !*(_DWORD *)(v4 + 36) )
        {
          goto LABEL_33;
        }
        goto LABEL_21;
      }
      if ( *(_DWORD *)(v4 + 28) >= 2u )
        goto LABEL_22;
    }
    else if ( !*(_DWORD *)(v4 + 28) )
    {
      goto LABEL_22;
    }
LABEL_21:
    v7 = -1073741811;
  }
LABEL_34:
  if ( v5 )
  {
    v12 = *(_DWORD *)(v4 + 24);
    if ( v6 )
    {
      if ( v12 )
        ExFreePoolWithTag(v12);
    }
  }
  if ( v16 )
  {
    v13 = *(_DWORD *)(v4 + 32);
    if ( v6 )
    {
      if ( v13 )
        ExFreePoolWithTag(v13);
    }
  }
  memset((_BYTE *)v4, 0, 44);
  return v7;
}
