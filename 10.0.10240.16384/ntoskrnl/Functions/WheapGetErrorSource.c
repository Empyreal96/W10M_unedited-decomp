// WheapGetErrorSource 
 
int *__fastcall WheapGetErrorSource(int a1, int a2)
{
  int v2; // r0
  int *v3; // r2
  int v4; // r4

  v3 = *(int **)(a1 + 8);
  v2 = *(_DWORD *)(a1 + 4);
  v4 = 0;
  if ( v2 <= 0 )
    return 0;
  while ( *(int *)((char *)v3 + 101) != a2 || *((_BYTE *)v3 + 72) )
  {
    ++v4;
    v3 = (int *)*v3;
    if ( v4 >= v2 )
      return 0;
  }
  return v3;
}
