// AlpcpExposeTokenAttribute 
 
int __fastcall AlpcpExposeTokenAttribute(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v6; // r4
  int v7; // r2
  int v8; // r6
  _DWORD *v9; // r9
  int v10; // r10
  int v11; // r2
  int v12; // r0
  int v13; // r0
  int v14; // r3
  int v15; // r0
  __int16 v16; // r2
  unsigned __int8 v18; // [sp+0h] [bp-78h]
  _DWORD *v19; // [sp+4h] [bp-74h]
  int v20; // [sp+4h] [bp-74h]
  int v21; // [sp+8h] [bp-70h]
  int v22; // [sp+Ch] [bp-6Ch]
  int v23; // [sp+10h] [bp-68h]
  int v24; // [sp+14h] [bp-64h]
  int v25; // [sp+18h] [bp-60h]
  int v26; // [sp+20h] [bp-58h] BYREF
  _DWORD *v27; // [sp+2Ch] [bp-4Ch]

  if ( (a2[5] & 0x80) != 0 )
  {
    v6 = -1073740029;
LABEL_18:
    v8 = (int)v27;
    goto LABEL_19;
  }
  v7 = a2[18];
  if ( v7 )
  {
    v8 = (int)v27;
    if ( *(int *)(v7 + 20) < 1 )
    {
      v6 = -1073741790;
      goto LABEL_19;
    }
    v9 = *(_DWORD **)(v7 + 28);
LABEL_7:
    v10 = 0;
    v6 = 0;
    goto LABEL_20;
  }
  v11 = a2[3];
  if ( (*(_DWORD *)(a1 + 244) & 6) != 2 )
    goto LABEL_17;
  if ( !v11 )
    goto LABEL_17;
  v12 = *(_DWORD *)(v11 + 244);
  if ( (v12 & 6) != 4 )
    goto LABEL_17;
  if ( (v12 & 0x400) == 0 )
  {
    v9 = *(_DWORD **)(v11 + 44);
    v8 = (int)v27;
    if ( !v9 )
    {
      v6 = -1073741790;
      goto LABEL_19;
    }
    goto LABEL_7;
  }
  v13 = a2[4];
  if ( !v13 )
  {
LABEL_17:
    v6 = -1073741790;
    goto LABEL_18;
  }
  v6 = SeCreateClientSecurityEx(v13, v11 + 156, 0, &v26);
  v8 = (int)v27;
  if ( v6 >= 0 )
  {
    v9 = v27;
    v10 = 1;
    v6 = 0;
    goto LABEL_20;
  }
LABEL_19:
  v9 = v19;
  v10 = v18;
LABEL_20:
  if ( v6 >= 0 )
  {
    v22 = v9[6];
    v23 = v9[7];
    v20 = v9[4];
    v21 = v9[5];
    v14 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v14 & 0xFFFFFFC0) + 0x134);
    ExAcquireResourceSharedLite(v9[12], 1);
    v24 = v9[13];
    v25 = v9[14];
    ExReleaseResourceLite(v9[12]);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134);
    *(_WORD *)(v15 + 308) = v16 + 1;
    if ( v16 == -1 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v15);
    if ( v10 )
      ObfDereferenceObject(v8);
    *a3 = v20;
    a3[1] = v21;
    a3[2] = v22;
    a3[3] = v23;
    a3[4] = v24;
    a3[5] = v25;
    *a4 |= 0x8000000u;
  }
  return v6;
}
