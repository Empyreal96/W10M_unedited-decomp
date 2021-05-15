// IopInitActivityIdIrp 
 
int __fastcall IopInitActivityIdIrp(int a1)
{
  int v1; // r9
  int *v2; // r8
  int *v3; // r10
  unsigned int v4; // r1
  int v5; // r2
  int v6; // r3
  int *v7; // r6
  int v9; // r1
  int v10; // r3
  int v11; // r6
  int v12; // r4
  _DWORD *v13; // r0
  int v14; // r1
  int v15; // r3
  int result; // r0
  int v19; // [sp+28h] [bp-40h] BYREF
  int v20; // [sp+2Ch] [bp-3Ch]
  int v21; // [sp+30h] [bp-38h]
  int v22; // [sp+34h] [bp-34h]
  int v23; // [sp+38h] [bp-30h] BYREF
  int v24; // [sp+3Ch] [bp-2Ch]
  int v25; // [sp+40h] [bp-28h]
  int v26; // [sp+44h] [bp-24h]

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v5 = 0;
  }
  else
  {
    __disable_irq();
    v5 = 1;
  }
  v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v5 )
    __enable_irq();
  if ( (v6 & 0x10001) != 0 )
    goto LABEL_28;
  v7 = *(int **)(v4 + 1036);
  if ( v7 )
  {
    if ( IoTraceHandle && EtwEventEnabled(IoTraceHandle, SHIDWORD(IoTraceHandle), (int)IoTrace_KernelIo_AllocateIrp) )
    {
      v2 = v7;
      v3 = IoTrace_KernelIo_AllocateIrp;
    }
    else
    {
      v9 = v7[1];
      v5 = v7[2];
      v10 = v7[3];
      v19 = *v7;
      v20 = v9;
      v21 = v5;
      v22 = v10;
      v1 = 1;
    }
    v11 = a1;
    goto LABEL_29;
  }
  if ( !PnpIsSafeToExamineUserModeTeb() )
  {
LABEL_28:
    v11 = a1;
    goto LABEL_29;
  }
  v12 = 0;
  if ( PsGetCurrentThreadTeb() )
  {
    v13 = (_DWORD *)PsGetCurrentThreadTeb();
    v14 = v13[981];
    v5 = v13[982];
    v15 = v13[983];
    v23 = v13[980];
    v24 = v14;
    v25 = v5;
    v26 = v15;
    v12 = 1;
  }
  v11 = a1;
  if ( v12 && memcmp((unsigned int)&NullGuid, (unsigned int)&v23, 16) )
  {
    if ( IoTraceHandle && EtwEventEnabled(IoTraceHandle, SHIDWORD(IoTraceHandle), (int)IoTrace_UserInitiatedIo) )
    {
      v2 = &v23;
      v3 = IoTrace_UserInitiatedIo;
    }
    else
    {
      v19 = v23;
      v20 = v24;
      v21 = v25;
      v22 = v26;
      v1 = 1;
    }
  }
LABEL_29:
  if ( !v1 )
    EtwActivityIdControl(3, &v19);
  result = IoSetActivityIdIrp(v11, &v19, v5);
  if ( result >= 0 )
  {
    **(_WORD **)(v11 + 104) |= 2u;
    if ( v2 )
      result = EtwWriteTransfer(IoTraceHandle, SHIDWORD(IoTraceHandle), (int)v3);
  }
  return result;
}
