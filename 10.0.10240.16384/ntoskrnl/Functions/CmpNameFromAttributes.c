// CmpNameFromAttributes 
 
int __fastcall CmpNameFromAttributes(int *a1, char a2, unsigned __int16 *a3)
{
  int v4; // r10
  int v6; // r0
  int v7; // r1
  _DWORD *v8; // r2
  int v9; // r3
  int *v10; // lr
  int v11; // r3
  unsigned int v12; // r8
  unsigned int v13; // r4
  int result; // r0
  int v15; // r5
  unsigned int v16; // r2
  int v17; // r0
  _WORD *v18; // r2
  int v19; // r5
  int v20; // r0
  _DWORD v21[4]; // [sp+10h] [bp-258h] BYREF
  _DWORD v22[3]; // [sp+20h] [bp-248h] BYREF
  int v23; // [sp+2Ch] [bp-23Ch]
  _DWORD *v24; // [sp+30h] [bp-238h]
  int v25; // [sp+34h] [bp-234h]
  int v26; // [sp+38h] [bp-230h]
  int v27; // [sp+3Ch] [bp-22Ch]
  int v28; // [sp+48h] [bp-220h]
  int v29; // [sp+4Ch] [bp-21Ch]

  v4 = a2;
  v21[2] = a3;
  *((_DWORD *)a3 + 1) = 0;
  if ( a2 == 1 && ((unsigned __int8)a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v6 = *a1;
  v7 = a1[1];
  v8 = (_DWORD *)a1[2];
  v9 = a1[3];
  v10 = a1 + 4;
  v22[2] = v6;
  v23 = v7;
  v24 = v8;
  v25 = v9;
  v11 = v10[1];
  v26 = *v10;
  v27 = v11;
  v21[0] = *v8;
  v12 = v8[1];
  v21[1] = v12;
  v13 = LOWORD(v21[0]);
  if ( v4 == 1 && LOWORD(v21[0]) )
  {
    if ( (v12 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v6);
    if ( LOWORD(v21[0]) + v12 > MmUserProbeAddress || LOWORD(v21[0]) + v12 < v12 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  if ( (v13 & 1) != 0 )
    return -1073741765;
  if ( !v23 )
  {
    if ( !v13 )
      return -1073741765;
    *a3 = v13;
    a3[1] = v13;
    v20 = ExAllocatePoolWithQuotaTag(9u, v13, 1852198211);
    *((_DWORD *)a3 + 1) = v20;
    if ( v20 )
    {
      memmove(v20, v12, v13);
      v19 = 0;
    }
    else
    {
      v19 = -1073741670;
    }
    goto LABEL_37;
  }
  if ( v23 < 0 && v4 == 1 )
    return -1073741816;
  if ( v12 && v13 >= 2 && *(_WORD *)v12 == 92 )
    return -1073741765;
  result = IoConvertFileHandleToKernelHandle(v23);
  if ( result >= 0 )
  {
    v15 = ZwQueryObject();
    ZwClose();
    if ( v15 < 0 )
      return v15;
    v22[0] = v28;
    v22[1] = v29;
    *a3 = 0;
    v16 = (unsigned __int16)v28 + v13 + 2;
    if ( v16 > 0xFFFF )
      return -1073741767;
    a3[1] = v16;
    v17 = ExAllocatePoolWithQuotaTag(9u, a3[1], 1852198211);
    *((_DWORD *)a3 + 1) = v17;
    if ( !v17 )
      return -1073741670;
    RtlAppendUnicodeStringToString(a3, (unsigned __int16 *)v22);
    if ( *a3 )
    {
      v18 = (_WORD *)(*a3 + *((_DWORD *)a3 + 1));
      if ( *(v18 - 1) != 92 )
      {
        *v18 = 92;
        *a3 += 2;
      }
    }
    v19 = RtlAppendUnicodeStringToString(a3, (unsigned __int16 *)v21);
LABEL_37:
    result = v19;
  }
  return result;
}
