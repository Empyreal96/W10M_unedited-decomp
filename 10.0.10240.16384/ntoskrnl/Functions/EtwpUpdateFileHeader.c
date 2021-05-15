// EtwpUpdateFileHeader 
 
int __fastcall EtwpUpdateFileHeader(_DWORD *a1, int a2)
{
  int v4; // r5
  int v6; // r10
  _BYTE *v7; // r0
  unsigned int v8; // r6
  int v9; // [sp+44h] [bp-3Ch]

  v4 = ZwQueryVolumeInformationFile();
  if ( v4 >= 0 )
  {
    if ( a2 )
      return sub_80A964();
    v6 = a1[1];
    if ( ((v9 - 1) & v6) != 0 )
    {
      v4 = -1073741811;
    }
    else
    {
      v7 = (_BYTE *)ExAllocatePoolWithTag(1, (v6 + 4095) & 0xFFFFF000, 1350005829);
      v8 = (unsigned int)v7;
      if ( v7 )
      {
        memset(v7, 0, a1[1]);
        EtwpInitializeBufferHeader(a1, v8);
        EtwpResetBufferHeader(v8, 4);
        EtwpAddLogHeader((int)a1);
        v4 = ZwWriteFile();
        if ( v4 >= 0 )
        {
          if ( (a1[3] & 0x20) != 0 )
            v4 = ZwSetInformationFile();
          if ( v4 >= 0 )
          {
            a1[44] = 1;
            a1[32] = 1;
            a1[36] = v6;
            a1[37] = 0;
          }
        }
        ExFreePoolWithTag(v8);
      }
      else
      {
        v4 = -1073741801;
      }
    }
  }
  return v4;
}
