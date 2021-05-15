// sub_96E6B0 
 
void __fastcall sub_96E6B0(int *a1)
{
  int v1; // r4
  int *v2; // r6
  int v3; // lr
  int v4; // r2
  int v5; // r3
  int v6; // r2

  v4 = a1[4] - v1;
  v5 = a1[3];
  a1[4] = v4;
  v2[4] = v1;
  v2[2] = v3;
  v2[3] = v5 + v4;
  v6 = *a1;
  *v2 = *a1;
  v2[1] = (int)a1;
  if ( *(int **)(v6 + 4) == a1 )
  {
    *(_DWORD *)(v6 + 4) = v2;
    *a1 = (int)v2;
    JUMPOUT(0x9610C6);
  }
  __fastfail(3u);
}
