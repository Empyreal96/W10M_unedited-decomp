// WmipCachePtrs 
 
int __fastcall WmipCachePtrs(int result, int a2, int *a3, int *a4, int *a5)
{
  int v8; // r2
  int *v9; // r3
  int v10; // r6
  int v11; // r4
  unsigned int v12; // r8
  int v13; // [sp+0h] [bp-20h]

  v13 = result;
  if ( *a3 != *a4 )
  {
LABEL_2:
    v8 = *a3;
    v9 = (int *)(*a5 + 8 * *a3);
    *v9 = v13;
    v9[1] = a2;
    *a3 = v8 + 1;
    return result;
  }
  result = ExAllocatePoolWithTag(1, 8 * (*a4 + 64), 1885957463);
  v10 = result;
  if ( result )
  {
    v11 = *a4;
    v12 = *a5;
    result = memmove(result, *a5, 8 * *a4);
    *a4 = v11 + 64;
    if ( v12 )
      result = ExFreePoolWithTag(v12);
    *a5 = v10;
    goto LABEL_2;
  }
  return result;
}
