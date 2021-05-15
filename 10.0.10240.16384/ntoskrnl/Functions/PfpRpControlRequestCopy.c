// PfpRpControlRequestCopy 
 
int __fastcall PfpRpControlRequestCopy(int *a1, int a2, int *a3, int a4, char a5)
{
  unsigned int v8; // r1
  int v9; // r2
  int v10; // r3
  int v12; // r0
  unsigned int v13; // r1
  unsigned __int64 v14; // kr08_8
  unsigned __int64 v15; // kr18_8
  int v16; // r8
  int v19; // [sp+20h] [bp-40h] BYREF
  unsigned int v20; // [sp+24h] [bp-3Ch]
  int v21; // [sp+28h] [bp-38h]
  int v22; // [sp+2Ch] [bp-34h]
  unsigned int v23; // [sp+30h] [bp-30h]
  int *varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  int *varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r1 = a2;
  if ( a5 && a2 )
  {
    if ( ((unsigned __int8)a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( (unsigned int)a1 + a2 > MmUserProbeAddress || (int *)((char *)a1 + a2) < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v8 = a1[1];
  v9 = a1[2];
  v10 = a1[3];
  v19 = *a1;
  v20 = v8;
  v21 = v9;
  v22 = v10;
  v23 = a1[4];
  if ( (unsigned __int16)v19 != 3 || HIWORD(v19) >= 4u )
    return -1073741811;
  if ( HIWORD(v19) != 1 )
  {
    v12 = v22;
    v13 = v21;
    goto LABEL_17;
  }
  if ( v20 )
    return -1073741811;
  v13 = v21;
  if ( v21 )
    return -1073741811;
  v12 = v22;
  if ( v22 || v23 )
    return -1073741811;
LABEL_17:
  v14 = 8i64 * v20 + __PAIR64__(v13 >> 29, 8 * v13);
  v15 = 4 * ((unsigned int)v12 + (unsigned __int64)v23) - (((_BYTE)v14 + 19) & 3) + v14 + 20 + 3;
  if ( HIDWORD(v15) )
    return -1073741675;
  if ( (_DWORD)v15 != a2 )
    return -1073741811;
  if ( (unsigned int)v15 <= 0x20 )
  {
    v16 = a4;
LABEL_23:
    memmove(v16, (int)a1, v15);
    memmove(v16, (int)&v19, 0x14u);
    *a3 = v16;
    return 0;
  }
  v16 = ExAllocatePoolWithTag(1, v15, 1129473616);
  if ( v16 )
    goto LABEL_23;
  return -1073741670;
}
