// ExpParseFastCacheHelper 
 
int __fastcall ExpParseFastCacheHelper(int a1, unsigned int *a2, unsigned int *a3, int a4)
{
  unsigned int v7; // r4
  int v8; // r5
  unsigned int v9; // r6
  int v10; // r0
  int v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = (int)a3;
  v12[1] = a4;
  v7 = 0;
  v8 = ExpParseFastCache(a1, 0, 0, v12);
  v9 = v12[0];
  if ( v8 != -1073741789 )
    goto LABEL_5;
  v10 = ExAllocatePoolWithTag(1, 8 * v12[0], 542329939);
  v7 = v10;
  if ( !v10 )
    return -1073741801;
  v8 = ExpParseFastCache(a1, v10, v9, 0);
  if ( v8 >= 0 )
  {
    qsort(v7, v9, 8u, (int (__fastcall *)(unsigned int, _BYTE *))ExpFastCacheDescriptorCompare);
LABEL_5:
    if ( v8 >= 0 )
    {
      *a3 = v7;
      v7 = 0;
      *a2 = v9;
    }
  }
  if ( v7 )
    return sub_811D64();
  return v8;
}
