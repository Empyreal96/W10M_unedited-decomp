// SepExamineGlobalSaclEx 
 
int __fastcall SepExamineGlobalSaclEx(int result, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9, int a10, unsigned __int8 a11, bool *a12, bool *a13)
{
  int v16; // r7
  unsigned int v17; // r2
  int v18; // r0
  bool v19; // r3
  bool v20; // r3
  unsigned int v21; // r1
  __int16 v22; // r3
  char v23; // [sp+28h] [bp-28h] BYREF
  char v24[3]; // [sp+29h] [bp-27h] BYREF
  int v25[9]; // [sp+2Ch] [bp-24h] BYREF

  v16 = result;
  if ( a12 && !*a12 || a13 && !*a13 )
  {
    v25[0] = 0;
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v17 + 308);
    ExAcquireResourceSharedLite((int)&SepRmGlobalSaclLock, 1);
    if ( SepRmGlobalSaclFind(v25, 0, v16, 0) >= 0 )
    {
      v18 = *(_DWORD *)(v25[0] + 12);
      if ( v18 )
      {
        SepExamineSaclEx(v18, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, &v23, v24);
        if ( a12 )
        {
          v19 = *a12 || v23;
          *a12 = v19;
        }
        if ( a13 )
        {
          v20 = *a13 || v24[0];
          *a13 = v20;
        }
      }
    }
    result = ExpReleaseResourceForThreadLite((int)&SepRmGlobalSaclLock, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = *(_WORD *)(v21 + 0x134) + 1;
    *(_WORD *)(v21 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
