// IoInitializeMiniCompletionPacket 
 
int __fastcall IoInitializeMiniCompletionPacket(int result, __int64 a2)
{
  *(_DWORD *)(result + 8) = 4;
  *(_BYTE *)(result + 36) = 0;
  *(_QWORD *)(result + 28) = a2;
  return result;
}
