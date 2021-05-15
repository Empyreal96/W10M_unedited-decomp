// PopWnfFullscreenVideoCallback 
 
int PopWnfFullscreenVideoCallback(int a1, int a2, int a3, ...)
{
  int v3; // r4
  unsigned int v4; // r3
  char v5; // r3
  unsigned int v7; // [sp+0h] [bp-18h] BYREF
  unsigned int v8[4]; // [sp+8h] [bp-10h] BYREF
  va_list varg_r3; // [sp+2Ch] [bp+14h] BYREF

  va_start(varg_r3, a3);
  v7 = 8;
  v3 = ExQueryWnfStateData(a1, (int *)varg_r3, (int)v8, &v7);
  if ( v3 >= 0 )
  {
    if ( v7 < 8 )
      return 0;
    PpmAcquireLock(&PopFxSystemLatencyLock);
    v4 = (v8[0] >> 1) & 1;
    if ( byte_61EC4F )
    {
      if ( !v4 )
      {
        v5 = 0;
        goto LABEL_11;
      }
    }
    else if ( v4 )
    {
      v5 = 1;
LABEL_11:
      byte_61EC4F = v5;
      PoFxSendSystemLatencyUpdate();
      goto LABEL_12;
    }
LABEL_12:
    PpmReleaseLock((int *)&PopFxSystemLatencyLock);
    return v3;
  }
  if ( (PoDebug & 1) != 0 )
    DbgPrint("PopWnfFullscreenVideoCallback: Failed to query WNF state data (Status=0x%x)\n", v3);
  return v3;
}
