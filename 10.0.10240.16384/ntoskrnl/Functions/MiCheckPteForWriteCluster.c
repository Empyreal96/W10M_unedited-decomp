// MiCheckPteForWriteCluster 
 
int __fastcall MiCheckPteForWriteCluster(int a1, unsigned int *a2, unsigned int a3, int a4, int a5, unsigned __int8 *a6)
{
  int v7; // r0
  int v8; // r4
  int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r4
  int varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  v7 = MiLockTransitionLeafPage(a2, (unsigned int)a6);
  v8 = v7;
  if ( !v7 )
    goto LABEL_13;
  if ( (*(_BYTE *)(v7 + 18) & 7) != 3 || *(_WORD *)(v7 + 16) )
  {
    v9 = *a6;
    __dmb(0xBu);
    v12 = (unsigned int *)(v8 + 12);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 & 0x7FFFFFFF, v12) );
    goto LABEL_12;
  }
  if ( (*(_DWORD *)(v7 + 8) & 0xFFFFFC1F) != a3
    || ((*(int *)(*(_DWORD *)(a1 + 4) + 4 * (a3 >> 18)) >> ((a3 >> 13) & 0x1F)) & 1) != 0 )
  {
    v9 = *a6;
    __dmb(0xBu);
    v10 = (unsigned int *)(v8 + 12);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0x7FFFFFFF, v10) );
LABEL_12:
    KfLowerIrql(v9);
LABEL_13:
    v8 = 0;
  }
  return v8;
}
