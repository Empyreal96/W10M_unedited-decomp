// MiAllocateInPageSupport 
 
int __fastcall MiAllocateInPageSupport(unsigned int a1, int a2, _DWORD *a3, int *a4)
{
  int v6; // r5
  int v8; // r8
  int v9; // r0
  int v10; // r4
  int v12; // r0

  v6 = a2;
  if ( a4 )
    v8 = *a4;
  else
    v8 = 0;
  if ( *a3 > 0x100u )
    *a3 = 256;
  if ( *a3 > 0x10u )
    v6 = a2 | 1;
  if ( a4 )
    v9 = v6 | 4;
  else
    v9 = v6;
  v10 = MiGetInPageSupportBlock(v9);
  if ( v10 )
    return v10;
  if ( a4 )
  {
    MiUnlockProtoPoolPage(v8, 17);
    v10 = MiGetInPageSupportBlock(v6);
    if ( !v10 )
    {
      if ( (v6 & 1) == 0 )
        return v10;
      *a3 = 16;
      v10 = MiGetInPageSupportBlock(v6 & 0xFFFFFFFE);
      if ( !v10 )
        JUMPOUT(0x544E5A);
    }
    v12 = MiLockProtoPoolPage(a1, 0);
    if ( !v12 )
      JUMPOUT(0x544E54);
    *a4 = v12;
    return v10;
  }
  return sub_544E44();
}
