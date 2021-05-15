// LpcSendWaitReceivePort 
 
int __fastcall LpcSendWaitReceivePort(_DWORD *a1, int a2, unsigned int a3, unsigned int *a4, char a5, char a6, unsigned int a7)
{
  int v8; // r4
  int v9; // r1
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r1
  __int16 v13; // r3

  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
  v9 = 131074;
  if ( a5 == 1 )
    v9 = 1179650;
  if ( a6 )
    v9 |= 0x200000u;
  v10 = AlpcpProcessSynchronousRequest(a1, v9, a2, 0, a3, a4, 0, a7, 0, a5);
  v11 = v10;
  if ( v10 == -1073740029 )
    v11 = -1073741769;
  if ( v11 == -1073740031 )
    v11 = -1073741229;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v11;
}
