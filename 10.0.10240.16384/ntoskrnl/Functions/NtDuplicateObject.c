// NtDuplicateObject 
 
int __fastcall NtDuplicateObject(int a1, int a2, int a3, _DWORD *a4, int a5, int a6, int a7)
{
  _DWORD *v7; // r5
  int v8; // r10
  _DWORD *v9; // r2
  int v10; // r6
  int v11; // r4
  int v12; // r9
  int v13; // r10
  int v15; // [sp+Ch] [bp-3Ch]
  int v16; // [sp+14h] [bp-34h] BYREF
  int v17; // [sp+18h] [bp-30h]
  int v18; // [sp+1Ch] [bp-2Ch] BYREF
  int v19; // [sp+20h] [bp-28h] BYREF
  int v20; // [sp+24h] [bp-24h]
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  _DWORD *varg_r3; // [sp+5Ch] [bp+14h]

  v7 = a4;
  varg_r3 = a4;
  v16 = a3;
  varg_r2 = a3;
  v17 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v18 = 0;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( a4 && v8 )
  {
    v9 = a4;
    if ( (unsigned int)a4 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
    *a4 = 0;
  }
  v10 = ObReferenceObjectByHandleWithTag(a1, 64, PsProcessType, v8, 1967415887, &v19, 0);
  if ( v10 >= 0 )
  {
    if ( v16 )
    {
      v12 = ObReferenceObjectByHandleWithTag(v16, 64, PsProcessType, v8, 1967415887, &v16, 0);
      v20 = v12;
      if ( v12 >= 0 )
      {
        v11 = v16;
      }
      else
      {
        v11 = 0;
        v16 = 0;
      }
    }
    else
    {
      v11 = 0;
      v16 = 0;
      v12 = 0;
      v20 = 0;
    }
    v15 = v8;
    v13 = v19;
    v10 = ObDuplicateObject(v19, v17, v11, &v18, a5, a6, a7, v15);
    v17 = v10;
    if ( v7 )
      *v7 = v18;
    ObfDereferenceObjectWithTag(v13);
    if ( v11 )
      ObfDereferenceObjectWithTag(v11);
    if ( v12 < 0 )
      v10 = v12;
  }
  return v10;
}
