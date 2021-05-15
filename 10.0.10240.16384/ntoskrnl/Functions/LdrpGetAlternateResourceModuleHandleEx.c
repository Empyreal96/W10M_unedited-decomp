// LdrpGetAlternateResourceModuleHandleEx 
 
int __fastcall LdrpGetAlternateResourceModuleHandleEx(int a1, int a2, int a3, int *a4)
{
  int v5; // r8
  int v6; // r4
  int v7; // r5
  int v8; // r2
  int v9; // r6
  int v10; // r1
  int v11; // lr
  _DWORD *v12; // r0
  int v13; // r5
  int v14; // r0
  int v15; // r2
  int v17; // [sp+8h] [bp-38h] BYREF
  int v18; // [sp+Ch] [bp-34h] BYREF
  int v19; // [sp+10h] [bp-30h]
  int v20; // [sp+14h] [bp-2Ch]
  int v21; // [sp+18h] [bp-28h]
  int v22; // [sp+1Ch] [bp-24h]

  v22 = a3;
  v21 = a1;
  v5 = 0;
  v18 = 0;
  v6 = 0;
  v17 = 0;
  v7 = 0;
  LdrpInitMuiCrits();
  KeWaitForSingleObject((unsigned int)&MuiMutex, 0, 0, 0, 0);
  *a4 = 0;
  v8 = AlternateResourceModuleCount;
  v9 = AlternateResourceModuleCount;
  v20 = AlternateResourceModuleCount;
  v10 = AlternateResourceModuleCount - 1;
  v19 = AlternateResourceModuleCount - 1;
  v11 = AlternateResourceModules;
  while ( v10 >= 0 )
  {
    v12 = (_DWORD *)(AlternateResourceModules + 40 * v10);
    if ( v12[1] == v21 )
    {
      if ( v5 )
      {
        v7 = 1;
        break;
      }
      v5 = v12[4];
      v18 = v5;
      v6 = v12[6];
      v17 = v6;
      v9 = v10;
      v20 = v10;
    }
    v19 = --v10;
  }
  if ( v7 )
  {
    v13 = v9;
    v19 = v9;
    while ( v13 >= 0 )
    {
      if ( *(_DWORD *)(v11 + 40 * v13 + 4) == v21 )
      {
        if ( LdrpGetMappingFromCacheEntry(v13, v22, &v18, &v17) )
        {
          v9 = v13;
          v20 = v13;
          v5 = v18;
          v6 = v17;
          v8 = AlternateResourceModuleCount;
          goto LABEL_17;
        }
        v5 = v18;
        v6 = v17;
        v8 = AlternateResourceModuleCount;
        v11 = AlternateResourceModules;
      }
      v19 = --v13;
    }
    v9 = v8;
    v20 = v8;
  }
LABEL_17:
  if ( v9 == v8 )
  {
    v18 = 0;
  }
  else
  {
    if ( !v6 )
    {
      v14 = RtlImageNtHeader(v5 & 0xFFFFFFFC);
      if ( v14 )
      {
        v15 = *(unsigned __int16 *)(v14 + 24);
        if ( v15 == 267 || v15 == 523 )
        {
          v6 = *(_DWORD *)(v14 + 80);
          v17 = v6;
        }
        else
        {
          v6 = 0;
          v17 = 0;
        }
      }
    }
    *a4 = v6;
  }
  KeReleaseMutant((unsigned int)&MuiMutex, 1, 0, 0);
  return v18;
}
