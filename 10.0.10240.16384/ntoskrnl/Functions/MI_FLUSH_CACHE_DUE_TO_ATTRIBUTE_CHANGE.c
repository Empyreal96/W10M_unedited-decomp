// MI_FLUSH_CACHE_DUE_TO_ATTRIBUTE_CHANGE 
 
int __fastcall MI_FLUSH_CACHE_DUE_TO_ATTRIBUTE_CHANGE(int result, int a2, int a3)
{
  int v5; // r5
  int v6; // r6
  __int64 v7; // r0
  int v8; // r8
  int v9; // [sp+0h] [bp-B0h] BYREF
  int v10; // [sp+4h] [bp-ACh]
  int v11; // [sp+8h] [bp-A8h]
  int v12; // [sp+Ch] [bp-A4h]
  int v13; // [sp+10h] [bp-A0h]
  int v14; // [sp+14h] [bp-9Ch]

  v12 = 0;
  v13 = 0;
  v9 = 0;
  LOWORD(v10) = 0;
  v11 = 33;
  v14 = 0;
  v5 = result;
  if ( a3 == 2 )
    v6 = 2;
  else
    v6 = 0;
  while ( a2 )
  {
    v7 = MiMapPageInHyperSpaceWorker(v5, 0, v6 | 0xC0000000);
    v8 = v7;
    KeInvalidatePage(v7, HIDWORD(v7), v5 << 12, (unsigned __int64)(unsigned int)v5 >> 20, v9, v10, v11, v12, v13, v14);
    result = MiUnmapPageInHyperSpaceWorker(v8, 17, 0x80000000);
    if ( a3 == 3 )
      return sub_50A108(result);
    --a2;
    ++v5;
  }
  if ( a3 == 3 )
    result = MiFlushTbList(&v9);
  return result;
}
