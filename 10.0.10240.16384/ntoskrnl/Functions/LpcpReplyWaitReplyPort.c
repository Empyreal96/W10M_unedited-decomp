// LpcpReplyWaitReplyPort 
 
int __fastcall LpcpReplyWaitReplyPort(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r5
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r1
  __int16 v8; // r3
  int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  LOBYTE(varg_r3) = a4;
  LOBYTE(varg_r2) = a3;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  if ( (_BYTE)a3 )
  {
    if ( (a2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 16) = *(_BYTE *)(a2 + 16);
  }
  v5 = AlpcpProcessSynchronousRequest(a1, 131073, a2, 0, a2, 0, 0, 0, a3, a4);
  v6 = v5;
  if ( v5 == -1073740029 )
    v6 = -1073741769;
  if ( v6 == -1073740031 )
    v6 = -1073741229;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return v6;
}
