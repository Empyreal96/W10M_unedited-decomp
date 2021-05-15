// CmVirtualKCBToRealPath 
 
int __fastcall CmVirtualKCBToRealPath(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned __int16 *v6; // r0
  _DWORD *v7; // r5
  int v8; // r6
  int v9; // r2
  int v10; // r1
  int v11; // r8
  int v12; // r0
  int v13; // r8
  int v15; // [sp+0h] [bp-20h] BYREF
  int v16; // [sp+4h] [bp-1Ch]
  int v17; // [sp+8h] [bp-18h]

  v15 = a2;
  v16 = a3;
  v17 = a4;
  v4 = -1073741670;
  if ( !CmpVEEnabled )
    return -1073741811;
  v6 = (unsigned __int16 *)CmpConstructName(a1);
  v7 = v6;
  if ( v6 )
  {
    v8 = 0;
    v9 = 5;
    v10 = 0;
    while ( *(_WORD *)(*((_DWORD *)v6 + 1) + v10) != 92 || --v9 )
    {
      ++v8;
      v10 = 2 * v8;
      if ( 2 * v8 >= (unsigned int)*v6 )
      {
        v4 = -1073741811;
        goto LABEL_14;
      }
    }
    v11 = *v6 + 2 * (9 - v8);
    v12 = ExAllocatePoolWithTag(1, v11, 1649298755);
    *(_DWORD *)(a2 + 4) = v12;
    if ( v12 )
    {
      *(_WORD *)a2 = 0;
      *(_WORD *)(a2 + 2) = v11;
      v13 = v7[1];
      HIWORD(v15) = HIWORD(*v7);
      v16 = v13;
      LOWORD(v15) = 18;
      v4 = RtlAppendUnicodeStringToString((unsigned __int16 *)a2, (unsigned __int16 *)&v15);
      if ( v4 < 0
        || (LOWORD(v15) = *(_WORD *)v7 - 2 * v8,
            v16 = v13 + 2 * v8,
            v4 = RtlAppendUnicodeStringToString((unsigned __int16 *)a2, (unsigned __int16 *)&v15),
            v4 < 0) )
      {
        RtlFreeAnsiString((_DWORD *)a2);
      }
    }
LABEL_14:
    ExFreePoolWithTag((unsigned int)v7);
  }
  return v4;
}
