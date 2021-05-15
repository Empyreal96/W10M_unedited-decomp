// FsRtlpOplockEnqueueRH 
 
int __fastcall FsRtlpOplockEnqueueRH(int *a1, int *a2)
{
  int v2; // r2
  int v4; // r4
  int v5; // r4
  int v7[14]; // [sp+0h] [bp-38h] BYREF

  v2 = *a1;
  *a2 = *a1;
  a2[1] = (int)a1;
  if ( *(int **)(v2 + 4) != a1 )
    sub_529F7C();
  *(_DWORD *)(v2 + 4) = a2;
  *a1 = (int)a2;
  v4 = a2[3];
  memset(v7, 0, 44);
  v7[10] = (int)a2;
  v5 = IoSetOplockPrivateFoExt(v4, v7);
  if ( v5 < 0 )
    FsRtlpOplockDequeueRH(a2);
  return v5;
}
