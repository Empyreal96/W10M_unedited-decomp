// ExAllocatePoolWithTagPriority 
 
int __fastcall ExAllocatePoolWithTagPriority(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r7
  unsigned int v6; // r8
  _DWORD *v9; // r0
  unsigned int v10; // r9
  int v11; // lr
  _DWORD *v12; // r2
  int *v13; // r2
  unsigned int v14; // r0
  int *v15; // r5
  _DWORD *v16; // t1
  unsigned int v17; // r0
  _DWORD *v18; // r1
  int v19; // r3
  unsigned int v20; // r3
  unsigned int v24; // [sp+14h] [bp-34h]

  v4 = a3;
  v5 = a1;
  v6 = a2;
  if ( (a4 & 8) != 0 )
    return sub_50E6E4();
  if ( a4 == 32 || (a1 & 2) != 0 || MmResourcesAvailable(a1, a2, a4, 1) )
    return ExAllocatePoolWithTag(v5, v6, v4);
  if ( v6 > 0xFF0 )
    return 0;
  if ( (v5 & 1) != 0 && (v5 & 0x20) != 0 )
  {
    v9 = (_DWORD *)MiSessionPoolVector();
    v10 = v9[36];
    v11 = v9[96] + v9[34];
    goto LABEL_27;
  }
  v10 = 0;
  v11 = 0;
  v12 = (_DWORD *)PoolVector[v5 & 1];
  if ( (v5 & 1) != 0 )
  {
    if ( (unsigned __int16)KeNumberNodes <= 1u )
    {
      v17 = 0;
      v18 = v12 + 34;
      do
      {
        ++v17;
        v11 += *v18 + v18[62];
        v19 = v18[2];
        v18 += 1184;
        v10 += v19;
      }
      while ( v17 <= ExpNumberOfPagedPools );
    }
    else
    {
      v14 = 0;
      v15 = &ExpPagedPoolDescriptor;
      do
      {
        v16 = (_DWORD *)*v15++;
        ++v14;
        v11 += v16[34] + v16[96];
        v10 += v16[36];
      }
      while ( v14 <= ExpNumberOfPagedPools );
    }
  }
  else if ( ExpNumberOfNonPagedPools == 1 )
  {
    v11 = v12[34] + v12[96] + v12[1280] + v12[1218];
    v10 = v12[36] + v12[1220];
  }
  else
  {
    v24 = 0;
    if ( !ExpNumberOfNonPagedPools )
      goto LABEL_27;
    v13 = &ExpNonPagedPoolDescriptor;
    do
    {
      v11 += *(_DWORD *)(*v13 + 384) + *(_DWORD *)(*v13 + 136) + *(_DWORD *)(*v13 + 5120) + *(_DWORD *)(*v13 + 4872);
      v10 += *(_DWORD *)(*v13 + 4880) + *(_DWORD *)(*v13 + 144);
      ++v24;
      ++v13;
    }
    while ( v24 < ExpNumberOfNonPagedPools );
    v5 = a1;
    v6 = a2;
  }
  v4 = a3;
LABEL_27:
  v20 = v10 >> 12;
  if ( v10 >> 12 > (v11 | 1u) )
    v20 = v11 | 1;
  if ( 100 * v20 / (v11 | 1u) >= 0x50 )
    return 0;
  return ExAllocatePoolWithTag(v5, v6, v4);
}
