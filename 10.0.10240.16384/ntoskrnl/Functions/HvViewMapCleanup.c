// HvViewMapCleanup 
 
int __fastcall HvViewMapCleanup(int result, int a2, int a3)
{
  int *v3; // r4
  int v4; // r3
  unsigned int *v5; // r7
  int v6; // r9
  unsigned int i; // r5
  int v8; // r6
  int *v9; // r8
  unsigned int v10; // r6
  unsigned int j; // r10
  int v12; // t1
  int v13; // r10
  unsigned int v14; // [sp+0h] [bp-30h]
  int v15; // [sp+4h] [bp-2Ch] BYREF
  int v16; // [sp+8h] [bp-28h]
  int v17; // [sp+Ch] [bp-24h]
  int v18; // [sp+10h] [bp-20h]

  v3 = (int *)result;
  v14 = 0;
  v4 = *(_DWORD *)(result + 12);
  v5 = 0;
  v17 = a2;
  v18 = a3;
  v6 = a2;
  if ( v4 )
  {
    for ( i = 0; i < 0x80; ++i )
    {
      v8 = *(_DWORD *)(v3[3] + 4 * i);
      v16 = v8;
      if ( !v8 )
        break;
      v9 = (int *)v8;
      v10 = v14;
      for ( j = 0; j < 0x40; ++j )
      {
        v12 = *v9;
        v9 += 6;
        if ( !v12 )
          break;
        v10 = v10 & 0x8003FFFF | ((j & 0x3F | ((i & 0x7F) << 6)) << 18);
        result = HvpViewUnmapViewOfPrimaryFile(result, v3[3], v10, &v15);
        v5 = (unsigned int *)((char *)v5 + v15);
      }
      v6 = v17;
      v14 = v10;
      result = (*(int (__fastcall **)(int, int))(v17 + 16))(v16, 1536);
    }
    (*(void (__fastcall **)(int, int))(v6 + 16))(v3[3], 512);
    v13 = v18;
    v3[3] = 0;
    if ( v13 )
    {
      CcClearPrivateWriteFile(v3[2]);
      MmReleaseResourceCharge(v5, 3, 1);
      v3[4] -= (int)v5;
    }
    result = ObfDereferenceObject(v3[2]);
    v3[2] = 0;
  }
  return result;
}
