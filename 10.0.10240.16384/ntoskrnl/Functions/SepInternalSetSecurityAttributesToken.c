// SepInternalSetSecurityAttributesToken 
 
int __fastcall SepInternalSetSecurityAttributesToken(int a1, char a2, int a3, int *a4, int a5)
{
  int v7; // r5
  int *v8; // r4
  int v9; // r2
  int v10; // r3
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15[6]; // [sp+8h] [bp-18h] BYREF

  v15[0] = a3;
  v15[1] = (int)a4;
  v7 = ObReferenceObjectByHandle(a1, 128, SeTokenObjectType, a2, v15, 0);
  v8 = (int *)v15[0];
  if ( v7 >= 0 )
  {
    if ( a4 )
    {
      v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v10 = *(__int16 *)(v9 + 0x134) - 1;
      *(_WORD *)(v9 + 308) = v10;
      ExAcquireResourceExclusiveLite(v8[12], 1, v9, v10);
      __dmb(0xFu);
      v7 = AuthzBasepSetSecurityAttributesToken(v8[119], a4, a5);
      if ( v7 >= 0 )
      {
        if ( a3 )
          v8[44] |= 0x20000u;
        ExAllocateLocallyUniqueId(v8 + 13);
      }
      __dmb(0xFu);
      v11 = ExpReleaseResourceForThreadLite(v8[12], __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(_WORD *)(v12 + 0x134) + 1;
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v11);
    }
    else
    {
      v7 = -1073741811;
    }
  }
  if ( v8 )
    ObfDereferenceObjectWithTag((int)v8);
  return v7;
}
