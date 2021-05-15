// CMFFlushHitsFile 
 
int __fastcall CMFFlushHitsFile(int a1, unsigned int a2)
{
  unsigned int v4; // r5
  int v5; // r4
  unsigned int v6; // r6
  unsigned int v7; // r0
  unsigned int v9; // [sp+20h] [bp-268h] BYREF
  unsigned int v10[2]; // [sp+28h] [bp-260h] BYREF
  int v11; // [sp+30h] [bp-258h]
  int v12; // [sp+34h] [bp-254h]
  _BYTE *v13; // [sp+38h] [bp-250h]
  int v14; // [sp+3Ch] [bp-24Ch]
  int v15; // [sp+40h] [bp-248h]
  int v16; // [sp+44h] [bp-244h]
  int v17; // [sp+48h] [bp-240h]
  int v18; // [sp+4Ch] [bp-23Ch]
  int v19; // [sp+50h] [bp-238h] BYREF
  _BYTE v20[8]; // [sp+58h] [bp-230h] BYREF
  unsigned __int16 v21[276]; // [sp+60h] [bp-228h] BYREF

  v4 = 0;
  if ( !a1 )
    return -1073741811;
  if ( (CMFFlagsCache & 8) != 0
    || (v9 = a1,
        v10[0] = a2,
        v5 = MmFlushVirtualMemory(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), &v9, v10, &v19),
        v5 == -1073741688) )
  {
    v5 = RtlStringCchPrintfW(v21, 0x104u, (int)L"%s\\rc%04u\\rescache.hit", (int)L"\\SystemRoot\\Rescache");
    if ( v5 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v20, v21);
      v11 = 24;
      v12 = 0;
      v14 = 576;
      v13 = v20;
      v15 = 0;
      v16 = 0;
      v5 = ZwOpenFile();
      if ( (v5 & 0xC0000000) != -1073741824 )
      {
        v11 = 24;
        v12 = 0;
        v14 = 512;
        v13 = 0;
        v15 = 0;
        v16 = 0;
        v5 = ZwCreateEvent();
        if ( (v5 & 0xC0000000) != -1073741824 )
        {
          v10[0] = 0;
          v10[1] = 0;
          v5 = CMFGetFileSizeEx(0, v10);
          if ( (v5 & 0xC0000000) != -1073741824 )
          {
            v6 = v10[0];
            if ( a2 < v10[0] )
            {
              v6 = a2;
              v10[0] = a2;
            }
            v7 = ExAllocatePoolWithTag(1, v6, 1668114000);
            v4 = v7;
            v9 = v7;
            if ( v7 )
            {
              memmove(v7, a1, v6);
              v17 = 0;
              v18 = 0;
              v5 = ZwWriteFile();
              if ( v5 == 259 )
                v5 = ZwWaitForSingleObject();
            }
            else
            {
              v5 = -1073741801;
            }
          }
        }
      }
    }
    if ( v4 )
      ExFreePoolWithTag(v4);
  }
  return v5;
}
