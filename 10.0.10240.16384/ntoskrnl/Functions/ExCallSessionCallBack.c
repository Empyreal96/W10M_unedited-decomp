// ExCallSessionCallBack 
 
int __fastcall ExCallSessionCallBack(int a1, int *a2, int a3, int a4, int *a5)
{
  int *v5; // r8
  int v9; // r7
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r6
  int v14; // r0
  int v15; // r2
  int v16; // r3
  int v17; // r5
  int v18; // r4
  int v19; // r2
  int v20; // r3
  int v22; // r4
  int v23; // r9
  int v24; // r2
  int v25; // r3
  int v26; // r5
  int v27; // r2
  int v28; // r3
  int v29; // [sp+4h] [bp-3Ch]
  char v30[56]; // [sp+8h] [bp-38h] BYREF

  v5 = a5;
  v29 = a3;
  v9 = 0;
  v13 = ExReferenceCallBackBlock(&PsWin32CallBack);
  if ( v13 )
  {
    if ( a2 )
    {
      v14 = MmGetSessionById(*a2, v10, v11, v12);
      v17 = v14;
      if ( v14 )
      {
        v18 = MmAttachSession(v14, (int)v30, v15, v16);
        if ( v18 < 0 )
        {
          v18 = -1073741811;
        }
        else
        {
          v9 = (*(int (__fastcall **)(_DWORD, int, int))(v13 + 4))(*(_DWORD *)(v13 + 8), a3, a4);
          MmDetachSession(v17, (int)v30, v19, v20);
        }
        ObfDereferenceObject(v17);
      }
      else
      {
        v18 = -1073741811;
      }
    }
    else
    {
      v22 = MmGetNextSession();
      if ( v22 )
      {
        do
        {
          v23 = MmGetSessionId(v22);
          v26 = MmAttachSession(v22, (int)v30, v24, v25);
          if ( v26 >= 0 )
          {
            v26 = (*(int (__fastcall **)(_DWORD, int, int))(v13 + 4))(*(_DWORD *)(v13 + 8), v29, a4);
            MmDetachSession(v22, (int)v30, v27, v28);
          }
          if ( !v23 )
            v9 = v26;
          v22 = MmGetNextSession();
        }
        while ( v22 );
        v5 = a5;
      }
      v18 = 0;
    }
    ExDereferenceCallBackBlock(&PsWin32CallBack, v13);
  }
  else
  {
    v18 = -1073741811;
  }
  if ( v18 >= 0 && v5 )
    *v5 = v9;
  return v18;
}
