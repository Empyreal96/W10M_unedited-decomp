// ViXdvDriverLoadImage 
 
BOOL __fastcall ViXdvDriverLoadImage(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r0
  int v6; // r4
  int v8; // r9
  unsigned int v9; // r6
  int v10; // r8
  int *v11; // r3
  int v12; // r7
  int (__fastcall *v13)(int); // r0
  const char *v14; // r0
  __int64 v15; // r0
  int v16; // r2
  int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = a4;
  v4 = *(_DWORD *)(a1 + 24);
  v5 = RtlImageDirectoryEntryToData(v4, 1, 0, (int)v17);
  v6 = v5;
  if ( !v5 || !*(_DWORD *)(v5 + 24) )
    return 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = (int *)(*(_DWORD *)(v5 + 32) + v4);
  do
  {
    v12 = *v11;
    v17[0] = (int)(v11 + 1);
    if ( !strcmp((int)"GetXdvDDIWrappers", (unsigned int *)(v12 + v4)) )
    {
      v13 = (int (__fastcall *)(int))ViXdvGetFuncAddress(v4, v6, v9);
      v8 = ViXdvBindXdvDDIWrappers(v13);
      if ( v8 == 1 )
        goto LABEL_18;
      v14 = "Error on Verifier Extention DDI bound process\n";
LABEL_11:
      VfUtilDbgPrint((int)v14);
      goto LABEL_18;
    }
    if ( !strcmp((int)"GetXdvDriverEntryWrappers", (unsigned int *)(v12 + v4)) )
    {
      v15 = ViXdvGetFuncAddress(v4, v6, v9);
      v10 = ViXdvBindXdvDriverEntryWrappers((int (__fastcall *)(_DWORD, int, int, _DWORD))v15, SHIDWORD(v15), v16);
      if ( v10 == 1 )
        goto LABEL_18;
      v14 = "Error on Verifier Extention entry point bound process\n";
      goto LABEL_11;
    }
    if ( !strcmp((int)"XdvHibernationNotification", (unsigned int *)(v12 + v4)) )
    {
      ViFnExtensionHiberFunc = (void *)ViXdvGetFuncAddress(v4, v6, v9);
    }
    else if ( !strcmp((int)"XdvNotifyExtensions", (unsigned int *)(v12 + v4)) )
    {
      ViFnXdvNotifyExtensions = (int (__fastcall *)(_DWORD))ViXdvGetFuncAddress(v4, v6, v9);
    }
    else if ( !strcmp((int)"XdvQueryDispatchTable", (unsigned int *)(v12 + v4)) )
    {
      ViFnXdvQueryDispatchTable = (int (__fastcall *)(_DWORD))ViXdvGetFuncAddress(v4, v6, v9);
    }
LABEL_18:
    ++v9;
    v11 = (int *)v17[0];
  }
  while ( v9 < *(_DWORD *)(v6 + 24) );
  return v8 && v10;
}
