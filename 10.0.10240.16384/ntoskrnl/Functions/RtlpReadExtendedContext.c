// RtlpReadExtendedContext 
 
int __fastcall RtlpReadExtendedContext(int a1, char a2, int a3, int a4, int a5, int *a6)
{
  int *v7; // r5
  int v8; // r8
  int v9; // r10
  int result; // r0
  int v11; // r9
  char v12; // r6
  int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  unsigned int v16; // r3
  _BYTE *v17; // r0
  int v18; // r6
  int v19; // r3
  int v20; // r1
  unsigned int v21; // r3
  int v22; // r5
  int *v23; // r3
  int v24; // r0
  int v25; // r2
  unsigned int v26; // r3
  int v27; // [sp+4h] [bp-54h]
  int v28; // [sp+8h] [bp-50h] BYREF
  int v29; // [sp+Ch] [bp-4Ch]
  int v30; // [sp+10h] [bp-48h]
  int v31; // [sp+14h] [bp-44h]
  int v32; // [sp+18h] [bp-40h]
  int v33; // [sp+20h] [bp-38h] BYREF

  v32 = a3;
  v29 = a2;
  v7 = a6;
  v8 = 0;
  v9 = 0;
  if ( !a6 )
    v7 = &v33;
  result = RtlpValidateContextFlags(a4, &v28);
  if ( result >= 0 )
  {
    v11 = RtlpReadExtendedContextLayout(1, a4, a5, v28, v7);
    if ( v11 < 0 )
      return v11;
    v30 = a4 & 0x10000;
    if ( (a4 & 0x10000) != 0 )
    {
      v8 = 4;
      v9 = a5 + 716;
      goto LABEL_14;
    }
    if ( (a4 & 0x100000) != 0 )
    {
      v9 = a5 + 1232;
    }
    else
    {
      if ( (a4 & 0x200000) != 0 )
      {
        v8 = 8;
        v9 = a5 + 416;
        goto LABEL_14;
      }
      if ( (a4 & 0x400000) == 0 )
      {
LABEL_14:
        v12 = v28;
        if ( (v28 & 1) != 0 && (v13 = v7[3]) != 0 )
        {
          v14 = v7[2];
          v15 = v14 + v9;
          if ( ((v8 - 1) & (v14 + v9)) != 0 )
            ExRaiseDatatypeMisalignment(v14);
          v16 = v14 + v13 + v9;
          v17 = (_BYTE *)MmUserProbeAddress;
          if ( v16 > MmUserProbeAddress || v16 < v15 )
          {
            *(_BYTE *)MmUserProbeAddress = 0;
            v17 = (_BYTE *)MmUserProbeAddress;
          }
        }
        else
        {
          v17 = (_BYTE *)MmUserProbeAddress;
        }
        v18 = v12 & 2;
        if ( v18 )
        {
          v19 = v7[5];
          if ( v19 )
          {
            v20 = v7[4];
            if ( ((v20 + v9) & 0x3F) != 0 )
              ExRaiseDatatypeMisalignment(v17);
            v21 = v19 + v20 + v9;
            if ( v21 > (unsigned int)v17 || v21 < v20 + v9 )
              *v17 = 0;
          }
        }
        v27 = (int)v7;
        v22 = v32;
        result = RtlpCopyExtendedContext(v29, v32, 0, a4, v9, v27);
        v11 = result;
        v31 = result;
        if ( result < 0 )
        {
          v28 = result;
          return result;
        }
        v23 = (int *)(*(_DWORD *)(v22 + 8) + v22);
        if ( v30 )
          goto LABEL_36;
        if ( (a4 & 0x100000) != 0 )
        {
          v23[12] = a4;
          goto LABEL_37;
        }
        if ( (a4 & 0x200000) != 0 || (a4 & 0x400000) != 0 )
LABEL_36:
          *v23 = a4;
LABEL_37:
        if ( v18 )
        {
          v24 = *(_DWORD *)(v22 + 16) + v22;
          v25 = *(_DWORD *)(v24 + 4) & MEMORY[0xFFFF93DC];
          *(_DWORD *)v24 &= MEMORY[0xFFFF93D8] & 0xFFFFFFFC;
          *(_DWORD *)(v24 + 4) = v25;
          if ( (MEMORY[0xFFFF93EC] & 2) != 0 )
          {
            v26 = MEMORY[0xFFFF93DC] | 0x80000000;
            *(_DWORD *)(v24 + 8) = MEMORY[0xFFFF93D8];
            *(_DWORD *)(v24 + 12) = v26;
          }
          else
          {
            *(_DWORD *)(v24 + 8) = 0;
            *(_DWORD *)(v24 + 12) = 0;
          }
          memset((_BYTE *)(v24 + 16), 0, 48);
        }
        return v11;
      }
      v9 = a5 + 912;
    }
    v8 = 16;
    goto LABEL_14;
  }
  return result;
}
