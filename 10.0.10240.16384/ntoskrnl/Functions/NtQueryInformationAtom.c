// NtQueryInformationAtom 
 
int __fastcall NtQueryInformationAtom(unsigned int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  int result; // r0
  _DWORD *v9; // r6
  _DWORD *v10; // r2
  int v11; // r4
  int v12; // r5
  unsigned int v13; // r3
  _DWORD *v14; // [sp+8h] [bp-38h] BYREF
  int v15; // [sp+Ch] [bp-34h]
  unsigned int v16; // [sp+10h] [bp-30h]
  int v17; // [sp+14h] [bp-2Ch]
  int v18; // [sp+18h] [bp-28h] BYREF
  unsigned int v19; // [sp+1Ch] [bp-24h] BYREF
  int v20[8]; // [sp+20h] [bp-20h] BYREF

  v16 = a1;
  v14 = 0;
  PsInvokeWin32Callout(2, (int)&v14, 0, 0);
  if ( !v14 )
    return -1073741790;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    ProbeForWrite(a3, a4, 4);
    v9 = (_DWORD *)a5;
    if ( a5 )
    {
      v10 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v10 = (_DWORD *)MmUserProbeAddress;
      *v10 = *v10;
    }
  }
  else
  {
    v9 = (_DWORD *)a5;
  }
  v11 = 0;
  v15 = 0;
  if ( a2 )
  {
    if ( a2 != 1 )
    {
      v12 = -1073741821;
      v17 = -1073741821;
      goto LABEL_21;
    }
    v11 = 4;
    v15 = 4;
    if ( a4 < 4 )
    {
      result = -1073741820;
      v16 = -1073741820;
      return result;
    }
    v12 = RtlQueryAtomsInAtomTable(v14, (a4 - 4) >> 1, (unsigned int *)a3, a3 + 4);
    v17 = v12;
    if ( v12 < 0 )
      goto LABEL_21;
    v11 = 2 * (*(_DWORD *)a3 + 2);
LABEL_20:
    v15 = v11;
    goto LABEL_21;
  }
  v11 = 6;
  v15 = 6;
  if ( a4 < 6 )
  {
    result = -1073741820;
    v16 = -1073741820;
    return result;
  }
  v18 = 0;
  v19 = a4 - 6;
  v12 = RtlQueryAtomInAtomTable(v14, v16, &v18, v20, a3 + 6, &v19);
  v17 = v12;
  if ( v12 >= 0 )
  {
    *(_WORD *)a3 = v18;
    *(_WORD *)(a3 + 2) = v20[0];
    v13 = v19;
    *(_WORD *)(a3 + 4) = v19;
    v11 = v13 + 8;
    goto LABEL_20;
  }
LABEL_21:
  if ( v9 )
    *v9 = v11;
  return v12;
}
