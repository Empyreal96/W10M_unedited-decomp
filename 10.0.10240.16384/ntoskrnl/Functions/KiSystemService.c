// KiSystemService 
 
int __fastcall KiSystemService(unsigned int a1, int a2, int a3, int a4, int (__fastcall *a5)(int, int, int, int), int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32)
{
  _DWORD *v32; // r12
  int v33; // r1
  unsigned int v34; // r0
  int *v35; // r3
  int *v36; // r3
  unsigned int v37; // r2
  int v38; // r3
  int v39; // r2
  int (__fastcall *v40)(_DWORD, _DWORD, _DWORD, _DWORD); // r3
  unsigned int v42; // r1
  bool v43; // zf
  int result; // r0
  char v45; // [sp+0h] [bp-40h]
  unsigned int v46; // [sp+0h] [bp-40h]
  int (__fastcall *v47)(_DWORD, _DWORD, _DWORD, _DWORD); // [sp+4h] [bp-3Ch]

  v32[24] = &a5;
  v33 = (a1 >> 12) & 1;
  v34 = a1 & 0xFFF;
  do
  {
    v35 = &KeServiceDescriptorTable;
    if ( (v32[20] & 0x40) != 0 )
      v35 = &KeServiceDescriptorTableShadow;
    v36 = &v35[4 * v33];
    v37 = v36[2];
    v38 = *v36;
    if ( v34 < v37 )
    {
      v39 = *(_DWORD *)(v38 + 4 * v34);
      v40 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))(v38 + (v39 >> 4));
      if ( v33 && *(_DWORD *)(v32[39] + 3952) )
      {
        v45 = v39;
        v47 = v40;
        PsInvokeWin32Callout(7, 0, 0, 0);
        LOBYTE(v39) = v45;
        v40 = v47;
        __mrc(15, 0, 13, 0, 3);
      }
      if ( v39 & 0xF )
        __asm { BX              R2 }
      v42 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v43 = (dword_682608 & 0x40) == 0;
      ++*(_DWORD *)(v42 + 2992);
      if ( v43 )
        return v40(a29, a30, a31, a32);
      a5 = v40;
      PerfInfoLogSysCallEntry(v40);
      a29 = a5(a29, a30, a31, a32);
      PerfInfoLogSysCallExit();
      return a29;
    }
    if ( !v33 )
      return -1073741796;
    v46 = v34;
    v43 = PsConvertToGuiThread() == 0;
    v34 = v46;
    v33 = 1;
    v32 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  }
  while ( v43 );
  if ( v46 >= dword_682018 )
    return -1073741796;
  result = *(char *)(v46 + dword_682010 + 4 * dword_682018);
  if ( result > 0 )
    return -1073741796;
  return result;
}
