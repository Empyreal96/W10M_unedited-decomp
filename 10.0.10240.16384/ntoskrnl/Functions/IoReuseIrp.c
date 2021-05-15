// IoReuseIrp 
 
int __fastcall IoReuseIrp(int a1, int a2)
{
  int v2; // r9
  int result; // r0
  int v6; // r5
  int v7; // r6
  int v8; // r2
  char v9; // r7
  int v11; // r10
  _DWORD *v12; // r2
  int v14; // r2
  int v15; // r3
  int v16; // r3
  __int64 v17; // kr00_8
  int v19; // [sp+10h] [bp-30h] BYREF
  int v20; // [sp+14h] [bp-2Ch]
  int v21; // [sp+18h] [bp-28h]
  int v22; // [sp+1Ch] [bp-24h]

  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v2 = 0;
  if ( (MmVerifierData & 0x10) != 0 )
    return sub_52A27C();
  v6 = *(char *)(a1 + 34);
  v7 = *(unsigned __int16 *)(a1 + 2);
  v8 = *(_DWORD *)(a1 + 104);
  v9 = *(_BYTE *)(a1 + 39) & 0x2D;
  if ( (*(_BYTE *)(a1 + 39) & 0x80) == 0 && v8 && (*(_WORD *)(v8 + 2) & 1) != 0 )
  {
    v12 = *(_DWORD **)(a1 + 104);
    v2 = 1;
    v19 = v12[3];
    v20 = v12[4];
    v21 = v12[5];
    v22 = v12[6];
  }
  IopFreeIrpExtension(a1, -1);
  v11 = *(_DWORD *)(a1 + 104);
  memset((_BYTE *)a1, 0, v7);
  *(_WORD *)a1 = 6;
  *(_BYTE *)(a1 + 35) = v6 + 1;
  *(_WORD *)(a1 + 2) = v7;
  *(_BYTE *)(a1 + 34) = v6;
  result = *(unsigned __int8 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A);
  *(_BYTE *)(a1 + 38) = result;
  *(_DWORD *)(a1 + 16) = a1 + 16;
  *(_DWORD *)(a1 + 20) = a1 + 16;
  *(_DWORD *)(a1 + 96) = a1 + 40 * v6 + 112;
  *(_BYTE *)(a1 + 39) = v9;
  *(_DWORD *)(a1 + 24) = a2;
  if ( v11 )
  {
    *(_DWORD *)(a1 + 104) = v11;
    if ( v2 == 1 )
      result = IoSetActivityIdIrp(a1, &v19);
    if ( (IopFunctionPointerMask & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
    {
      v14 = *(_DWORD *)(a1 + 104);
      if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0
        || (!v14 || (*(_WORD *)(v14 + 2) & 1) == 0 ? (v15 = 0) : (v15 = 1),
            !v15
         || ((result = IoTraceHandle, !*(_QWORD *)&IoTraceHandle)
          || (result = EtwEventEnabled(IoTraceHandle, MEMORY[0x631B04], IoTrace_KernelIo_ReuseIrp)) == 0 ? (v16 = 0) : (v16 = 1),
             v16)) )
      {
        EtwActivityIdControl(3, &v19);
        v17 = *(_QWORD *)&IoTraceHandle;
        if ( *(_QWORD *)&IoTraceHandle && EtwEventEnabled(IoTraceHandle, MEMORY[0x631B04], IoTrace_KernelIo_ReuseIrp) )
          EtwWriteTransfer(v17, SHIDWORD(v17), (int)IoTrace_KernelIo_ReuseIrp);
        result = IoSetActivityIdIrp(a1, &v19);
      }
    }
  }
  return result;
}
