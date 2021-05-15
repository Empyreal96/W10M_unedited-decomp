// PsIsSystemThread 
 
BOOL __fastcall PsIsSystemThread(int a1)
{
  return (*(_DWORD *)(a1 + 76) & 0x400) != 0;
}
