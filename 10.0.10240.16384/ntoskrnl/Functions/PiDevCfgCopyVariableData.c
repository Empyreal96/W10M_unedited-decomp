// PiDevCfgCopyVariableData 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDevCfgCopyVariableData(int a1, _DWORD *a2)
{
  int v3; // r1
  int v4; // r6
  int v5; // r4 OVERLAPPED
  int v7; // r1
  int v8; // r0
  int v9; // r3

  v3 = a2[6];
  v4 = 0;
  v5 = 0;
  if ( !v3 )
    goto LABEL_9;
  if ( *((unsigned __int16 *)a2 + 8) == 0x8000 )
  {
    v4 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v3, 0, 0);
    if ( v4 >= 0 )
    {
      v5 = 0;
LABEL_9:
      *(_DWORD *)(a1 + 16) = a2[4];
      v9 = a2[5];
      *(_QWORD *)(a1 + 20) = *(_QWORD *)(&v5 - 1);
      return v4;
    }
  }
  else
  {
    v7 = a2[5];
    if ( !v7 )
      goto LABEL_9;
    v8 = ExAllocatePoolWithTag(1, v7, 1667526736);
    v5 = v8;
    if ( v8 )
    {
      memmove(v8, a2[6], a2[5]);
      goto LABEL_9;
    }
    v4 = -1073741670;
  }
  return v4;
}
