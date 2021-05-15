// KiInitializeMutant 
 
int __fastcall KiInitializeMutant(int result, int a2, char a3)
{
  int v3; // r4
  unsigned int v5; // r7
  int v6; // r0
  int v7; // lr
  unsigned int *v8; // r5
  unsigned int v9; // r1
  int *v10; // r0
  int v11; // r2

  v3 = result;
  *(_BYTE *)result = 2;
  *(_BYTE *)(result + 2) = 0;
  if ( !a2 )
  {
    *(_DWORD *)(result + 4) = 1;
    *(_DWORD *)(result + 24) = 0;
LABEL_3:
    *(_DWORD *)(v3 + 8) = v3 + 8;
    *(_DWORD *)(v3 + 12) = v3 + 8;
    *(_BYTE *)(v3 + 28) = 0;
    *(_BYTE *)(v3 + 29) = a3;
    return result;
  }
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 24) = v5;
  v6 = KfRaiseIrql(2);
  v7 = v6;
  v8 = (unsigned int *)(v5 + 44);
  do
    v9 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( !v9 )
  {
    v10 = *(int **)(v5 + 480);
    v11 = v3 + 16;
    *(_DWORD *)(v3 + 16) = v5 + 476;
    *(_DWORD *)(v3 + 20) = v10;
    if ( *v10 != v5 + 476 )
      __fastfail(3u);
    *v10 = v11;
    *(_DWORD *)(v5 + 480) = v11;
    __dmb(0xBu);
    *v8 = 0;
    result = KfLowerIrql(v7);
    goto LABEL_3;
  }
  return sub_50EE14(v6, v9, 1);
}
