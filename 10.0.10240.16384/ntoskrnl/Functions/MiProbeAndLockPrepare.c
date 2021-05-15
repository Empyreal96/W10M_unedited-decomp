// MiProbeAndLockPrepare 
 
int __fastcall MiProbeAndLockPrepare(unsigned int *a1, unsigned int a2, unsigned int a3, int a4, char a5, unsigned int a6, int a7)
{
  unsigned int v9; // r9
  unsigned int v10; // r4
  int v11; // r2
  unsigned int v12; // r10
  __int16 v13; // r3
  __int16 v14; // r3
  unsigned int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r0
  int result; // r0

  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = a3 + a4;
  a1[9] = v9;
  a1[6] = a2;
  a1[5] = a6;
  *a1 = a3;
  a1[1] = a3 + a4;
  if ( a5 && (v10 > MmUserProbeAddress || a3 >= v10) )
  {
    result = -1073741819;
    ++dword_6343C0;
  }
  else
  {
    v11 = *(_DWORD *)(a2 + 20);
    a1[4] = a2 + 28;
    v12 = ((a3 & 0xFFF) + v11 + 4095) >> 12;
    a1[2] = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
    a1[3] = (((v10 - 1) >> 10) & 0x3FFFFC) - 0x40000000;
    v13 = *(_WORD *)(a2 + 6);
    a1[14] = 0xFFFFF;
    if ( a6 )
      v14 = v13 | 0x80;
    else
      v14 = v13 & 0xFF7F;
    *(_WORD *)(a2 + 6) = v14;
    *(_WORD *)(a2 + 6) = v14 | 2;
    if ( a3 >= MmUserProbeAddress )
    {
      a1[10] = 0;
      *(_DWORD *)(a2 + 8) = 0;
    }
    else
    {
      v15 = *(_DWORD *)(v9 + 116);
      a1[10] = v15;
      *(_DWORD *)(a2 + 8) = v15;
      if ( a7 )
      {
        v16 = (unsigned int *)(a1[10] + 280);
        do
          v17 = __ldrex(v16);
        while ( __strex(v17 + v12, v16) );
      }
    }
    MiInitializeProbePacketVm(a1);
    result = 0;
  }
  return result;
}
