// PiDqDeleteUserObjectFromLoadedHives 
 
int __fastcall PiDqDeleteUserObjectFromLoadedHives(unsigned __int16 *a1, int a2)
{
  int v4; // r0
  int i; // r4
  unsigned __int16 *v6; // r3
  int v8; // [sp+Ch] [bp-224h]
  unsigned int v9; // [sp+10h] [bp-220h] BYREF
  char v10[536]; // [sp+18h] [bp-218h] BYREF

  v4 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, 0, (int)L"\\REGISTRY\\USER", 0);
  if ( v4 >= 0 )
  {
    for ( i = 0; ; ++i )
    {
      v9 = 256;
      if ( PnpCtxRegEnumKey(v4, 0, i, (int)v10, &v9) < 0 )
        break;
      v4 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, 0, (int)v10, 0);
      if ( v4 >= 0 )
      {
        PiDqDeleteUserObject(v8, a1, a2, v6);
        v4 = ZwClose();
      }
    }
  }
  return 0;
}
