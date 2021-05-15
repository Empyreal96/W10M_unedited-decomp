// MmGetCacheAttribute 
 
int __fastcall MmGetCacheAttribute(__int64 a1, int *a2, int a3)
{
  unsigned int v3; // r5
  int v6; // r1
  int v7; // r3
  int v8; // r3
  int *varg_r2; // [sp+20h] [bp+10h]

  varg_r2 = a2;
  v3 = a1 >> 12;
  if ( !MI_IS_PFN(v3) )
    return -1073741503;
  v6 = MmPfnDatabase + 24 * v3;
  if ( !*(_WORD *)(v6 + 16) )
    KeBugCheck2(26, 4658, v3, *(_BYTE *)(v6 + 18) & 7, 0, 0);
  v7 = *(unsigned __int8 *)(v6 + 18) >> 6;
  switch ( v7 )
  {
    case 1:
      v8 = 1;
LABEL_11:
      *a2 = v8;
      return 0;
    case 0:
      v8 = 0;
      goto LABEL_11;
    case 2:
      v8 = 2;
      goto LABEL_11;
  }
  return -1073741585;
}
