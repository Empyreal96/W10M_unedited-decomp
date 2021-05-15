// IopSymlinkUpdateECP 
 
int __fastcall IopSymlinkUpdateECP(int a1, int a2, int a3, unsigned __int16 *a4, __int16 a5, __int16 a6)
{
  int v6; // r4
  unsigned int v7; // r5
  int v8; // r7
  __int16 v10; // r8
  int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r0
  int v15; // r1
  int v16; // r0
  int v17; // r4
  int v18; // r6
  unsigned int v19; // r4
  int v20; // [sp+1Ch] [bp-24h] BYREF
  int v21; // [sp+20h] [bp-20h]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  unsigned __int16 *varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = *(_DWORD *)(a1 + 8);
  v7 = a2;
  v8 = 0;
  v10 = a3;
  varg_r1 = a2;
  if ( (v6 & 0x80) != 0 )
    v8 = *(_DWORD *)(a1 + 60);
  v11 = IopSymlinkGetECP(v8, (int)&v20);
  v12 = *a4;
  if ( *(unsigned __int16 *)(v7 + 14) < v12 )
  {
    v15 = v20;
    v21 = v20;
    if ( v20 == v7 )
      return sub_7F9C88(v11);
    if ( *(_DWORD *)(v20 + 8) != v7 )
    {
      do
        v15 = *(_DWORD *)(v15 + 8);
      while ( *(_DWORD *)(v15 + 8) != v7 );
      v21 = v15;
    }
    v16 = ExAllocatePoolWithTag(1, v12 + 20, 1767075657);
    v17 = v16;
    if ( !v16 )
      return -1073741670;
    v18 = v21;
    *(_DWORD *)(v21 + 8) = v16;
    IopSymlinkInitializeSymlinkInfo(v16, *a4 + 20, *((_DWORD *)a4 + 1), *a4, v10, 0, 0, 0, a6, *(_DWORD *)(v7 + 8));
    if ( v7 == v18 )
    {
      *(_DWORD *)(v7 + 8) = 0;
      FsRtlFreeExtraCreateParameter(v7);
    }
    else
    {
      ExFreePoolWithTag(v7);
    }
    v7 = v17;
  }
  else
  {
    RtlCopyUnicodeString((unsigned __int16 *)(v7 + 12), a4);
  }
  *(_WORD *)(v7 + 2) = a6;
  *(_WORD *)(v7 + 4) = a5;
  *(_WORD *)v7 = v10;
  if ( (*(_WORD *)(v7 + 2) & 1) == 0 )
  {
    v13 = *(_DWORD *)(v7 + 8);
    if ( v13 )
    {
      do
      {
        v19 = *(_DWORD *)(v13 + 8);
        ExFreePoolWithTag(v13);
        v13 = v19;
      }
      while ( v19 );
    }
    *(_DWORD *)(v7 + 8) = 0;
  }
  return 0;
}
