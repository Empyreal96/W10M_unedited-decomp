// SeSetSecurityAttributesTokenEx 
 
int __fastcall SeSetSecurityAttributesTokenEx(int a1, char a2, int a3, int a4, int *a5, int a6, _BYTE *a7)
{
  int v7; // r4
  int v8; // r5
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v14; // [sp+8h] [bp-20h] BYREF
  int v15; // [sp+Ch] [bp-1Ch] BYREF
  _DWORD v16[6]; // [sp+10h] [bp-18h] BYREF

  v16[0] = 0;
  v16[1] = 0;
  v14 = 0;
  if ( a3 )
    return -1073741811;
  if ( a4 && (SepTokenSingletonAttributesConfig & 3) == 3 )
  {
    if ( a2 )
    {
      v7 = -1073741790;
    }
    else
    {
      v7 = ObReferenceObjectByHandle(a1, 128, SeTokenObjectType, 0, &v15, 0);
      v8 = v15;
      if ( v7 >= 0 )
      {
        v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v9 + 308);
        ExAcquireResourceSharedLite(*(_DWORD *)(v8 + 48), 1);
        if ( SepGetProcUniqueLuidAndIndexFromToken(v8, &v14, v16) >= 0 )
        {
          v7 = SepSetSingletonEntry(v14, a5, a6);
          if ( v7 >= 0 )
            *a7 = 1;
        }
        else
        {
          *a7 = 0;
          v7 = AuthzBasepSetSecurityAttributesToken(*(_DWORD *)(v8 + 476), a5, a6);
        }
        v10 = ExpReleaseResourceForThreadLite(*(_DWORD *)(v8 + 48), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
        v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v12 = *(_WORD *)(v11 + 0x134) + 1;
        *(_WORD *)(v11 + 308) = v12;
        if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
          KiCheckForKernelApcDelivery(v10);
      }
      if ( v8 )
        ObfDereferenceObjectWithTag(v8);
    }
  }
  else
  {
    *a7 = 0;
    v7 = SepInternalSetSecurityAttributesToken(a1, a2, 1, a5, a6);
  }
  return v7;
}
