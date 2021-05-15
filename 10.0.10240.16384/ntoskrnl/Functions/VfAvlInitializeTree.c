// VfAvlInitializeTree 
 
int __fastcall VfAvlInitializeTree(_DWORD *a1, int a2, int a3, int a4)
{
  int v7; // r0
  unsigned int v8; // r6
  int v9; // r5
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r3

  __dmb(0xBu);
  a1[1] = 0;
  *a1 = a2;
  if ( !a3 )
    return sub_8E5348();
  a1[4] = a3 + 16;
  if ( a2 )
  {
    v11 = HalQueryMaximumProcessorCount(1, a2, 0);
    if ( v11 < 0x40 )
    {
      if ( v11 < 0x20 )
        v12 = 16;
      else
        v12 = 32;
    }
    else
    {
      v12 = 64;
    }
    a1[3] = v12;
  }
  else
  {
    a1[3] = 1;
  }
  v7 = ExAllocatePoolWithTag(512, a1[3] << 8, 1413572182);
  a1[2] = v7;
  if ( !v7 )
    return -1073741801;
  v8 = 0;
  if ( a1[3] )
  {
    v9 = 0;
    do
    {
      *(_DWORD *)(a1[2] + v9 + 56) = 0;
      v10 = a1[2] + v9;
      __dmb(0xBu);
      *(_DWORD *)(v10 + 128) = 0;
      *(_DWORD *)(a1[2] + v9 + 60) = 0;
      RtlInitializeGenericTableAvl(
        a1[2] + v9,
        (unsigned int)ViAvlCompareNode,
        (unsigned int)ViAvlAllocateNode,
        a4,
        (int)a1);
      ++v8;
      v9 += 256;
    }
    while ( v8 < a1[3] );
  }
  return 0;
}
