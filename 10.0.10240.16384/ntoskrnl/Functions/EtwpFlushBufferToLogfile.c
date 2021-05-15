// EtwpFlushBufferToLogfile 
 
int __fastcall EtwpFlushBufferToLogfile(int a1)
{
  unsigned int v2; // r7
  int v4; // r5
  int v5; // r1
  __int64 v6; // kr08_8

  v2 = *(_DWORD *)(a1 + 4);
  if ( !*(_DWORD *)(a1 + 216) )
  {
    v4 = ZwWriteFile();
    if ( v4 >= 0 )
    {
      *(_QWORD *)(a1 + 144) += v2;
      v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C);
      *(_QWORD *)(v5 + 1872) += v2;
    }
    else
    {
      v6 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
      if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_WRITE_FAILED) )
        EtwpEventWriteTemplateAdmin(v6, HIDWORD(v6), ETW_EVENT_WRITE_FAILED);
    }
    if ( v4 >= 0 )
    {
      ++*(_DWORD *)(a1 + 176);
      ++*(_DWORD *)(a1 + 128);
      JUMPOUT(0x75EBBC);
    }
    JUMPOUT(0x809CCC);
  }
  return sub_809C0C();
}
