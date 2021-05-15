// FsRtlNotifyCompleteIrp 
 
int __fastcall FsRtlNotifyCompleteIrp(int a1, int a2, unsigned int a3, int a4, int a5)
{
  int v5; // r9
  unsigned int v6; // r8
  _DWORD *v7; // r6
  _DWORD *v8; // r5
  int result; // r0
  int v10; // r2
  int v11; // r1
  int v12; // r0
  int v13; // r0
  int v14; // r0
  unsigned int v15; // r0
  unsigned int varg_r2; // [sp+30h] [bp+10h]
  int varg_r2a; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]
  int varg_r3a; // [sp+34h] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a4;
  v6 = a3;
  v7 = (_DWORD *)a2;
  v8 = (_DWORD *)a1;
  result = FsRtlNotifySetCancelRoutine(a1, a2);
  if ( result || !a5 )
  {
    if ( v5 )
    {
LABEL_25:
      *(_BYTE *)(v8[24] + 3) |= 1u;
      v8[6] = v5;
      return IofCompleteRequest((int)v8, 1);
    }
    v10 = v8[24];
    if ( !v6 || *(_DWORD *)(v10 + 8) < v6 )
    {
      v5 = 268;
      goto LABEL_25;
    }
    v11 = v7[11];
    if ( !v11 )
    {
LABEL_23:
      v8[7] = v6;
      v7[12] = 0;
      goto LABEL_25;
    }
    v12 = v8[3];
    if ( !v12 )
    {
      v13 = v8[1];
      if ( v13 )
      {
        if ( (*(_WORD *)(v13 + 6) & 5) != 0 )
          v14 = *(_DWORD *)(v13 + 12);
        else
          v14 = MmMapLockedPagesSpecifyCache(v13, 0, 1, 0, 0, 1073741840);
        if ( v14 )
        {
          memmove(v14, v7[11], v6);
        }
        else
        {
          v5 = 268;
          varg_r3a = 268;
          v6 = 0;
          varg_r2a = 0;
        }
LABEL_19:
        PsReturnProcessPagedPoolQuota(v7[18], v7[14]);
        v15 = v7[11];
        if ( v15 != v8[3] )
        {
          if ( v15 )
            ExFreePoolWithTag(v15);
        }
        v7[11] = 0;
        v7[14] = 0;
        goto LABEL_23;
      }
      if ( (*(_BYTE *)(v10 + 3) & 1) != 0 )
      {
        v8[2] |= 0x70u;
        v8[3] = v7[11];
        goto LABEL_19;
      }
      v12 = v8[15];
    }
    memmove(v12, v11, v6);
    goto LABEL_19;
  }
  return result;
}
