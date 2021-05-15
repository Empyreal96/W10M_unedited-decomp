// LpcpRequestWaitReplyPort 
 
int __fastcall LpcpRequestWaitReplyPort(int a1, int a2, unsigned int a3, int a4, char a5, int a6)
{
  unsigned int v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r1
  __int16 v11; // r3
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r3 = a4;
  LOBYTE(varg_r3) = a4;
  v6 = a3;
  if ( (_BYTE)a4 )
  {
    if ( (a3 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a3 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a3 = *(_BYTE *)a3;
    *(_BYTE *)(a3 + 16) = *(_BYTE *)(a3 + 16);
  }
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = AlpcpProcessSynchronousRequest(a1, a6 | 0x20000, a2, 0, v6, 0, 0, 0, (char)a4, a5, a4);
  v9 = v8;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v8);
  if ( v9 == -1073740029 )
    v9 = -1073741769;
  if ( v9 == -1073740031 )
    v9 = -1073741229;
  return v9;
}
