// sub_50B9A8 
 
void __fastcall sub_50B9A8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int v14; // r4
  int v15; // r5
  int *v16; // r6
  int v17; // r8
  int v18; // r6

  v18 = *v16;
  if ( v18 != a4 && !RtlpHeapListCompare(v17, v18, a14, 1) )
  {
    *(_DWORD *)(*(_DWORD *)(v14 + 32) + 4 * v15) = v18;
    JUMPOUT(0x4DE5D0);
  }
  *(_DWORD *)(*(_DWORD *)(v14 + 32) + 4 * v15) = 0;
  JUMPOUT(0x4DE5BA);
}
