// SepIsMinTCB 
 
int __fastcall SepIsMinTCB(unsigned __int16 *a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v9; // r4
  unsigned int v10; // r4
  int v11; // r3
  int v12; // r6
  int v13; // r7
  int result; // r0
  int v15; // [sp+0h] [bp-30h]
  __int16 v16[2]; // [sp+10h] [bp-20h] BYREF
  int v17; // [sp+14h] [bp-1Ch]
  unsigned __int16 *varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  do
    v9 = __ldrex((unsigned int *)&dword_646664);
  while ( !v9 && __strex(0, (unsigned int *)&dword_646664) );
  __dmb(0xBu);
  if ( v9 || (result = SepSetSystemPaths(), result >= 0) )
  {
    if ( a1 )
    {
      v10 = *(unsigned __int16 *)dword_646664;
      v11 = v10 < 0x2A ? *(unsigned __int16 *)dword_646664 : 42;
      v12 = *a1;
      if ( v12 > v11 )
      {
        v13 = *((_DWORD *)a1 + 1);
        if ( *(_WORD *)(v13 + 2) == 63 )
        {
          if ( RtlPrefixUnicodeString((unsigned __int16 *)dword_646664, a1, 1) )
          {
LABEL_11:
            v16[0] = v12 - v10;
            v16[1] = v12 - v10;
            v17 = v13 + 2 * ((v12 - (unsigned int)(unsigned __int16)(v12 - v10)) >> 1);
            result = ((int (__fastcall *)(int *, int, __int16 *, int, _BYTE, int, int, int))SepIsImageInMinTcbList)(
                       &SeMsMinTCBList,
                       11,
                       v16,
                       a2,
                       varg_r2,
                       a4,
                       a5,
                       a6);
            if ( result < 0 && (SeCiDebugOptions & 1) == 0 && KdDebuggerEnabled && !KdDebuggerNotPresent )
            {
              LOBYTE(v15) = varg_r2;
              result = ((int (__fastcall *)(int *, int, __int16 *, int, int, int, int, int))SepIsImageInMinTcbList)(
                         &SeMsMinTestTCBList,
                         9,
                         v16,
                         a2,
                         v15,
                         a4,
                         a5,
                         a6);
            }
            return result;
          }
        }
        else if ( RtlPrefixUnicodeString((unsigned __int16 *)&dword_402160, a1, 1) )
        {
          LOWORD(v10) = 42;
          goto LABEL_11;
        }
      }
    }
    result = -1073741275;
  }
  return result;
}
