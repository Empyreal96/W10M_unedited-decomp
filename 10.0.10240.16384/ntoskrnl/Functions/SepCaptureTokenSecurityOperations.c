// SepCaptureTokenSecurityOperations 
 
int __fastcall SepCaptureTokenSecurityOperations(_DWORD *a1, unsigned int a2, int a3, int *a4)
{
  unsigned int v5; // r5
  unsigned int v6; // r9
  int v7; // r4
  int v8; // r8
  int v9; // r0
  unsigned int v10; // r2
  int v12; // [sp+0h] [bp-30h] BYREF
  int v13; // [sp+4h] [bp-2Ch]
  unsigned int v14; // [sp+8h] [bp-28h]
  unsigned int v15; // [sp+Ch] [bp-24h]
  _DWORD *varg_r0; // [sp+38h] [bp+8h]
  unsigned int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int *varg_r3; // [sp+44h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a2;
  v6 = (unsigned int)a1;
  varg_r0 = a1;
  if ( (_BYTE)a3 )
  {
    if ( *a1 == 1 )
    {
      v8 = 4;
      v12 = 4;
      v5 = 1;
      v14 = 1;
    }
    else
    {
      if ( !a2 )
      {
        v7 = -1073741811;
        v13 = -1073741811;
        return v7;
      }
      a1 = (_DWORD *)RtlULongLongToULong(4 * a2, a2 >> 30, &v12);
      v7 = (int)a1;
      if ( (int)a1 < 0 )
      {
        v13 = (int)a1;
        return v7;
      }
      v14 = v5;
      v8 = v12;
    }
    if ( v8 )
    {
      if ( (v6 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( v8 + v6 > MmUserProbeAddress || v8 + v6 < v6 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    v9 = ExAllocatePoolWithTag(1, v8, 1884251475);
    v12 = v9;
    if ( !v9 )
      return -1073741801;
    v10 = 0;
    v15 = 0;
    while ( v10 < v5 )
    {
      *(_DWORD *)(v9 + 4 * v10) = *(_DWORD *)(v6 + 4 * v10);
      v15 = ++v10;
    }
    *a4 = v9;
  }
  else
  {
    *a4 = (int)a1;
  }
  return 0;
}
