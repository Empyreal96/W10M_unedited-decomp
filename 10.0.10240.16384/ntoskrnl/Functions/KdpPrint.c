// KdpPrint 
 
int __fastcall KdpPrint(unsigned int a1, unsigned int a2, int a3, unsigned int a4, char a5, int a6, int a7, _BYTE *a8)
{
  int v8; // r5
  _BYTE *v9; // r6
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r5
  _BYTE v14[512]; // [sp-200h] [bp-220h] BYREF
  int var20[12]; // [sp+0h] [bp-20h] BYREF
  _BYTE *varg_r2; // [sp+30h] [bp+10h]
  unsigned int varg_r3; // [sp+34h] [bp+14h]

  var20[10] = a1;
  var20[11] = a2;
  v8 = a4;
  varg_r3 = a4;
  v9 = (_BYTE *)a3;
  varg_r2 = (_BYTE *)a3;
  if ( a1 >= 0x9A )
  {
    a1 = 101;
    a2 = 3;
  }
  *a8 = 0;
  if ( a2 <= 0x1F )
    a2 = 1 << a2;
  if ( (Kd_WIN2000_Mask & a2) != 0 || (*(_DWORD *)*(&KdComponentTable + a1) & a2) != 0 )
  {
    if ( a4 > 0x200 )
    {
      v8 = 512;
      LOWORD(varg_r3) = 512;
    }
    if ( a5 )
    {
      if ( v8 )
      {
        v11 = v8 + a3;
        if ( (unsigned int)&v9[v8] > MmUserProbeAddress || v11 < (unsigned int)v9 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      KdpQuickMoveMemory(v14, v9, v8);
      v9 = v14;
      varg_r2 = v14;
    }
    var20[1] = (int)v9;
    LOWORD(var20[0]) = v8;
    KdLogDbgPrint(var20);
    if ( !KdDebuggerNotPresent || KdEventLoggingPresent )
    {
      v12 = KdEnterDebugger(a6, a7);
      if ( KdpPrintString(var20) )
        v10 = -2147483645;
      else
        v10 = 0;
      KdExitDebugger(v12);
    }
    else
    {
      v10 = -1073741667;
    }
  }
  else
  {
    v10 = 0;
  }
  *a8 = 1;
  return v10;
}
