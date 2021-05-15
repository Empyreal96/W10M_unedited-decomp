// IopRegistryInitializeCallbacks 
 
int IopRegistryInitializeCallbacks()
{
  __int16 **v0; // r4
  __int16 *v1; // r6
  __int16 **v2; // r5
  __int16 *v3; // r3
  int v4; // r0
  char v6[8]; // [sp+18h] [bp-28h] BYREF
  char v7[32]; // [sp+20h] [bp-20h] BYREF

  v0 = &IopRegistryRegisteredCallbacks;
  v6[0] = 0;
  v1 = 0;
  if ( off_617578 )
  {
    v2 = &IopRegistryRegisteredCallbacks;
    do
    {
      v3 = v0[6];
      if ( v3 )
        v4 = ((int (__fastcall *)(__int16 **))v3)(v0);
      else
        v4 = 0;
      if ( v4 < 0 )
      {
        v0[1] = 0;
      }
      else
      {
        RtlInitUnicodeString((unsigned int)v7, (unsigned __int16 *)*v0);
        v0[10] = (__int16 *)IopRegistryCallback;
        v0[11] = v1;
        v0[8] = 0;
        if ( IopRegistryOpenDeepestPath(v7, v0 + 4, v6) >= 0 )
        {
          ZwNotifyChangeKey();
          if ( v6[0] )
            v0[5] = (__int16 *)((unsigned int)v0[5] | 1);
        }
      }
      v2 += 14;
      v1 = (__int16 *)((char *)v1 + 1);
      v0 = v2;
    }
    while ( v2[2] );
  }
  return 0;
}
