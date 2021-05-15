// DrvDbSplitDeviceIdDriverInfMatch 
 
int __fastcall DrvDbSplitDeviceIdDriverInfMatch(unsigned __int16 *a1, _WORD *a2, unsigned int a3, int a4)
{
  unsigned int v4; // r4
  int v7; // r8
  _WORD *v8; // r0
  _WORD *v9; // r6
  int v10; // r10
  unsigned int v12; // r0
  char v13; // r3
  unsigned int v14; // r0

  v4 = a3;
  v7 = 0;
  v8 = wcschr(a1, 92);
  v9 = v8;
  if ( !v8 )
  {
    v10 = wcslen(a1);
    if ( a4 )
    {
      *(_BYTE *)a4 = 0;
      *(_WORD *)(a4 + 2) = 0;
    }
    goto LABEL_10;
  }
  v10 = v8 - a1;
  if ( a4 )
  {
    if ( wcschr(v8 + 1, 92) )
      return sub_7E3558();
    if ( v9[1] == 42 )
    {
      v13 = 3;
    }
    else
    {
      v12 = wcstol(v9 + 1, 0, 16);
      if ( v12 )
      {
        *(_BYTE *)a4 = 2;
        v14 = v12 - 1;
        if ( v14 > 0xFFFF )
          LOWORD(v14) = -1;
        *(_WORD *)(a4 + 2) = v14;
        goto LABEL_9;
      }
      v13 = 1;
    }
    *(_WORD *)(a4 + 2) = 0;
    *(_BYTE *)a4 = v13;
  }
LABEL_9:
  v4 = a3;
LABEL_10:
  if ( !a2 || (v7 = RtlStringCchCopyNExW(a2, v4, (int)a1, v10, 0, 0, 2304), v7 >= 0) )
  {
    if ( a4 )
      *(_BYTE *)(a4 + 1) = -1;
  }
  return v7;
}
