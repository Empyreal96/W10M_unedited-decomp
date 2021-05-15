// PopExecutePowerAction 
 
void __fastcall PopExecutePowerAction(_DWORD *a1, int a2, int *a3, int a4, int a5)
{
  int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // lr
  int v9; // r10
  int v11; // r9
  const char *v12; // r0
  const char *v13; // r3
  int v14; // r1
  int v15; // r4
  unsigned int v16; // r7
  int v17; // r3
  int v18; // r6
  int v19; // r6
  int v20; // r6
  int v21; // r0
  char v22; // r3
  int v23; // r2
  int v24; // r0
  int v25; // r3
  unsigned int v26; // r1
  int **v27; // r0
  int *v28; // r2
  char v29[8]; // [sp+8h] [bp-60h] BYREF
  int v30[2]; // [sp+10h] [bp-58h] BYREF
  int v31[4]; // [sp+18h] [bp-50h] BYREF
  int v32; // [sp+28h] [bp-40h] BYREF
  int v33; // [sp+2Ch] [bp-3Ch]
  int v34; // [sp+30h] [bp-38h]
  int var30[17]; // [sp+38h] [bp-30h] BYREF
  int varg_r3; // [sp+7Ch] [bp+14h] BYREF

  var30[14] = (int)a1;
  var30[15] = a2;
  var30[16] = (int)a3;
  varg_r3 = a4;
  v5 = *a3;
  v6 = a3[1];
  v7 = a3[2];
  v8 = a4;
  v30[0] = a4;
  varg_r3 = a4;
  v9 = a2;
  v11 = 0;
  v32 = v5;
  v33 = v6;
  v34 = v7;
  if ( (dword_682610 & 0x8000) != 0 )
  {
    v31[1] = v5;
    v31[2] = a4;
    var30[1] = 0;
    var30[2] = 12;
    var30[3] = 0;
    v31[0] = (int)a1;
    var30[0] = (int)v31;
    EtwTraceKernelEvent(var30, 1, 0x80008000, 4642, 4200450);
    v8 = v30[0];
  }
  if ( (a1[1] & 0x80) == 0 )
  {
LABEL_71:
    v14 = 0;
    goto LABEL_72;
  }
  if ( (PoDebug & 8) != 0 )
  {
    PopSystemStateString(v8);
    v12 = PopPowerActionString(v5);
    DbgPrint("PopExecutePowerAction: %s, Flags %x, Min=%s\n", v12, v33, v13);
  }
  PopVerifySystemPowerState(&varg_r3, a5);
  if ( PopVerifyPowerActionPolicy(&v32) )
  {
    v14 = -1073741637;
LABEL_72:
    PopCompleteAction((int)a1, v14);
    return;
  }
  v15 = v32;
  if ( v32 == 2 || v32 == 3 )
    v16 = v33 | 0x80000000;
  else
    v16 = v33;
  v17 = a1[1];
  v18 = 0;
  if ( (v17 & 2) == 0 )
  {
    a1[1] = v17 | 2;
    if ( v15 == 6 && PsWin32CalloutsEstablished )
    {
      if ( *a1 == 2 )
      {
        v15 = 0;
        v11 = 32;
      }
      else if ( !*a1 )
      {
        v15 = 0;
        if ( byte_61EC44 )
          v11 = 32;
        else
          v11 = 16;
        KeQueryPerformanceCounter(v30, 0);
        PopShutdownButtonPressTime = v30[0];
        MEMORY[0x61F7E4] = v30[1];
      }
      PopDiagTraceShutdownAction(6, v11, *a1);
    }
    if ( (unsigned int)(v15 - 4) <= 2 )
      PopDiagTraceShutdownAction(v15, v11, *a1);
    if ( !byte_61EC61 )
      PopResetActionDefaults();
    if ( v15 )
    {
      v29[0] = 0;
      if ( v15 == 7 )
        v16 |= 0x10000000u;
      if ( v15 == 3 )
        v19 = 5;
      else
        v19 = varg_r3;
      if ( PopCompareActions(v15, dword_61EC64) >= 0 )
      {
        PopPromoteActionFlag(v29, 1, v16, 0, 1);
        PopPromoteActionFlag(v29, 1, v16, 0, 2);
        PopPromoteActionFlag(v29, 4, v16, 0, 0x10000000);
        if ( v15 == 2 && v19 < *(_DWORD *)(PopPolicy + 68) )
          v19 = *(_DWORD *)(PopPolicy + 68);
        if ( v19 > dword_61EC68 )
        {
          dword_61EC68 = v19;
          v29[0] |= 4u;
        }
      }
      PopPromoteActionFlag(v29, 1, v16, 1, 4);
      PopPromoteActionFlag(v29, 5, v16, 1, 0x80000000);
      PopPromoteActionFlag(v29, 0, v16, 1, 0x40000000);
      PopPromoteActionFlag(v29, 0, v16, 1, 8);
      v20 = dword_61EC64;
      if ( PopCompareActions(v15, dword_61EC64) <= 0 )
      {
        v23 = (unsigned __int8)v29[0];
      }
      else
      {
        v21 = PopCompareActions(v15, 3);
        v22 = v29[0];
        if ( v21 >= 0 )
          v22 = v29[0] | 2;
        v23 = (unsigned __int8)v22 | 5;
        dword_61EC64 = v15;
        v20 = v15;
        dword_61EC74 = *a1;
        dword_61EC78 = 0;
        if ( !*a1 )
          dword_61EC78 = a1[3];
      }
      if ( v20 == 3 )
        dword_61EC64 = 2;
      if ( v23 )
      {
        v18 = 1;
        if ( !byte_61EC61 || byte_61EC61 == 1 )
        {
          byte_61EC61 = 1;
          dword_61EC70 = 0;
          v24 = 2;
        }
        else
        {
          PopAction[0] |= v23;
          v24 = 1;
        }
        PopGetPolicyWorker(v24);
      }
      else
      {
        v18 = 0;
      }
    }
  }
  v25 = a1[1];
  if ( (v25 & 1) == 0 )
  {
    a1[1] = v25 | 1;
    if ( v11 == 32 )
    {
      __dmb(0xBu);
      do
        v26 = __ldrex(PopShutdownEventCode);
      while ( __strex(0x20u, PopShutdownEventCode) );
    }
    else
    {
      if ( v11 != 16 )
      {
LABEL_65:
        PopSetNotificationWork(v9);
        goto LABEL_66;
      }
      __dmb(0xBu);
      do
        v26 = __ldrex(PopShutdownEventCode);
      while ( !v26 && __strex(0x10u, PopShutdownEventCode) );
    }
    __dmb(0xBu);
    if ( !v26 )
      v9 |= 0x10u;
    goto LABEL_65;
  }
LABEL_66:
  if ( (a1[1] & 0x20) == 0 )
    return;
  if ( !v18 )
    goto LABEL_71;
  v27 = (int **)dword_61E974;
  v28 = (int *)(a1[2] + 20);
  *v28 = (int)&PopActionWaiters;
  v28[1] = (int)v27;
  if ( *v27 != &PopActionWaiters )
    __fastfail(3u);
  *v27 = v28;
  dword_61E974 = (int)v28;
}
