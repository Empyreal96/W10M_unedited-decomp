// sub_7C3EB8 
 
void __fastcall sub_7C3EB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int *v7; // r6
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned __int8 *v11; // r7
  int v12; // r0
  unsigned int v13; // r2

  v7 = (unsigned int *)(a7 + 40);
  v8 = KeAbPreAcquire(a7 + 40, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v7, v8, (unsigned int)v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = (unsigned __int8 *)(a7 + 52);
  v12 = KeAbPreAcquire(a7 + 52, 0, 0);
  do
    v13 = __ldrex(v11);
  while ( __strex(v13 | 1, v11) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a7 + 52), v12, a7 + 52);
  JUMPOUT(0x6B8564);
}
