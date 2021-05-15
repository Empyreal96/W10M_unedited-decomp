// ViTriageSameDriversFromDump 
 
int __fastcall ViTriageSameDriversFromDump(int a1, int a2, int a3, int a4)
{
  int v6; // r3
  _DWORD *v8; // r4
  _DWORD *v9; // r6
  unsigned int v10; // r7
  unsigned int v11; // r5
  int v12; // r0
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  if ( TriageGetDriverCount(a2, v13) < 0 )
  {
    DbgPrintEx(93, 3, (int)"CRASH TRIAGE: failed to get driver count from the dump.\n", v6);
    return 0;
  }
  v8 = *(_DWORD **)(a1 + 16);
  v9 = (_DWORD *)(a1 + 16);
  if ( v8 != (_DWORD *)(a1 + 16) )
  {
    v10 = v13[0];
    while ( 1 )
    {
      v11 = 0;
      if ( !v10 )
        break;
      while ( 1 )
      {
        v12 = TriageGetLoaderEntry(a2, v11);
        if ( v12 )
        {
          if ( v8[16] == *(_DWORD *)(v12 + 64) )
            break;
        }
        if ( ++v11 >= v10 )
          goto LABEL_10;
      }
      v8 = (_DWORD *)*v8;
      if ( v8 == v9 )
        return 1;
    }
LABEL_10:
    DbgPrintEx(93, 3, (int)"Matching checksum for module %wZ not found in triage dump\n", (int)(v8 + 11));
    return 0;
  }
  return 1;
}
