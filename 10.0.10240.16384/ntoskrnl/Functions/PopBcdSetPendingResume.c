// PopBcdSetPendingResume 
 
int __fastcall PopBcdSetPendingResume(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r2
  int v8; // r5
  int v9; // r2
  int v10; // r2
  __int16 v12; // [sp+8h] [bp-30h] BYREF
  int v13; // [sp+Ch] [bp-2Ch] BYREF
  char v14[40]; // [sp+10h] [bp-28h] BYREF

  v13 = 0;
  v6 = PopBcdSetupResumeObject(a4);
  if ( v6 >= 0 )
  {
    HIBYTE(v12) = 0;
    LOBYTE(v12) = KdDebuggerEnabled != 0;
    BcdSetElementDataWithFlags(a4, 0x26000006u, (unsigned __int8)KdDebuggerEnabled, (int)&v12, 2);
    v6 = BcdQueryObject(a4, 0, 0, v14);
    if ( v6 >= 0 )
    {
      v6 = BcdOpenObject(a1, &GUID_WINDOWS_BOOTMGR, &v13);
      v8 = v13;
      if ( v6 >= 0 )
      {
        v6 = BcdSetElementDataWithFlags(v13, 0x23000006u, v7, (int)v14, 16);
        if ( v6 >= 0 )
        {
          v12 = 1;
          v6 = BcdSetElementDataWithFlags(v8, 0x26000005u, v9, (int)&v12, 2);
          if ( v6 >= 0 )
          {
            v12 = (unsigned __int8)byte_61EED0;
            v6 = BcdSetElementDataWithFlags(v8, 0x26000025u, v10, (int)&v12, 2);
            if ( v6 >= 0 )
              v6 = 0;
          }
        }
      }
      if ( v8 )
        BcdCloseObject(v8);
    }
  }
  return v6;
}
