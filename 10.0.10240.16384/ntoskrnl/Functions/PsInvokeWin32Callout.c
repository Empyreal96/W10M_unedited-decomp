// PsInvokeWin32Callout 
 
int __fastcall PsInvokeWin32Callout(int a1, int a2, int a3, int *a4)
{
  int v7; // r0
  unsigned int v8; // r4
  int v9; // r5
  int result; // r0
  int v11; // r0
  int v12[4]; // [sp+8h] [bp-10h] BYREF

  v12[0] = (int)a4;
  switch ( a3 )
  {
    case 0:
LABEL_2:
      v7 = ExReferenceCallBackBlock(&PsWin32CallBack);
      v8 = v7;
      if ( v7 )
      {
        v9 = (*(int (__fastcall **)(_DWORD, int, int))(v7 + 4))(*(_DWORD *)(v7 + 8), a1, a2);
        ExDereferenceCallBackBlock(&PsWin32CallBack, v8);
        return v9;
      }
      return -1073741811;
    case 1:
      v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      if ( (*(_DWORD *)(v11 + 192) & 0x10000) != 0 )
      {
        v11 = MmGetSessionId(v11);
        if ( *a4 == v11 )
          goto LABEL_2;
      }
      v9 = ExCallSessionCallBack(v11, a4, a1, a2, v12);
      if ( v9 < 0 )
        return v9;
      result = v12[0];
      break;
    case 2:
      v9 = ExCallSessionCallBack(a1, 0, a1, a2, v12);
      if ( v9 < 0 )
        return v9;
      result = v12[0];
      break;
    default:
      return -1073741811;
  }
  return result;
}
