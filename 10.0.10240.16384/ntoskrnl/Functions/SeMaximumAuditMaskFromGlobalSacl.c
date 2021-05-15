// SeMaximumAuditMaskFromGlobalSacl 
 
int __fastcall SeMaximumAuditMaskFromGlobalSacl(int result, int a2, int a3, _DWORD *a4)
{
  int v4; // r6
  unsigned int v8; // r5
  unsigned int v9; // r1
  __int16 v10; // r3
  int v11; // [sp+0h] [bp-20h] BYREF
  int v12[7]; // [sp+4h] [bp-1Ch] BYREF

  v11 = a3;
  v12[0] = (int)a4;
  v4 = result;
  if ( result && *(_DWORD *)(result + 4) )
  {
    v11 = 0;
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    ExAcquireResourceSharedLite((int)&SepRmGlobalSaclLock, 1);
    if ( SepRmGlobalSaclFind(&v11, 0, v4, 0) >= 0 )
    {
      v12[0] = 0;
      SeMaximumAuditMask(*(_DWORD *)(v11 + 12), a2, a3, v12);
      *a4 |= v12[0];
    }
    result = ExReleaseResourceLite((int)&SepRmGlobalSaclLock);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
