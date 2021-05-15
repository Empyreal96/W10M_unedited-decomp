// DbgkpPostModuleMessages 
 
int __fastcall DbgkpPostModuleMessages(int result, int a2, int a3)
{
  int v4; // r8
  _DWORD *v5; // r6
  _DWORD *v6; // r4
  unsigned int i; // r5
  int v8; // r0
  int v9; // [sp+4h] [bp-FCh]
  unsigned int v11[10]; // [sp+10h] [bp-F0h] BYREF
  _DWORD v12[50]; // [sp+38h] [bp-C8h] BYREF

  v4 = result;
  v5 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(result + 320) + 12) + 12);
  v6 = (_DWORD *)*v5;
  for ( i = 0; v6 != v5 && i < DbgkpMaxModuleMsgs; ++i )
  {
    if ( i > 1 )
    {
      memset(v12, 0, 168);
      v12[6] = 5;
      v12[9] = v6[6];
      v8 = RtlImageNtHeader(v12[9]);
      if ( v8 )
      {
        v12[10] = *(_DWORD *)(v8 + 12);
        v12[11] = *(_DWORD *)(v8 + 16);
      }
      if ( MmGetFileNameForAddress(v8, v11) >= 0 )
      {
        v11[2] = 24;
        v11[3] = 0;
        v11[5] = 1600;
        v11[4] = (unsigned int)v11;
        v11[6] = 0;
        v11[7] = 0;
        v9 = 32;
        if ( ZwOpenFile() < 0 )
          v12[8] = 0;
        ExFreePoolWithTag(v11[1]);
      }
      if ( a3 )
      {
        result = DbgkpQueueMessage(v4, a2, v12, 2, a3, v9, a2);
      }
      else
      {
        DbgkpSendApiMessage(v4, 3, v12);
        result = -1073741823;
      }
      if ( result < 0 )
      {
        result = v12[8];
        if ( v12[8] )
          result = ObCloseHandle(v12[8]);
      }
    }
    v6 = (_DWORD *)*v6;
  }
  return result;
}
