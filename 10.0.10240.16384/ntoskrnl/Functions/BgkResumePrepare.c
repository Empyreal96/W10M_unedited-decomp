// BgkResumePrepare 
 
int __fastcall BgkResumePrepare(int a1)
{
  int v2; // r4
  int v3; // r0
  int v4; // r0
  int v5; // r5
  const void *v6; // r2
  int v7; // r4
  char *v8; // r0
  const void *v9; // r2

  v2 = 0;
  if ( a1 )
  {
    v3 = BgkpLockBgfxCodeSection();
    v4 = BgGetContext(v3);
    v5 = v4;
    if ( !v4 )
    {
      BgkpUnlockBgfxCodeSection(0);
      return -1073741670;
    }
    v6 = *(const void **)(v4 + 8);
    if ( v6 )
      PoSetHiberRange(a1, 0x8000, v6, *(const void **)(v4 + 12), 1263093570);
    dword_64B0A4 = v5;
  }
  else
  {
    v7 = dword_64B0A4;
    if ( !dword_64B0A4 )
      return -1073741670;
    v8 = PoSetHiberRange(0, 0x10000, (const void *)dword_64B0A4, *(const void **)dword_64B0A4, 0);
    v9 = *(const void **)(v7 + 8);
    if ( v9 )
      v8 = PoSetHiberRange(0, 0x10000, v9, *(const void **)(v7 + 12), 0);
    v2 = BgMarkHiberPhase(v8);
  }
  return v2;
}
