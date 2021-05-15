// PsOpenProcess 
 
int __fastcall PsOpenProcess(unsigned int a1, int a2, int a3, int *a4, char a5, char a6)
{
  _DWORD *v6; // r6
  int v7; // r10
  _DWORD *v8; // r1
  BOOL v9; // r4
  int v10; // r3
  int v11; // r8
  int v12; // r2
  _DWORD *v13; // r4
  int v14; // r5
  int v15; // r2
  int v16; // r4
  int v18; // [sp+14h] [bp-1CCh] BYREF
  int v19; // [sp+18h] [bp-1C8h] BYREF
  int v20; // [sp+1Ch] [bp-1C4h]
  int v21; // [sp+20h] [bp-1C0h] BYREF
  int v22; // [sp+24h] [bp-1BCh]
  int v23; // [sp+28h] [bp-1B8h]
  int v24; // [sp+30h] [bp-1B0h] BYREF
  int v25; // [sp+34h] [bp-1ACh]
  int v26; // [sp+38h] [bp-1A8h]
  int v27; // [sp+3Ch] [bp-1A4h] BYREF
  _DWORD v28[4]; // [sp+40h] [bp-1A0h] BYREF
  _BYTE v29[16]; // [sp+50h] [bp-190h] BYREF
  int v30; // [sp+60h] [bp-180h]
  int v31; // [sp+64h] [bp-17Ch]
  _BYTE v32[92]; // [sp+6Ch] [bp-174h] BYREF
  _DWORD _C8[76]; // [sp+C8h] [bp-118h] BYREF

  _C8[72] = a1;
  _C8[74] = a3;
  _C8[75] = a4;
  v22 = a2;
  _C8[73] = a2;
  v6 = (_DWORD *)a1;
  v21 = a1;
  v19 = 0;
  v24 = 0;
  v7 = 0;
  v25 = 0;
  v23 = -1;
  v18 = -1;
  if ( a5 )
  {
    v8 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v8 = (_DWORD *)MmUserProbeAddress;
    *v8 = *v8;
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(3);
    v9 = *(_DWORD *)(a3 + 8) != 0;
    v20 = *(_DWORD *)(a3 + 12) & 0xDF2;
    v26 = v20;
    if ( a4 )
    {
      if ( ((unsigned __int8)a4 & 3) != 0 )
        ExRaiseDatatypeMisalignment(3);
      v19 = *a4;
      v24 = v19;
      v7 = a4[1];
      v25 = v7;
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
    v11 = a6;
  }
  else
  {
    v9 = *(_DWORD *)(a3 + 8) != 0;
    v12 = *(_DWORD *)(a3 + 12);
    v11 = a6;
    if ( a6 )
      v20 = v12 & 0xDF2;
    else
      v20 = v12 & 0x10FF2;
    if ( a4 )
    {
      v19 = *a4;
      v24 = v19;
      v7 = a4[1];
      v25 = v7;
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
  }
  if ( v9 || !v10 )
  {
    v14 = -1073741776;
    goto LABEL_33;
  }
  v13 = (_DWORD *)(PsProcessType + 52);
  SeCaptureSubjectContextEx(
    __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
    v28);
  v14 = SepCreateAccessStateFromSubjectContext(v28, (int)v29, (int)_C8, v22, v13);
  if ( v14 >= 0 )
  {
    if ( SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v11) )
    {
      v15 = v30;
      if ( (v30 & 0x2000000) != 0 )
        v15 = 0x1FFFFF;
      v31 |= v15;
      v30 = 0;
    }
    if ( v7 )
    {
      v14 = PsLookupProcessThreadByCid(&v24, &v18, &v21);
      if ( v14 < 0 )
      {
LABEL_27:
        SepDeleteAccessState((int)v29);
        SeReleaseSubjectContext(v32);
        goto LABEL_33;
      }
      ObfDereferenceObject(v21);
    }
    else
    {
      v14 = PsLookupProcessByProcessId(v19, &v18);
      if ( v14 < 0 )
        goto LABEL_27;
    }
    v16 = v18;
    v14 = ObOpenObjectByPointer(v18, v20, v29, 0, PsProcessType, v11, &v27);
    SepDeleteAccessState((int)v29);
    SeReleaseSubjectContext(v32);
    v23 = *(_DWORD *)(v16 + 176);
    v18 = v23;
    ObfDereferenceObjectWithTag(v16);
    if ( v14 >= 0 )
      *v6 = v27;
  }
LABEL_33:
  v19 = v14;
  v18 = v22;
  v21 = v23;
  _C8[50] = &v21;
  _C8[51] = 0;
  _C8[52] = 4;
  _C8[53] = 0;
  _C8[54] = &v18;
  _C8[55] = 0;
  _C8[56] = 4;
  _C8[57] = 0;
  _C8[58] = &v19;
  _C8[59] = 0;
  _C8[60] = 4;
  _C8[61] = 0;
  EtwWrite(EtwApiCallsProvRegHandle, MEMORY[0x61A654], (int)KERNEL_AUDIT_API_OPENPROCESS, 0);
  return v14;
}
