// SeExamineGlobalSacl 
 
int __fastcall SeExamineGlobalSacl(int result, int a2, int a3, int a4, unsigned __int8 a5, bool *a6, bool *a7)
{
  int v10; // r10
  unsigned int v11; // r5
  unsigned __int16 *v12; // r0
  bool v13; // r3
  bool v14; // r3
  unsigned int v15; // r1
  __int16 v16; // r3
  char v17; // [sp+10h] [bp-28h] BYREF
  char v18[3]; // [sp+11h] [bp-27h] BYREF
  int v19[9]; // [sp+14h] [bp-24h] BYREF

  v10 = result;
  if ( a6 && !*a6 )
  {
    v19[0] = 0;
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    ExAcquireResourceSharedLite((int)&SepRmGlobalSaclLock, 1);
    if ( SepRmGlobalSaclFind(v19, 0, v10, 0) >= 0 )
    {
      v12 = *(unsigned __int16 **)(v19[0] + 12);
      if ( v12 )
      {
        SeExamineSacl(v12, a2, a3, a4, a5, &v17, v18);
        v13 = *a6 || v17;
        *a6 = v13;
        if ( a7 )
        {
          v14 = *a7 || v18[0];
          *a7 = v14;
        }
      }
    }
    result = ExReleaseResourceLite((int)&SepRmGlobalSaclLock);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
