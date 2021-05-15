// DbgkMapViewOfSection 
 
int __fastcall DbgkMapViewOfSection(int result, int a2, int a3)
{
  int v5; // r5
  int v6; // r4
  int v7; // r3
  int v8; // r0
  _DWORD v9[8]; // [sp+8h] [bp-C0h] BYREF
  int v10; // [sp+28h] [bp-A0h]
  int v11; // [sp+2Ch] [bp-9Ch]
  int v12; // [sp+30h] [bp-98h]
  int v13; // [sp+34h] [bp-94h]
  int v14; // [sp+38h] [bp-90h]

  v5 = result;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    result = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (*(_DWORD *)(result + 0x3C0) & 4) == 0 )
    {
      if ( *(_DWORD *)(v5 + 340) )
      {
        if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
          || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
        {
          v6 = 0;
        }
        else
        {
          v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
        }
        if ( v6 && v5 == *(_DWORD *)(result + 336) )
        {
          result = DbgkpSuppressDbgMsg(v6);
          if ( result )
            return result;
          v7 = v6 + 20;
        }
        else
        {
          v7 = 0;
        }
        v14 = v7;
        v10 = DbgkpSectionToFileHandle(a2);
        v11 = a3;
        v12 = 0;
        v13 = 0;
        v8 = RtlImageNtHeader(a3);
        if ( v8 )
        {
          v12 = *(_DWORD *)(v8 + 12);
          v13 = *(_DWORD *)(v8 + 16);
        }
        v9[0] = 3407900;
        v9[1] = 8;
        v9[6] = 5;
        DbgkpSendApiMessage(v5, 1, v9);
        result = v10;
        if ( v10 )
          result = ObCloseHandle(v10);
      }
    }
  }
  return result;
}
