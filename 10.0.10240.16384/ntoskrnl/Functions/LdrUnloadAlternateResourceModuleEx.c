// LdrUnloadAlternateResourceModuleEx 
 
int __fastcall LdrUnloadAlternateResourceModuleEx(int a1)
{
  unsigned __int8 v2; // r3
  unsigned int v3; // r1
  int i; // r5
  int v5; // r2
  int v6; // r4
  int v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r4
  unsigned __int8 v12; // [sp+8h] [bp-28h]
  int v13; // [sp+Ch] [bp-24h]

  v2 = 0;
  v12 = 0;
  if ( !a1 )
    return v2;
  LdrpInitMuiCrits();
  KeWaitForSingleObject((unsigned int)&MuiMutex, 0, 0, 0, 0);
  v3 = AlternateResourceModuleCount;
  if ( AlternateResourceModuleCount )
  {
    for ( i = AlternateResourceModuleCount; ; --i )
    {
      if ( i <= 0 )
        goto LABEL_23;
      v5 = AlternateResourceModules + 40 * i;
      if ( *(_DWORD *)(v5 - 36) == a1 )
        break;
LABEL_21:
      ;
    }
    v6 = v5 - 40;
    v7 = *(_DWORD *)(v5 - 24);
    if ( v7 && v7 != -1 )
    {
      MmUnmapViewInSystemSpace();
      if ( *(_DWORD *)(v6 + 20) )
      {
        ZwClose();
        *(_DWORD *)(v6 + 20) = 0;
      }
      *(_DWORD *)(v6 + 16) = 0;
      v3 = AlternateResourceModuleCount;
    }
    if ( i != v3 )
    {
      memmove(v6, v6 + 40, 40 * (v3 - i));
      v3 = AlternateResourceModuleCount;
    }
    AlternateResourceModuleCount = --v3;
    if ( v3 )
    {
      if ( v3 >= AltResMemBlockCount - 32 )
      {
LABEL_20:
        v12 = 1;
        goto LABEL_21;
      }
      v9 = ExAllocatePoolWithTag(1, 40 * (AltResMemBlockCount - 32), 1766880370);
      v13 = v9;
      if ( !v9 )
      {
        v12 = 0;
        goto LABEL_23;
      }
      v10 = AlternateResourceModules;
      memmove(v9, AlternateResourceModules, 40 * (AltResMemBlockCount - 32));
      ExFreePoolWithTag(v10, 0);
      AlternateResourceModules = v13;
      v8 = AltResMemBlockCount - 32;
    }
    else
    {
      ExFreePoolWithTag(AlternateResourceModules, 0);
      v8 = 0;
      AlternateResourceModules = 0;
    }
    AltResMemBlockCount = v8;
    v3 = AlternateResourceModuleCount;
    goto LABEL_20;
  }
  v12 = 1;
LABEL_23:
  KeReleaseMutant((unsigned int)&MuiMutex, 1, 0, 0);
  return v12;
}
