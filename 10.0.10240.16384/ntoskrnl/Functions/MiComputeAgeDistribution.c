// MiComputeAgeDistribution 
 
unsigned int __fastcall MiComputeAgeDistribution(int a1, int a2)
{
  _BYTE *v4; // r0
  _DWORD *v5; // r5
  unsigned int result; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r6
  _DWORD *v9; // r2
  int *v10; // r1
  int v11; // t1
  unsigned int v12; // r4
  int v13; // r6
  int v14; // r1
  _DWORD *v15; // r2
  int v16; // r3
  int v17; // r0
  int v18; // r2
  _DWORD *v19; // r1
  unsigned int v20; // r0
  _BYTE v21[16]; // [sp-4h] [bp-40h] BYREF
  int v22; // [sp+Ch] [bp-30h] BYREF
  char v23[24]; // [sp+10h] [bp-2Ch] BYREF

  v22 = 0;
  v4 = memset(v23, 0, sizeof(v23));
  v5 = *(_DWORD **)(a1 + 3512);
  if ( a2 != 1 )
    return sub_5168DC(v4);
  KeAcquireInStackQueuedSpinLock(&dword_634980, v21);
  v7 = *(_DWORD **)(a1 + 3516);
  v8 = (_DWORD *)(a1 + 3516);
  while ( v7 != v8 )
  {
    MiUpdateClaimDistribution(v7 - 3, &v22);
    v7 = (_DWORD *)*v7;
  }
  v9 = v5 + 314;
  v10 = &v22;
  do
  {
    v11 = *v10++;
    *v9++ = v11;
  }
  while ( v9 != v5 + 321 );
  v12 = 0;
  v13 = 6;
  v14 = 2;
  v15 = v5 + 6;
  do
  {
    v16 = v15[314];
    --v13;
    --v15;
    v12 += v16;
    --v14;
  }
  while ( v14 );
  v5[313] = v12;
  KeReleaseInStackQueuedSpinLock(v21);
  v17 = v5[310];
  v18 = 0;
  if ( v12 < 4 * v17 )
  {
    v19 = &v5[v13];
    do
    {
      ++v18;
      v12 += v19[314];
      if ( !v13 )
        break;
      --v13;
      --v19;
    }
    while ( v12 < 4 * v17 );
  }
  v20 = v5[306];
  if ( v20 )
  {
    result = (unsigned __int16)(1000 * v18 / v20);
    if ( result > 0x3E8 )
      result = 1000;
  }
  else if ( v18 )
  {
    result = 1000;
  }
  else
  {
    result = 0;
  }
  return result;
}
