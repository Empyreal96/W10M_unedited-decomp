// BgpFoInitialize 
 
int __fastcall BgpFoInitialize(_DWORD *a1, void *a2, int a3, unsigned int a4)
{
  void **v6; // r0
  void **v7; // r4
  void ***v9; // r2
  unsigned int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  if ( !FontLibraryInitialized )
  {
    FopFontFileListHead = &FopFontFileListHead;
    *(_DWORD *)algn_618F74 = &FopFontFileListHead;
    FontLibraryInitialized = 1;
  }
  v6 = (void **)BgpFwAllocateMemory(0x20u);
  v7 = v6;
  if ( v6 )
  {
    memset(v6, 0, 32);
    v7[6] = v7 + 6;
    v7[7] = v7 + 6;
    v7[2] = a1;
    v7[4] = a2;
    if ( FioFwReadUlong(a1, v10) >= 0 )
    {
      if ( v10[0] == 1953784678 )
        JUMPOUT(0x975E90);
      v7[3] = (void *)1;
      if ( FopInitializeFonts(v7) >= 0 )
      {
        v9 = (void ***)FopFontFileListHead;
        *v7 = FopFontFileListHead;
        v7[1] = &FopFontFileListHead;
        if ( v9[1] != &FopFontFileListHead )
          __fastfail(3u);
        v9[1] = v7;
        FopFontFileListHead = v7;
        JUMPOUT(0x975EBC);
      }
    }
    JUMPOUT(0x975EB6);
  }
  return sub_975E8C();
}
