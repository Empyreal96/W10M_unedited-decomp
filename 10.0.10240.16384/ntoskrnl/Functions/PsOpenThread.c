// PsOpenThread 
 
int __fastcall PsOpenThread(unsigned int a1, int a2, int a3, int *a4, char a5, char a6)
{
  int v8; // r6
  int v9; // r9
  _DWORD *v10; // r4
  BOOL v11; // r4
  int v12; // r10
  int v13; // r3
  int v14; // r1
  int v15; // r3
  int v16; // r5
  int v17; // r2
  int v18; // r4
  int v19; // r3
  int v21; // [sp+14h] [bp-1CCh] BYREF
  bool v22; // [sp+18h] [bp-1C8h]
  int v23; // [sp+1Ch] [bp-1C4h] BYREF
  int v24[2]; // [sp+20h] [bp-1C0h] BYREF
  int v25; // [sp+28h] [bp-1B8h] BYREF
  int v26; // [sp+2Ch] [bp-1B4h]
  _DWORD v27[2]; // [sp+30h] [bp-1B0h] BYREF
  int v28; // [sp+38h] [bp-1A8h] BYREF
  _BYTE v29[16]; // [sp+40h] [bp-1A0h] BYREF
  int v30; // [sp+50h] [bp-190h]
  int v31; // [sp+54h] [bp-18Ch]
  _BYTE v32[92]; // [sp+5Ch] [bp-184h] BYREF
  _DWORD _B8[80]; // [sp+B8h] [bp-128h] BYREF

  _B8[76] = a1;
  _B8[78] = a3;
  _B8[79] = a4;
  v21 = a2;
  _B8[77] = a2;
  v27[0] = a1;
  v23 = a1;
  v8 = 0;
  v25 = 0;
  v9 = 0;
  v26 = 0;
  if ( a5 )
  {
    v10 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v11 = *(_DWORD *)(a3 + 8) != 0;
    v22 = *(_DWORD *)(a3 + 8) != 0;
    v12 = *(_DWORD *)(a3 + 12) & 0xDF2;
    v27[1] = v12;
    if ( a4 )
    {
      if ( ((unsigned __int8)a4 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v8 = *a4;
      v25 = *a4;
      v9 = a4[1];
      v26 = v9;
      v13 = 1;
    }
    else
    {
      v13 = 0;
    }
    v23 = a6;
  }
  else
  {
    v11 = *(_DWORD *)(a3 + 8) != 0;
    v14 = *(_DWORD *)(a3 + 12);
    v23 = a6;
    if ( a6 )
      v15 = 3570;
    else
      v15 = 69618;
    v12 = v14 & v15;
    if ( a4 )
    {
      v8 = *a4;
      v25 = *a4;
      v9 = a4[1];
      v26 = v9;
      v13 = 1;
    }
    else
    {
      v13 = 0;
    }
  }
  if ( v11 || !v13 )
  {
    v16 = -1073741776;
    goto LABEL_34;
  }
  v16 = SeCreateAccessState((int)v29, (int)_B8, a2, (_DWORD *)(PsThreadType + 52));
  if ( v16 < 0 )
  {
LABEL_34:
    v19 = v21;
    goto LABEL_35;
  }
  if ( SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v23, (int)&SeDebugPrivilege) )
  {
    v17 = v30;
    if ( (v30 & 0x2000000) != 0 )
      v17 = 0x1FFFFF;
    v31 |= v17;
    v30 = 0;
  }
  if ( v8 )
  {
    v16 = PsLookupProcessThreadByCid(&v25, 0, v24);
    if ( v16 < 0 )
    {
LABEL_27:
      SepDeleteAccessState((int)v29);
      SeReleaseSubjectContext((int)v32);
      goto LABEL_34;
    }
    v18 = v24[0];
  }
  else
  {
    v16 = PsLookupThreadByThreadId(v9, v24);
    if ( v16 < 0 )
      goto LABEL_27;
    v18 = v24[0];
    v8 = *(_DWORD *)(v24[0] + 876);
    v25 = v8;
  }
  v16 = ObOpenObjectByPointer(v18, v12, v29, 0, PsThreadType, v23, &v28);
  SepDeleteAccessState((int)v29);
  SeReleaseSubjectContext((int)v32);
  ObfDereferenceObject(v18);
  if ( v16 < 0 )
    goto LABEL_34;
  *(_DWORD *)v27[0] = v28;
  v19 = v21;
LABEL_35:
  v21 = v16;
  v24[0] = v19;
  v23 = v9;
  v27[0] = v8;
  _B8[50] = v27;
  _B8[51] = 0;
  _B8[52] = 4;
  _B8[53] = 0;
  _B8[54] = &v23;
  _B8[55] = 0;
  _B8[56] = 4;
  _B8[57] = 0;
  _B8[58] = v24;
  _B8[59] = 0;
  _B8[60] = 4;
  _B8[61] = 0;
  _B8[62] = &v21;
  _B8[63] = 0;
  _B8[64] = 4;
  _B8[65] = 0;
  EtwWrite(EtwApiCallsProvRegHandle, MEMORY[0x61A654], (int)KERNEL_AUDIT_API_OPENTHREAD, 0);
  return v16;
}
