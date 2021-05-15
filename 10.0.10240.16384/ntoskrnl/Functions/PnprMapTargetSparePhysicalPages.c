// PnprMapTargetSparePhysicalPages 
 
int __fastcall PnprMapTargetSparePhysicalPages(__int64 a1, __int64 a2, __int64 *a3, int *a4, int *a5)
{
  __int64 v5; // r2
  int v6; // r6
  int result; // r0
  int v8; // r3
  int v9; // r2
  int v10; // r2
  __int64 varg_r0; // [sp+20h] [bp+8h]

  varg_r0 = a1;
  v5 = a1;
  v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  LODWORD(a1) = 0;
  if ( __PAIR64__(HIDWORD(a1), varg_r0) == 0x7FFFFFFFFFFFFFFFi64
    || (result = PnprMapPhysicalPages((int *)(*(_DWORD *)(PnprContext + 104) + 12 * v6), v5, a3, a4), result >= 0) )
  {
    if ( a2 == 0x7FFFFFFFFFFFFFFFi64 )
      return result;
    result = PnprMapPhysicalPages((int *)(*(_DWORD *)(PnprContext + 108) + 12 * v6), a2, a3, a5);
    if ( result >= 0 )
      return result;
    v8 = PnprContext;
    v9 = *(_DWORD *)(PnprContext + 608);
    if ( !v9 )
      v9 = 4226;
  }
  else
  {
    v8 = PnprContext;
    v9 = *(_DWORD *)(PnprContext + 608);
    if ( !v9 )
      v9 = 4214;
  }
  *(_DWORD *)(v8 + 608) = v9;
  v10 = *(_DWORD *)(v8 + 612);
  if ( !v10 )
    v10 = 10;
  *(_DWORD *)(v8 + 612) = v10;
  return result;
}
