// KsepPatchDriverImportsTable 
 
int __fastcall KsepPatchDriverImportsTable(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int *v7; // r5
  int v8; // r10
  int v9; // r3
  _DWORD *v10; // r4
  int v11; // r8
  int v12; // r0
  int v13; // r6
  int v14; // [sp+0h] [bp-28h] BYREF
  int v15; // [sp+4h] [bp-24h]
  int v16; // [sp+8h] [bp-20h]

  v15 = a3;
  v16 = a4;
  if ( a1 && a2 )
  {
    v15 = RtlImageDirectoryEntryToData(*(_DWORD *)(a1 + 24), 1, 12, (int)&v14);
    if ( !v15 )
      return -1073741823;
    v7 = *(int **)(a2 + 24);
    if ( v7 )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = *v7;
        if ( *v7 == 4 )
          return 0;
        if ( v9 == 2 || !v9 || v9 == 1 )
          break;
LABEL_26:
        v8 += 12;
        v7 = (int *)(v8 + *(_DWORD *)(a2 + 24));
        if ( !v7 )
          return 0;
      }
      v10 = (_DWORD *)v7[2];
      if ( v10 )
      {
        v11 = 0;
        while ( 1 )
        {
          if ( *v10 == 2 )
            goto LABEL_26;
          if ( !v10[2] || !v10[3] || *v10 )
            return -1073741811;
          result = ((int (*)(void))KsepPatchImportTableEntry)();
          if ( result == -1073741275 )
          {
            if ( !VfIsVerifierEnabled() )
              goto LABEL_25;
            if ( !VfIsVerificationEnabledForImage(a1) )
              goto LABEL_25;
            v12 = VfGetHookAddressForOriginal(v10[1]);
            v13 = v12;
            if ( !v12 )
              goto LABEL_25;
            result = KsepPatchImportTableEntry(v15, v14, v12, v10[2]);
            if ( result < 0 )
              goto LABEL_24;
            v10[3] = v13;
          }
          if ( result < 0 )
          {
LABEL_24:
            if ( result != -1073741275 )
              return result;
          }
LABEL_25:
          v11 += 16;
          v10 = (_DWORD *)(v7[2] + v11);
          if ( !v10 )
            goto LABEL_26;
        }
      }
    }
  }
  return -1073741811;
}
