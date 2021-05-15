// RtlGetThreadLangIdByIndex 
 
int __fastcall RtlGetThreadLangIdByIndex(int a1, unsigned int a2, _DWORD *a3, unsigned int *a4)
{
  int v6; // r4
  int v7; // r5
  unsigned int v8; // r8
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r3
  _BYTE *v12; // r0
  int v13; // r2
  unsigned int v14; // r2
  unsigned __int16 v15; // r2
  int v17; // [sp+10h] [bp-28h]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( a1 || !a3 )
    return -1073741811;
  v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C);
  if ( (v9 & 0x400) != 0 || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
    v10 = 0;
  else
    v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
  v11 = *(_DWORD *)(v10 + 4024);
  if ( v11 )
  {
    if ( (v11 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v9);
    v12 = (_BYTE *)MmUserProbeAddress;
    if ( v11 + 56 > MmUserProbeAddress || v11 + 56 < v11 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v12 = (_BYTE *)MmUserProbeAddress;
    }
    v13 = *(_DWORD *)(v11 + 16);
    if ( v13 )
    {
      v8 = *(unsigned __int16 *)(v11 + 4);
      if ( a2 < v8 )
      {
        if ( (v13 & 1) != 0 )
          ExRaiseDatatypeMisalignment(v12);
        v14 = v13 + 6 * a2;
        if ( v14 + 6 > (unsigned int)v12 || v14 + 6 < v14 )
          *v12 = 0;
        v17 = *(_DWORD *)v14;
        v15 = *(_WORD *)(v14 + 4);
        if ( (unsigned __int16)v17 == 1 )
          v7 = v15;
        else
          v6 = -1073741595;
      }
    }
  }
  *a3 = v7;
  if ( a4 )
    *a4 = v8;
  if ( !v6 && !v7 )
    v6 = -1073741275;
  return v6;
}
