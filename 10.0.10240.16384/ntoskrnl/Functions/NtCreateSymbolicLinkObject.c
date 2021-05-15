// NtCreateSymbolicLinkObject 
 
int __fastcall NtCreateSymbolicLinkObject(unsigned int a1, int a2, int a3, int *a4)
{
  int v7; // r0
  int *v8; // r1
  unsigned int v9; // r10
  unsigned int v10; // r1
  unsigned int v11; // r8
  unsigned int v12; // r3
  _DWORD *v13; // r2
  int *v14; // r2
  int v15; // r3
  int v16; // r9
  _DWORD *v17; // r6
  int v18; // r0
  _DWORD *v19; // r8
  int v20; // r9
  int *v21; // r0
  int v22; // r8
  int v23; // r1
  _DWORD *v24; // r3
  int v25; // r1
  int v26; // r6
  int *v27; // r2
  _DWORD *v28; // r3
  int v29; // r1
  _DWORD *v30; // r2
  unsigned int **v31; // r2
  _WORD v34[4]; // [sp+18h] [bp-C8h] BYREF
  int v35; // [sp+20h] [bp-C0h] BYREF
  unsigned int v36; // [sp+24h] [bp-BCh]
  int v37; // [sp+28h] [bp-B8h]
  int v38; // [sp+30h] [bp-B0h] BYREF
  unsigned int v39; // [sp+34h] [bp-ACh]
  _DWORD *v40; // [sp+3Ch] [bp-A4h] BYREF
  int v41; // [sp+40h] [bp-A0h] BYREF
  int v42; // [sp+44h] [bp-9Ch]
  _DWORD *v43; // [sp+48h] [bp-98h]
  int v44; // [sp+4Ch] [bp-94h]
  int v45; // [sp+50h] [bp-90h]
  unsigned int v46; // [sp+54h] [bp-8Ch] BYREF
  int v47; // [sp+58h] [bp-88h] BYREF
  int v48; // [sp+5Ch] [bp-84h] BYREF
  _DWORD _60[38]; // [sp+60h] [bp-80h] BYREF

  _60[34] = a1;
  _60[36] = a3;
  _60[37] = a4;
  v42 = a2;
  _60[35] = a2;
  v43 = (_DWORD *)a1;
  v46 = a1;
  v41 = a3;
  v47 = 0;
  v40 = 0;
  RtlInitUnicodeString((unsigned int)&v35, 0);
  RtlInitUnicodeString((unsigned int)&v38, 0);
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v44 = v7;
  LOBYTE(v34[0]) = v7;
  if ( v7 )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v7);
    v8 = *(int **)(a3 + 8);
    if ( v8 )
    {
      v35 = *v8;
      v9 = v8[1];
      v36 = v9;
      v37 = (unsigned __int16)v35;
      if ( (_WORD)v35 && ((unsigned __int16)v35 + v9 > MmUserProbeAddress || (unsigned __int16)v35 + v9 < v9) )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    else
    {
      v9 = v36;
      v37 = (unsigned __int16)v35;
    }
    v38 = *a4;
    v10 = a4[1];
    v45 = v10;
    v39 = v10;
    v11 = HIWORD(v38);
    v12 = MmUserProbeAddress;
    if ( HIWORD(v38) && (HIWORD(v38) + v10 > MmUserProbeAddress || HIWORD(v38) + v10 < v10) )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v12 = MmUserProbeAddress;
    }
    v13 = (_DWORD *)a1;
    if ( a1 >= v12 )
      v13 = (_DWORD *)v12;
    *v13 = *v13;
    v7 = v44;
  }
  else
  {
    v38 = *a4;
    v45 = a4[1];
    v39 = v45;
    v14 = *(int **)(a3 + 8);
    v11 = HIWORD(v38);
    if ( v14 )
    {
      v35 = *v14;
      v9 = v14[1];
      v36 = v9;
    }
    else
    {
      v9 = v36;
    }
    v37 = (unsigned __int16)v35;
  }
  if ( (v11 & 1) != 0 )
  {
    v15 = 2 * (v11 >> 1);
    v11 = (unsigned __int16)v15;
    HIWORD(v38) = v15;
  }
  if ( !v11 || (unsigned __int16)v38 > v11 || (v38 & 1) != 0 )
    return -1073741811;
  v16 = ObCreateObject(v7, ObpSymbolicLinkObjectType, a3, v7, 0, 24, 0, 0, &v40);
  v17 = v40;
  if ( v16 >= 0 )
  {
    KeQuerySystemTime(v40);
    v17[4] = 0;
    *((_WORD *)v17 + 5) = v11;
    *((_WORD *)v17 + 4) = v38;
    v18 = ExAllocatePoolWithTag(1, v11, 1953331539);
    v17[3] = v18;
    if ( !v18 )
    {
      ObfDereferenceObject((int)v17);
      v16 = -1073741801;
LABEL_35:
      v21 = &v38;
      goto LABEL_36;
    }
    memmove(v18, v45, v11);
    v19 = v43;
    v20 = v42;
    if ( RtlIsSandboxedToken(0, v44) )
      v17[5] = 2;
    else
      v17[5] = 0;
    v16 = ObInsertObject(v17, 0, v20, 0, &v48, &v47);
    v41 = v16;
    *v19 = v47;
  }
  if ( v16 )
    goto LABEL_35;
  v21 = v17 + 2;
LABEL_36:
  v46 = v16;
  v41 = v42;
  v43 = (_DWORD *)HIDWORD(EtwApiCallsProvRegHandle);
  v22 = EtwApiCallsProvRegHandle;
  if ( EtwApiCallsProvRegHandle )
  {
    v34[0] = 0;
    v23 = 0;
    if ( v9 )
    {
      _60[0] = v9;
      _60[1] = 0;
      _60[2] = v37;
      _60[3] = 0;
      v23 = 1;
    }
    v24 = &_60[4 * v23];
    *v24 = v34;
    v24[1] = 0;
    v24[2] = 2;
    v24[3] = 0;
    v25 = v23 + 1;
    v26 = v21[1];
    if ( v26 )
    {
      v27 = &_60[4 * v25];
      *v27 = v26;
      v27[1] = 0;
      v27[2] = *(unsigned __int16 *)v21;
      v27[3] = 0;
      ++v25;
    }
    v28 = &_60[4 * v25];
    *v28 = v34;
    v28[1] = 0;
    v28[2] = 2;
    v28[3] = 0;
    v29 = v25 + 1;
    v30 = &_60[4 * v29];
    *v30 = &v41;
    v30[1] = 0;
    v30[2] = 4;
    v30[3] = 0;
    v31 = (unsigned int **)&_60[4 * v29 + 4];
    *v31 = &v46;
    v31[1] = 0;
    v31[2] = (unsigned int *)4;
    v31[3] = 0;
    EtwWrite(v22, (int)v43, (int)KERNEL_AUDIT_API_CREATESYMBOLICLINKOBJECT, 0);
  }
  return v16;
}
