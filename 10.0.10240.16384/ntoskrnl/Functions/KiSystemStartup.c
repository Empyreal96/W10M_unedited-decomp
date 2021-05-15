// KiSystemStartup 
 
void __fastcall __noreturn KiSystemStartup(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  _DWORD *v6; // r5
  _DWORD *v7; // r0
  int v12; // r0
  int v13; // r1

  KeLoaderBlock_0 = a1;
  v6 = (_DWORD *)a1[19];
  if ( !v6 )
    v6 = &unk_64D580;
  v7 = v6 - 352;
  __mcr(15, 0, (unsigned int)(v6 - 352), 13, 0, 4);
  v7[4] = v6;
  v7[3] = v7;
  a1[19] = v6;
  if ( !v6[1020] )
    v6[1020] = a1[18] + 12288;
  __asm
  {
    CPS.W           #0x11
    CPS.W           #0x12
    CPS.W           #0x1B
    CPS.W           #0x17
    CPS.W           #0x13
  }
  KiInitializeBootStructures(a1);
  if ( !*(_DWORD *)(a1[19] + 20) )
    KdInitSystem(0, a1);
  __asm { CPSIE           A }
  __mcr(15, 0, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFF0 | 0xF, 13, 0, 3);
  v12 = a1[20];
  v13 = a1[21];
  v6[433] = &a5;
  KiInitializeKernel(v12, v13);
  if ( !v6[5] )
    KiInitializeGSCookieValue();
  *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x86) = 2;
  do
  {
    _ZF = KiBarrierWait == 0;
    __yield();
  }
  while ( !_ZF );
  __dmb(0xBu);
  KiIdleLoop();
}
