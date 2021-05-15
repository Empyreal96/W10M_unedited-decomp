// SepCaptureOctetStringArray 
 
int __fastcall SepCaptureOctetStringArray(unsigned int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r10
  int v6; // r4
  unsigned int v7; // r5
  int v8; // r0
  unsigned int v9; // r6
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r9
  int v14; // r0
  unsigned int v15; // r5
  unsigned int v16; // r10
  int v17; // r3
  unsigned int v18; // r1
  int v19; // r0
  int *v20; // r5
  int v23; // [sp+4h] [bp-3Ch] BYREF
  int *v24; // [sp+Ch] [bp-34h]
  int v25; // [sp+10h] [bp-30h]
  unsigned int v26; // [sp+14h] [bp-2Ch]
  int v27; // [sp+18h] [bp-28h]
  int v28; // [sp+1Ch] [bp-24h]
  unsigned int varg_r0; // [sp+48h] [bp+8h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  v24 = (int *)a4;
  varg_r3 = a4;
  v4 = a2;
  varg_r1 = a2;
  v23 = 0;
  v6 = RtlULongLongToULong(8 * a2, a2 >> 29, &v23);
  if ( v6 >= 0 )
  {
    v7 = v23;
    v8 = ExAllocatePoolWithTag(1, v23, 1950442835);
    v9 = v8;
    v25 = v8;
    if ( v8 )
    {
      if ( v7 )
      {
        if ( (a1 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v8);
        if ( v7 + a1 > MmUserProbeAddress || v7 + a1 < a1 )
        {
          *(_BYTE *)MmUserProbeAddress = 0;
          v4 = a2;
        }
        else
        {
          v4 = a2;
        }
      }
      memmove(v8, a1, v7);
      v10 = 0;
      v11 = v9;
      while ( v10 < v4 )
      {
        if ( *(_DWORD *)(v11 + 4) + v7 < v7 )
        {
          v6 = -1073741675;
LABEL_18:
          ExFreePoolWithTag(v9);
          return v6;
        }
        v7 += *(_DWORD *)(v11 + 4);
        ++v10;
        v11 += 8;
      }
      v12 = ExAllocatePoolWithTag(1, v7, 1950442835);
      v13 = v12;
      v27 = v12;
      if ( !v12 )
      {
        v6 = -1073741670;
        goto LABEL_18;
      }
      memmove(v12, v9, 8 * v4);
      v14 = v13 + 8 * v4;
      v23 = v14;
      v15 = 0;
      v26 = 0;
      while ( v15 < v4 )
      {
        v16 = v9 + 8 * v15;
        v17 = *(_DWORD *)(v16 + 4);
        if ( v17 )
        {
          v18 = *(_DWORD *)v16 + v17;
          if ( v18 > MmUserProbeAddress || v18 < *(_DWORD *)v16 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
        memmove(v14, *(_DWORD *)v16, *(_DWORD *)(v16 + 4));
        v19 = v23;
        *(_DWORD *)(v13 + 8 * v15) = v23;
        v14 = v19 + *(_DWORD *)(v16 + 4);
        v23 = v14;
        v28 = v14;
        v26 = ++v15;
        v4 = a2;
      }
      v20 = v24;
      ExFreePoolWithTag(v9);
      *v20 = v13;
      v6 = 0;
    }
    else
    {
      v6 = -1073741670;
    }
  }
  return v6;
}
