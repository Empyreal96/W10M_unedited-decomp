// PfpSectInfoHandleOutOfBuffers 
 
int __fastcall PfpSectInfoHandleOutOfBuffers(_DWORD *a1)
{
  return PfFbBufferListAllocateTemporary(a1, 0x4000);
}
