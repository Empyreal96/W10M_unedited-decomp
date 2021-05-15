// PiDevCfgQueryIncludedDriverNode 
 
int __fastcall PiDevCfgQueryIncludedDriverNode(int a1, int a2, unsigned __int16 *a3, int a4, _DWORD *a5)
{
  unsigned __int16 *v6; // r7
  int v9; // r0
  int v10; // r4
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r1
  int v17; // r0
  int v18; // r0
  int v19; // r0
  _BYTE *v20; // r0
  _DWORD *v21; // r5
  int v22; // r2
  int v23; // r0
  int v25; // [sp+10h] [bp-30h] BYREF
  int v26; // [sp+14h] [bp-2Ch] BYREF
  int v27; // [sp+18h] [bp-28h] BYREF
  int v28; // [sp+1Ch] [bp-24h]

  v6 = (unsigned __int16 *)a2;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  if ( !a2 )
  {
    v13 = PiDevCfgOpenDriverConfiguration(*(_DWORD *)(a1 + 8), a3, &v26);
    v10 = v13;
    if ( v13 == -1073741772 )
    {
      v10 = 0;
    }
    else if ( v13 < 0 )
    {
      goto LABEL_53;
    }
    v14 = v26;
    if ( v26 )
    {
      v6 = *(unsigned __int16 **)(a1 + 24);
LABEL_20:
      if ( *(_DWORD *)(a1 + 32) )
      {
        v15 = ExpAllocateStringRoutine(*(unsigned __int16 *)(a1 + 30));
        v28 = v15;
        if ( !v15 )
        {
LABEL_7:
          v10 = -1073741670;
          goto LABEL_53;
        }
        memmove(v15, *(_DWORD *)(a1 + 32), *(unsigned __int16 *)(a1 + 30));
      }
      else
      {
        v28 = 0;
      }
      v16 = *(_DWORD *)(a1 + 8);
      v27 = *(_DWORD *)(a1 + 28);
      v10 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v16, 0, 0);
      goto LABEL_25;
    }
    v6 = *(unsigned __int16 **)(a1 + 196);
    if ( v6 )
    {
      if ( *v6 )
      {
        while ( 1 )
        {
          v17 = PiDevCfgGetDriverPackageId((int)v6, (int)&v27);
          v10 = v17;
          if ( v17 == -1073741772 )
            goto LABEL_9;
          if ( v17 < 0 )
            goto LABEL_53;
          v18 = PnpOpenObjectRegKey(PiPnpRtlCtx, v28, 7, 131097, 0, (int)&v25, 0, 0);
          v10 = v18;
          if ( v18 == -1073741772 )
          {
            v10 = -1073741072;
LABEL_39:
            v14 = v26;
            break;
          }
          if ( v18 < 0 )
            goto LABEL_53;
          v19 = PiDevCfgOpenDriverConfiguration(v25, a3, &v26);
          v10 = v19;
          if ( v19 < 0 )
          {
            if ( v19 != -1073741772 )
              goto LABEL_39;
            v10 = 0;
            ZwClose();
            v25 = 0;
            RtlFreeAnsiString(&v27);
            v6 += wcslen(v6) + 1;
            if ( *v6 )
              continue;
          }
          v14 = v26;
          goto LABEL_41;
        }
      }
      if ( v10 < 0 )
      {
LABEL_54:
        v22 = v25;
        goto LABEL_55;
      }
LABEL_41:
      if ( v14 )
        goto LABEL_42;
    }
    v10 = -1073741685;
    goto LABEL_57;
  }
  if ( !wcsicmp(a2, *(unsigned __int16 **)(a1 + 24)) )
  {
    v9 = PiDevCfgOpenDriverConfiguration(*(_DWORD *)(a1 + 8), a3, &v26);
    v10 = v9;
    if ( v9 == -1073741772 )
    {
LABEL_4:
      v10 = -1073741685;
LABEL_53:
      v14 = v26;
      goto LABEL_54;
    }
    if ( v9 < 0 )
      goto LABEL_53;
    goto LABEL_20;
  }
  v11 = PiDevCfgGetDriverPackageId((int)v6, (int)&v27);
  v10 = v11;
  if ( v11 == -1073741772 )
    goto LABEL_9;
  if ( v11 < 0 )
    goto LABEL_53;
  v12 = PnpOpenObjectRegKey(PiPnpRtlCtx, v28, 7, 131097, 0, (int)&v25, 0, 0);
  v10 = v12;
  if ( v12 == -1073741772 )
  {
LABEL_9:
    v10 = -1073741072;
    goto LABEL_53;
  }
  if ( v12 < 0 )
    goto LABEL_53;
  v10 = PiDevCfgOpenDriverConfiguration(v25, a3, &v26);
  if ( v10 == -1073741772 )
    goto LABEL_4;
LABEL_25:
  if ( v10 < 0 )
    goto LABEL_53;
LABEL_42:
  v20 = (_BYTE *)ExAllocatePoolWithTag(1, 240, 1667526736);
  v21 = v20;
  if ( !v20 )
    goto LABEL_7;
  memset(v20, 0, 240);
  v21[25] = 32;
  v21[32] = v21 + 32;
  v21[33] = v21 + 32;
  v21[30] = v21 + 30;
  v21[31] = v21 + 30;
  v21[52] = v21 + 52;
  v21[53] = v21 + 52;
  if ( !RtlCreateUnicodeString((int)(v21 + 5), v6) )
  {
LABEL_44:
    v10 = -1073741670;
    v22 = v25;
    v14 = v26;
    goto LABEL_51;
  }
  if ( v28 )
  {
    v23 = ExpAllocateStringRoutine(HIWORD(v27));
    v21[8] = v23;
    if ( !v23 )
      goto LABEL_44;
    memmove(v23, v28, HIWORD(v27));
  }
  else
  {
    v21[8] = 0;
  }
  v21[7] = v27;
  if ( !RtlCreateUnicodeString((int)(v21 + 11), a3) )
    goto LABEL_44;
  v21[13] = a4;
  v22 = 0;
  v14 = 0;
  v21[2] = v25;
  v21[4] = v26;
  v25 = 0;
  v26 = 0;
  *a5 = v21;
  v21 = 0;
LABEL_51:
  if ( v21 )
  {
    PiDevCfgFreeDriverNode();
    goto LABEL_53;
  }
LABEL_55:
  if ( !v14 )
    goto LABEL_58;
  ZwClose();
LABEL_57:
  v22 = v25;
LABEL_58:
  if ( v22 )
    ZwClose();
  RtlFreeAnsiString(&v27);
  return v10;
}
