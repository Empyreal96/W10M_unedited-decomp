// IopReadyDeviceObjects 
 
int __fastcall IopReadyDeviceObjects(int result)
{
  __int64 v1; // r2

  v1 = *(_QWORD *)(result + 4);
  *(_DWORD *)(result + 8) = HIDWORD(v1) | 0x10;
  while ( (_DWORD)v1 )
  {
    *(_DWORD *)(v1 + 28) &= 0xFFFFFF7F;
    LODWORD(v1) = *(_DWORD *)(v1 + 12);
  }
  return result;
}
