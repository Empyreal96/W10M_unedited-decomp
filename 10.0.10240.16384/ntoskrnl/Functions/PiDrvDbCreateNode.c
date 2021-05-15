// PiDrvDbCreateNode 
 
int __fastcall PiDrvDbCreateNode(unsigned __int16 *a1, int a2, int a3, int a4, int *a5)
{
  _BYTE *v7; // r0
  int v8; // r4
  unsigned __int16 v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  unsigned __int16 v16; // r3
  int v17; // r0
  int v18; // r2
  int v19; // r3
  int v20; // r2
  int v21; // r3
  int **v22; // r1

  v7 = (_BYTE *)ExAllocatePoolWithTag(512, 288, 1650749520);
  v8 = (int)v7;
  if ( v7 )
  {
    memset(v7, 0, 288);
    *(_DWORD *)(v8 + 32) = a2;
    if ( RtlCreateUnicodeString(v8 + 8, a1) )
    {
      v10 = *(_WORD *)(v8 + 8);
      *(_WORD *)(v8 + 16) = 0;
      v10 += 38;
      *(_WORD *)(v8 + 18) = v10;
      v11 = ExpAllocateStringRoutine(v10);
      *(_DWORD *)(v8 + 20) = v11;
      if ( v11 )
      {
        if ( RtlAppendUnicodeToString((unsigned __int16 *)(v8 + 16), (int)L"\\REGISTRY\\MACHINE\\", v12, v13) >= 0
          && RtlAppendUnicodeToString((unsigned __int16 *)(v8 + 16), (int)a1, v14, v15) >= 0 )
        {
          v16 = *(_WORD *)(v8 + 8);
          *(_WORD *)(v8 + 24) = 0;
          v16 += 58;
          *(_WORD *)(v8 + 26) = v16;
          v17 = ExpAllocateStringRoutine(v16);
          *(_DWORD *)(v8 + 28) = v17;
          if ( v17 )
          {
            if ( RtlAppendUnicodeToString(
                   (unsigned __int16 *)(v8 + 24),
                   (int)L"\\SystemRoot\\System32\\config\\",
                   v18,
                   v19) >= 0
              && RtlAppendUnicodeToString((unsigned __int16 *)(v8 + 24), (int)a1, v20, v21) >= 0 )
            {
              if ( (*(_DWORD *)(v8 + 32) & 4) != 0 )
              {
                if ( ExInitializeResourceLite(v8 + 44) < 0 )
                  goto LABEL_14;
                *(_BYTE *)(v8 + 100) = 1;
                KeInitializeTimerEx((_DWORD *)(v8 + 144), 0);
                KeInitializeDpc(v8 + 192, (int)PiDrvDbUnloadNodeDpcRoutine, v8);
                *(_DWORD *)(v8 + 240) = 0;
                if ( ZwCreateEvent() < 0 )
                  goto LABEL_14;
                *(_DWORD *)(v8 + 272) = -1;
                *(_DWORD *)(v8 + 276) = 0;
                *(_BYTE *)(v8 + 281) = 1;
              }
              v22 = (int **)dword_62F984;
              *(_DWORD *)v8 = &PiDrvDbNodeList;
              *(_DWORD *)(v8 + 4) = v22;
              if ( *v22 != &PiDrvDbNodeList )
                __fastfail(3u);
              *v22 = (int *)v8;
              dword_62F984 = v8;
              *a5 = v8;
              v8 = 0;
            }
          }
        }
      }
    }
LABEL_14:
    if ( v8 )
      PiDrvDbDestroyNode(v8);
    JUMPOUT(0x7CF38E);
  }
  return sub_7CF38C();
}
