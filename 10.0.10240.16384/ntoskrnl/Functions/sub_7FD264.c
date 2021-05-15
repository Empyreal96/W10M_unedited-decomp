// sub_7FD264 
 
void sub_7FD264()
{
  int v0; // r5
  int *v1; // r6
  char v2; // r8
  int v3; // r2
  int **v4; // r1

  v3 = *(_DWORD *)(v0 + 4) + 64;
  v4 = *(int ***)(*(_DWORD *)(v0 + 4) + 68);
  *v1 = v3;
  v1[1] = (int)v4;
  if ( *v4 != (int *)v3 )
    __fastfail(3u);
  *v4 = v1;
  *(_DWORD *)(v3 + 4) = v1;
  if ( (v2 & 3) == 0 )
    CmpUnlockKcb(*(_DWORD **)(v0 + 4));
  JUMPOUT(0x732E44);
}
