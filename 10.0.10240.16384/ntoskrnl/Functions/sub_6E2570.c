// sub_6E2570 
 
int __fastcall sub_6E2570(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int *v7; // r2
  int v8; // r1
  unsigned int v9; // r1
  int v11; // [sp+0h] [bp-20h]
  int v12; // [sp+4h] [bp-1Ch] BYREF
  int v13; // [sp+8h] [bp-18h]
  int v14; // [sp+Ch] [bp-14h]

  v12 = a2;
  v13 = a3;
  v14 = a4;
  if ( !a1 )
    return -1073741811;
  v6 = KeAbPreAcquire((unsigned int)&dword_922C04, 0, 0);
  v14 = 0;
  v13 = 17;
  v7 = &dword_922C04;
  do
    v8 = __ldrex((unsigned int *)&dword_922C04);
  while ( !v8 && __strex(0x11u, (unsigned int *)&dword_922C04) );
  __dmb(0xBu);
  v13 = v8;
  if ( v8 )
    ExfAcquirePushLockSharedEx(&dword_922C04, v6, (unsigned int)&dword_922C04);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( dword_922BEC )
  {
    v12 = *(_DWORD *)dword_922BEC;
    v11 = sub_6E2544(&v12, v8, (int)v7, v12);
    if ( v11 >= 0 )
      memmove(a1, v12, 0x30u);
  }
  else
  {
    v11 = -1073741275;
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&dword_922C04);
  while ( v9 == 17 && __strex(0, (unsigned int *)&dword_922C04) );
  if ( v9 != 17 )
    ExfReleasePushLockShared(&dword_922C04);
  KeAbPostRelease((unsigned int)&dword_922C04);
  return v11;
}
