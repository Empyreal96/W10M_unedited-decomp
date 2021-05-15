// PopBcdClearPendingResume 
 
int __fastcall PopBcdClearPendingResume(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  v5 = BcdOpenObject(a1, &GUID_WINDOWS_BOOTMGR, v7);
  if ( v5 >= 0 )
  {
    v5 = BcdDeleteElement(v7[0]);
    if ( v5 >= 0 )
    {
      v5 = BcdDeleteElement(v7[0]);
      if ( v5 >= 0 )
        BcdFlushStore(a1);
    }
    BcdCloseObject(v7[0]);
  }
  return v5;
}
