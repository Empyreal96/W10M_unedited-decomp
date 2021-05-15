// ViThunkSnapSharedExportByName 
 
int __fastcall ViThunkSnapSharedExportByName(int a1, int a2, int *a3, int a4)
{
  int v7; // r9
  int v8; // r0
  int *v9; // r8
  int v10; // t1
  int v11; // r4
  int *v12; // r4
  int v13; // r5
  int v14; // r3
  int v15; // t1
  int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = a4;
  *a3 = 0;
  a3[1] = 0;
  v7 = 0;
  v8 = RtlImageDirectoryEntryToData(a1, 1, 1, (int)v17);
  v9 = (int *)v8;
  if ( v8 && *(_DWORD *)(v8 + 12) )
  {
    do
    {
      v10 = *v9;
      v9 += 5;
      if ( !v10 )
        break;
      v11 = *(v9 - 2);
      if ( !stricmp((unsigned __int8 *)(v11 + a1), "ntoskrnl.exe") || !stricmp((unsigned __int8 *)(v11 + a1), "hal.dll") )
      {
        v12 = (int *)(*(v9 - 5) + a1);
        v13 = *(v9 - 1) + a1;
        v14 = *v12;
        if ( *v12 )
        {
          while ( v14 < 0 || stricmp((unsigned __int8 *)(v14 + a1 + 2), *(unsigned __int8 **)a2) )
          {
            v15 = v12[1];
            ++v12;
            v14 = v15;
            v13 += 4;
            if ( !v15 )
              goto LABEL_10;
          }
          *a3 = v13;
          v7 = 1;
          a3[1] = *(_DWORD *)(a2 + 4);
          return v7;
        }
      }
LABEL_10:
      ;
    }
    while ( v9[3] );
  }
  return v7;
}
