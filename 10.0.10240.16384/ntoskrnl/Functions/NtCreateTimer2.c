// NtCreateTimer2 
 
int __fastcall NtCreateTimer2(unsigned int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v6; // r5
  int result; // r0
  _DWORD *v8; // r2
  int v9[2]; // [sp+1Ch] [bp-1Ch] BYREF
  _DWORD _24[11]; // [sp+24h] [bp-14h] BYREF

  _24[8] = a2;
  _24[9] = a3;
  v9[0] = a2;
  v9[1] = a3;
  _24[0] = a4;
  _24[10] = a4;
  v6 = (_DWORD *)a1;
  _24[7] = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
    return -1073741790;
  v8 = (_DWORD *)a1;
  if ( a1 >= MmUserProbeAddress )
    v8 = (_DWORD *)MmUserProbeAddress;
  *v8 = *v8;
  if ( a4 != 2 && a4 != 8 )
    return -1073741582;
  if ( (a4 & 2) == 0 || (result = ExpCheckIRTimerAccess(1), result >= 0) )
  {
    result = ObCreateObject(1, ExpIRTimerObjectType, 0, 1, 0, 88, 0, 0, v9);
    if ( result >= 0 )
    {
      KeInitializeTimer2(v9[0], 0, 0, a4);
      result = ObInsertObject(v9[0], 0, a5, 0, 0, _24);
      v9[0] = result;
      if ( result >= 0 )
        *v6 = _24[0];
    }
  }
  return result;
}
