// VfCtxHookAndConnectInterruptEx 
 
int __fastcall VfCtxHookAndConnectInterruptEx(int *a1)
{
  int v2; // r3
  int v3; // r3
  int v4; // r5
  unsigned int v5; // r0
  int v6; // r3
  unsigned int v8; // [sp+0h] [bp-40h] BYREF
  int v9[14]; // [sp+8h] [bp-38h] BYREF

  v8 = 0;
  v2 = ViCtxInitializedIsrStateBlocks;
  __dmb(0xBu);
  if ( !v2 )
    return pXdvIoConnectInterruptEx(a1);
  v3 = *a1;
  if ( *a1 != 1 && v3 != 2 && v3 != 3 )
    return pXdvIoConnectInterruptEx(a1);
  v4 = ViCtxSetPrivateConnectParameters(v9, a1, &v8);
  if ( v4 >= 0 )
  {
    v4 = pXdvIoConnectInterruptEx(v9);
    v5 = v8;
    if ( v8 )
    {
      v6 = v9[0];
      *a1 = v9[0];
      if ( v4 < 0 )
      {
        ExFreePoolWithTag(v5);
      }
      else if ( v6 == 1 || v6 == 2 || v6 == 3 )
      {
        a1[2] = v9[2];
      }
    }
  }
  return v4;
}
