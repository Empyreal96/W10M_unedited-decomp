// AlpcpCreateConnectionPort 
 
int __fastcall AlpcpCreateConnectionPort(_DWORD *a1, _BYTE *a2, unsigned int a3, int a4, unsigned __int8 a5, char a6)
{
  int v8; // r9
  _DWORD *v9; // r2
  int v10; // r1
  _BYTE *v11; // r2
  int v12; // r4
  int *v13; // r5
  int v14; // r8
  int *v15; // r1
  int *v16; // r1
  int v17; // r0
  _DWORD *v18; // r3
  _BYTE *v20; // [sp+1Ch] [bp-6Ch] BYREF
  int v21; // [sp+24h] [bp-64h] BYREF
  int v22; // [sp+28h] [bp-60h]
  _DWORD *v23; // [sp+2Ch] [bp-5Ch]
  unsigned int v24; // [sp+30h] [bp-58h]
  _BYTE *v25; // [sp+34h] [bp-54h]
  int v26; // [sp+38h] [bp-50h] BYREF
  _BYTE v27[40]; // [sp+3Ch] [bp-4Ch] BYREF
  _DWORD *varg_r0; // [sp+90h] [bp+8h]
  _BYTE *varg_r1; // [sp+94h] [bp+Ch]
  unsigned int varg_r2; // [sp+98h] [bp+10h]
  int varg_r3; // [sp+9Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v22 = a4;
  varg_r3 = a4;
  v20 = a2;
  v23 = a1;
  v25 = a2;
  v24 = a3;
  v26 = 0;
  memset(v27, 0, sizeof(v27));
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v8 )
  {
    v9 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
    if ( a3 )
    {
      v10 = a3;
      if ( a3 >= MmUserProbeAddress )
        v10 = MmUserProbeAddress;
      memmove((int)&v26, v10, 0x2Cu);
    }
    v11 = v20;
  }
  else
  {
    if ( a3 )
      memmove((int)&v26, a3, 0x2Cu);
    v11 = v20;
  }
  v12 = ObCreateObject(v8, AlpcPortObjectType, v11, v8, 0, 284, 0, 0, &v20);
  v13 = (int *)v20;
  if ( v12 >= 0 )
  {
    memset(v20, 0, 284);
    if ( a3 && (v26 & 0x40000) != 0 )
      v14 = 1;
    else
      v14 = a5;
    v12 = AlpcpInitializePort(v13, 1, v14);
    if ( v12 < 0 )
      goto LABEL_19;
    v15 = a3 ? &v26 : 0;
    v12 = AlpcpValidateAndSetPortAttributes((int)v13, (int)v15, (int)v13, 0, v22, v14, a6);
    if ( v12 < 0 )
      goto LABEL_19;
    if ( a6 )
      v13[61] |= 0x3000u;
    if ( a3 )
      v16 = &v26;
    else
      v16 = 0;
    AlpcpSetOwnerProcessPort((int)v13, v16);
    v17 = AlpcpAllocateBlob(AlpcConnectionType, 40, 1);
    v13[2] = v17;
    if ( !v17 )
    {
      v12 = -1073741801;
LABEL_19:
      ObfDereferenceObject((int)v13);
      return v12;
    }
    *(_DWORD *)(v17 + 8) = 0;
    *(_DWORD *)v13[2] = v13;
    *(_DWORD *)(v13[2] + 4) = 0;
    *(_DWORD *)(v13[2] + 36) = 0;
    v18 = (_DWORD *)(v13[2] + 12);
    v18[1] = v18;
    *v18 = v18;
    v12 = AlpcInitializeHandleTable((_DWORD *)(v13[2] + 20));
    if ( v12 < 0 )
      goto LABEL_19;
    v12 = ObInsertObject(v13, 0, 2031617, 0, 0, &v21);
    if ( v12 >= 0 )
      *a1 = v21;
  }
  return v12;
}
