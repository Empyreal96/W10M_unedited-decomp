// SepCaptureFqbnArray 
 
int __fastcall SepCaptureFqbnArray(unsigned int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r10
  int v6; // r4
  unsigned int v7; // r6
  int v8; // r0
  unsigned int v9; // r5
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int i; // r2
  int v13; // r0
  int v14; // r8
  int v15; // r0
  unsigned int v16; // r6
  unsigned int v17; // r10
  int v18; // r2
  unsigned int v19; // r3
  int v20; // r0
  int *v21; // r6
  int v24; // [sp+4h] [bp-3Ch] BYREF
  int *v25; // [sp+8h] [bp-38h]
  int v26; // [sp+10h] [bp-30h]
  unsigned int v27; // [sp+14h] [bp-2Ch]
  int v28; // [sp+18h] [bp-28h]
  int v29; // [sp+1Ch] [bp-24h]
  unsigned int varg_r0; // [sp+48h] [bp+8h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  v25 = (int *)a4;
  varg_r3 = a4;
  v4 = a2;
  varg_r1 = a2;
  v24 = 0;
  v6 = RtlULongLongToULong(16 * a2, a2 >> 28, &v24);
  if ( v6 >= 0 )
  {
    v7 = v24;
    v8 = ExAllocatePoolWithTag(1, v24, 1950442835);
    v9 = v8;
    v26 = v8;
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
      v10 = (v7 + 1) & 0xFFFFFFFE;
      v11 = v9;
      if ( v10 >= v7 )
      {
        for ( i = 0; i < v4; ++i )
        {
          if ( *(unsigned __int16 *)(v11 + 8) + v10 < v10 )
          {
            v6 = -1073741675;
LABEL_20:
            ExFreePoolWithTag(v9);
            return v6;
          }
          v10 += *(unsigned __int16 *)(v11 + 8);
          v11 += 16;
        }
        v13 = ExAllocatePoolWithTag(1, v10, 1950442835);
        v14 = v13;
        v28 = v13;
        if ( !v13 )
        {
          v6 = -1073741670;
          goto LABEL_20;
        }
        memmove(v13, v9, 16 * v4);
        v15 = (v14 + 16 * v4 + 1) & 0xFFFFFFFE;
        v24 = v15;
        v16 = 0;
        v27 = 0;
        while ( v16 < v4 )
        {
          v17 = v9 + 16 * v16;
          v18 = *(unsigned __int16 *)(v17 + 8);
          if ( *(_WORD *)(v17 + 8) )
          {
            v19 = *(_DWORD *)(v17 + 12);
            if ( (v19 & 1) != 0 )
              ExRaiseDatatypeMisalignment(v15);
            if ( v19 + v18 > MmUserProbeAddress || v19 + v18 < v19 )
              *(_BYTE *)MmUserProbeAddress = 0;
          }
          memmove(v15, *(_DWORD *)(v17 + 12), *(unsigned __int16 *)(v17 + 8));
          v20 = v24;
          *(_DWORD *)(v14 + 16 * v16 + 12) = v24;
          v15 = v20 + *(unsigned __int16 *)(v17 + 8);
          v24 = v15;
          v29 = v15;
          v27 = ++v16;
          v4 = a2;
        }
        v21 = v25;
        ExFreePoolWithTag(v9);
        *v21 = v14;
        v6 = 0;
      }
      else
      {
        ExFreePoolWithTag(v9);
        v6 = -1073741675;
      }
    }
    else
    {
      v6 = -1073741670;
    }
  }
  return v6;
}
