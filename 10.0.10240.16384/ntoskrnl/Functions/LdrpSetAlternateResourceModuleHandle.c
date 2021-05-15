// LdrpSetAlternateResourceModuleHandle 
 
int __fastcall LdrpSetAlternateResourceModuleHandle(int a1, _DWORD *a2, int *a3, int a4, int a5, unsigned __int16 a6, int a7, int a8, int a9)
{
  unsigned int v12; // r4
  unsigned int v13; // lr
  int v14; // r1
  _DWORD *v15; // r2
  unsigned int v16; // r2
  _BYTE *v17; // r0
  int v18; // r4
  _BYTE *v19; // r0
  int v20; // r4
  unsigned int v21; // r2
  int v22; // r4
  unsigned int i; // r2
  unsigned __int16 *v24; // r0
  int v25; // r2
  int v26; // r3
  int v27; // r0
  int v28; // r0
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r3
  int v33; // r3
  int v35; // [sp+8h] [bp-30h]

  if ( !a1 || (a7 & 0xFFFFFFC8) != 0 || (a7 & 3) == 3 || (a7 & 1) != 0 && !a2 || (a7 & 4) != 0 )
    return 0;
  LdrpInitMuiCrits();
  KeWaitForSingleObject((unsigned int)&MuiMutex, 0, 0, 0, 0);
  v12 = 0;
  v13 = AlternateResourceModuleCount;
  v14 = AlternateResourceModules;
  while ( v12 < AlternateResourceModuleCount )
  {
    v15 = (_DWORD *)(AlternateResourceModules + 40 * v12);
    if ( v15[1] == a1 )
    {
      if ( (a7 & 2) != 0 && v15[2] )
        goto LABEL_58;
      if ( (a7 & 1) != 0 && v15[4] && a6 && *(unsigned __int16 *)v15 == a6 )
      {
        if ( *a2 != -1 )
        {
          MmUnmapViewInSystemSpace(*a2);
          if ( a3 )
            ZwClose();
          v14 = AlternateResourceModules;
        }
        v16 = v14 + 40 * v12;
        *a2 = *(_DWORD *)(v16 + 16);
        if ( a3 )
          *a3 = *(_DWORD *)(v16 + 20);
        goto LABEL_58;
      }
    }
    ++v12;
  }
  if ( (a7 & 0x10) != 0 )
    goto LABEL_58;
  if ( !AlternateResourceModules )
  {
    v17 = (_BYTE *)ExAllocatePoolWithTag(1, 1280);
    v18 = (int)v17;
    if ( !v17 )
      goto LABEL_58;
    memset(v17, 0, 1280);
    AlternateResourceModules = v18;
    AltResMemBlockCount = 32;
LABEL_31:
    v14 = AlternateResourceModules;
    v13 = AlternateResourceModuleCount;
    goto LABEL_32;
  }
  if ( AlternateResourceModuleCount >= (unsigned int)AltResMemBlockCount )
  {
    v19 = (_BYTE *)ExAllocatePoolWithTag(1, 40 * (AltResMemBlockCount + 32));
    v35 = (int)v19;
    if ( !v19 )
      goto LABEL_58;
    v20 = AltResMemBlockCount;
    memset(v19, 0, 40 * (AltResMemBlockCount + 32));
    v21 = 40 * v20;
    v22 = AlternateResourceModules;
    memmove(v35, AlternateResourceModules, v21);
    ExFreePoolWithTag(v22, 0);
    AlternateResourceModules = v35;
    AltResMemBlockCount += 32;
    goto LABEL_31;
  }
LABEL_32:
  for ( i = 0; i < v13; ++i )
  {
    v24 = (unsigned __int16 *)(v14 + 40 * i);
    if ( *((_DWORD *)v24 + 1) == a1 )
    {
      if ( (a7 & 2) != 0 && !*((_DWORD *)v24 + 2) )
      {
        *((_DWORD *)v24 + 2) = a4;
        *((_DWORD *)v24 + 9) = a8;
        goto LABEL_58;
      }
      if ( (a7 & 1) != 0 && !*((_DWORD *)v24 + 4) && (*v24 == a6 || !*v24) )
      {
        v25 = v14 + 40 * i;
        *(_DWORD *)(v25 + 16) = *a2;
        if ( a3 )
          v26 = *a3;
        else
          v26 = 0;
        *(_DWORD *)(v25 + 20) = v26;
        *(_WORD *)v25 = a6;
        *(_DWORD *)(v25 + 36) = a8;
        *(_DWORD *)(v25 + 24) = a9;
        goto LABEL_58;
      }
    }
  }
  v27 = RtlImageNtHeader(a1 & 0xFFFFFFFC);
  if ( v27 )
  {
    v28 = *(_DWORD *)(v27 + 88);
    v29 = AlternateResourceModuleCount;
    v30 = AlternateResourceModules + 40 * AlternateResourceModuleCount;
    *(_DWORD *)(v30 + 4) = a1;
    *(_DWORD *)(v30 + 8) = a4;
    if ( (a7 & 1) != 0 )
    {
      if ( a2 )
        v31 = *a2;
      else
        v31 = 0;
      *(_DWORD *)(v30 + 16) = v31;
      if ( a3 )
        v32 = *a3;
      else
        v32 = 0;
      *(_DWORD *)(v30 + 20) = v32;
      v33 = a9;
    }
    else
    {
      v33 = 0;
      *(_DWORD *)(v30 + 16) = 0;
      *(_DWORD *)(v30 + 20) = 0;
    }
    *(_DWORD *)(v30 + 24) = v33;
    *(_WORD *)v30 = a6;
    *(_DWORD *)(v30 + 12) = v28;
    *(_DWORD *)(v30 + 36) = a8;
    AlternateResourceModuleCount = v29 + 1;
  }
LABEL_58:
  KeReleaseMutant((unsigned int)&MuiMutex, 1, 0, 0);
  return 1;
}
