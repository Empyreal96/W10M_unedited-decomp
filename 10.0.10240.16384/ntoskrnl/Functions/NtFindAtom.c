// NtFindAtom 
 
int __fastcall NtFindAtom(unsigned int a1, unsigned int a2, _WORD *a3)
{
  int result; // r0
  int v7; // r3
  unsigned __int16 *v8; // r10
  _WORD *v9; // r2
  __int16 v10; // [sp-4h] [bp-238h] BYREF
  _DWORD *v11; // [sp+4h] [bp-230h] BYREF
  _WORD *v12; // [sp+8h] [bp-22Ch]
  _WORD *v13; // [sp+Ch] [bp-228h]
  _WORD v14[272]; // [sp+14h] [bp-220h] BYREF

  v13 = a3;
  v11 = 0;
  PsInvokeWin32Callout(2, (int)&v11, 0, 0);
  if ( !v11 )
    return -1073741790;
  if ( a2 > 0x1FE )
    return -1073741811;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  LOBYTE(v10) = *(_BYTE *)(v7 + 346);
  v8 = (unsigned __int16 *)a1;
  v12 = (_WORD *)a1;
  if ( (_BYTE)v10 )
  {
    if ( a3 )
    {
      v9 = a3;
      if ( (unsigned int)a3 >= MmUserProbeAddress )
        v9 = (_WORD *)MmUserProbeAddress;
      v7 = (unsigned __int16)*v9;
      *v9 = v7;
    }
    if ( a1 )
    {
      if ( a2 )
      {
        if ( (a1 & 1) != 0 )
          ExRaiseDatatypeMisalignment();
        if ( a2 + a1 > MmUserProbeAddress || a2 + a1 < a1 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      v8 = v14;
      v12 = v14;
      memmove((int)v14, a1, a2);
      v7 = (int)v14;
      v14[a2 >> 1] = 0;
    }
  }
  result = RtlLookupAtomInAtomTable(v11, v8, &v10, v7);
  if ( a3 )
  {
    if ( result >= 0 )
      *a3 = v10;
  }
  return result;
}
