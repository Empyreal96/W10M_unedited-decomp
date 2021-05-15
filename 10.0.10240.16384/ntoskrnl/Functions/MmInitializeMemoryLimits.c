// MmInitializeMemoryLimits 
 
int __fastcall MmInitializeMemoryLimits(int a1, int a2)
{
  int *v3; // r3
  unsigned int v5; // r6
  int *v6; // r8
  unsigned int *v7; // r0
  unsigned int *v8; // r4
  int *v9; // r2
  unsigned int v10; // r5
  unsigned int v11; // r9
  int v12; // lr
  unsigned int *v14; // r1
  int v15; // r3
  int v16; // r0
  unsigned int *v17; // r6
  __int64 v18; // kr00_8
  int v19; // r3

  v3 = *(int **)(a1 + 24);
  v5 = 0;
  v6 = (int *)(a1 + 24);
  while ( v3 != v6 )
  {
    v3 = (int *)*v3;
    ++v5;
  }
  v7 = (unsigned int *)ExAllocatePoolWithTag(512, 8 * (v5 + 1), 1817013581);
  v8 = v7;
  if ( !v7 )
    return 0;
  *v7 = v5;
  v9 = *(int **)(a1 + 24);
  v10 = 0;
  v11 = 0;
  v12 = -1;
  if ( v9 == v6 )
    return sub_969628();
  v14 = v7;
  do
  {
    v15 = v9[2];
    if ( v15 < 33 && *(_BYTE *)(v15 + a2) )
    {
      v18 = *(_QWORD *)(v9 + 3);
      v11 += HIDWORD(v18);
      if ( (_DWORD)v18 == v12 )
      {
        v14[1] += HIDWORD(v18);
        v12 += v9[4];
      }
      else
      {
        v14[2] = v18;
        v19 = v9[4];
        ++v10;
        v14[3] = v19;
        v14 += 2;
        v12 = v18 + v19;
      }
    }
    v9 = (int *)*v9;
  }
  while ( v9 != v6 );
  if ( !v10 )
    return sub_969628();
  if ( v5 > v10 )
  {
    v16 = ExAllocatePoolWithTag(512, 8 * v10 + 8, 1817013581);
    v17 = (unsigned int *)v16;
    if ( v16 )
    {
      memmove(v16 + 8, (int)(v8 + 2), 8 * v10);
      ExFreePoolWithTag((unsigned int)v8);
      v8 = v17;
    }
  }
  *v8 = v10;
  v8[1] = v11;
  return (int)v8;
}
