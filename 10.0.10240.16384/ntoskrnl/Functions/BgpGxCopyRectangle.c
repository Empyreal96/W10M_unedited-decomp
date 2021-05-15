// BgpGxCopyRectangle 
 
int __fastcall BgpGxCopyRectangle(unsigned int *a1, unsigned int *a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int v5; // r0
  unsigned int v6; // r4
  unsigned int v8; // r1
  unsigned int v9; // r7
  unsigned int v10; // r4
  unsigned int v11; // r8
  int v12; // r9
  int i; // r10

  v6 = a1[2];
  v5 = a1[1];
  v8 = a2[1];
  v9 = v6 >> 3;
  v10 = *a2;
  v11 = v8;
  if ( v8 >= v5 )
    v11 = v5;
  if ( v10 >= *a1 )
    v10 = *a1;
  v12 = a2[5] + (*a4 + v8 * a4[1]) * v9;
  for ( i = a1[5] + (*a3 + a3[1] * v5) * v9; v10; i += a1[1] * v9 )
  {
    memmove(i, v12, v11 * v9);
    --v10;
    v12 += a2[1] * v9;
  }
  return BgpGxMarkClean((int)a1);
}
