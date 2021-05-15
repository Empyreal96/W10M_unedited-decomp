// sub_7EEBA0 
 
void sub_7EEBA0()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r2
  unsigned int v3; // r2
  int v4; // r2
  int v5; // r0
  int v6; // r0
  unsigned int v7; // r1
  int v8; // r3

  if ( v1 == 2 )
  {
    v0 = (_DWORD *)v0[1];
    if ( !v0 || (v2 = v0[67], (v2 & 0x2000) == 0) || v0[69] != 24 || (v2 & 0x1000) == 0 )
    {
      v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v3 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      while ( 1 )
      {
        if ( !v0 )
          goto LABEL_19;
        if ( v0[6] )
        {
          v5 = PnpDeviceObjectFromDeviceInstance((int)(v0 + 5));
          if ( v5 )
            break;
        }
        v0 = (_DWORD *)*v0;
      }
      ObfDereferenceObject(v5);
LABEL_19:
      v6 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v8 = (__int16)(*(_WORD *)(v7 + 0x134) + 1);
      *(_WORD *)(v7 + 308) = v8;
      if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
        KiCheckForKernelApcDelivery(v6);
      JUMPOUT(0x780DA6);
    }
  }
  else if ( v1 != 3 )
  {
    JUMPOUT(0x780DC8);
  }
  do
  {
    v0 = (_DWORD *)*v0;
    if ( !v0 )
      break;
    v4 = v0[67];
    if ( (v4 & 0x2000) == 0 )
      break;
  }
  while ( v0[69] == 24 && (v4 & 0x1000) != 0 );
  JUMPOUT(0x780DA0);
}
