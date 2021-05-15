// SepCaptureUnicodeStringArray 
 
int __fastcall SepCaptureUnicodeStringArray(int a1, unsigned int a2, int a3, int *a4)
{
  int v4; // r10
  int v6; // r5
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned __int16 *v9; // r0
  int v10; // t1
  unsigned int v11; // r3
  int v12; // r0
  int v13; // r8
  int v14; // r0
  unsigned int v15; // r5
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r2
  unsigned int v19; // r0
  unsigned int v21; // [sp+4h] [bp-34h] BYREF
  int *v22; // [sp+8h] [bp-30h]
  unsigned int v23; // [sp+Ch] [bp-2Ch]
  int v24; // [sp+10h] [bp-28h]
  int v25; // [sp+14h] [bp-24h]
  int varg_r0; // [sp+40h] [bp+8h]
  unsigned int varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]
  int *varg_r3; // [sp+4Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v22 = a4;
  varg_r3 = a4;
  v4 = (char)a3;
  LOBYTE(varg_r2) = a3;
  v21 = 0;
  *a4 = 0;
  if ( !a1 )
  {
    if ( !a2 )
      return 0;
    return -1073741811;
  }
  if ( !a2 )
    return -1073741811;
  if ( !(_BYTE)a3 )
  {
    *a4 = a1;
    return 0;
  }
  v6 = SeCaptureUnicodeStringStructures();
  if ( v6 >= 0 )
  {
    v6 = RtlULongLongToULong(8 * a2, a2 >> 29, &v21);
    if ( v6 >= 0 )
    {
      v7 = (v21 + 1) & 0xFFFFFFFE;
      if ( v7 >= v21 )
      {
        v8 = 0;
        v9 = 0;
        while ( v8 < a2 )
        {
          v10 = *v9;
          v9 += 4;
          v11 = v10 + v7;
          if ( v10 + v7 < v7 )
            goto LABEL_13;
          v7 = v11;
          ++v8;
        }
        v12 = ExAllocatePoolWithTag(1, v7, 1950442835);
        v13 = v12;
        v24 = v12;
        if ( v12 )
        {
          memmove(v12, 0, 8 * a2);
          v14 = (v13 + 8 * a2 + 1) & 0xFFFFFFFE;
          v21 = v14;
          v15 = 0;
          v23 = 0;
          while ( v15 < a2 )
          {
            if ( *(_WORD *)(8 * v15) )
            {
              v16 = *(_DWORD *)(8 * v15 + 4);
              if ( (v16 & 1) != 0 )
                ExRaiseDatatypeMisalignment(v14);
              v17 = *(unsigned __int16 *)(8 * v15) + v16;
              if ( v17 > MmUserProbeAddress || v17 < v16 )
                *(_BYTE *)MmUserProbeAddress = 0;
            }
            memmove(v14, *(_DWORD *)(8 * v15 + 4), *(unsigned __int16 *)(8 * v15));
            v18 = v13 + 8 * v15;
            v19 = v21;
            *(_DWORD *)(v18 + 4) = v21;
            *(_WORD *)(v18 + 2) = *(_WORD *)v18;
            v14 = v19 + *(unsigned __int16 *)(8 * v15);
            v21 = v14;
            v25 = v14;
            v23 = ++v15;
          }
          *v22 = v13;
          v6 = 0;
        }
        else
        {
          SeReleaseUnicodeStringStructures(0, v4);
          v6 = -1073741670;
        }
      }
      else
      {
LABEL_13:
        SeReleaseUnicodeStringStructures(0, v4);
        v6 = -1073741675;
      }
    }
    else
    {
      SeReleaseUnicodeStringStructures(0, v4);
    }
  }
  return v6;
}
