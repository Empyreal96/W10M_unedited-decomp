// SepCreateSidValuesBlock 
 
int __fastcall SepCreateSidValuesBlock(int **a1, int *a2, unsigned int a3, int a4, int a5, unsigned int a6)
{
  int *v7; // r2
  int **v8; // r6
  int v10; // r1
  unsigned int v11; // r8
  int v12; // r10
  int *v13; // r0
  int *v14; // r5
  bool v15; // zf
  int v16; // r10
  unsigned int v17; // r4
  int v18; // r2
  unsigned int v21; // [sp+4h] [bp-24h]

  v7 = a2;
  v8 = a1;
  if ( !a1 )
    return -1073741811;
  v10 = a5;
  *a1 = 0;
  v11 = a3;
  if ( a6 < a3 )
  {
    v11 = a3 - 1;
    v10 = a5 - 4 * *(unsigned __int8 *)(*(_DWORD *)(a4 + 8 * a6) + 1) - 8;
  }
  v12 = (((v10 + 3) & 0xFFFFFFFC) + ((4 * *(unsigned __int8 *)(*v7 + 1) + 11) & 0xFFFFFFFC) + 15) & 0xFFFFFFFC;
  v13 = (int *)ExAllocatePoolWithTag(1, v12, 1985176915);
  v14 = v13;
  if ( !v13 )
    return -1073741670;
  memset(v13, 0, v12);
  *v14 = v12;
  v14[1] = 1;
  v15 = a3 == -1;
  v21 = a3 + 1;
  v16 = (int)(v14 + 3);
  v17 = 0;
  if ( v15 )
    goto LABEL_12;
  do
  {
    if ( v17 )
    {
      if ( v17 - 1 == a6 )
        goto LABEL_10;
      v18 = *(_DWORD *)(a4 + 8 * v17 - 8);
    }
    else
    {
      v18 = *a2;
    }
    RtlCopySid(4 * (*(unsigned __int8 *)(v18 + 1) + 2), v16, v18);
    v16 += (4 * *(unsigned __int8 *)(v16 + 1) + 11) & 0xFFFFFFFC;
LABEL_10:
    ++v17;
  }
  while ( v17 < v21 );
  v8 = a1;
LABEL_12:
  v14[2] = v11 + 1;
  *v8 = v14;
  return 0;
}
