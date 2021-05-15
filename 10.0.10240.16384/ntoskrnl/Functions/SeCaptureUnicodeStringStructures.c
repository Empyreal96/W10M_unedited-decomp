// SeCaptureUnicodeStringStructures 
 
int __fastcall SeCaptureUnicodeStringStructures(unsigned int a1, unsigned int a2, int a3, _DWORD *a4)
{
  unsigned int v7; // r8
  int v8; // r4
  int v9; // r0
  int *v10; // r3
  int v11; // r2
  int v12; // r1
  _DWORD *v13; // r3
  int v15; // [sp+0h] [bp-28h] BYREF
  unsigned int v16; // [sp+4h] [bp-24h]
  _DWORD *v17; // [sp+8h] [bp-20h]
  unsigned int varg_r0; // [sp+30h] [bp+8h]
  unsigned int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]
  _DWORD *varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v15 = a2;
  v16 = a3;
  v17 = a4;
  varg_r3 = a4;
  v7 = 0;
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
  v8 = RtlULongLongToULong(8 * a2, a2 >> 29, &v15);
  if ( v8 >= 0 )
  {
    v9 = ExAllocatePoolWithTag(1, v15, 1934976339);
    v17 = (_DWORD *)v9;
    if ( v9 )
    {
      if ( v15 )
      {
        if ( (a1 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v9);
        if ( v15 + a1 > MmUserProbeAddress || v15 + a1 < a1 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      while ( 1 )
      {
        v16 = v7;
        if ( v7 >= a2 )
          break;
        v10 = (int *)(a1 + 8 * v7);
        v11 = *v10;
        v12 = v10[1];
        __dmb(0xBu);
        v13 = (_DWORD *)(v9 + 8 * v7);
        *v13 = v11;
        v13[1] = v12;
        v7 = v16 + 1;
      }
      *a4 = v9;
    }
    else
    {
      v8 = -1073741670;
    }
  }
  return v8;
}
