// sub_7BDE9C 
 
int __fastcall sub_7BDE9C(int a1, int a2, int a3)
{
  int v4; // r4
  _DWORD *v5; // r7
  unsigned int *v6; // r5
  unsigned int v7; // r2
  int (__fastcall *v8)(int); // [sp-4h] [bp-4h]

  if ( (v5[38] & a3) != 0 )
    JUMPOUT(0x720E1C);
  v6 = (unsigned int *)(a2 - 4);
  __dmb(0xBu);
  do
    v7 = __ldrex(v6);
  while ( v7 == 17 && __strex(0, v6) );
  if ( v7 != 17 )
    ExfReleasePushLockShared(v6);
  KeAbPostRelease((unsigned int)v6);
  AlpcpCancelMessage(v5, v4, 0x10000);
  return v8(-1073741769);
}
