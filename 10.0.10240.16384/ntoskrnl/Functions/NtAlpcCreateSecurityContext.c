// NtAlpcCreateSecurityContext 
 
int __fastcall NtAlpcCreateSecurityContext(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v5; // r4
  int v6; // r4
  int v7; // r9
  unsigned int v8; // r1
  int v9; // r3
  int *v10; // r5
  int *v11; // r2
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r6
  int v17; // r2
  int v18; // r3
  int v19; // r5
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r1
  unsigned int v23; // r1
  __int16 v24; // r3
  _DWORD *v26; // [sp+Ch] [bp-44h] BYREF
  int v27; // [sp+10h] [bp-40h] BYREF
  int v28; // [sp+18h] [bp-38h]
  int *v29; // [sp+1Ch] [bp-34h]
  int v30; // [sp+20h] [bp-30h]
  int v31; // [sp+28h] [bp-28h] BYREF
  int v32; // [sp+2Ch] [bp-24h]
  int v33; // [sp+30h] [bp-20h]
  int varg_r0; // [sp+58h] [bp+8h]
  int varg_r1; // [sp+5Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r0 = a1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  if ( a2 )
  {
    v6 = -1073741811;
  }
  else
  {
    v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( v7 )
    {
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a3 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a3 = *(_BYTE *)a3;
      *(_BYTE *)(a3 + 8) = *(_BYTE *)(a3 + 8);
      v8 = *(_DWORD *)(a3 + 4);
      v9 = *(_DWORD *)(a3 + 8);
      v28 = *(_DWORD *)a3;
      v29 = (int *)v8;
      v30 = v9;
      v10 = (int *)v8;
      if ( v8 )
      {
        v11 = v29;
        if ( v8 >= MmUserProbeAddress )
          v11 = (int *)MmUserProbeAddress;
        v31 = *v11;
        v32 = v11[1];
        v33 = v11[2];
      }
    }
    else
    {
      v12 = *(_DWORD *)(a3 + 4);
      v13 = *(_DWORD *)(a3 + 8);
      v28 = *(_DWORD *)a3;
      v29 = (int *)v12;
      v30 = v13;
      v10 = (int *)v12;
      if ( v12 )
      {
        v14 = *(_DWORD *)(v12 + 4);
        v15 = v10[2];
        v31 = *v10;
        v32 = v14;
        v33 = v15;
      }
    }
    a1 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v7, &v26);
    v6 = a1;
    if ( a1 >= 0 )
    {
      v16 = (int)v26;
      if ( !v10 )
      {
        v17 = v26[40];
        v18 = v26[41];
        v31 = v26[39];
        v32 = v17;
        v33 = v18;
      }
      v6 = AlpcpCreateSecurityContext(v26, 1, &v31, &v27);
      if ( v6 >= 0 )
      {
        v19 = v27;
        *(_DWORD *)(a3 + 8) = *(_DWORD *)(v27 + 4);
        __dmb(0xBu);
        v20 = (unsigned int *)(v19 - 12);
        do
        {
          v21 = __ldrex(v20);
          v22 = v21 - 1;
        }
        while ( __strex(v22, v20) );
        __dmb(0xBu);
        if ( v22 <= 0 )
        {
          if ( v22 )
            KeBugCheckEx(24, 0, v19, 33, v22);
          AlpcpDestroyBlob(v19);
        }
      }
      a1 = ObfDereferenceObject(v16);
    }
  }
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v6;
}
