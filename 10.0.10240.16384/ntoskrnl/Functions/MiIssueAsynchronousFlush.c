// MiIssueAsynchronousFlush 
 
unsigned int __fastcall MiIssueAsynchronousFlush(_DWORD *a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6, char a7, int a8)
{
  unsigned int v9; // r5
  _DWORD *v10; // r1
  _DWORD *v11; // r8
  unsigned int *v13; // r10
  unsigned int *v14; // r1
  unsigned int v15; // r2
  int v16; // r7
  int v17; // r4
  int v18; // r4
  int v19; // r0
  unsigned int varg_r1; // [sp+44h] [bp+Ch]
  unsigned int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v9 = a2;
  v10 = (_DWORD *)(a2 + 32);
  *(_BYTE *)(v9 + 26) = 4;
  *(_BYTE *)(v9 + 24) = 0;
  *(_BYTE *)(v9 + 25) = 0;
  *(_DWORD *)(v9 + 28) = 0;
  *v10 = v10;
  v10[1] = v10;
  v11 = *(_DWORD **)(v9 + 40);
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 4) = 0;
  v13 = (unsigned int *)(a3 + 1120);
  *(_DWORD *)(v9 + 8) = &v11[(v11[5] >> 12) + 7];
  if ( a4 )
  {
    v14 = (unsigned int *)(a4 + 8);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 + 1, v14) );
    __dmb(0xBu);
  }
  v16 = IoAsynchronousPageWrite(
          a1,
          v11,
          &a5,
          (void (__fastcall *)(int, int *, _DWORD))MiFlushComplete,
          v9,
          a8,
          0,
          a7,
          (int *)v9,
          (int *)(v9 + 12));
  if ( (v16 & 0xC0000000) == -1073741824 )
  {
    *(_DWORD *)v9 = v16;
    *(_DWORD *)(v9 + 4) = 0;
    v17 = KfRaiseIrql(1);
    MiFlushComplete((_DWORD *)v9, (int *)v9);
    KfLowerIrql(v17);
    if ( a4 )
      *(_DWORD *)(a4 + 12) = v16;
    v11[5] = 0;
  }
  else
  {
    v18 = 0;
    v19 = KfRaiseIrql(1);
    do
    {
LABEL_11:
      v9 += 140;
      if ( v9 >= (unsigned int)v13 )
        v9 = a3;
      if ( !*(_DWORD *)(v9 + 8) || *(_DWORD *)(v9 + 28) == 1 )
      {
        KfLowerIrql(v19);
        return v9;
      }
      ++v18;
    }
    while ( v18 != 8 );
    KfLowerIrql(v19);
    KeWaitForMultipleObjects(8u, v13, 1, 19, 0, 0, 0, (int *)(a3 + 1152));
    v9 = a3;
    while ( *(int *)v9 >= 0 )
    {
      v9 += 140;
      if ( !--v18 )
      {
        v19 = KfRaiseIrql(1);
        goto LABEL_11;
      }
    }
    *(_DWORD *)(*(_DWORD *)(v9 + 40) + 20) = 0;
  }
  return 0;
}
