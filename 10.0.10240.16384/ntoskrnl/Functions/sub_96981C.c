// sub_96981C 
 
int __fastcall sub_96981C(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r7
  __int16 *v6; // r4
  __int16 *v7; // r8
  int v8; // r3
  __int16 *v9; // r5
  int v10; // r3
  int v11; // r10
  int v12; // r0
  int *v13; // r1
  __int64 v14; // r0
  int (__fastcall *v16)(int); // [sp-4h] [bp-4h]

  v6 = MmLargePageDriverBuffer;
  v7 = &MmLargePageDriverBuffer[(unsigned int)(a4 - 2) >> 1];
  if ( MmLargePageDriverBuffer < v7 )
  {
    do
    {
      v8 = (unsigned __int16)*v6;
      if ( v8 == 9 || v8 == 10 || v8 == 13 || v8 == 32 || v8 == 12288 || !*v6 )
      {
        ++v6;
      }
      else
      {
        if ( v8 == 42 )
        {
          *(_BYTE *)(v4 + 1197) = 1;
          break;
        }
        v9 = v6;
        do
        {
          v10 = (unsigned __int16)*v9;
          if ( v10 == 9 )
            break;
          if ( v10 == 10 )
            break;
          if ( v10 == 13 )
            break;
          if ( v10 == 32 )
            break;
          if ( v10 == 12288 )
            break;
          if ( !*v9 )
            break;
          ++v9;
        }
        while ( v9 < v7 );
        v11 = 2 * (v9 - v6);
        v12 = ExAllocatePoolWithTag(512, 16, 1884056909);
        if ( !v12 )
          break;
        *(_DWORD *)(v12 + 12) = v6;
        *(_WORD *)(v12 + 8) = v11;
        *(_WORD *)(v12 + 10) = v11;
        v13 = *(int **)(v4 + 1208);
        *(_DWORD *)v12 = v4 + 1204;
        *(_DWORD *)(v12 + 4) = v13;
        if ( *v13 != v4 + 1204 )
          __fastfail(3u);
        *v13 = v12;
        *(_DWORD *)(v4 + 1208) = v12;
        v6 = v9 + 1;
      }
    }
    while ( v6 < v7 );
  }
  MiInitializeBootLoadedDriverPfns(v5);
  LODWORD(v14) = v5;
  MiReloadBootLoadedDrivers(v14);
  MiMarkBootImagesNonPaged(v5);
  VfInitBootDriversLoaded(v5);
  return v16(1);
}
