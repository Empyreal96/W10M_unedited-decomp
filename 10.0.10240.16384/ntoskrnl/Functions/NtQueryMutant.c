// NtQueryMutant 
 
int __fastcall NtQueryMutant(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int v8; // r5
  int v9; // r9
  _DWORD *v10; // r4
  _DWORD *v11; // r2
  bool v12; // zf
  int v13; // r8
  int v14; // r1
  char v15; // r0
  bool v16; // r3
  int v18[3]; // [sp+Ch] [bp-34h] BYREF
  int v19; // [sp+18h] [bp-28h] BYREF
  int v20; // [sp+1Ch] [bp-24h]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  varg_r0 = a1;
  if ( a2 && a2 != 1 )
    return -1073741821;
  if ( a4 != 8 )
    return -1073741820;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v9 )
  {
    ProbeForWrite(a3, 8, 4);
    v10 = (_DWORD *)a5;
    if ( a5 )
    {
      v11 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v11 = (_DWORD *)MmUserProbeAddress;
      *v11 = *v11;
    }
  }
  else
  {
    v10 = (_DWORD *)a5;
  }
  v8 = ObReferenceObjectByHandle(a1, 1, ExMutantObjectType, v9, v18);
  v18[1] = v8;
  if ( v8 >= 0 )
  {
    v12 = a2 == 0;
    v13 = v18[0];
    if ( v12 )
    {
      v14 = *(_DWORD *)(v18[0] + 4);
      v15 = *(_BYTE *)(v18[0] + 28);
      v16 = *(_DWORD *)(v13 + 24) == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      if ( v9 )
      {
        *(_DWORD *)a3 = v14;
        *(_BYTE *)(a3 + 4) = v16;
        *(_BYTE *)(a3 + 5) = v15;
        if ( v10 )
          *v10 = 8;
        goto LABEL_28;
      }
      *(_DWORD *)a3 = v14;
      *(_BYTE *)(a3 + 4) = v16;
      *(_BYTE *)(a3 + 5) = v15;
    }
    else
    {
      KeQueryOwnerMutant(v18[0], &v19);
      if ( v9 )
      {
        *(_DWORD *)a3 = v19;
        *(_DWORD *)(a3 + 4) = v20;
        if ( v10 )
          *v10 = 8;
LABEL_28:
        ObfDereferenceObject(v13);
        return v8;
      }
      *(_DWORD *)a3 = v19;
      *(_DWORD *)(a3 + 4) = v20;
    }
    if ( v10 )
      *v10 = 8;
    goto LABEL_28;
  }
  return v8;
}
