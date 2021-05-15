// NtCreateThread 
 
int __fastcall NtCreateThread(unsigned int a1, int a2, int a3, int a4, unsigned int a5, int a6, int *a7, char a8)
{
  int *v8; // r6
  int result; // r0
  _DWORD *v10; // r2
  int v11; // r0
  int v12; // r2
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v19; // [sp+38h] [bp-200h]
  int v20; // [sp+50h] [bp-1E8h] BYREF
  int v21; // [sp+54h] [bp-1E4h]
  int v22; // [sp+58h] [bp-1E0h]
  int v23; // [sp+5Ch] [bp-1DCh]
  int v24; // [sp+60h] [bp-1D8h]
  int v25; // [sp+64h] [bp-1D4h]
  char v26[16]; // [sp+68h] [bp-1D0h] BYREF
  _DWORD _78[118]; // [sp+78h] [bp-1C0h] BYREF

  _78[114] = a1;
  _78[116] = a3;
  _78[117] = a4;
  _78[115] = a2;
  v19 = (_DWORD *)a1;
  v25 = a4;
  v8 = (int *)a6;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  if ( !a6 )
    return -1073741811;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v10 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
    if ( a5 )
    {
      if ( (a5 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a5 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a5 = *(_BYTE *)a5;
      *(_BYTE *)(a5 + 4) = *(_BYTE *)(a5 + 4);
    }
    if ( (a6 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v11 = memmove((int)_78, a6, 0x1A0u);
    v8 = _78;
    if ( ((unsigned __int8)a7 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v11);
  }
  result = RtlpSanitizeContextFlags(v8);
  if ( result >= 0 )
  {
    *v8 &= 0x20000Fu;
    *v19 = 0;
    v20 = *a7;
    v12 = a7[1];
    v21 = v12;
    if ( v20 || v12 )
    {
      result = -1073741637;
    }
    else
    {
      v13 = a7[1];
      v14 = a7[2];
      v15 = a7[3];
      v20 = *a7;
      v21 = v13;
      v22 = v14;
      v23 = v15;
      v24 = a7[4];
      if ( v24 )
      {
        v26[0] = 1;
        result = PspCreateThread(v19, a2, a3, a4, 0, 0, (_DWORD *)a5, (int)v8, (int)&v20, a8 == 1, 0, 0, v26);
      }
      else
      {
        result = -1073741811;
      }
    }
  }
  return result;
}
