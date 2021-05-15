// WmipDetermineInstanceBaseIndex 
 
unsigned int __fastcall WmipDetermineInstanceBaseIndex(unsigned int a1, char *a2)
{
  unsigned int v4; // r7
  int *v5; // r0
  int *v6; // r5
  int *v7; // r4
  int *v8; // r6
  int v9; // r8
  int v11; // r2

  v4 = 0;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v5 = WmipFindGEByGuid(a1, 0);
  v6 = v5;
  if ( v5 )
  {
    v7 = (int *)v5[8];
    v8 = v5 + 8;
    while ( v7 != v8 )
    {
      if ( (v7[2] & 1) != 0 )
      {
        v9 = v7[12];
        if ( !wcscmp(a2, (char *)(v9 + 4)) )
        {
          v11 = v7[9];
          if ( v4 <= *(_DWORD *)v9 + v11 )
            v4 = *(_DWORD *)v9 + v11;
        }
      }
      v7 = (int *)*v7;
    }
    WmipUnreferenceEntry((int *)&WmipGEChunkInfo, v6);
  }
  KeReleaseMutex((int)&WmipSMMutex);
  return v4;
}
