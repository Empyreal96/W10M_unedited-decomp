// MiCommitVadCfgBits 
 
int __fastcall MiCommitVadCfgBits(int a1, int *a2, unsigned __int8 *a3)
{
  __int64 v7; // kr00_8
  int v8; // r9
  int v9; // r8
  int v10; // r0
  int v11; // r1
  int v12; // r3

  __mrc(15, 0, 13, 0, 3);
  if ( !MiIsProcessCfgEnabled() )
    return 0;
  v7 = *(_QWORD *)(a1 + 12);
  v8 = (HIDWORD(v7) + 1) << 12;
  v9 = (_DWORD)v7 << 12;
  if ( a2 )
  {
    v9 = *a2;
    v8 = (a2[1] | 0xFFF) + 1;
  }
  v10 = MiSelectCfgBitMap();
  if ( v11 == 1 )
    return MiMarkSharedImageCfgBits(v10, a1);
  if ( v11 == 2 )
    return MiMarkPrivateImageCfgBits(v10, a1);
  if ( v11 != 3 )
    return -1073741823;
  if ( a3 )
    v12 = *a3;
  else
    v12 = 1;
  return MiMarkPrivateOpenCfgBits(v10, v9, v8, v12);
}
