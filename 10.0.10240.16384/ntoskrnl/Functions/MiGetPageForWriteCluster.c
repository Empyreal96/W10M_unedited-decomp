// MiGetPageForWriteCluster 
 
int __fastcall MiGetPageForWriteCluster(int a1, unsigned int *a2, unsigned int a3, int a4, int a5, _DWORD *a6, int *a7)
{
  int v8; // r0
  int v9; // r4
  unsigned int *v11; // r2
  unsigned int v12; // r0
  _DWORD var18[10]; // [sp+8h] [bp-18h] BYREF
  unsigned int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  var18[8] = a1;
  var18[9] = a2;
  varg_r3 = a4;
  var18[0] = a3;
  var18[1] = a4;
  *a7 = 1;
  varg_r2 = a3;
  v8 = MiCheckPteForWriteCluster(a1, a2, a3, (int)var18, a1, (unsigned __int8 *)var18);
  v9 = v8;
  if ( v8 )
  {
    *a7 = MiReferencePageForModifiedWrite(v8, 0);
    __dmb(0xBu);
    v11 = (unsigned int *)(v9 + 12);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 & 0x7FFFFFFF, v11) );
    KfLowerIrql(LOBYTE(var18[0]));
    if ( *a7 )
    {
      *a6 = 0;
      return (v9 - MmPfnDatabase) / 24;
    }
    return -1;
  }
  if ( *a6 > 0x1Fu || ((*(int *)(*(_DWORD *)(a1 + 4) + 4 * (varg_r2 >> 18)) >> ((varg_r2 >> 13) & 0x1F)) & 1) != 0 )
    return -1;
  ++*a6;
  v9 = dword_6348F0;
  return (v9 - MmPfnDatabase) / 24;
}
