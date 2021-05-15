// HvpViewMapViewOfPrimaryFile 
 
int __fastcall HvpViewMapViewOfPrimaryFile(int a1, int a2, int a3, unsigned int a4, int a5)
{
  unsigned int v8; // r6
  int v9; // r8
  _BYTE *v10; // r4
  _BYTE *v11; // r0
  int v12; // r4
  int *v13; // r8
  _DWORD v15[10]; // [sp+18h] [bp-28h] BYREF

  v8 = 0;
  v9 = HIBYTE(a4) & 0x7F;
  v10 = *(_BYTE **)(a2 + 4 * v9);
  if ( !v10 )
  {
    v11 = (_BYTE *)(*(int (__fastcall **)(int, _DWORD, int))(a1 + 12))(1536, 0, 943017283);
    v10 = v11;
    if ( !v11 )
    {
LABEL_3:
      v12 = -1073741670;
LABEL_10:
      if ( v8 )
        CmpReleaseGlobalQuota(v8);
      return v12;
    }
    memset(v11, 0, 1536);
    *(_DWORD *)(a2 + 4 * v9) = v10;
  }
  v13 = (int *)&v10[24 * ((a4 >> 18) & 0x3F)];
  v15[0] = a4;
  v15[1] = 0;
  if ( !CmpClaimGlobalQuota(a5) )
    goto LABEL_3;
  v8 = a5;
  if ( CcMapData(a3, (int)v15, a5, 17, v13 + 1, (int *)&v10[24 * ((a4 >> 18) & 0x3F)]) )
  {
    MmProtectSystemCacheView(*v13, (a5 + 4095) & 0xFFFFF000, 2u);
    v13[4] = a5;
    v12 = 0;
  }
  else
  {
    v12 = -1073741670;
  }
  if ( v12 < 0 )
    goto LABEL_10;
  return v12;
}
