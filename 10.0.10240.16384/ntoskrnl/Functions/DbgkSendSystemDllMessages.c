// DbgkSendSystemDllMessages 
 
int __fastcall DbgkSendSystemDllMessages(int result, int a2, _DWORD *a3)
{
  _DWORD *v3; // r4
  int v4; // r9
  int v5; // r10
  int *v6; // r5
  int i; // r8
  int v8; // r2
  int v9; // r0
  int v10; // r6
  int v11; // [sp+8h] [bp-90h]
  int v12; // [sp+Ch] [bp-8Ch]
  int v15; // [sp+30h] [bp-68h]
  int v16; // [sp+38h] [bp-60h]
  _BYTE v17[56]; // [sp+60h] [bp-38h] BYREF

  v3 = a3;
  v4 = result;
  if ( result )
    v5 = *(_DWORD *)(result + 336);
  else
    v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v6 = a3 + 8;
  for ( i = 0; i < 2; ++i )
  {
    result = PsQuerySystemDllInfo(i);
    v12 = result;
    if ( result )
    {
      memset(v6, 0, 20);
      v8 = *(_DWORD *)(v12 + 12);
      v16 = v8;
      __dmb(0xBu);
      v6[1] = v8;
      if ( v4 && i )
      {
        v15 = 1;
        LOBYTE(v11) = 1;
        KiStackAttachProcess(v5, 0, (int)v17);
        v8 = v16;
      }
      else
      {
        v15 = 0;
        LOBYTE(v11) = 0;
      }
      v9 = RtlImageNtHeader(v8);
      if ( v9 )
      {
        v6[2] = *(_DWORD *)(v9 + 12);
        v6[3] = *(_DWORD *)(v9 + 16);
      }
      if ( v4 )
      {
        v10 = 0;
      }
      else
      {
        if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
          || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
        {
          v10 = 0;
        }
        else
        {
          v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
        }
        if ( v10 )
        {
          RtlStringCbCopyW(v10 + 3072, 0x20Au);
          *(_DWORD *)(v10 + 20) = v10 + 3072;
          v6[4] = v10 + 20;
          v3 = a3;
        }
      }
      if ( v15 )
        KiUnstackDetachProcess((unsigned int)v17, 0);
      if ( ZwOpenFile() < 0 )
        *v6 = 0;
      *v3 = 3407900;
      v3[1] = 8;
      v3[6] = 5;
      if ( v4 )
      {
        result = DbgkpQueueMessage(v5, v4, v3, 2, a2, 32, v11);
        if ( result < 0 )
        {
          result = *v6;
          if ( *v6 )
            result = ObCloseHandle(result);
        }
      }
      else
      {
        DbgkpSendApiMessage(v5, 3, v3);
        result = *v6;
        if ( *v6 )
          result = ObCloseHandle(result);
        if ( v10 )
          *(_DWORD *)(v10 + 20) = 0;
      }
    }
  }
  return result;
}
